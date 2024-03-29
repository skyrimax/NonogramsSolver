#pragma once

#include <memory>
#include <vector>

#include <stdexcept>

template <class T, class Allocator = std::allocator<T>>
class Grid
{
public:
    // Type to indicate size of container
    typedef size_t size_type;

    Grid(size_type nbRows = 0, size_type nbCols = 0)
        : m_data(nbRows * nbCols, Allocator()), m_nbRows(nbRows), m_nbCols(nbCols)
    {
    }

    Grid(size_type nbRows, size_type nbCols, const T &val)
        : m_data(nbRows * nbCols, val, Allocator()), m_nbRows(nbRows), m_nbCols(nbCols)
    {
    }

    Grid(size_type nbRows, size_type nbCols, const std::vector<T> &data)
        : m_data(nbRows * nbCols == data.size() ? data : throw std::invalid_argument("Invalid argument: nbRows*nbCols MUST equal the size of the data vector")),
          m_nbRows(nbRows), m_nbCols(nbCols)
    {
    }

    Grid(size_type nbRows, size_type nbCols, std::vector<T> &&data)
        : m_data(nbRows * nbCols == data.size() ? std::move(data) : throw std::invalid_argument("Invalid argument: nbRows*nbCols MUST equal the size of the data vector")),
          m_nbRows(nbRows), m_nbCols(nbCols)
    {
    }

    Grid(const Grid<T> &grid)
        : m_data(grid.m_data), m_nbRows(grid.m_nbRows), m_nbCols(grid.m_nbCols)
    {
    }

    Grid(Grid<T> &&grid)
        : m_data(std::move(grid.m_data)), m_nbRows(grid.m_nbRows), m_nbCols(grid.m_nbCols)
    {
        grid.m_nbRows = 0;
        grid.m_nbCols = 0;
    }

    ~Grid()
    {
    }

    // Assignement operator overloading
    Grid<T> &operator=(const Grid<T> &grid)
    {
        m_nbRows = grid.m_nbRows;
        m_nbCols = grid.m_nbCols;
        m_data = grid.m_data;

        return *this;
    }

    Grid<T> &operator=(Grid<T> &&grid)
    {
        m_nbRows = grid.m_nbRows;
        m_nbCols = grid.m_nbCols;
        m_data = std::move(grid.m_data);

        grid.m_nbRows = 0;
        grid.m_nbCols = 0;

        return *this;
    }

    // Capacity related member functions
    size_type nbRows() const
    {
        return m_nbRows;
    }

    size_type nbCols() const
    {
        return m_nbCols;
    }

    void resize(size_type nbRows, size_type nbCols)
    {
        std::vector<T> newArray(nbRows * nbCols);

        for (int i = 0; i < m_nbRows && i < nbRows; ++i)
        {
            for (int j = 0; j < m_nbCols && j < nbCols; ++j)
            {
                newArray[i * nbCols + j] = this->at(i, j);
            }
        }

        m_data.swap(newArray);

        m_nbRows = nbRows;
        m_nbCols = nbCols;
    }

    void resize(size_type nbRows, size_type nbCols, const T &val)
    {
        std::vector<T> newArray(nbRows * nbCols, val);

        for (int i = 0; i < m_nbRows && i < nbRows; ++i)
        {
            for (int j = 0; j < m_nbCols && j < nbCols; ++j)
            {
                newArray[i * nbCols + j] = this->at(i, j);
            }
        }

        m_data.swap(newArray);

        m_nbRows = nbRows;
        m_nbCols = nbCols;
    }

    bool empty() const
    {
        return m_data.empty();
    }

    // Element access methods
    T &operator()(size_type row, size_type col)
    {
        return m_data[row * m_nbCols + col];
    }

    const T &operator()(size_type row, size_type col) const
    {
        return m_data[row * m_nbCols + col];
    }

    T &at(size_type row, size_type col)
    {
        if (row < m_nbRows && col < m_nbCols)
        {
            return m_data[row * m_nbCols + col];
        }
        else
        {
            throw std::out_of_range("vector::_M_range_check");
        }
    }

    const T &at(size_type row, size_type col) const
    {
        if (row < m_nbRows && col < m_nbCols)
        {
            return m_data[row * m_nbCols + col];
        }
        else
        {
            throw std::out_of_range("vector::_M_range_check");
        }
    }

