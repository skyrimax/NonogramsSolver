#include "grid.hpp"

#pragma once

#include <exception>
#include <utility>

template<class T>
std::vector<T> Grid<T>::data()
{
	return m_data;
}

template<class T>
const std::vector<T> Grid<T>::data() const
{
	return m_data;
}

template<class T>
void Grid<T>::assign(size_type nbRows, size_type nbCols, const T & val)
{
	std::vector<T>newArray(nbRows*nbCols, val);

	m_data.swap(newArray);

	m_nbRows = nbRows;
	m_nbCols = nbCols;
}

// template<class T>
// void Grid<T>::insertRows(size_type row, const Grid<T>& elements)
// {
// 	int i;
// 	int j;

// 	std::vector<T> newArray((m_nbRows + elements.m_nbRows)*m_nbCols);

// 	for (i = 0; i < row; ++i) {
// 		for (j = 0; j < m_nbCols; ++j) {
// 			newArray[i*m_nbCols + j] = m_data[i*m_nbCols + j];
// 		}
// 	}

// 	for (i = row; i < row + elements.m_nbRows; ++i) {
// 		for (j = 0; j < m_nbCols && j < elements.m_nbCols; ++j) {
// 			newArray[i*m_nbCols + j]=elements.m_data[i*m_nbCols + j];
// 		}

// 		for (j=elements.m_nbCols; j < m_nbRows; ++j) {
// 			newArray[i*m_nbCols + j] = T();
// 		}
// 	}

// 	for (i = row + elements.m_nbRows; i < m_nbRows; ++i) {
// 		for (j = 0; j < m_nbCols; ++j) {
// 			newArray[i*m_nbCols + j] = m_data[(i-elements.m_nbRows)*m_nbCols + j];
// 		}
// 	}

// 	m_data.swap(newArray);
// }

// template<class T>
// void Grid<T>::insertRow(size_type row, const std::vector<T>& elements)
// {
// 	int i;
// 	int j;

// 	std::vector<T>newArray((m_nbRows + 1)*m_nbCols);

// 	for (i = 0; i < row; ++i) {
// 		for (j = 0; j < m_nbCols; ++j) {
// 			newArray[i*m_nbCols + j] = m_data[i*m_nbCols + j];
// 		}
// 	}

// 	for (i = row; i < row + 1; ++i) {
// 		for (j = 0; j < m_nbCols && j < elements.size(); ++j) {
// 			newArray[i*m_nbCols + j] = elements[j];
// 		}

// 		for (j = elements.size(); j < m_nbRows; ++j) {
// 			newArray[i*m_nbCols + j] = T();
// 		}
// 	}

// 	for (i = row + elements.m_nbRows; i < m_nbRows; ++i) {
// 		for (j = 0; j < m_nbCols; ++j) {
// 			newArray[i*m_nbCols + j] = m_data[(i - 1)*m_nbCols + j];
// 		}
// 	}

// 	m_data.swap(newArray);
// }

// template<class T>
// void Grid<T>::insertCols(size_type col, const Grid<T>& elements)
// {
// 	int i;
// 	int j;

// 	std::vector<T>newArray(m_nbRows*(m_nbCols+elements.m_nbCols));

// 	for (j = 0; j < col; ++j) {
// 		for (i = 0; i < m_nbRows; ++i) {
// 			newArray[i*m_nbCols + j] = m_data[i*m_nbCols + j];
// 		}
// 	}

// 	for (j = col; j < col + elements.m_nbCols; ++j) {
// 		for (i = 0; i < m_nbRows && i < elements.m_nbRows; ++i) {
// 			newArray[i*m_nbCols + j] = elements.m_data[i*m_nbCols + j];
// 		}

// 		for (i=elements.m_nbRows; i < m_nbRows; ++i) {
// 			newArray[i*m_nbCols + j] = T();
// 		}
// 	}

// 	for (j = col + elements.m_nbCols; j < m_nbCols; ++j) {
// 		for (i = 0; i < m_nbRows; ++i) {
// 			newArray[i*m_nbCols + j] = m_data[i*m_nbCols + (j - elements.m_nbRows)];
// 		}
// 	}

// 	m_data.swap(newArray);
// }

// template<class T>
// void Grid<T>::insertCol(size_type col, const std::vector<T>& elements)
// {
// 	int i;
// 	int j;

// 	std::vector<T>newArray(m_nbRows*(m_nbCols + 1));

// 	for (j = 0; j < col; ++j) {
// 		for (i = 0; i < m_nbRows; ++i) {
// 			newArray[i*m_nbCols + j] = m_data[i*m_nbCols + j];
// 		}
// 	}

// 	for (j = col; j < col + 1; ++j) {
// 		for (i = 0; i < m_nbRows && i < elements.size(); ++i) {
// 			newArray[i*m_nbCols + j] = elements[j];
// 		}

// 		for (i = elements.size(); i < m_nbRows; ++i) {
// 			newArray[i*m_nbCols + j] = T();
// 		}
// 	}

// 	for (j = col + elements.m_nbCols; j < m_nbCols; ++j) {
// 		for (i = 0; i < m_nbRows; ++i) {
// 			newArray[i*m_nbCols + j] = m_data[(i - 1)*m_nbCols + j];
// 		}
// 	}

// 	m_data.swap(newArray);
// }

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