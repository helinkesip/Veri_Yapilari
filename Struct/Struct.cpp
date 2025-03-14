
#include <iostream>
struct Person {
    const char* name;
    int age;
};

int main()
{

    struct Person p1;

    p1.name = "Helin";
    p1.age = 20;

    printf("Person's name: %s\n ", p1.name);
    printf("Person's age: %d\n ", p1.age);



    return 0;
}