    Grid<std::reference_wrapper<T>> rows(size_type row, size_type n=1)
    {
    	std::vector<std::reference_wrapper<T>>rowsToReturnData;
        rowsToReturnData.reserve(n*m_nbCols);

    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m_nbCols; ++j) {
                rowsToReturnData.push_back(
                    std::ref(this->at(row + i, j)));
    		}
    	}

    	return Grid<std::reference_wrapper<T>>(n, m_nbCols,
                                                rowsToReturnData);
    }

    const Grid<std::reference_wrapper<const T>> rows(size_type row, size_type n = 1) const
    {
        std::vector<std::reference_wrapper<const T>>rowsToReturnData;
    	rowsToReturnData.reserve(n*m_nbCols);

    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m_nbCols; ++j) {
    			rowsToReturnData.push_back(
                    std::ref(this->at(row + i, j)));
    		}
    	}

    	return Grid<std::reference_wrapper<const T>>(n, m_nbCols,
                                                rowsToReturnData);
    }

    std::vector<std::reference_wrapper<T>> row(size_type row)
    {
    	std::vector<std::reference_wrapper<T>>rowToReturn;
        rowToReturn.reserve(m_nbCols);

    	for (int j = 0; j < m_nbCols; ++j) {
    		rowToReturn.push_back(
                std::ref(this->at(row, j)));
    	}

    	return rowToReturn;
    }

    const std::vector<std::reference_wrapper<const T>> row(size_type row) const
    {
    	std::vector<std::reference_wrapper<const T>>rowToReturn;
        rowToReturn.reserve(m_nbCols);

    	for (int j = 0; j < m_nbCols; ++j) {
    		rowToReturn.push_back(
                std::cref(this->at(row, j)));
    	}

    	return rowToReturn;
    }

    Grid<std::reference_wrapper<T>> cols(size_type col, size_type n = 1)
    {
    	std::vector<std::reference_wrapper<T>>colsToReturnData;
        colsToReturnData.reserve(n*m_nbRows);

    	for (int i = 0; i < m_nbRows; ++i) {
    		for (int j = 0; j < n; ++j) {
                colsToReturnData.push_back(
                    std::ref(this->at(i, col + j)));
    		}
    	}

    	return Grid<std::reference_wrapper<T>>(m_nbRows, n,
                                                colsToReturnData);
    }

    const Grid<std::reference_wrapper<const T>> cols(size_type col, size_type n = 1) const
    {
    	std::vector<std::reference_wrapper<const T>>colsToReturnData;
        colsToReturnData.reserve(n*m_nbRows);

    	for (int i = 0; i < m_nbRows; ++i) {
    		for (int j = 0; j < n; ++j) {
                colsToReturnData.push_back(
                    std::ref(this->at(i, col + j)));
    		}
    	}

    	return Grid<std::reference_wrapper<const T>>(m_nbRows, n,
                                                colsToReturnData);
    }

    std::vector<std::reference_wrapper<T>> col(size_type col)
    {
    	std::vector<std::reference_wrapper<T>>colToReturn;
        colToReturn.reserve(m_nbRows);

    	for (int i = 0; i < m_nbRows; ++i) {
    		colToReturn.push_back(
                std::ref(this->at(i, col)));
    	}

    	return colToReturn;
    }

    const std::vector<std::reference_wrapper<const T>> col(size_type col) const
    {
    	std::vector<std::reference_wrapper<const T>>colToReturn;
        colToReturn.reserve(m_nbRows);

    	for (int i = 0; i < m_nbRows; ++i) {
    		colToReturn.push_back(
                std::ref(this->at(i, col)));
    	}

    	return colToReturn;
    }

    // Grid<T> firstRowGrid()
    // {
    // 	return rows(0);
    // }

    // const Grid<T> firstRowGrid() const
    // {
    // 	return rows(0);
    // }

    // std::vector<T> firstRowVector()
    // {
    // 	return row(0);
    // }

    // const std::vector<T> firstRowVector() const
    // {
    // 	return row(0);
    // }

    // Grid<T> lastRowGrid()
    // {
    // 	return rows(m_nbRows - 1);
    // }

    // const Grid<T> lastRowGrid() const
    // {
    // 	return rows(m_nbRows - 1);
    // }

    // std::vector<T> lastRowVector()
    // {
    // 	return row(m_nbRows - 1);
    // }

    // const std::vector<T> lastRowVector() const
    // {
    // 	return row(m_nbRows - 1);
    // }

    // Grid<T> firstColGrid()
    // {
    // 	return cols(0);
    // }

    // const Grid<T> firstColGrid() const
    // {
    // 	return cols(0);
    // }

    // std::vector<T> firstColVector()
    // {
    // 	return col(0);
    // }

    // const std::vector<T> firstColVector() const
    // {
    // 	return col(0);
    // }

    // Grid<T> lastColGrid()
    // {
    // 	return cols(m_nbCols-1);
    // }

    // const Grid<T> lastColGrid() const
    // {
    // 	return cols(m_nbCols - 1);
    // }

    // std::vector<T> lastColVector()
    // {
    // 	return col(m_nbCols - 1);
    // }

    // const std::vector<T> lastColVector() const
    // {
    // 	return col(m_nbCols - 1);
    // }

    std::vector<T>& data()
    {
        return m_data;
    }

    const std::vector<T>& data() const
    {
        return m_data;
    }

    // Modifiers
    void assign(size_type nbRows, size_type nbCols, const T &val)
    {
        std::vector<T> newArray(nbRows * nbCols, val);

        m_data.swap(newArray);

        m_nbRows = nbRows;
        m_nbCols = nbCols;
    }

    // void insertRows(size_type row, const Grid<T>& elements)
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

    // void insertRow(size_type row, const std::vector<T>& elements)
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

    // void insertCols(size_type col, const Grid<T>& elements)
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

    // void insertCol(size_type col, const std::vector<T>& elements)
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

    // void removeRows(size_type row, size_type n=1)
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

    // void removeCols(size_type col, size_type n = 1)
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

    void swap(Grid<T> &grid)
    {
        int holdNbRows(m_nbRows);
        int holdNbCols(m_nbCols);

        m_data.swap(grid.m_data);

        m_nbRows = grid.m_nbRows;
        m_nbCols = grid.m_nbCols;

        grid.m_nbRows = holdNbRows;
        grid.m_nbCols = holdNbCols;
    }

    void clear()
    {
        m_data.clear();

        m_nbCols = 0;
        m_nbRows = 0;
    }

private:
    std::vector<T> m_data;
    size_type m_nbRows;
    size_type m_nbCols;
};