#include "grid.hpp"

#pragma once

#include <exception>
#include <utility>

// template<class T>
// void Grid<T>::removeRows(size_type row, size_type n)
// {
// 	int i;
// 	int j;

// 	int newNbRows = (m_nbRows - row > n) ? m_nbRows - n : row + 1;

// 	std::vector<T>newArray(newNbRows*m_nbCols);

// 	for (i = 0; i < row; ++i) {
// 		for (j = 0; j < m_nbCols; ++j) {
// 			newArray[i*m_nbCols + j] = m_data[i*m_nbCols + j];
// 		}
// 	}

// 	for (i = row + n; i < m_nbRows; ++i) {
// 		for (j = 0; j < m_nbCols; ++j) {
// 			newArray[(i - n)*m_nbCols + j] = m_data[i*m_nbCols + j];
// 		}
// 	}
// }

// template<class T>
// void Grid<T>::removeCols(size_type col, size_type n)
// {
// 	int i;
// 	int j;

// 	int newNbCols = (m_nbCols - col > n) ? m_nbCols - n : col + 1;

// 	std::vector<T>newArray(m_nbRows*newNbCols);

// 	for (j = 0; j < col; ++j) {
// 		for (i = 0; i < m_nbRows; ++i) {
// 			newArray[i*m_nbCols + j] = m_data[i*m_nbCols + j];
// 		}
// 	}

// 	for (j = col + n; j < m_nbCols; ++j) {
// 		for (i = 0; i < m_nbCols; ++i) {
// 			newArray[i*m_nbCols + j - n] = m_data[i*m_nbCols + j];
// 		}
// 	}
// }

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