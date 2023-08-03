#include<iostream>
using namespace std;
int main(){
    int n,m,arr[20][20];
    cout<<"enter the row and the column size\n";
    cin>>n>>m;
    int**p=new int*[n];

    for(int i=0;i<n;i++){
        p[i]=new int[m];
        // for(int j=0;j<m;j++){
        //     scanf("%d",&arr[i][j]);
        // }
    }
     cout<<"enter the matrix element";
//     printf("the elements are:\n");
//      for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             printf("%d",arr[i][j]);
            
//           printf("\t");  
//         }

//         printf("\n");
//     }
//     return 0;
// }