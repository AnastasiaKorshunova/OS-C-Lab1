#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Структура для хранения данных о студенте
struct Student {
    char name[50];
    char surname[50];
    char birthdate[11];  // формат: "ДД.ММ.ГГГГ"
};

// Проверка корректности даты (формат "ДД.ММ.ГГГГ")
int is_valid_date(const char *date) {
    if (strlen(date) != 10 || date[2] != '.' || date[5] != '.')
        return 0;
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(date[i]))
            return 0;
    }
    return 1;
}

// Функция ввода данных о студенте
int input_student(struct Student *student) {
    printf("Введите имя: ");
    scanf("%49s", student->name);
    
    printf("Введите фамилию: ");
    scanf("%49s", student->surname);
    
    printf("Введите дату рождения (ДД.ММ.ГГГГ): ");
    scanf("%10s", student->birthdate);
    
    // Проверка правильности введенных данных
    if (!is_valid_date(student->birthdate)) {
        printf("Ошибка: Неверный формат даты рождения.\n");
        return 0;
    }
    return 1;
}

// Функция вывода карточки студента
void print_student(const struct Student *student) {
    printf("\n--- Карточка студента ---\n");
    printf("Имя: %s\n", student->name);
    printf("Фамилия: %s\n", student->surname);
    printf("Дата рождения: %s\n", student->birthdate);
    printf("-------------------------\n");
}

int main() {
    struct Student student;
    
    if (input_student(&student)) {
        print_student(&student);
    } else {
        printf("Пожалуйста, исправьте ошибки и попробуйте снова.\n");
    }
    
    return 0;
}
