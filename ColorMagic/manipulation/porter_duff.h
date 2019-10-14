/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "base_color_blend.h"
#include "..\spaces\color_base.h"
#include "color_converter.h"

namespace color_manipulation
{
	//! Static class for porter duff color blending operations
	/*!
	* This static class implements all 12 porter duff color blending operations.
	*/
	class porter_duff : protected base_color_blend
	{
	public:
		//! Static function that combines two colors by using the porter duff src operator.
		/*!
		* Static function that combines two colors by using the porter duff src operator. The 
		* result will only contain information from source. See \see{dest} for the inverted 
		* version of this operator.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the src operator.
		*/
		static color_space::color_base* src(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff dest operator.
		/*!
		* Static function that combines two colors by using the porter duff dest operator. The
		* result will only contain information from destination.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the dest operator.
		*/
		static color_space::color_base* dest(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff atop operator.
		/*!
		* Static function that combines two colors by using the porter duff atop operator. If
		* there is only source information (destination has alpha 0.f) the result will also use
		* alpha = 0.f. Otherwise a combination of source and destination or only destination will
		* be used. See \see{dest_atop} for the inverted version of this operator.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the atop operator.
		*/
		static color_space::color_base* atop(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff dest atop operator.
		/*!
		* Static function that combines two colors by using the porter duff dest atop operator. If
		* there is only destination information (source has alpha 0.f) the result will also use
		* alpha = 0.f. Otherwise a combination of destination and source or only source will be used.
		* This is the inverted version of \see{atop}.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the dest atop operator.
		*/
		static color_space::color_base* dest_atop(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff over operator.
		/*!
		* Static function that combines two colors by using the porter duff over operator. The
		* result is calculated by "drawing" the source color over the destination color.
		* See \see{dest_over} for the inverted version of this operator.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the over operator.
		*/
		static color_space::color_base* over(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff dest over operator.
		/*!
		* Static function that combines two colors by using the porter duff dest over operator. The
		* result is calculated by "drawing" the destination color over the source color.
		* This is the inverted version of \see{over}.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the dest over operator.
		*/
		static color_space::color_base* dest_over(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff in operator.
		/*!
		* Static function that combines two colors by using the porter duff in operator. The
		* result will only contain information of the source color. However the condition to
		* return source is whether there is a destination color in the same position.
		* See \see{dest_in} for the inverted version of this operator.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the in operator.
		*/
		static color_space::color_base* in(color_space::color_base* source, color_space::color_base* destination);		

		//! Static function that combines two colors by using the porter duff dest in operator.
		/*!
		* Static function that combines two colors by using the porter duff dest in operator. The
		* result will only contain information of the destination color. However the condition to
		* return destination is whether there is a source color in the same position.
		* This is the inverted version of \see{in}.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the dest in operator.
		*/
		static color_space::color_base* dest_in(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff out operator.
		/*!
		* Static function that combines two colors by using the porter duff out operator. The
		* result will only contain information of the source color. However the condition to
		* return source is whether there is no destination color in the same position.
		* See \see{dest_out} for the inverted version of this operator.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the out operator.
		*/
		static color_space::color_base* out(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff dest out operator.
		/*!
		* Static function that combines two colors by using the porter duff dest out operator. The
		* result will only contain information of the destination color. However the condition to
		* return destination is whether there is no source color in the same position.
		* This is the inverted version of \see{out}.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the dest out operator.
		*/
		static color_space::color_base* dest_out(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff xor operator.
		/*!
		* Static function that combines two colors by using the porter duff xor operator. The
		* operation will return source if there is the destination color and vice versa. If 
		* both colors overlap the result will be nothing.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the xor operator.
		*/
		static color_space::color_base* x_or(color_space::color_base* source, color_space::color_base* destination);

		//! Static function that combines two colors by using the porter duff clear operator.
		/*!
		* Static function that combines two colors by using the porter duff clear operator. The
		* operation will return nor source or destination.
		* Since the operation is done in rgb deep color space a conversion will be done first. 
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in 
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \return the combination of source and destination calculated with the clear operator.
		*/
		static color_space::color_base* clear(color_space::color_base* source, color_space::color_base* destination);
	};
}
