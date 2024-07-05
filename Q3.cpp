#include<iostream>
#include<climits>
using namespace std;

// Function to find the most minimum number in array that is not present 
int findMin(int arr[], int size, int* present) {
    for (int i = 0; i < size; i++)
        present[arr[i]] += 1; // count occurrence

    
    int min = INT_MAX;  // gives min number
    for (int i = 0; i < size; i++)
        if (present[i] == 0) {
            min = i;
            break;
        }
    return min;
}

// chks if segment is possible 
int chkSegment(int* present, int index) {
    // Check if all values from 0 to index-1 are present at least twice
    for (int i = index - 1; i >= 0; i--)
        if (present[i] < 2)
            return -1;
    return 1;
}

int main() {
    // Get  input
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    if(size<=0)
    cout<<"Invalid Input"<<endl;
else{
    // Create a dynamic array 
    int* arr = new int[size];
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // Create a dynamic array for occurrence count
    int* present = new int[size]();
    int index = findMin(arr, size, present);

    if (chkSegment(present, index) == -1)
        cout << "Impossible: " << -1 << endl;
    else {
        int startInd = 1;
        int endInd = 0;
        for (int i = 0, j = 0; i < size && j < index; i++) {
            if (arr[i] == j)
                j++;
            endInd = i;
        }
        endInd += 1;
        cout << "Segments: " << 2 << endl;
        cout << startInd << "-" << endInd << endl;
        cout << endInd + 1 << "-" << size << endl;
    }

    // Delete the dynamic arrays to free memory
    delete[] arr;
    delete[] present;
}
    return 0;
}