#pragma once

#include "..\utils\color_type.h"

#include <vector>

namespace color_space
{
	class icolor
	{
	public:
		icolor(int component_count) { m_component_vector.reserve(component_count); }

		virtual color_type get_color_type() const {
			return color_type::UNDEFINED;
		}

		friend bool operator==(const icolor& lhs, const icolor& rhs)
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

		friend bool operator!=(const icolor& lhs, const icolor& rhs)
		{
			return !(lhs == rhs);
		}

		std::vector<float> m_component_vector;
	};
}