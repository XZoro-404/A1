#include "Queue.c"

Data getChildren(int parent, int * number) {
    int child = 0; // the Pid(s) for the children in the file
    char filePath[35] = ""; // the string for the file path
    int arraySize = 0; // an array to hold the children Pid(s)

    // Below we are changing the parent int to a string and creating the file path string
    sprintf(filePath, "/proc/%d/task/%d/children", parent, parent);

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
        arraySize++; // increments the array size
    }
    fclose(in_file); // closes the file
    Data children;
    children.result = number;
    children.length = arraySize;
    return children;
}

/*

	Function name: dataProcess
	Input to the Method: the main queue we created in main
	Output: none
	Brief Description of the task:
	Creates a new Node reference that holds the dequeued Node then gets the data and prints
	appropriately based on the input and level as well as queueing the children.

 */

void dataProcess(Queue* queue)
{

	//Initializing the temporary node
	Node temp;
	temp = dequeue(queue);

	//Initializing the Data struct to process
	int childrenNums[MAX_CHILD_ARR_SIZE];
	Data tempData = getChildren(temp.num, childrenNums);

	//Prints tabs based on the level of the child
	for(int idx = 0; idx < temp.level; idx++) {

		printf("\t");

	}

	//Prints the inital string to be built upon
	printf("Children of %d:", temp.num);

	//Queues chidren as well as printing them
	for(int childIdx = 0; childIdx < tempData.length; childIdx++) {

		printf("%d ", tempData.result[childIdx]);
		Node child;
		child.num = tempData.result[childIdx];
		child.level = temp.level + 1;
		enqueue(&child, queue);
	}

}
