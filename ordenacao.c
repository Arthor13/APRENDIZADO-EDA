#include <stdio.h>
#include <stdlib.h>

void ctro (int* a, int* b){

            if (a < b){

                swap(&a,&b);
            }


}



void swap(int* a, int* b){


    int t = *a;
    *a = *b;
    *b = t; 

    }


void insermal(int arr[], int l, int r) {
   

    for (int i = l; i <= r; i ++){

        for (int j = r; j > l; j --){

             if (arr[j] < arr[j-1]){

                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;

            }


        }



    }
   

    }
        
    
    void inserbom(int arr[], int l, int r) {
   
   
        for (int i = r; i > l; i --){

            if (arr[i] < arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;

            }

        }

            for(int j = l +2;j <=r; j ++){
                int i = j;
                int temp = arr[i];

                while(temp < arr[i - 1] ){

                    arr[i] = arr[i - 1];
                    i -=1;

                }

                arr[i] = temp;

            }
        
    }

 
    void inserH(int arr[], int l, int r, int h) {
   
   
            for(int j = l + h ; j <=r; j ++){
                int i = j;
                int temp = arr[i];

                while(j >= l+h && temp < arr[i - h] ){

                    arr[i] = arr[i - h];
                    i -= h;

                }

                arr[i] = temp;

            }
        
    } 
    
    void shell(int arr[], int l, int r) {
   
        int i;

        for (i = 1; i < (r-l)/9; i = 3 *i +1);

        for ( ;i > 0 ; i/=3){

            inserH(arr,l,r,i);

        }


        
    } 

 int separa(int *arr, int l, int r){

        int j = arr[r], ax = l;

        for (int i = l;i < r; i ++){
            
            if (arr[i] < j){

                    swap(&arr[i], &arr[ax]);
                    ax +=1;
            }



        }
    swap (&arr[ax], &arr[r]);

    return ax;

    }

    void quick3(int *arr, int l, int r){



        if (r <= l){    

            return;}


        else{
            if (arr[(r-l/2)] < arr[r]){
              swap(&arr[(r-l/2)],&arr[r]);
            }
            if (arr[l]< arr[(r-l/2)]){

                swap(&arr[(r-l/2)],&arr[l]);
            }
            if (arr[r] < arr[(r-l/2)]){
                swap(&arr[r],&arr[(r-l/2)]);
            }
        
        
        int j = separa(arr,l,r);
        quick3(arr,l, j - 1);
        quick3(arr,j + 1, r);

        }

}
  


int main() {
    
    
   
    int n = 100,  vet[n];

    for (int i = 0; i < n; i ++ ){

        vet[i] = rand();

    }


    quick3(vet, 0, n);  

    for (int i = 0; i < n; i++) {
        printf("%d", vet[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }

    printf("\n");
    

    return 0;
}