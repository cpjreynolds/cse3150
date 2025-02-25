#include <iostream>

#include "linked_list.hpp"

/*
 * build_new_linked_list:
 *
 *  Creates a linked list with `nelts` elements, initialized with incrementing
 *  data values beginning with 0.
 *
 *      returns a pointer to the first node in the linked list
 *      if nelts == 0, returns null
 */
node* build_new_linked_list(int nelts)
{
    if (nelts < 1) {
        return nullptr; // nullptr is preferable to NULL in c++
    }
    node* root = new node{.data = 0, .next = nullptr};
    node* llist = root;

    /*
     * original code had a few bugs:
     *      would add one more node than requested
     *      would overwrite previous nodes data
     *
     * this fixes both issues
     */
    for (int i = 1; i < nelts; ++i) {
        /*
         * at the start of each iteration, the current node pointed to by
         * `llist` already has `data`, just needs a `next`.
         *
         * this loop inits `data` to previous + 1
         */
        llist->next = new node{.data = llist->data + 1, .next = nullptr};
        llist = llist->next;
    }

    return root;
}

/*
 * get_linked_list_data_item_value:
 *
 *  returns -1 if not enough nodes
 */
int get_linked_list_data_item_value(node* start, int index, int nelts)
{
    // needs to be num >= total
    // otherwise you'll be able to index one after the end of the list
    // presuming indices begin at 0
    if (!start || index >= nelts || index < 0 || nelts < 1) {
        // overrun
        return -1;
    }
    node* llist = start;

    for (int i = 0; i < index; ++i) {
        llist = llist->next;
    }

    return llist->data;
}

void print_linked_list(node* start, int _nelts)
{
    std::cout << start << std::endl;
}

/*
 * output_linked_list
 *
 * print_linked_list is not easily testable without redirecting/capturing
 * stdout, so I made this instead to test stringifying a list.
 */
std::ostream& operator<<(std::ostream& os, const node* n)
{
    os << "{";
    // last node points to nullptr.
    // (kinda obviates the need for passing `nelts` each time but I wasn't
    // going to change the interface set out in the exercise)
    while (n) {
        os << n->data;
        n = n->next;
        if (n) {
            os << ", ";
        }
    }
    return os << "}";
}

/*
 * update_data_in_linked_list:
 *      Returns false if index >= nelts
 *      Returns true otherwise
 */
bool update_data_in_linked_list(node* start, int index, int value, int nelts)
{
    if (!start || index >= nelts || index < 0 || nelts < 1) {
        // overrun
        return false;
    }
    node* llist = start;
    for (int i = 0; i < index; ++i) {
        llist = llist->next;
    }
    llist->data = value;
    return true;
}

/*
 * delete_linked_list
 *
 *  deallocates given list beginning with `start`
 *
 * NOTE: not sure how to test this with a unit framework. Valgrind would be how
 * I would diagnose a memory leak. There's no way to test for a leak or
 * use-after-free in doctest.h that I could find.
 */
void delete_linked_list(node* start)
{
    node* current = start;
    node* next = nullptr;
    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
}

/*
 * get_list_length
 *
 *  returns the number of nodes in the list.
 *
 *  used for testing to assert created lists are the size they should be.
 */
size_t get_list_length(const node* start)
{
    size_t len = 0;
    while (start) {
        ++len;
        start = start->next;
    }
    return len;
}