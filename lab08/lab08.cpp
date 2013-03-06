#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

// Linked list item struct
struct Item {
  int value;
  Item *next;
};

// Global declarations of an array and linked list head pointer
const int MAXSIZE = 50000;
int list[MAXSIZE];
Item *head;

int arraySequentialSearch( int value ) {
  //An array-based sequential search algorithm. Returns the index position
  //of the value being searched for if found and returns -1 otherwise
  for ( int loc=0; loc<MAXSIZE; loc++ ) {
    if ( list[loc] == value ) {
      return loc;
    }
  }

  return -1;
}

Item *linkedSequentialSearch( int value ) {
  //A linked-list-based sequential search algorithm. Returns a pointer to the item
  //containing the value if found and a null otherwise
  Item *current = head;

  while ( current != NULL ) {
    if ( current->value == value ) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

int arrayBinarySearch( int value ) {
  //An array-based binary search algorithm. Returns the index position
  //of the value being searched for if found and returns -1 otherwise
  int first=0, last=MAXSIZE-1, mid;

  while ( first <= last ) {
    mid = (first + last) / 2;

    if ( list[mid] == value ) {
      //Found it
      return mid;
    }

    //Haven't found it, yet. Determine which sublist to continue with and
    //adjust first or last
    if ( list[mid] > value ) {
      //Go left, so adjust last to be mid-1
      last = mid - 1;
    } else {
      //Go right, so adjust first to be mid+1
      first = mid + 1;
    }
  }

  return -1;
}



// **************** CHANGE ME ************************
// Change the code to populate data with random numbers
// between 0 and 1,000,000 and insert them in sorted order
void populateLinkedList() {
  //Appends MAXSIZE even numbers in the list
  Item *temp, *last, *temp2, *trailer;
  
  //Create the first item so that in the for loop we don't
  //have to check for head == NULL
  head = new Item;
  head->value = 0;
  head->next = NULL;
  last = head;

  for ( int i=1; i < MAXSIZE; i++ ) {
    temp = new Item;
    temp->value = rand()%(1000000);
    temp->next = NULL;
    if(temp->value < head->value) {
    	temp->next = head->next;
   		head = temp;
    }
    else if(temp->value > last->value) {
    	last->next = temp;
    	last = temp;
    }
    else {
    	temp2 = head;
    	while(temp2->next->value < temp->value) {
    		temp2 = temp2->next; 	
    	}
    	temp->next = temp2->next;
    	temp2->next = temp;
    }
  }
  
//The following loop will check to see if linked list is in order
  /*Item* temp3;
  temp3 = head;
  for(int i = 0; i < MAXSIZE - 1; i++) {
  	if(temp3->value > temp3->next->value) {
  		cout << i << ": Items not in order." << endl;
  	}
  	temp3 = temp3->next;
  }*/
}

// **************** CHANGE ME ************************
// Change the code to populate data with random numbers
// between 0 and 1,000,000
void populateArrayList() {
  //Puts MAXSIZE even numbers in the list
  for ( int i=0; i<MAXSIZE; i++ ) {
    list[i] = rand()%(1000000);
  }
}

// **************** WRITE ME ************************
// Add your code (function(s)) to implement Selection Sort
void selectionSort() {
	for(int i = 0; i < MAXSIZE; i++) {
		int temp = list[i];
		int min = list[i];
		int minAddress = i;
		for(int j = i + 1; j < MAXSIZE; j++) {
			if(list[j] < min) {
				min = list[j];
				minAddress = j;
			}
		}
		list[i] = min;
		list[minAddress] = temp;
	}
}

// **************** WRITE ME ************************
// Add your code (function(s)) to implement Merge Sort
void merge(int* input, int left, int right) {
	int mid = (left+right)/2;
	
	int x = 0;
	int y = left;
	int z = mid + 1;
	
	int temp[right - left + 1];
	
	while(y <= mid && z <= right) {
		if(input[y] < input[z]) {
			temp[x++] = input[y++];
		}	else {
			temp[x++] = input[z++];
		}
	}
	
	while(y <= mid) {
		temp[x++] = input[y++];
	}
	
	while(z <= right) {
		temp[x++] = input[z++];
	}
	
	for(int i = left; i <= right; i++) {
		input[i] = temp[i-left];
	}
}

void mergeSort(int* input, int left, int right) {
	if(left < right) {
		int mid = (left + right)/2;
		mergeSort(input, left, mid);
		mergeSort(input, mid + 1, right);
		merge(input, left, right);
	}
}

int other[MAXSIZE];

int main() {
	
  clock_t start, finish;
  double  duration;
  cout << "List size of " << MAXSIZE << endl;
	
	// Setting the state of rand to a new value
	srand(time(NULL));
	
  //Put data into the two types of lists
  populateArrayList();
  populateLinkedList();

  start = clock();

  // Add your call to either selection or merge sort here.
	
	//selectionSort();
	mergeSort(list, 0, 49999);
	
	cout << "Done sorting." << endl;


  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Total CPU for sort time: "<<duration<<endl;

  // Write a for loop to check that data in your array is 
  // in sorted order

	for(int i = 0; i < MAXSIZE - 1; i++) {
		if(list[i+1] < list[i]) {
			cout << "ITEMS NOT IN ORDER" << endl;
			cout << i << ": " << list[i] << endl << i+1 << ": " << list[i+1] << endl;
		}
	}

  //Let's start off with a value not in the list and see how long it takes.
  int numiters = 100000;
  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    arraySequentialSearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU for array sequential search time: "<<duration/numiters<<endl;

  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    linkedSequentialSearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU for linked sequential search time: "<<duration/numiters<<endl;

  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    arrayBinarySearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU time for array binary searches time: "<<duration/numiters<<endl;


  return 0;
}

