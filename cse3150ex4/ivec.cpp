#ifdef TESTING

#include "ivec.hpp"
#include "doctest.h"

#include <sstream>

TEST_CASE("int_vector")
{
    SUBCASE("int_vector::int_vector()")
    {
        int_vector t;
        CHECK(t.id == -1);
        CHECK(t.from == 0);
        CHECK(t.to == 0);
    }

    SUBCASE("int_vector::int_vector(int,int,int)")
    {
        int_vector t(1, 2, 3);
        CHECK(t.id == 1);
        CHECK(t.from == 2);
        CHECK(t.to == 3);
    }

    SUBCASE("int_vector::int_vector(&)")
    {
        int_vector x(1, 2, 3);
        int_vector t = x; // copy ctor
        CHECK(t.id == 1);
        CHECK(t.from == 2);
        CHECK(t.to == 3);
    }

    SUBCASE("int_vector::operator<<")
    {
        std::ostringstream out;
        int_vector x(1, 2, 3);
        out << x;
        CHECK(out.str() == "1: 2 3");
    }

    SUBCASE("int_vector::operator>>")
    {
        std::istringstream in("1: 2 3");
        int_vector x;
        in >> x;
        CHECK(in.str() == "1: 2 3");
    }

    SUBCASE("int_vector::from_stream")
    {
        std::istringstream in("1 2\n1 3\n1 4\n2 7\n9 11");
        auto ivs = int_vector::from_stream(in);
        CHECK(ivs == std::vector({int_vector(0, 1, 2), int_vector(1, 1, 3),
                                  int_vector(2, 1, 4), int_vector(3, 2, 7),
                                  int_vector(4, 9, 11)}));
    }

    SUBCASE("int_vector::from_stream(empty)")
    {
        std::istringstream in("");
        auto ivs = int_vector::from_stream(in);
        CHECK(ivs.empty());
    }
}

#endif
