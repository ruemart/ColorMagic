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
	class gamma_part
	{
	public:
		gamma_part() : m_gamma_function(nullptr), m_upper_border(1.f) {}

		gamma_part(std::function<float(float)> gamma_function, float upper_border = 1.f) : m_gamma_function(gamma_function), m_upper_border(upper_border) {}

		gamma_part(const gamma_part& other)
		{
			this->m_gamma_function = other.get_gamma_function();
			this->m_upper_border = other.get_upper_border();
		}

		gamma_part& operator=(const gamma_part& other)
		{
			if (this != &other)
			{
				this->m_gamma_function = other.get_gamma_function();
				this->m_upper_border = other.get_upper_border();
			}
			return *this;
		}

		bool operator==(const gamma_part& other)
		{
			return m_upper_border == other.get_upper_border();
		}

		friend bool operator==(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() == rhs.get_upper_border();
		}

		bool operator!=(const gamma_part& other)
		{
			return !(*this == other);
		}

		friend bool operator!=(const gamma_part& lhs, const gamma_part& rhs)
		{
			return !(lhs == rhs);
		}

		bool operator<(const gamma_part& other)
		{
			return m_upper_border < other.get_upper_border();
		}

		friend bool operator<(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() < rhs.get_upper_border();
		}

		bool operator>(const gamma_part& other)
		{
			return m_upper_border > other.get_upper_border();
		}

		friend bool operator>(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() > rhs.get_upper_border();
		}

		bool operator<=(const gamma_part& other)
		{
			return m_upper_border <= other.get_upper_border();
		}

		friend bool operator<=(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() <= rhs.get_upper_border();
		}

		bool operator>=(const gamma_part& other)
		{
			return m_upper_border >= other.get_upper_border();
		}

		friend bool operator>=(const gamma_part& lhs, const gamma_part& rhs)
		{
			return lhs.get_upper_border() >= rhs.get_upper_border();
		}

		float get_upper_border() const { return m_upper_border; }

		void set_upper_border(float new_border) { m_upper_border = new_border; }

		std::function<float(float)> get_gamma_function() const { return m_gamma_function; }

		void set_gamma_function(std::function<float(float)> new_gamma_function) { m_gamma_function = new_gamma_function; }

	protected:
		float m_upper_border;

		std::function<float(float)> m_gamma_function;
	};

	class gamma
	{
	public:
		gamma() : m_gamma_curve_parts(std::vector<gamma_part*>()), m_inverse_gamma_curve_parts(std::vector<gamma_part*>()) {}

		gamma(std::vector<gamma_part*> gamma_parts, std::vector<gamma_part*> inverse_gamma_parts) : m_gamma_curve_parts(gamma_parts), m_inverse_gamma_curve_parts(inverse_gamma_parts)
		{
			sort_gamma_parts(m_gamma_curve_parts);
			sort_gamma_parts(m_inverse_gamma_curve_parts);
		}

		gamma(const gamma& other)
		{
			m_gamma_curve_parts = other.get_gamma_curve_parts();
			m_inverse_gamma_curve_parts = other.get_inverse_gamma_curve_parts();
			sort_gamma_parts(m_gamma_curve_parts);
			sort_gamma_parts(m_inverse_gamma_curve_parts);
		}

		gamma& operator=(const gamma& other)
		{
			if (this != &other)
			{
				m_gamma_curve_parts = other.get_gamma_curve_parts();
				m_inverse_gamma_curve_parts = other.get_inverse_gamma_curve_parts();
				sort_gamma_parts(m_gamma_curve_parts);
				sort_gamma_parts(m_inverse_gamma_curve_parts);
			}
			return *this;
		}

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

		bool operator!=(const gamma& other)
		{
			return !(*this == other);
		}

		friend bool operator!=(const gamma& lhs, const gamma& rhs)
		{
			return !(lhs == rhs);
		}

		std::vector<gamma_part*> get_gamma_curve_parts() const { return m_gamma_curve_parts; }

		void add_gamma_curve_part(gamma_part* new_part)
		{
			m_gamma_curve_parts.push_back(new_part);
			sort_gamma_parts(m_gamma_curve_parts);
		}

		bool remove_gamma_curve_part(std::vector<gamma_part*>::iterator position)
		{
			m_gamma_curve_parts.erase(position);
		}

		void set_gamma_curve_parts(std::vector<gamma_part*> new_gamma_curve_parts)
		{
			m_gamma_curve_parts = new_gamma_curve_parts;
			sort_gamma_parts(m_gamma_curve_parts);
		}

		std::vector<gamma_part*> get_inverse_gamma_curve_parts() const { return m_inverse_gamma_curve_parts; }

		void add_inverse_gamma_curve_part(gamma_part* new_part)
		{
			m_inverse_gamma_curve_parts.push_back(new_part);
			sort_gamma_parts(m_inverse_gamma_curve_parts);
		}

		bool remove_inverse_gamma_curve_part(std::vector<gamma_part*>::iterator position)
		{
			m_inverse_gamma_curve_parts.erase(position);
		}

		void set_inverse_gamma_curve_parts(std::vector<gamma_part*> new_gamma_curve_parts)
		{
			m_inverse_gamma_curve_parts = new_gamma_curve_parts;
			sort_gamma_parts(m_inverse_gamma_curve_parts);
		}

		float gamma_correction(float input_value)
		{
			for(gamma_part* part : m_gamma_curve_parts)
			{
				if (input_value <= part->get_upper_border())
				{
					return (part->get_gamma_function())(input_value);
				}
			}
			return input_value;
		}

		float inverse_gamma_correction(float input_value)
		{
			for (gamma_part* part : m_inverse_gamma_curve_parts)
			{
				if (input_value <= part->get_upper_border())
				{
					return (part->get_gamma_function())(input_value);
				}
			}
			return input_value;
		}

	protected:
		void sort_gamma_parts(std::vector<gamma_part*> gamma_parts)
		{
			std::sort(gamma_parts.begin(), gamma_parts.end());
		}

		std::vector<gamma_part*> m_gamma_curve_parts;

		std::vector<gamma_part*> m_inverse_gamma_curve_parts;
	};
	
	class gamma_presets
	{
	public:
		gamma* gamma1_8()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 1.8f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 1.8f); }));

			return new gamma(g, ig);
		}
		
		gamma* gamma2_2()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 2.2f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 2.2f); }));

			return new gamma(g, ig);
		}

		gamma* gamma2_6()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 2.6f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 2.6f); }));

			return new gamma(g, ig);
		}

		gamma* gamma2_8()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 2.8f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 2.8f); }));

			return new gamma(g, ig);
		}

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

		gamma* gammaAdobe()
		{
			std::vector<gamma_part*> g;
			std::vector<gamma_part*> ig;

			g.push_back(new gamma_part([](float input) { return std::powf(input, 1.f / 2.19921875f); }));
			ig.push_back(new gamma_part([](float input) { return std::powf(input, 2.19921875f); }));

			return new gamma(g, ig);
		}

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