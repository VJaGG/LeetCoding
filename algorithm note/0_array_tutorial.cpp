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



// #include <cstdio>
// int main(){
//     char str1[20];
//     char str2[5][10];
//     gets(str1);
//     for (int i = 0; i < 3; i++){
//         gets(str2[i]);
//     }
//     puts(str1);
//     for (int i = 0; i < 3; i++){
//         puts(str2[i]);
//     }
//     return 0;
// }



// #include <cstdio>
// int main(){
//     char str[15];
//     for (int i = 0; i < 3; i++){
//         str[i] = getchar();        
//     }
//     puts(str);
//     return 0;
// }



// #include <string.h>  // 包含了许多用于字符数组的函数
// #include <stdio.h>
// int main(){
//     char str[10];
//     gets(str);
//     int len = strlen(str);
//     printf("%s\n", str);
//     printf("%d\n", len);
//     return 0;
// }



// #include <string.h>
// #include <stdio.h>
// int main(){
//     char str1[50], str2[50];
//     gets(str1);
//     gets(str2);
//     int cmp = strcmp(str1, str2);
//     if (cmp < 0){
//         printf("str1 < str2\n");
//     }else if (cmp > 0){
//         printf("str1 > str2\n");
//     }else{
//         printf("str1 == str2\n");
//     }
//     return 0;
// }



// #include <string.h>
// #include <stdio.h>
// int main(){
//     char str1[50], str2[50];
//     gets(str1);
//     puts(str1);
//     puts(str2);
//     gets(str2);
//     strcpy(str1, str2);
//     puts(str1);
//     return 0;
// }



// #include <stdio.h>
// #include <string.h>
// int main(){
//     char str1[50], str2[50];
//     gets(str1);
//     gets(str2);
//     puts(str1);
//     strcat(str1, str2);
//     puts(str1);
//     return 0;
// }


// sscanf写法的作用是把字符数组str中的内容以"%d"的格式写道n中
// 从左至右
// #include <stdio.h>
// int main(){
//     int n, m;
//     char str[100] = "123 12312";
//     sscanf(str, "%d %d", &n, &m);
//     printf("%d\n", n);
//     printf("%d\n", m);
//     return 0;
// }


// sprintf写法的作用是把n以"%d"的格式写到str字符数组中
// 从右至左

// #include <stdio.h>
// int main(){
//     int n = 233;
//     char str[100];
//     sprintf(str, "%d", n);
//     printf("%s\n", str);
//     return 0;
// }


// #include <stdio.h>
// int main(){
//     int n;
//     double db;
//     char str[100] = "2048:3.14,hello", str2[100];
//     sscanf(str, "%d:%lf,%s", &n, &db, str2);
//     printf("n=%d, db=%.2f, str2=%s\n", n, db, str2);
//     return 0;
// }


// #include <stdio.h>
// int main(){
//     int n = 12;
//     double db = 3.1415;
//     char str[100], str2[100] = "good";
//     sprintf(str, "%d:%.2f,%s", n, db, str2);
//     printf("str=%s\n", str);
//     return 0;
// }

#include <stdio.h>
int main(){
    int n;
    double db;
    char str[100];
    scanf("%d:%lf,%s", &n, &db, str);
    printf("%d\n", n);
    printf("%lf\n", db);
    printf("%s\n", str);
    return 0;
}
