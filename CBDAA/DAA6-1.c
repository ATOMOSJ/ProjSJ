#include <stdio.h>
int count =0;
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1,auxiliary, source, destination );
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1,source, destination, auxiliary );
    count++;
    
}

int main() {
    int numDisks;
    printf("enter the no. of disk\n");
    scanf("%d",&numDisks); 
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    printf("the no. of moves: %d\n",count);
    return 0;
}
