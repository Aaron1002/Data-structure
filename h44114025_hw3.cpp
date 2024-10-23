/*
   This code can be compiled and run ok.

   usage:
     ./h44114025_hw3.exe  
	   
   compile:
     gcc h44114025_hw3.cpp -o h44114025_hw3  
   
   pseudocode:
    void ins_sort(double* data, int n)
        for (int i=1; i<n; i++){
            double key = data[i];
            int j = i - 1;

            while (j>=0 && data[j] > key){
                data[j+1] = data[j];
                j--;
            }
            data[j+1] = key;
        }
    -----------------------------------    
    void mg_sort(double* arr, int start, int end)
        if (start < end){   
            int mid = floor( (start+end)/2 );   
            mg_sort(arr, start, mid); 
            mg_sort(arr, mid+1, end); 
            merge(arr, start, mid, end);    
        }
    ------------------------------------
    void merge(double* arr, int start, int mid, int end)
        
        int n1 = mid - start + 1;   
        int n2 = end - mid; 
        double *L = new double[n1+1]; 
        double *R = new double[n2+1]; 
        
        for (int i=0; i<n1; i++){   
            L[i] = arr[start+i];
        }
        for (int i=0; i<n2; i++){   
            R[i] = arr[mid+i+1];
        }
        
        L[n1] = INT_MAX;    
        R[n2] = INT_MAX;    


        int i = 0;
        int j = 0;
        for (int k=start; k<end+1; k++){   
            if (L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
        }
        delete[] L;
        delete[] R;
 
   coded by 王晏國, ID: H44114025, email: h44114025@gs.ncku.edu.tw
   date: 2024.10.23
*/

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

void printout_array(double*, int, int);
void duplicate_array(double*, double*, int, int);
void ins_sort(double*, int);
void is_ascending(double*, int);
void mg_sort(double*, int, int);
void merge(double*, int, int, int);

int main(){

    int n = 0;

    // input data
    cout << "Please input n: ";
    cin >> n;
    cout << endl;

    double* A = new double[n];
    double* B = new double[n];
    cout << "Please input " << n << " real numbers: ";
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    printout_array(A, 1, n);
    
    // copy A to B
    duplicate_array(A, B, 1, n);
    
    // sort A by insertion sort
    ins_sort(A, n);
    cout << "By insertion sort:" << endl; 
    printout_array(A, 1, n);
    is_ascending(A, n);

    // sort B by merge sort
    mg_sort(B, 0, n-1);
    cout << "By merge sort:" << endl; 
    printout_array(B, 1, n);
    is_ascending(B, n);

    delete[] A;
    delete[] B;

    return 0;
}

void printout_array(double* arr, int m, int n){

    for (int i=0; i < m; i++){
        for (int j=0; j<n; j++){
            if (j != n-1){
                cout << arr[i * m + j] << ", "; // like frame & page的移動 
            }
            else{
                cout << arr[i * m + j];
            }
        } 
        cout << endl;
    }
    
}    

void duplicate_array(double* A, double* B, int m, int n){
    
    for (int i=0; i<n; i++){
        B[i] = A[i];
    }

}

void ins_sort(double* data, int n){

    for (int i=1; i<n; i++){
        double key = data[i];
        int j = i - 1;

        while (j>=0 && data[j] > key){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }

}

void is_ascending(double* arr, int n){
    long flag = 1;   // ascending or not
    for (int i=1; i<n; i++){
        if (arr[i] >= arr[i-1])
            continue;
        else{
            flag = 0;
            break;
        }        
    }

    if (flag)
        cout << "Great!! It is in ascending order!!" << endl;
    else if (!flag)
        cout << "Warning!! the order is NOT ascending!!" << endl;
}

void mg_sort(double* arr, int start, int end){
    if (start < end){   // **when start==mid==end,recursion終止**
        int mid = floor( (start+end)/2 );   
        mg_sort(arr, start, mid); //前半sort
        mg_sort(arr, mid+1, end); //後半sort
        merge(arr, start, mid, end);    
    }
}
void merge(double* arr, int start, int mid, int end){
    
    int n1 = mid - start + 1;   //前半的元素數量
    int n2 = end - mid; //後半的元素數量
    double *L = new double[n1+1]; 
    double *R = new double[n2+1]; 
    
    for (int i=0; i<n1; i++){   //放前半元素
        L[i] = arr[start+i];
    }
    for (int i=0; i<n2; i++){   //放後半元素
        R[i] = arr[mid+i+1];
    }
    
    L[n1] = INT_MAX;    
    R[n2] = INT_MAX;    
/*  設終止條件給下面i,j的移動，當一陣列空時，INT_MAX(sentinel value)
    會讓該陣列不再被選取。其中，INT_MAX為int之最大值(可視為無限大)  */

    int i = 0;
    int j = 0;
    for (int k=start; k<end+1; k++){    //比較前半&後半個元素大小並放入原array
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }
    delete[] L;
    delete[] R;
    
}