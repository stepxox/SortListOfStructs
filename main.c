#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char street[50];
} User;

void swap(User *a, User *b)
{
    User tmp;
    tmp  = *b;
    *b = *a;
    *a = tmp;
}

User sort(User users[], size_t length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (strcmp(users[j].name, users[j + 1].name) > 0) {
                swap(&users[j], &users[j + 1]);
            }
        }
    }
    return users[0];
}

int main(void) {
    User users[7] = {
            { name: "Stepan Magor", age: 12, street: "Negrice 32" },
            { name: "Stepan Kantor", age: 13, street: "Urbanova 37" },
            { name: "Marek Valasek", age: 10, street: "Negrice 32" },
            { name: "Dominik Humr", age: 15, street: "Brno" },
            { name: "Pavel Mrak", age: 13, street: "HaViZoV" },
            { name: "Jirka Novak", age: 42, street: "Zajicov" },
            { name: "Alfons Negr", age: 42, street: "Zajicov" },
    };

    User user = sort(users, 7);

    for (int i = 0; i < 6; i++) {
        User u = users[i];
        printf("%s %d %s\n", u.name, u.age, u.street);
    }

    return 0;
}
