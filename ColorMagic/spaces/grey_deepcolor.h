#pragma once

#include "color_base.h"
#include <string>
#include <vector>

namespace color_space
{
	class grey_deepcolor : public color_base
	{
	public:
		grey_deepcolor(float value = 0.f, float alpha = 1.f);
		grey_deepcolor(const grey_deepcolor& other);

		grey_deepcolor& operator=(const grey_deepcolor& other);
		
		float grey();
		void grey(float new_grey);
		float alpha();
		void alpha(float new_alpha);

	private:

	};
}