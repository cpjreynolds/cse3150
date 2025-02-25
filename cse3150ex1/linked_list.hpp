#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <ostream>

struct node {
    int data;
    node* next;
};

node* build_new_linked_list(int nelts);

int get_linked_list_data_item_value(node* start, int index, int nelts);

void print_linked_list(node* start, int nelts);

std::ostream& operator<<(std::ostream& os, const node* n);

bool update_data_in_linked_list(node* start, int index, int value, int nelts);

void delete_linked_list(node* start);

size_t get_list_length(const node* start);

#endif
