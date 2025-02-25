#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <sstream>
using std::ostringstream;
using std::string;

#include "doctest.h"
#include "linked_list.hpp"

TEST_CASE("linked_list testing")
{
    node* lzero = build_new_linked_list(0);
    node* lneg = build_new_linked_list(-1);
    node* lone = build_new_linked_list(1);
    node* ltwo = build_new_linked_list(2);
    node* lfive = build_new_linked_list(5);

    /*
     * first test the length of each list, if this fails the whole suite fails
     * because if we can't tell the length of each list there are bigger
     * problems afoot.
     */
    REQUIRE_EQ(get_list_length(lzero), 0);
    REQUIRE_EQ(get_list_length(lneg), 0);
    REQUIRE_EQ(get_list_length(lone), 1);
    REQUIRE_EQ(get_list_length(ltwo), 2);
    REQUIRE_EQ(get_list_length(lfive), 5);

    SUBCASE("build_new_linked_list")
    {
        SUBCASE("zero-element list")
        {
            CHECK_EQ(lzero, nullptr);
        }
        SUBCASE("negative-element list")
        {
            CHECK_EQ(lneg, nullptr);
        }
        SUBCASE("one-element list")
        {
            CHECK_EQ(lone->data, 0);
            CHECK_EQ(lone->next, nullptr);
        }
        SUBCASE("two-element list")
        {
            CHECK_EQ(ltwo->data, 0);
            CHECK_EQ(ltwo->next->data, 1);
            CHECK_EQ(ltwo->next->next, nullptr);
        }
        SUBCASE("five-element list")
        {
            CHECK_EQ(lfive->data, 0);
            CHECK_EQ(lfive->next->data, 1);
            CHECK_EQ(lfive->next->next->data, 2);
            CHECK_EQ(lfive->next->next->next->data, 3);
            CHECK_EQ(lfive->next->next->next->next->data, 4);
            CHECK_EQ(lfive->next->next->next->next->next, nullptr);
        }
    }

    SUBCASE("get_linked_list_data_item_value")
    {
        // first two subcases are just ensuring bad parameters don't cause
        // segfaults.
        SUBCASE("zero-element list")
        {
            CHECK_EQ(get_linked_list_data_item_value(lzero, 0, 0), -1);
            CHECK_EQ(get_linked_list_data_item_value(lzero, 0, 1), -1);
            CHECK_EQ(get_linked_list_data_item_value(lzero, 1, 1), -1);
        }
        SUBCASE("negative-element list")
        {
            CHECK_EQ(get_linked_list_data_item_value(lneg, 0, -1), -1);
            CHECK_EQ(get_linked_list_data_item_value(lneg, -1, -1), -1);
            CHECK_EQ(get_linked_list_data_item_value(lneg, 1, 1), -1);
        }
        SUBCASE("one-element list")
        {
            CHECK_EQ(get_linked_list_data_item_value(lone, 0, 1), 0);
            CHECK_EQ(get_linked_list_data_item_value(lone, 1, 1), -1);
            CHECK_EQ(get_linked_list_data_item_value(lone, -1, 1), -1);
        }
        SUBCASE("two-element list")
        {
            CHECK_EQ(get_linked_list_data_item_value(ltwo, 0, 2), 0);
            CHECK_EQ(get_linked_list_data_item_value(ltwo, 1, 2), 1);
            CHECK_EQ(get_linked_list_data_item_value(ltwo, 2, 2), -1);
        }
        SUBCASE("five-element list")
        {
            CHECK_EQ(get_linked_list_data_item_value(lfive, 0, 5), 0);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 1, 5), 1);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 2, 5), 2);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 3, 5), 3);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 4, 5), 4);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 5, 5), -1);
        }
    }

    SUBCASE("output_linked_list")
    {
        SUBCASE("zero-element list")
        {
            ostringstream out;
            out << lzero;
            CHECK_EQ(out.str(), "{}");
        }
        SUBCASE("negative-element list")
        {
            ostringstream out;
            out << lneg;
            CHECK_EQ(out.str(), "{}");
        }
        SUBCASE("one-element list")
        {
            ostringstream out;
            out << lone;
            CHECK_EQ(out.str(), "{0}");
        }
        SUBCASE("two-element list")
        {
            ostringstream out;
            out << ltwo;
            CHECK_EQ(out.str(), "{0, 1}");
        }
        SUBCASE("five-element list")
        {
            ostringstream out;
            out << lfive;
            CHECK_EQ(out.str(), "{0, 1, 2, 3, 4}");
        }
    }

    SUBCASE("update_data_in_linked_list")
    {
        SUBCASE("zero-element list")
        {
            CHECK_EQ(update_data_in_linked_list(lzero, 0, 9, 0), false);
            // deliberately bad data
            CHECK_EQ(update_data_in_linked_list(lzero, 0, 9, 1), false);
            CHECK_EQ(update_data_in_linked_list(lzero, -1, 9, 1), false);
            CHECK_EQ(update_data_in_linked_list(lzero, 0, 9, -1), false);

            CHECK_EQ(get_linked_list_data_item_value(lzero, 0, 0), -1);

            SUBCASE("zero-element output after update")
            {
                ostringstream out;
                out << lzero;
                CHECK_EQ(out.str(), "{}");
            }
        }
        SUBCASE("negative-element list")
        {
            CHECK_EQ(update_data_in_linked_list(lneg, 0, 9, -1), false);

            CHECK_EQ(get_linked_list_data_item_value(lzero, 0, 0), -1);
            SUBCASE("negative-element output after update")
            {
                ostringstream out;
                out << lneg;
                CHECK_EQ(out.str(), "{}");
            }
        }
        SUBCASE("one-element list")
        {
            CHECK_EQ(update_data_in_linked_list(lone, 0, 1, 1), true);
            CHECK_EQ(update_data_in_linked_list(lone, 1, 2, 1), false);
            CHECK_EQ(get_linked_list_data_item_value(lone, 0, 1), 1);
            CHECK_EQ(get_linked_list_data_item_value(lone, 1, 1), -1);

            SUBCASE("one-element output after update")
            {
                ostringstream out;
                out << lone;
                CHECK_EQ(out.str(), "{1}");
            }
        }
        SUBCASE("two-element list")
        {
            CHECK_EQ(update_data_in_linked_list(ltwo, 0, 2, 2), true);
            CHECK_EQ(update_data_in_linked_list(ltwo, 1, 3, 2), true);
            CHECK_EQ(update_data_in_linked_list(ltwo, 2, 4, 2), false);
            CHECK_EQ(get_linked_list_data_item_value(ltwo, 0, 2), 2);
            CHECK_EQ(get_linked_list_data_item_value(ltwo, 1, 2), 3);
            CHECK_EQ(get_linked_list_data_item_value(ltwo, 2, 2), -1);

            SUBCASE("two-element output after update")
            {
                ostringstream out;
                out << ltwo;
                CHECK_EQ(out.str(), "{2, 3}");
            }
        }
        SUBCASE("five-element list")
        {
            CHECK_EQ(update_data_in_linked_list(lfive, 0, 5, 5), true);
            CHECK_EQ(update_data_in_linked_list(lfive, 1, 6, 5), true);
            CHECK_EQ(update_data_in_linked_list(lfive, 2, 7, 5), true);
            CHECK_EQ(update_data_in_linked_list(lfive, 3, 8, 5), true);
            CHECK_EQ(update_data_in_linked_list(lfive, 4, 9, 5), true);
            CHECK_EQ(update_data_in_linked_list(lfive, 5, 10, 5), false);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 0, 5), 5);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 1, 5), 6);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 2, 5), 7);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 3, 5), 8);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 4, 5), 9);
            CHECK_EQ(get_linked_list_data_item_value(lfive, 5, 5), -1);

            SUBCASE("five-element output after update")
            {
                ostringstream out;
                out << lfive;
                CHECK_EQ(out.str(), "{5, 6, 7, 8, 9}");
            }
        }
    }

    SUBCASE("get_list_length")
    // none of this should have changed, make sure for sanity.
    {
        SUBCASE("zero-element list")
        {
            CHECK_EQ(get_list_length(lzero), 0);
        }
        SUBCASE("negative-element list")
        {
            CHECK_EQ(get_list_length(lneg), 0);
        }
        SUBCASE("one-element list")
        {
            CHECK_EQ(get_list_length(lone), 1);
        }
        SUBCASE("two-element list")
        {
            CHECK_EQ(get_list_length(ltwo), 2);
        }
        SUBCASE("five-element list")
        {
            CHECK_EQ(get_list_length(lfive), 5);
        }
    }

    delete_linked_list(lneg);
    delete_linked_list(lzero);
    delete_linked_list(lone);
    delete_linked_list(ltwo);
    delete_linked_list(lfive);
}