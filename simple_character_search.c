#include <stdio.h>
#include <string.h>

void findSubstring(const char *str, const char *substring) {
    //strstr(); нь string-с substring-г хайгаад олдвол тухайн substring-н хамгийн эхний тэмдэгтийн хаяг(result)-ийг буцаана. 
    char *result = strstr(str, substring);

    if(result != NULL) {
        //бидний хайж буй substring-ийн хаягнаас өгөгдсөн string-ийн хаягийг хасаж тухайн substring-ийн байрлал(position) буюу индексийг олж буцаана.
        int position = result - str;
        return position;
    }
    else { 
        //бидний хайж буй утга олдохгүй бол -1 -ийг буцаана. 
        return -1;
    }
}

int main() {
    //Тогтмол утгатай string-ийг оруулсан.
    const char *text = "Hello, I'm Nyamgerel, a 4th-year Information Systems major at the National University of Mongolia. Alongside my studies, I work as a Project Manager at Fibo Cloud, where I oversee both private and public cloud projects. My responsibilities include project management, sales operations, and client relations, ensuring smooth project delivery and business growth."
    //Гараас хайх утгыг оруулна. 
    char searchWord[100];
    printf("Хайх утгаа оруулна уу: ");
    fgets(searchWord, sizeof(searchWord), stdin);

    //Гараас авсан хайх утгыг шинэ мөрөнд шилжүүлэхгүйн тулд ашигласан. 
    searchWord[strcspn(searchWord, "\n")] = 0;

    //substring-ийн байршлыг олох функц.
    int location = findSubstring(text, searchWord);

    //Хэрэв -1 биш буюу хайж буй утга маань олдвол доорх текстийг хэвлэнэ.
    if(location != -1) {
        printf("Таны хайж буй үг болох \"%s\" %d-д байна.", searchWord, location);
    }
    //Эсрэг тохиолдолд доорх текстийг хэвлэнэ.
    else {
        printf("Таны хайж буй үг болох \"%s\" энэ өгүүлбэрт байхгүй байна", searchWord);
    }

    return 0;
}
