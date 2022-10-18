#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * getChildren(int parent) {

    char parentNum[20] = ""; // the int that gets passed in
    char filePath[100] = ""; // the string for the file path
    // Below we are changing the parent int to a string and creating the file path string
    sprintf(parentNum, "%d", parent);
    strcat(filePath, "/proc/");
    strcat(filePath, parentNum);
    strcat(filePath, "/task/");
    strcat(filePath, parentNum);
    strcat(filePath, "/children");

//    printf("Here is the file location: %s", filePath); // you can uncomment this to debug the filepath
    FILE *in_file = fopen(filePath, "r"); // read only
    int number; // this is the numbers in the children file
    int arraySize = 0;

    // test for files not existing.
    if (in_file == NULL) {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }
    // goes through the file and gets the numbers while counting the amount of ints in the file
    while (fscanf(in_file, "%d", &number ) == 1)
    {
        arraySize++;
        printf("number: %d\n", number);
    }
    printf("final number: %d", arraySize);
    fclose(in_file);
}

int main(int argc, char * argv[]){

    int * example = getChildren(1);

}


