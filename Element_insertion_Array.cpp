#include <iostream>
using namespace std;

void insertElement(int arr[], int& n, int element, int position) {
    // Shift elements to the right to make space for the new element
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element at the specified position
    arr[position] = element;
    // Increase the size of the array
    n++;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5}; // Initial array
    int n = 5; // Current size of the array
    int element, position;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Get the element and position from the user
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert the element: ";
    cin >> position;

    // Ensure the position is within the valid range
    if (position < 0 || position > n) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    insertElement(arr, n, element, position);

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
