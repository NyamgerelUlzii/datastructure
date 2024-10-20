#include <stdio.h>
#include <string.h>

void findSubstring(const char *str, const char *substring) {
    char *result = strstr(str, substring);

    if(result != NULL) {
        int position = result - str;
        return position;
    }
    else { 
        return -1;
    }
}

int main() {
    const char *text = "Hello, I'm Nyamgerel, a 4th-year Information Systems major at the National University of Mongolia. Alongside my studies, I work as a Project Manager at Fibo Cloud, where I oversee both private and public cloud projects. My responsibilities include project management, sales operations, and client relations, ensuring smooth project delivery and business growth."
    char searchWord[100];
    printf("Хайх утгаа оруулна уу: ");
    fgets(searchWord, sizeof(searchWord), stdin);

    searchWord[strcspn(searchWord, "\n")] = 0;

    int location = findSubstring(text, searchWord);

    if(location != -1) {
        printf("Таны хайж буй үг болох \"%s\" %d-д байна.", searchWord, location);
    }
    else {
        printf("Таны хайж буй үг болох \"%s\" энэ өгүүлбэрт байхгүй байна", searchWord);
    }

    return 0;
}