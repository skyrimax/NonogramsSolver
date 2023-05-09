#include <vector>

#include <BS_thread_pool.hpp>

namespace NS
{
    class NonogramSolver
    {
    private:
        // Tread pool for parallel processing
        BS::thread_pool tp;

    public:
        NonogramSolver(/* args */);
        ~NonogramSolver();
    };
}