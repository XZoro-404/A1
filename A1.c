#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * getChildren(int parent, int * number) {
    int child = 0; // the Pid(s) for the children in the file
    char parentNum[20] = ""; // the int that gets passed in
    char filePath[50] = ""; // the string for the file path
    int arraySize = 0; // an array to hold the children Pid(s)

    // Below we are changing the parent int to a string and creating the file path string
    sprintf(parentNum, "%d", parent);
    strcat(filePath, "/proc/");
    strcat(filePath, parentNum);
    strcat(filePath, "/task/");
    strcat(filePath, parentNum);
    strcat(filePath, "/children");

    FILE *in_file = fopen(filePath, "r"); // read only

    // test for files not existing.
    if (in_file == NULL) {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }

    // goes through the file and gets the numbers while counting the amount of ints in the file
    while (fscanf(in_file, "%d", &child ) == 1)
    {
        number[arraySize] = child; // sets the child pid to an array
        printf("\nNumbers: %d\n", number[arraySize]);
        arraySize++; // increments the array size
    }
    fclose(in_file); // closes the file
    Data childern;
    children.result = number;
    children.length = arraySize;
    return &children;
}

int main(int argc, char * argv[]){

//    int * example = getChildren(1);
    int userInput = 348;
    int number[100];
    getChildren(userInput, &number[0]);
    printf("numbers: %d", number[0]);


}


