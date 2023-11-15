#include<iostream>
#include<iomanip>
using namespace std;
void fill_array(int arr[], int size) {
    for (int k = 0; k < size; k++) {
        cout << "Please enter the " << k << " index value of your array" << endl;
        cin >> arr[k];
    }
}
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard
void print_array(int arr[], int size) {
    int additive = 0;
    for (int j = 0; j < size; j += 5) {
        for (int k = 0; k < 5 && (j + k) < size; k++) {
            cout << arr[j + k] << " ";
        }
        cout << endl;
        additive += 5;
    }
}

int linear_search(int arr[], int size, int key) {
    int index = 0;
    bool found = false;
    while (!found && (index < size)) {
        if (arr[index] == key) {
            found = true;
        }
        else {
            index++;
        }
    }
    if (found) {
        return index;
    }
    else {
        return -1;
    }
}
// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If
//the key cannot be found in arr, -1 is returned
void swapValues(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int indexOfSmallest(int arr[], int startIndex, int size) {
    int min = arr[startIndex];
    int indexOfMin = startIndex;
    for (int i = startIndex + 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            indexOfMin = i;
        }
    }
    return indexOfMin;
}
void select_sort(int arr[], int size) {
    int nextsmallIndex;
    for (int k = 0; k < size; k++) {
        nextsmallIndex = indexOfSmallest(arr, k, size);
        swapValues(arr[k], arr[nextsmallIndex]);
    }
}
// pre-condition: arr has given size

// post-condition: the elements in arr are rearranged from least to largest
void insert_sort(int arr[], int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void bubble_sort(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapValues(arr[j], arr[j + 1]);
            }
        }
    }
}
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void menu() {
    cout << "Menu" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Select Sort" << endl;
    cout << "3. Insert Sort" << endl;
    cout << "4. Bubble Sort" << endl;
    cout << "5. End Program" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    int a[9];
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            fill_array(a, 9);
            cout << "Enter the key you want to search: ";
            int key;
            cin >> key;
            int index = linear_search(a, 9, key);
            if (index == -1)
                cout << "The key " << key << " is not in array\n";
            else
                cout << "The key " << key << " is #" << (index + 1) << " element in array\n";
            break;
        }
        case 2:
        {
            fill_array(a, 9);
            select_sort(a, 9);
            cout << "After sort, the array is:\n";
            print_array(a, 9);
            break;
        }
        case 3:
        {
            fill_array(a, 9);
            insert_sort(a, 9);
            cout << "After sort, the array is:\n";
            print_array(a, 9);
            break;
        }
        case 4:
        {
            fill_array(a, 9);
            bubble_sort(a, 9);
            cout << "After sort, the array is:\n";
            print_array(a, 9);
            break;
        }
        case 5:
        {
            cout << "Thank you for using the array functions\n";
            break;
        }
        default:
        {
            cout << "Wrong choice. Please choose from menu: ";
            break;
        }
        }
    } while (choice != 5);
    return 0;
}