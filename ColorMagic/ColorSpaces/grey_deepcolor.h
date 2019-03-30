#pragma once

#include "icolor.h"
#include <string>
#include <vector>

namespace ColorSpaces
{
	class grey_deepcolor : public icolor
	{
	public:
		grey_deepcolor(float value = 0.f);
		grey_deepcolor(float value = 0.f, float alpha = 1.f);
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