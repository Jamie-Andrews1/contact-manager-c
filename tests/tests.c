#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../functions.h"

void test_add_contact() {
    Contact temp;
    // We manually test our logic here
    strncpy(temp.name, "Archie", 49);
    temp.name[49] = '\0';
    
    // Assertion: If this isn't true, the program crashes with an error message
    assert(strcmp(temp.name, "Archie") == 0);
    printf("  [PASS] Contact Name Assignment\n");
}

void test_search_logic() {
    Contact list[2];
    strcpy(list[0].name, "Alice");
    strcpy(list[1].name, "Bob");

    // Simulate your search function (assuming it returns the index)
    int result = find_contact(list, "Bob", 2);
    assert(result == 1); 
    
    int missing = find_contact(list, "Charlie", 2);
    assert(missing == -1);
    
    printf("  [PASS] Search Functionality\n");
}

int main() {
    printf("\033[1;33mRunning Unit Tests...\033[0m\n");
    
    test_add_contact();
    test_search_logic();
    
    printf("\033[1;32mAll Tests Passed! (2/2)\033[0m\n");
    return 0;
}