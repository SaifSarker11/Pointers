#include<stdio.h>
int main(){
    int* ptr = (int[]){10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    //comment out all other statements except individual statement, to execute accordingly to the comments below.
    printf("%d\n", *ptr++); //10, *ptr = *(ptr + 1)
    printf("%d\n", *(ptr++)); //10, *ptr = *(ptr + 1)
    printf("%d\n", (*ptr)++); //10, *ptr = *(ptr + 1)
    printf("%d\n", ++*ptr); //11, *ptr = array[0] = 11
    printf("%d\n", ++(*ptr)); //11, *ptr = array[0] = 11
    printf("%d\n", *(++ptr)); //*ptr = *(ptr + 1) = 20
    printf("%d\n", *++ptr); // *ptr = *(ptr + 1) = 20
    return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
    int arr[] = {11, 13, 15, 17, 19};
    int* ptr = arr;
    int m = *(ptr + 2);
    int n = *(ptr + 4);
    printf("%s\n", m < n ? "True" : "False");
    printf("%s\n", m <= n ? "True" : "False");
    printf("%s\n", m == n ? "True" : "False");
    printf("%s\n", m > n ? "True" : "False");
    printf("%s\n", m >= n ? "True" : "False");
    printf("%s\n", m != n ? "True" : "False");
    return 0;
}

#include<stdio.h>
int main(){
    int* ptr = (int[]){1, 2, 3, 4, 5};
    for(int i = *ptr; i <= *(ptr + 4); i++){
        printf("%d", i);
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
int main(){
    char c = 'A';
    int i = 11;
    long l = 12345678;
    long long ll = 1234556789012345;
    float f = 3.14159;
    double lf = 3.1415926535;
    printf("\n%p", (void*)&c);
    printf("\n%p", (void*)&i);
    printf("\n%p", (void*)&l);
    printf("\n%p", (void*)&ll);
    printf("\n%p", (void*)&f);
    printf("\n%p", (void*)&lf);
    return 0;
}

#include<stdio.h>
int* max(int* arr, int n){
    int* ptr1 = arr;
    for(int i = 1; i < n; i++){
        if(arr[i] > *(ptr1)) ptr1 = &arr[i];
    }
    return ptr1;
}
int* min(int* arr, int n){
    int* ptr2 = arr;
    for(int i = 1; i < n; i++){
        if(arr[i] < *(ptr2)) ptr2 = &arr[i];
    }
    return ptr2;
}
int main(){
    int n;
    printf("Enter number of elements of the array:");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    int* max_val = max(array, n);
    int* min_val = min(array, n);
    printf("\nThe maximum value of the array is: %d", *max_val);
    printf("\nThe minimum value of the array is: %d", *min_val);
    return 0;
}

#include<stdio.h>
int* compute_gcd(int* a, int* b, int* gcd){
    int x = *a;
    int y = *b;
    if(x < 0) x = -x;
    if(y < 0) y = -y;
    while(y != 0){
        int temp = y;
        y = x % y;
        x = temp;
    }
    *gcd = x;
    return gcd;
}
int* compute_lcm(int* a, int* b, int* lcm){
    int x = *a;
    int y = *b;
    int abs_product = (x < 0 ? -x : x) * (y < 0 ? -y : y);
    if(x < 0) x = -x;
    if(y < 0) y = -y;
    while(y != 0){
        int temp = y;
        y = x % y;
        x = temp;
    }
    int hcf = x;
    if(hcf == 0) *lcm = 0;
    else *lcm = abs_product / hcf;
    return lcm;
}
int main(){
    int m, n;
    int gcd, lcm;
    int* gcd_ptr;
    int* lcm_ptr;
    printf("Enter the value of m & n: ");
    scanf("%d %d", &m, &n);
    gcd_ptr = compute_gcd(&m, &n, &gcd);
    lcm_ptr = compute_lcm(&m, &n, &lcm);
    printf("GCD of %d and %d is: %d\n", m, n, *gcd_ptr);
    printf("LCM of %d and %d is: %d\n", m, n, *lcm_ptr);   
    return 0;
}

#include<stdio.h>
double compute_mean(int* arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(arr + i);
    }
    return (double)sum / n;
}
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    double mean = compute_mean(array, n);
    printf("Mean: %0.2f\n", mean);
    return 0;
}

#include<stdio.h>
void bubble_sort(int* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
double find_median(int* arr, int n){
    if(n % 2 == 0){
        return (*(arr + (n/2 - 1)) + *(arr + (n/2))) / 2.0;
    }else{
        return *(arr + (n/2));
    }
}
int main(){
    int n;
    printf("The number of array elements: ");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    bubble_sort(&array[0], n);
    double median = find_median(array, n);
    printf("Median: %0.2f\n", median);
    return 0;
}

#include<stdio.h>
void bubble_sort(int* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
int calculate_mode(int* arr, int n){
    int current_count = 1;
    int max_count = 1;
    int mode = *(arr + 0);
    for(int i = 1; i < n; i++){
        if(*(arr + i) == *(arr + i - 1)) current_count++;
        else{
            if(current_count > max_count){
                max_count = current_count;
                mode = *(arr + i - 1);
            }
            current_count = 1;
        }
    }
    if(current_count > max_count){
        mode = *(arr + n - 1); 
    }
    return mode;
}
int main(){
    int n;
    printf("The number of array elements: ");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    bubble_sort(&array[0], n);  
    int mode = calculate_mode(array, n);
    printf("Mode: %d", mode);
    return 0;
}

#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main(){
    char message[200];
    char *left, *right;
    int ch;
    char* ptr = message;
    printf("Enter a message: ");
    while((ch = getchar()) != '\n' && ptr < message + 200){
        if(isalpha(ch)){
            *ptr++ = toupper(ch);
        }
    }
    left = message;
    right = ptr - 1;
    bool is_palindrome = true;
    while(left < right){
        if(*left != *right){
            is_palindrome = false;
            break;
        }
        left++;
        right--;
    }
    if(is_palindrome){
        printf("Palindrome.");
    }else{
        printf("Not a palindrome.");
    }
    return 0;
}

#include <stdio.h>
#include<ctype.h>
#include <stdbool.h>
int main(){
    char message[200];
    char *left, *right;
    int ch;
    char* ptr = message;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && ptr < message + 200){
        if (isalpha(ch)){
            if (ch >= 'a' && ch <= 'z') {
                *ptr++ = ch - 32; 
            }else{
                *ptr++ = ch;
            }
        }
    }
    left = message;
    right = ptr - 1;
    bool is_palindrome = true;
    while(left < right){
        if(*left != *right){
            is_palindrome = false;
            break;
        }
        left++;
        right--;
    }
    if(is_palindrome){
        printf("Palindrome.");
    }else{
        printf("Not a palindrome.");
    }
    return 0;
}

#include<stdio.h>
int main(){
    char message[200];
    int ch;
    char* ptr = message;
    printf("Enter a message: ");
    while((ch = getchar()) != '\n' && ptr < message + 200){
        *(ptr++) = (char)ch;
    }
    printf("Reversal is: ");
    while(ptr > message){
        putchar(*(--ptr));
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
void sorted(int num, int info[][2]){
    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - i - 1; j++){
            if(info[j][1] < info[j + 1][1]){
                for(int k = 0; k < 2; k++){
                    int temp = info[j][k];
                    info[j][k] = info[j + 1][k];
                    info[j + 1][k] = temp;
                }
            }
        }
    }
}
int main(){
    int number;
    printf("Enter the number of applicants: ");
    scanf("%d", &number);
    int info[number][2];
    printf("\nEnter information: ");
    for(int i = 0; i < number; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &info[i][j]);
        }
    }
    sorted(number, info);
    for(int i = 0; i < number; i++){
        printf("%d %d\n", info[i][0], info[i][1]);
    }
    return 0;
} 

#include<stdio.h>
#include<string.h>
int main(){
int n;
printf("Enter the size of array: ");
scanf("%d", &n);
int arr[n];
printf("\nEnter array elements: ");
for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
}
char string[100];
int shift;
printf("Enter shift amount: ");
scanf("%s %d", string, &shift);
int temp[n];
if(strcmp("right", string) == 0){
    for(int i = 0; i < n; i++){
        *(temp + (i + shift) % n) = *(arr + i);
    }
}
else if(strcmp("left", string) == 0){
    for(int i = 0; i < n; i++){
        *(temp + i) = *(arr + (i + shift) % n);
    }
}
for(int i = 0; i < n; i++){
    *(arr + i) = *(temp + i);
}
for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
}
return 0;
}