#pragma once

#include "icolor.h"
#include <string>
#include <vector>

namespace ColorSpaces
{
	class grey_deepcolor : public icolor
	{
	public:
		grey_deepcolor();
		grey_deepcolor(float value);
		grey_deepcolor(float value, float alpha);
		grey_deepcolor(const grey_deepcolor& other);

		color_type get_color_type() override { return color_type::GREY_DEEP; }

		grey_deepcolor& operator=(const grey_deepcolor& other);
		
		float grey();
		void grey(float new_grey);
		float alpha();
		void alpha(float new_alpha);

	private:

	};
}