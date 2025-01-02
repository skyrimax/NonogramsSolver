add_library(thread_pool INTERFACE
            thread-pool/BS_thread_pool.hpp)

target_include_directories(thread_pool INTERFACE
                            thread-pool)