// Mergin two sorted arrays
#include <iostream>
using namespace std;


int *mergeTwoArray(int arr1[], int arr2[], int n_1, int n_2) {

    // A new array with combination of sizes of both array.
    int *arr = new int[n_1 + n_2];
    
    int i = 0; // Initial pointer pointing at first index of arr1;
    int j = 0; // Initial pointer pointing at first index of arr2;
    int k = 0; // Intitla pointer pointing at first index of arr;
    
    // Run while loop until one of its pointer reaches at end.
    
    while ((i < n_1) && (j < n_2)) {
        // compare the first one with second one. and place at kth index of newely created array whatever element is less.
        cout << "J " << j << endl;
        if(arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    
    while(i < n_1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
   
    while(j < n_2) {
        arr[k] = arr2[j]; 
        j++;
        k++;
    }
    
    // cout << arr[4];
    
    return arr;
}

int main() {

    int arr1[] = {2,4,5,6,6,7};
    int arr2[] = {1,3,9,10};
    
    int n_1 = sizeof(arr1) / sizeof(arr1[0]);
    int n_2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // cout << "N1 " << n_1 << "N2  " << n_2 << endl; 
    
    int *item = mergeTwoArray(arr1, arr2, n_1, n_2);
    
    cout << (n_1 + n_2)  << endl;
    
    for(int i = 0; i < (n_1 + n_2); i++) {
        cout << item[i] << endl;
    }
}
