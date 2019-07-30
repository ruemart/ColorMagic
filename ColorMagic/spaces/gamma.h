/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include <algorithm>
#include <functional>
#include <vector>

namespace color_space
{
	//! Class that represents a gamma function.
	/*!
	* This class implements various functions to do gamma correction.
	*/
	class gamma_part
	{
	public:
		//! Default constructor.
		gamma_part() : m_gamma_function(nullptr), m_upper_border(1.f) {}

		//! Default constructor.
		/*!
		* \param gamma_function The function to calculate gamma corrections. Input value is the value to convert, return value is the result.
		* \param upper_border The conversion will only be done using this function if the input is lower than this value. Since the conversion is
		* done in rgb deep space (value range [0, 1]) 1 is the maximum possible value for the border.
		*/
		gamma_part(std::function<float(float)> gamma_function, float upper_border = 1.f) : m_gamma_function(gamma_function), m_upper_border(upper_border) {}

		//! Default copy constructor.
		gamma_part(const gamma_part& other)
		{
			this->m_gamma_function = other.get_gamma_function();
			this->m_upper_border = other.get_upper_border();
		}

		//! Default deconstructor.
		/*!
		* Default deconstructor.
		*/
		~gamma_part()
		{
			m_gamma_function = nullptr;
		}

		//! Assignment operator
		gamma_part& operator=(const gamma_part& other)
		{
			if (this != &other)
			{
				this->m_gamma_function = other.get_gamma_function();
				this->m_upper_border = other.get_upper_border();
			}
			return *this;
		}

		//! Equality operator
		friend bool operator==(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() == rhs.get_upper_border() && lhs.get_gamma_function_address() == rhs.get_gamma_function_address();
		}

		//! Equality operator
		friend bool operator==(gamma_part& lhs, gamma_part& rhs)
		{
			return lhs.get_upper_border() == rhs.get_upper_border() && lhs.get_gamma_function_address() == rhs.get_gamma_function_address();
		}

		//! Inequality operator
		friend bool operator!=(const gamma_part& lhs, const gamma_part& rhs)
		{
			return !(lhs == rhs);
		}

		//! Inequality operator
		friend bool operator!=(gamma_part& lhs, gamma_part& rhs)
		{
			return !(lhs == rhs);
		}

		//! Comparison operator
		friend bool operator<(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() < rhs.get_upper_border();
		}

		//! Comparison operator
		friend bool operator>(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() > rhs.get_upper_border();
		}

		//! Comparison operator
		friend bool operator<=(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() <= rhs.get_upper_border();
		}

		//! Comparison operator
		friend bool operator>=(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() >= rhs.get_upper_border();
		}

		//! Comparison operator
		friend bool operator<(gamma_part& lhs, gamma_part& rhs)
		{
			return lhs.get_upper_border() < rhs.get_upper_border();
		}

		//! Comparison operator
		friend bool operator>(gamma_part& lhs, gamma_part& rhs)
		{
			return lhs.get_upper_border() > rhs.get_upper_border();
		}

		//! Comparison operator
		friend bool operator<=(gamma_part& lhs, gamma_part& rhs)
		{
			return lhs.get_upper_border() <= rhs.get_upper_border();
		}

		//! Comparison operator
		friend bool operator>=(gamma_part& lhs, gamma_part& rhs)
		{
			return lhs.get_upper_border() >= rhs.get_upper_border();
		}

		//! Access the upper border.
		float get_upper_border() const { return m_upper_border; }

		//! Set a new upper border.
		void set_upper_border(float new_border) { m_upper_border = new_border; }

		//! Access the gamma function.
		std::function<float(float)> get_gamma_function() const { return m_gamma_function; }

		//! Set a new gamma function.
		void set_gamma_function(std::function<float(float)> new_gamma_function) { m_gamma_function = new_gamma_function; }

		//! Access the memory address of the gamma function. Used for function comparison.
		long get_gamma_function_address() const
		{
			if (!m_gamma_function) return 0;

			return *(long *)(char *)&m_gamma_function;
		}

	protected:
		//! The gamma function.
		std::function<float(float)> m_gamma_function;

		//! The upper border.
		float m_upper_border;
	};

	//! Class that stores functions for gamma and inverse gamma calculation.
	/*!
	* This class stores functions for gamma and inverse gamma calculation.
	*/
	class gamma
	{
	public:
		//! Default constructor.
		gamma() : m_gamma_curve_parts(std::vector<gamma_part*>()), m_inverse_gamma_curve_parts(std::vector<gamma_part*>()) {}

