#include "grid.hpp"

#pragma once

#include <exception>
#include <utility>

template<class T>
void Grid<T>::swap(Grid<T>& grid)
{
	int holdNbRows(m_nbRows);
	int holdNbCols(m_nbCols);

	m_data.swap(grid.m_data);

	m_nbRows = grid.m_nbRows;
	m_nbCols = grid.m_nbCols;

	grid.m_nbRows = holdNbRows;
	grid.m_nbCols = holdNbCols;
}

template<class T>
void Grid<T>::clear()
{
	m_data.clear();

	m_nbCols = 0;
	m_nbRows = 0;
}