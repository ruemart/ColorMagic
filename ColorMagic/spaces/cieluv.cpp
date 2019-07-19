#include "stdafx.h"
#include "cieluv.h"

color_space::cieluv::cieluv(float L, float u, float v, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 3, 100.f, -100.f)
{
	this->m_type = color_type::CIELUV;
	this->L(L);
	this->u(u);
	this->v(v);
}

color_space::cieluv::cieluv(const color_space::cieluv & other) : color_base(other.alpha(), other.get_rgb_color_space(), 4, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::cieluv::cieluv(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 4, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::CIELUV && other.get_component_vector().size() == 4)
	{
		this->m_type = color_type::CIELUV;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("cieluv: Error while creating cieluv class from base object. Base object and this derived class have different types.");
	}
}

color_space::cieluv & color_space::cieluv::operator=(const cieluv & other)
{
	if (this != &other)
	{
		this->m_type = other.get_color_type();
		this->m_component_vector = other.get_component_vector();
		this->m_max = other.get_component_max();
		this->m_min = other.get_component_min();
	}
	return *this;
}

float color_space::cieluv::L() const
{
	return m_component_vector[0];
}

void color_space::cieluv::L(float new_L)
{
	set_component(new_L, 0, 100.f, 0.f);
}

float color_space::cieluv::u() const
{
	return m_component_vector[1];
}

void color_space::cieluv::u(float new_u)
{
	set_component(new_u, 1);
}

float color_space::cieluv::v() const
{
	return m_component_vector[2];
}

void color_space::cieluv::v(float new_v)
{
	set_component(new_v, 2);
}