		//! Default constructor.
		/*!
		* \param gamma_parts A vector of gamma_part objects used for default gamma corrections. 
		* \param inverse_gamma_parts A vector of gamma_part objects used for inverse gamma corrections. 
		*/
		gamma(std::vector<gamma_part*> gamma_parts, std::vector<gamma_part*> inverse_gamma_parts) : m_gamma_curve_parts(gamma_parts), m_inverse_gamma_curve_parts(inverse_gamma_parts)
		{
			sort_gamma_parts();
			sort_inverse_gamma_parts();
		}

		//! Default copy constructor.
		gamma(const gamma& other)
		{
			m_gamma_curve_parts = other.get_gamma_curve_parts();
			m_inverse_gamma_curve_parts = other.get_inverse_gamma_curve_parts();
			sort_gamma_parts();
			sort_inverse_gamma_parts();
		}

		//! Default deconstructor.
		/*!
		* Default deconstructor.
		*/
		~gamma()
		{
			
		}

		//! Assignment operator
		gamma& operator=(const gamma& other)
		{
			if (this != &other)
			{
				m_gamma_curve_parts = other.get_gamma_curve_parts();
				m_inverse_gamma_curve_parts = other.get_inverse_gamma_curve_parts();
				sort_gamma_parts();
				sort_inverse_gamma_parts();
			}
			return *this;
		}

		//! Equality operator
		bool operator==(const gamma& other)
		{
			if (m_gamma_curve_parts.size() != other.get_gamma_curve_parts().size() || m_inverse_gamma_curve_parts.size() != other.get_inverse_gamma_curve_parts().size())
			{
				return false;
			}

			for (auto i = 0; i < m_gamma_curve_parts.size(); ++i)
			{
				if (m_gamma_curve_parts[i] != other.get_gamma_curve_parts()[i])
				{
					return false;
				}
			}

			for (auto i = 0; i < m_inverse_gamma_curve_parts.size(); ++i)
			{
				if (m_inverse_gamma_curve_parts[i] != other.get_inverse_gamma_curve_parts()[i])
				{
					return false;
				}
			}
			return true;
		}

		//! Equality operator
		friend bool operator==(const gamma& lhs, const gamma& rhs)
		{
			if (lhs.get_gamma_curve_parts().size() != rhs.get_gamma_curve_parts().size() || lhs.get_inverse_gamma_curve_parts().size() != rhs.get_inverse_gamma_curve_parts().size())
			{
				return false;
			}

			for (auto i = 0; i < lhs.get_gamma_curve_parts().size(); ++i)
			{
				if (lhs.get_gamma_curve_parts()[i] != rhs.get_gamma_curve_parts()[i])
				{
					return false;
				}
			}

			for (auto i = 0; i < lhs.get_inverse_gamma_curve_parts().size(); ++i)
			{
				if (lhs.get_inverse_gamma_curve_parts()[i] != rhs.get_inverse_gamma_curve_parts()[i])
				{
					return false;
				}
			}
			return true;
		}

		//! Inequality operator
		bool operator!=(const gamma& other)
		{
			return !(*this == other);
		}

		//! Inequality operator
		friend bool operator!=(const gamma& lhs, const gamma& rhs)
		{
			return !(lhs == rhs);
		}

		//! Access the default gamma parts
		std::vector<gamma_part*> get_gamma_curve_parts() const { return m_gamma_curve_parts; }

		//! Add a new gamma function to the list of default gamma parts
		void add_gamma_curve_part(gamma_part* new_part)
		{
			m_gamma_curve_parts.push_back(new_part);
			sort_gamma_parts();
		}
		
		//! Remove the given gamma function from the list of default gamma parts
		bool remove_gamma_curve_part(std::vector<gamma_part*>::iterator position)
		{
			m_gamma_curve_parts.erase(position);
		}

		//! Replace the list of default gamma parts.
		void set_gamma_curve_parts(std::vector<gamma_part*> new_gamma_curve_parts)
		{
			m_gamma_curve_parts = new_gamma_curve_parts;
			sort_gamma_parts();
		}

		//! Access the inverse gamma parts
		std::vector<gamma_part*> get_inverse_gamma_curve_parts() const { return m_inverse_gamma_curve_parts; }

		//! Add a new gamma function to the list of inverse gamma parts
		void add_inverse_gamma_curve_part(gamma_part* new_part)
		{
			m_inverse_gamma_curve_parts.push_back(new_part);
			sort_inverse_gamma_parts();
		}

		//! Remove the given gamma function from the list of inverse gamma parts
		bool remove_inverse_gamma_curve_part(std::vector<gamma_part*>::iterator position)
		{
			m_inverse_gamma_curve_parts.erase(position);
		}

		//! Replace the list of inverse gamma parts.
		void set_inverse_gamma_curve_parts(std::vector<gamma_part*> new_gamma_curve_parts)
		{
			m_inverse_gamma_curve_parts = new_gamma_curve_parts;
			sort_inverse_gamma_parts();
		}

