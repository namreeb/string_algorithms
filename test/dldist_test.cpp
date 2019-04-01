/*
 * MIT License
 *
 * Copyright (c) 2019 namreeb (legal@namreeb.org) http://github.com/namreeb/string_algorithms
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "dldist.hpp"

#include <iostream>
#include <string>

const struct
{
    std::string a;
    std::string b;
    int expected_score;
} tests[] =
{
    { "test", "test", 0},                   // trivial case
    { "test", "et", 2},                     // deletion
    { "test", "thisisateststring", 13},     // insertions
    { "test", "tEst", 1},                   // substitution
    { "test", "stet", 2},                   // transposition
};

int main()
{
    auto constexpr num_tests = sizeof(tests) / sizeof(tests[0]);

    for (auto i = 0u; i < num_tests; ++i)
    {
        auto const score1 = nam::damerau_levenshtein_distance(tests[i].a, tests[i].b);
        auto const score2 = nam::damerau_levenshtein_distance(tests[i].b, tests[i].a);

        if (score1 != score2)
            std::cout << "WARNING: commutative property violation" << std::endl;

        std::cout << "nam::damerau_levenshtein_distance(\"" << tests[i].a << "\", \"" << tests[i].b << "\") = "
            << score1 << ".  Expected " << tests[i].expected_score << std::endl;

        if (score1 != tests[i].expected_score)
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}