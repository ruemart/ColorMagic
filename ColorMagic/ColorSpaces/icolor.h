#pragma once

#include "color_type.h"
#include <vector>

namespace ColorSpaces
{
	class icolor
	{
	public:
		icolor(int component_count) { component_vector.reserve(component_count); }

		virtual color_type get_color_type() const {
			return color_type::UNDEFINED;
		}

		friend bool operator==(const icolor& lhs, const icolor& rhs)
		{
			bool precondition = (lhs.get_color_type() == rhs.get_color_type()) && (lhs.component_vector.size() == rhs.component_vector.size());

			if (!precondition)
			{
				return false;
			}

			for (std::vector<float>::size_type i = 0; i < lhs.component_vector.size(); ++i)
			{
				if (lhs.component_vector[i] != rhs.component_vector[i])
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

		std::vector<float> component_vector;
	};
}