		//! Takes the matching default gamma_part and calculates the gamma correction.
		float gamma_correction(float input_value)
		{
			for (gamma_part* part : m_gamma_curve_parts)
			{
				if (part == nullptr || !(part->get_gamma_function())) continue;

				if (input_value <= part->get_upper_border())
				{
					return (part->get_gamma_function())(input_value);
				}
			}
			return input_value;
		}

		//! Takes the matching inverse gamma_part and calculates the gamma correction.
		float inverse_gamma_correction(float input_value)
		{
			for (gamma_part* part : m_inverse_gamma_curve_parts)
			{
				if (part == nullptr || !(part->get_gamma_function())) continue;

				if (input_value <= part->get_upper_border())
				{
					return (part->get_gamma_function())(input_value);
				}
			}
			return input_value;
		}

	protected:
		//! Sort the default gamma parts in ascending order depending on the upper border.
		void sort_gamma_parts()
		{
			std::sort(m_gamma_curve_parts.begin(), m_gamma_curve_parts.end(), [](gamma_part* gp1, gamma_part* gp2) { return (*gp1) < (*gp2); });
		}

		//! Sort the inverse gamma parts in ascending order depending on the upper border.
		void sort_inverse_gamma_parts()
		{
			std::sort(m_inverse_gamma_curve_parts.begin(), m_inverse_gamma_curve_parts.end(), [](gamma_part* gp1, gamma_part* gp2) { return (*gp1) < (*gp2); });
		}

		//! The default gamma parts in ascending order depending on their upper border.
		std::vector<gamma_part*> m_gamma_curve_parts;

		//! The inverse gamma parts in ascending order depending on their upper border.
		std::vector<gamma_part*> m_inverse_gamma_curve_parts;
	};

	//! Class that stores some default gamma functions.
	/*!
	* This class stores gamma functions like 2.2, 1.8 or sRGB function.
	*/
	class gamma_presets
	{
	public:
		//! Returns a simple 1.8 gamma function that does gamma correction by calculating input ^ 1.8 or input ^ 1/1.8
		gamma* gamma1_8()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 1.8f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 1.8f); }));

			return new gamma(g, ig);
		}

		//! Returns a simple 2.2 gamma function that does gamma correction by calculating input ^ 2.2 or input ^ 1/2.2
		gamma* gamma2_2()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 2.2f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 2.2f); }));

			return new gamma(g, ig);
		}

		//! Returns a simple 2.6 gamma function that does gamma correction by calculating input ^ 2.6 or input ^ 1/2.6
		gamma* gamma2_6()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 2.6f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 2.6f); }));

			return new gamma(g, ig);
		}

		//! Returns a simple 2.8 gamma function that does gamma correction by calculating input ^ 2.8 or input ^ 1/2.8
		gamma* gamma2_8()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 2.8f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 2.8f); }));

			return new gamma(g, ig);
		}

		//! Returns the sRGB gamma function that consists of two parts with a border at 0.0031308f or 0.04045f.
		gamma* sRGB()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return 12.92f * input; }, 0.0031308f));
			g.push_back(new gamma_part([](float input) { return 1.055f * std::powf(input, 1.f / 2.4f) - 0.055f; }, 1.f));

			ig.push_back(new gamma_part([](float input) { return input / 12.92f; }, 0.04045f));
			ig.push_back(new gamma_part([](float input) { return std::powf((input + 0.055f) / 1.055f, 2.4f); }, 1.f));

			return new gamma(g, ig);
		}

		//! Returns the Adobe gamma function that does gamma correction by calculating input ^ 2.19921875f or input ^ 1/2.19921875f
		gamma* gammaAdobe()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 2.19921875f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 2.19921875f); }));

			return new gamma(g, ig);
		}

		//! Returns the Romm gamma function that consists of two parts with a border at 0.001953f.
		gamma* gammaRomm()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return 16.f * input; }, 0.001953f));
			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 1.8f); }, 1.f));

			ig.push_back(new gamma_part([](float input) { return input / 16.f; }, 0.001953f));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 1.8f); }, 1.f));

			return new gamma(g, ig);
		}

		//! Returns the UHDTV gamma function that consists of two parts with a border at 0.081f or 0.018053968510807f.
		gamma* gammaUHDTV()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return input / 4.5f; }, 0.081f));
			g.push_back(new gamma_part([](float input) { return std::powf((input + 0.099f) / 1.099f, 1.f / 0.45f); }, 1.f));

			ig.push_back(new gamma_part([](float input) { return 4.5f * input; }, 0.018053968510807f));
			ig.push_back(new gamma_part([](float input) { return 1.099f * std::powf(input, 0.45f) - 0.099f; }, 1.f));

			return new gamma(g, ig);
		}
	};
}