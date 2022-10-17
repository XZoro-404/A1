#include <stdio.h>
#include <stdlib.h>

int * getChildren(int parent) {
    FILE *in_file = fopen("testNum", "r"); // read only
    int number;
    int arraySize = 0;

    // test for files not existing.
    if (in_file == NULL) {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }

    while (fscanf(in_file, "%d", &number ) == 1)
    {
        arraySize++;
        printf("number: %d\n", arraySize);


    }
    fclose(in_file);
}

int main(int argc, char * argv[]){

    int * example = getChildren(1);

}


