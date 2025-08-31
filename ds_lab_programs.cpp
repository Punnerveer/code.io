// ============================
// Experiment 1: Matrix Addition
// ============================
#include <iostream>
using namespace std;

// Function to input a matrix
void inputMatrix(int matrix[10][10], int rows, int cols) {
    cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to add two matrices
void addMatrices(int A[10][10], int B[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    int A[10][10], B[10][10], result[10][10];

    cout << "Enter number of rows and columns for matrices: ";
    cin >> rows >> cols;

    inputMatrix(A, rows, cols);
    inputMatrix(B, rows, cols);

    addMatrices(A, B, result, rows, cols);

    cout << "\nResultant Matrix after Addition:\n";
    displayMatrix(result, rows, cols);

    return 0;
}


// =====================================
// Experiment 2: Menu-driven Array Ops
// =====================================
#include <iostream>
using namespace std;

const int SIZE = 100;  // Max array size

// Display array elements
void displayArray(int arr[], int n) {
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insert element at a given position
void insertElement(int arr[], int &n, int elem, int pos) {
    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];  // Shift right
    }
    arr[pos] = elem;
    n++;
}

// Delete element at a given position
void deleteElement(int arr[], int &n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];  // Shift left
    }
    n--;
}

int main() {
    int arr[SIZE], n = 0, choice, elem, pos;

    cout << "Enter initial size of array: ";
    cin >> n;
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    do {
        cout << "\n--- Array Menu ---\n";
        cout << "1. Display Elements\n2. Insert Element\n3. Delete Element\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayArray(arr, n);
                break;
            case 2:
                cout << "Enter element and position: ";
                cin >> elem >> pos;
                insertElement(arr, n, elem, pos);
                break;
            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteElement(arr, n, pos);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
