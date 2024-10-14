#include <iostream>
#include <cstdlib>
using namespace std;

void printout_array(int**&, int, int);
void create_array(int**&, int, int, int, int, double);
void AMB(int**&, int**&, int**&, int, int, int);
int rin(int, int, double);

int main()
{
    int **A = nullptr;
    int **B = nullptr;
    int **C = nullptr;
    
    int p;  // number of rows for A
    int q;  // number of columns/rows for A/B
    int r;  // number of columns for B 
    int min;    // min number limit
    int max;    // max number limit
    double rs;  // random seed
    
    cout << "Please input (p,q,r,min,max,rs): ";
    cin >> p >> q >> r >> min >> max >> rs;

    srand(rs);
    create_array(A, p, q, min, max, rs);
    create_array(B, q, r, min, max, rs);
    AMB(C, A, B, p, q, r);
    cout << "A = " << endl; 
    printout_array(A, p, q);
    cout << "B = " << endl;
    printout_array(B, q, r);
    cout << "C = " << endl;
    printout_array(C, p, r);

    return 0;
}

void printout_array(int**& arr, int row, int column){
    for (int i =0; i<row; i++){
        for (int j=0; j<column; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------------------" << endl;
}

void create_array(int **&arr, int p, int q, int min, int max, double rs){
    arr = new int*[p];
    for (int i=0; i<p; i++){
        arr[i] = new int[q];
    }
    
    for (int i=0; i<p; i++){
        for (int j=0; j<q; j++){
            arr[i][j] = rin(min, max, rs);
        }
    }    
    
}

void AMB(int**& C, int**& A, int**& B, int p, int q, int r){
    C = new int*[p];
    for (int i=0; i<p; i++){
        C[i] = new int[r];
    }

    for (int i=0; i<r; i++){
        for (int j=0; j<p; j++){
            for (int k=0; k<q; k++){
                C[j][i] += A[j][k] * B[k][i];
            }
        }    
    }

}

int rin(int min, int max, double rs){
    return rand() % (max - min) + min;
}