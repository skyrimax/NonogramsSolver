#include "grid.hpp"

#pragma once

#include <exception>
#include <utility>

template<class T>
void Grid<T>::clear()
{
	m_data.clear();

	m_nbCols = 0;
	m_nbRows = 0;
}