
/*### Algorithm
1. Define the number of rows and columns.
2. Declare a 2D array with the specified rows and columns.
3. Initialize the array with values or take input from the user.
4. Access and manipulate the array elements as needed.*\

### Program
```cpp
#include <iostream>
using namespace std;

int main() {
    // Define the number of rows and columns
    int rows = 3, cols = 4;

    // Declare a 2D array
    int array[3][4];

    // Initialize the array with values or take input from the user
    cout << "Enter values for the 2D array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> array[i][j];
        }
    }

    // Display the 2D array
    cout << "2D array values:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
