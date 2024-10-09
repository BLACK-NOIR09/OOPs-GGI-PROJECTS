#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int arr[], int n) {
    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }

    return second;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int secondLargest = findSecondLargest(arr, n);

    if (secondLargest == INT_MIN) {
        cout << "There is no second largest element in the array." << endl;
    } else {
        cout << "The second largest element in the array is: " << secondLargest << endl;
    }

    return 0;
}
