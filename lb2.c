#include <stdio.h>

#define ROWS 2
#define COLS 3

int lsum(int m[ROWS][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == j) {
                sum += m[i][i]; 
        }
        }
       
    }
    return sum;
}

int main() {
   
    int m[ROWS][COLS] = {{1, 2, 3}, {4, 5, 7},{1,2,3}};
    
    printf("%d", lsum(m)); 
    return 0;
}
