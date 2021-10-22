#include <cstddef>
#include "list.h"

struct ListItem
{
    Data data;
    ListItem* next;
};

// struct List defined in list.h

List* list_create()
{
    return new List;
}

void list_delete(List* list)
{
    delete list;
}

ListItem* list_first(List* list)
{
    return list->head;
}

Data list_item_data(const ListItem* item)
{
    if(item)
        return item->data; 
}

ListItem* list_item_next(ListItem* item)
{
    return item->next;
}

ListItem* list_item_prev(ListItem* item) 
{
    return NULL; // Not applicable for the singly linked lists.
}

ListItem* list_insert(List* list, Data data)
{
    ListItem* new_element = new ListItem;
    new_element->data = data;
    new_element->next = list->head;
    list->head = new_element;
    return NULL;
}

ListItem* list_insert_after(List* list, ListItem* item, Data data)
{
    ListItem* new_element = new ListItem;
    new_element->data = data;
    new_element->next = item->next;
    item->next = new_element;
    return NULL;
}

ListItem* list_erase(List* list, ListItem* item)
{
    return NULL; // Not applicable for the singly linked lists.
}

ListItem* list_erase_next(List* list, ListItem* item)
{
    if (item->next != nullptr)
    {
        ListItem* item_next = item->next;
        item->next = item->next->next;
        delete item_next;
        return NULL;
    }
}
