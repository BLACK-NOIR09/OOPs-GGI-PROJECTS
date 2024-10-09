#include <iostream>
using namespace std;

void deleteElement(int arr[], int& n, int position) {
    // Shift elements to the left to fill the gap created by the deleted element
    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Decrease the size of the array
    n--;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5}; // Initial array
    int n = 5; // Current size of the array
    int position;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Get the position from the user
    cout << "Enter the position of the element to delete: ";
    cin >> position;

    // Ensure the position is within the valid range
    if (position < 0 || position >= n) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    deleteElement(arr, n, position);

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
