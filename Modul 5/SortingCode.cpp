#include <iostream>
using namespace std;

//Input Array
void inputArray(string arr[], int n) {
    cout << "Masukkan elemen array: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

//Tampil Array
void tampilArray(string arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Bubble Sort
void bubbleSort(string arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//Selection Sort
void selectionSort(string arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        swap(arr[i], arr[min]);
    }
}


//Insertion Sort
void insertionSort(string arr[], int n) {
    for(int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


//Function Merge
void merge(string arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {

        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(string arr[], int left, int right) {

    if(left < right) {

        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

//Merge Sort
void shellSort(string arr[], int n) {
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            string temp = arr[i];
            int j;

            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Function Partition
int partition(string arr[], int low, int high) {
    string pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(string arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int pilihan = 0;

    while(pilihan != 7) {

        cout << "\n--------------------------";
        cout << "\n|         SORTING        |\n";
        cout << "--------------------------\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "--------------------------\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        
        switch(pilihan) {
            
            case 1: {
                int n;
                cout << "Jumlah elemen: ";
                cin >> n;
                
                string arr[n];
                
                inputArray(arr, n);
                
                insertionSort(arr, n);
                
                cout << "Hasil Insertion Sort:\n";
                tampilArray(arr, n);
                break;
            }
            
            case 2: {
                int n;
                cout << "Jumlah elemen: ";
                cin >> n;
    
                string arr[n];
    
                inputArray(arr, n);
    
                mergeSort(arr, 0, n - 1);
    
                cout << "Hasil Merge Sort:\n";
                tampilArray(arr, n);
                break;
            }

            case 3: {
                int n;
                cout << "Jumlah elemen: ";
                cin >> n;

                string arr[n];

                inputArray(arr, n);

                shellSort(arr, n);

                cout << "Hasil Shell Sort:\n";
                tampilArray(arr, n);
                break;
            }

            case 4: {
                int n;
                cout << "Jumlah elemen: ";
                cin >> n;

                string arr[n];

                inputArray(arr, n);

                quickSort(arr, 0, n - 1);

                cout << "Hasil Quick Sort:\n";
                tampilArray(arr, n);
                break;
            }

            case 5: {
                int n;
                cout << "Jumlah elemen: ";
                cin >> n;

                string arr[n];

                inputArray(arr, n);

                bubbleSort(arr, n);

                cout << "Hasil Bubble Sort:\n";
                tampilArray(arr, n);
                break;
            }

            case 6: {
                int n;
                cout << "Jumlah elemen: ";
                cin >> n;

                string arr[n];

                inputArray(arr, n);

                selectionSort(arr, n);

                cout << "Hasil Selection Sort:\n";
                tampilArray(arr, n);
                break;
            }

            case 7:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}