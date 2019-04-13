/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once
#define _USE_MATH_DEFINES

#include "..\utils\color_type.h"

#include <vector>
#include <exception>
#include <math.h>

namespace color_space
{
	class color_base
	{
	public:
		color_base(int component_count, float component_max = 1.f, float component_min = 0.f)
		{
			m_max = component_max;
			m_min = component_min;

			for (auto i = 0; i < component_count; ++i)
			{
				m_component_vector.push_back(-1);
			}
		}

		virtual color_type get_color_type() const { return m_type; }
		virtual float get_component_max() const { return m_max; }
		virtual float get_component_min() const { return m_min; }

		friend bool operator==(const color_base& lhs, const color_base& rhs)
		{
			bool precondition = (lhs.get_color_type() == rhs.get_color_type()) && (lhs.m_component_vector.size() == rhs.m_component_vector.size());

			if (!precondition)
			{
				return false;
			}

			for (std::vector<float>::size_type i = 0; i < lhs.m_component_vector.size(); ++i)
			{
				if (lhs.m_component_vector[i] != rhs.m_component_vector[i])
				{
					return false;
				}
			}

			return true;
		}

		friend bool operator!=(const color_base& lhs, const color_base& rhs)
		{
			return !(lhs == rhs);
		}

		color_base operator+(const color_base& rhs)
		{
			color_base result(this->m_component_vector.size(), this->get_component_max(), this->get_component_min());
			if (this->get_color_type() == rhs.get_color_type() && this->m_component_vector.size() == rhs.m_component_vector.size())
			{
				result.m_type = this->m_type;
				for (auto i = 0; i < this->m_component_vector.size(); ++i)
				{
					result.m_component_vector[i] = clamp(this->m_component_vector[i] + rhs.m_component_vector[i], m_max, m_min);
				}
			}
			else
			{
				throw new std::invalid_argument("Color Base: Error while adding two colors: The colors to add have different types.");
			}
			return result;
		}

		std::vector<float> m_component_vector;

	protected:
		float clamp(float in_value, float max, float min) { return fmaxf(fminf(in_value, max), min); }
		void set_component(float new_value, int index) { m_component_vector[index] = clamp(new_value, m_max, m_min); }
		void set_component(float new_value, int index, float max, float min) { m_component_vector[index] = clamp(new_value, max, min); }

		float m_max = 1.f;
		float m_min = 0.f;
		color_type m_type = color_type::UNDEFINED;
	};
}