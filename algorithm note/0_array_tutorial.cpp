// #include <stdio.h>

// int main(){
//     int a[10] = {1, 2, 3, 4, 5, 6};
//     for (int i = 0; i < 10; i++){
//         printf("a[%d] = %d\n", i, a[i]);    
//     }
//     return 0;
    
// }

// #include <cstdio>

// int main(){
//     int a[10];
//     scanf("%d", &a[0]);
//     for (int i = 1; i < 10; i++){
//         a[i] = a[i - 1] * 2;
//     }
//     for (int i = 0; i < 10; i++){
//         printf("a[%d] = %d\n", i, a[i]);
//     }
//     return 0;
// }


// #include <cstdio>
// int main(){
//     int a[10] = {3, 1, 4, 5, 2, 7, 0, 8};
//     for (int i = 0; i < 7; i++){
//         for (int j = 0; j < 7 - i; j++){
//             if (a[j] > a[j+1]){
//                 int temp = a[j];
//                 a[j] = a[j+1];
//                 a[j+1] = temp;
//             }
//         }
//     }
//     for (int i = 0; i < 8; i++){
//         printf("a[%d] = %d\n", i, a[i]);    
//     }
//     return 0;
// }


// #include <cstdio>
// int main(){
//     int a[5][6];
//     double db[10][10];
//     char ch[256][256];
//     bool vis[1000][1000];
// }

// #include <stdio.h>
// int main(){
//     int a[5][6] = {{3, 1, 2}, {8, 4}, {}, {1, 2, 3, 4, 5}};
//     for (int i = 0; i < 5; i++){
//         for (int j = 0; j < 6; j++){
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");        
//     }
//     return 0;
// }


// #include <cstdio>
// int main(){
//     int a[3][3], b[3][3];
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             scanf("%d", &a[i][j]);
//         }
//     }
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             scanf("%d", &b[i][j]);
//         }
//     }
//     int c[3][3] = {};
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             c[i][j] = a[i][j] + b[i][j];
//         }
//     }
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             printf("%d ", c[i][j]);
//         }
//         printf("\n");
//     }
// }


// #include <cstdio>
// int arr[1000000000];
// int main(){
//     for (int i = 0; i < 1000000; i++){
//         arr[i] = i;
//     }
//     return 0;

// }


// #include <cstdio>
// int main(){
//     int a[3][3][3];
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             for (int k = 0; k < 3; k++){
//                 scanf("%d", &a[i][j][k]);
//                 a[i][j][k]++;
//             }   
//         } 
//     }
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             for (int k = 0; k < 3; k++){
//                 printf("%d\n", a[i][j][k]);
//             }   
//         }   
//     }
//     return 0;
// }



// #include <cstdio>
// #include <cstring>

// int main(){
//     int a[5] = {1, 2, 3, 4, 5};
//     printf("%d\n", sizeof(a));
//     memset(a, 0, sizeof(a));
//     for (int i = 0; i < 5; i++){
//         printf("a[%d]=%d ", i, a[i]);
//     }
//     printf("\n");
//     memset(a, -1, sizeof(a));
//     for (int i = 0; i < 5; i++){
//         printf("a[%d]=%d ", i, a[i]);
//     }
//     printf("\n");
//     return 0;
// }




// #include <stdio.h>
// int main(){
//     char str[15] = {'G', 'o', 'o', 'd', ' ', 's', 't', 'o', 'r', 'y', '!'};
//     for (int i = 0; i < 15; i++){
//         printf("%c", str[i]);
//     }
//     return 0;
    
// }


// #include <stdio.h>
// int main(){
//     char str[15] = "Good Story!";
//     for (int i = 0; i < 11; i++){
//         printf("%c", str[i]);
//     }
//     return 0;
// }


// #include <stdio.h>
// int main(){
//     char str[10];
//     scanf("%s", str);
//     printf("%s\n", str);
//     for (int i = 0; i < 10; i++){
//         scanf("%c", &str[i]);
//     }
//     printf("%s\n", str);
// }


// #include <stdio.h>
// int main(){
//     char str[5][5];
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             str[i][j] = getchar();
//         }
//         getchar();  // 这句是为了把输入中每行末尾的换行符吸收掉
//     }
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             putchar(str[i][j]);
//         }
//         putchar('\n');
//     }
//     return 0;
// }


#include <cstdio>

int main(){
    char str1[20];
    char str2[5][10];
    gets(str1);
    for (int i = 0; i < 3; i++){
        gets(str2[i]);
    }
    puts(str1);
    for (int i = 0; i < 3; i++){
        puts(str2[i]);
    }
    return 0;
}





