# Test program for Damerau Levenshtein
add_executable(dldist_test dldist_test.cpp "${CMAKE_CURRENT_SOURCE_DIR}/../include/dldist.hpp")

target_include_directories(dldist_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include/")
