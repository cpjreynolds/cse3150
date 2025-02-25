#include <iostream>
#include <fstream>
#include <string>
#include <ranges>

#ifndef TESTING

#include "ivec.hpp"

int main(int argc, char** argv)
{
    std::string fname = "vectors_1.txt";
    if (argc == 2) {
        fname = std::string(argv[1]);
    }

    std::ifstream ifile(fname);
    auto vecs = int_vector::from_stream(ifile);

    for (auto& iv : vecs | std::views::reverse) {
        std::cout << iv << std::endl;
    }
    return 0;
}

#else
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#endif
