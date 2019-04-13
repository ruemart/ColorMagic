/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>
#include <vector>

namespace color_space
{
	class grey_truecolor : public color_base
	{
	public:
		grey_truecolor(unsigned char value = ((unsigned char)0), unsigned char alpha = ((unsigned char)255));
		grey_truecolor(const grey_truecolor& other);
		grey_truecolor(const color_base& other);

		grey_truecolor& operator=(const grey_truecolor& other);

		unsigned char grey();
		void grey(unsigned char new_grey);
		unsigned char alpha();
		void alpha(unsigned char new_alpha);

	private:

	};
}