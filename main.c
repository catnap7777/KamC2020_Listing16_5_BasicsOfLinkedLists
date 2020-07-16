
//Listing 16_5 The basics of a linked list; page 404
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//the list data structure
struct data {
    char name[20];
    struct data *next;
};

//define typedefs (synonyms) for the structure
//and a pointer to it
//So, when you see PERSON, substitute 'struct data *' and for the next line
//  this means struct data *LINE --> where LINK is a pointer to the structure data
typedef struct data PERSON;
typedef PERSON *LINK;

int main(void)
{
    //head, new, and current pointers
    LINK head = NULL;
    LINK new = NULL;
    LINK current = NULL;

    //add the first list element. We do not assume the list is empty, although
    // in this demo program it always will be

    new = (LINK)malloc(sizeof(PERSON));
    new->next = head;
    head = new;
    strcpy(new->name, "Abigail");

    //add an element to the end of the list
    //we assume the list contails at least one element

    current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }

    new =  (LINK)malloc(sizeof(PERSON));
    current->next = new;
    new->next = NULL;
    strcpy(new->name, "Carolyn");

    //add a new element at the second position in the list
    new = (LINK)malloc(sizeof(PERSON));
    new->next = head->next;
    head->next = new;
    strcpy(new->name, "Beatrice");

    //print all the data items in order
    current = head;
    while(current != NULL)
    {
        printf("\n%s", current->name);
        current = current->next;
    }

    printf("\n\n");
    return 0;

}
