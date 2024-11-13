/*
   This code can be compiled and run ok.
	   
   compile:
     g++ h44114025_hw4.cpp -o h44114025_hw4
   
   pseudocode:
   
    deleteMax(int*& old_A, int& remain_size){
        swap(old_A[0], old_A[remain_size-1]); 
        remain_size--;
        heapify(old_A, 0, remain_size);    
    }

    heapify(int*& old_A, int from, int remain_size){
        int parent = from; 
        int L_child = 2 * parent + 1;
        int R_child = 2 * parent + 2;
        int largest = parent;
        
        if (L_child < remain_size && old_A[L_child] > old_A[parent]){
            largest = L_child;
        }
        if (R_child < remain_size && old_A[R_child] > old_A[largest]){
            largest = R_child;
        }
        
        if (largest != parent){
            swap(old_A[largest], old_A[parent]);
            heapify(old_A, largest, remain_size);
        }
        
    }

    heapSort(int*& old_A, int row, int n){
        int remain_size = n;
        
        for (int i=n/2; i>=0; i--){
            heapify(old_A, i, n);  
        }
        
        for (int i=0; i<n; i++){
            deleteMax(old_A, remain_size);
        }

    }


    quickSort(int*& old_B, int low, int high){
        if (low < high){
            int mid = partition(old_B, low, high);
            quickSort(old_B, low, mid-1);
            quickSort(old_B, mid+1, high);
        }    
    }

    partition(int*& old_B, int low, int high){
        int pivot = old_B[high];
        int i = low - 1;

        for (int j=low; j<=(high-1); j++){
            if (old_B[j] <= pivot){
                i++;
                swap(old_B[i], old_B[j]);
            }
        }
        swap(old_B[i+1], old_B[high]);
        return (i+1);
    }
 
   coded by 王晏國, ID: H44114025, email: h44114025@gs.ncku.edu.com
   date: 2024.11.12
*/


#include <iostream>
using namespace std;

void create_array(int*&, int, int, int, int);
void printout_array(int*&, int, int);
void duplicate_array(int*&, int*&, int, int);

void deleteMax(int*&, int&);
void heapify(int*&, int, int);
void heapSort(int*&, int, int);

void quickSort(int*&, int, int);
int partition(int*&, int, int);

int main()
{
    int *A = nullptr;
    int *B = nullptr;
    
    int n = 0; 
    int min = 0;
    int max = 0;
    int rs = 0;

    printf("Please input [n, a_min, a_max, rs]: "); // a_min, a_max => range of the numbers
    cin >> n >> min >> max >> rs;
    
    /* Create array */
    srand(rs);    
    create_array(A, 1, n, min, max);
    printf("old A = ");
    printout_array(A, 1, n);
    
    /* Duplicate array*/
    create_array(B, 1, n, min, max);
    duplicate_array(A, B, 1, n);
    printf("old B = ");
    printout_array(B, 1, n);

    /* Heap Sort */
    heapSort(A, 1, n);
    printf("By heap sort:\n new A = ");
    printout_array(A, 1, n);
    
    /* Quick Sort */
    quickSort(B, 0, n-1);
    printf("By quick sort:\n new B = ");
    printout_array(B, 1, n);

    delete[] A;
    delete[] B;

    return 0;
}

void create_array(int*& arr, int p, int q, int min, int max){
    arr = new int[q];
    
    for (int i=0; i<q; i++){
        arr[i] = rand() % (max - min + 1) + min;
    }   
    
}

void printout_array(int*& arr, int row, int column){
    for (int i =0; i<column; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "---------------------------------------------" << endl;
}

void duplicate_array(int*& A, int*& B, int m, int n){
    for (int i=0; i<n; i++){
        B[i] = A[i];
    }
}


void deleteMax(int*& old_A, int& remain_size){
    swap(old_A[0], old_A[remain_size-1]); // swap the last and the first element
    remain_size--;
    heapify(old_A, 0, remain_size);    // adjust the heap
}

void heapify(int*& old_A, int from, int remain_size){
    int parent = from; // index
    int L_child = 2 * parent + 1;
    int R_child = 2 * parent + 2;
    int largest = parent;
    
    if (L_child < remain_size && old_A[L_child] > old_A[parent]){
        largest = L_child;
    }
    if (R_child < remain_size && old_A[R_child] > old_A[largest]){
        largest = R_child;
    }
    
    if (largest != parent){
        swap(old_A[largest], old_A[parent]);
        heapify(old_A, largest, remain_size);
    }
    
}

void heapSort(int*& old_A, int row, int n){
    int remain_size = n;
    
    // Build a heap
    for (int i=n/2; i>=0; i--){
        heapify(old_A, i, n);  
    }
    
    for (int i=0; i<n; i++){
        deleteMax(old_A, remain_size);
    }

}


void quickSort(int*& old_B, int low, int high){
    if (low < high){
        int mid = partition(old_B, low, high);
        quickSort(old_B, low, mid-1);
        quickSort(old_B, mid+1, high);
    }    
}

int partition(int*& old_B, int low, int high){
    int pivot = old_B[high];
    int i = low - 1;

    for (int j=low; j<=(high-1); j++){
        if (old_B[j] <= pivot){
            i++;
            swap(old_B[i], old_B[j]);
        }
    }
    swap(old_B[i+1], old_B[high]);
    return (i+1);
}