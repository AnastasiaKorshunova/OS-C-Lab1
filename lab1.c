#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *name = NULL;
char *surname = NULL;
char *birthdate = NULL;
char *specialization = NULL;

int is_valid_date(char *date)
{
    if (date[2] != '.' || date[5] != '.')
        return 0;
    for (int i = 0; i < 10; i++)
    {
        if (i != 2 && i != 5 && !isdigit(date[i]))
            return 0;
    }
    return 1;
}

void input_student()
{
    size_t len;

    int is_valid = 0;

    while (!is_valid)
    {
        printf("Enter NAME (no more than 30 symbols): ");
        getline(&name, &len, stdin);

        if (strlen(name) < 30)
        {   
            is_valid = 1;
        }
        else
        {
            printf("Should be less than 30 symbols\n");
        }
    }

    is_valid = 0;
    while (!is_valid)
    {
        printf("Enter SURNAME (no more than 30 symbols): ");

        getline(&surname, &len, stdin);

        if (strlen(surname) < 30)
        {
            is_valid = 1;
        }
        else
        {
            printf("Should be less than 30 symbols\n");
        }
    }

    is_valid = 0;
    while (!is_valid)
    {
        printf("Enter DATE OF BIRTH (DD.MM.YYYY): ");
        getline(&birthdate, &len, stdin);

        if (is_valid_date(birthdate))
        {
            is_valid = 1;
        }
        else
        {
            printf("Wrong date format. Please try again.\n");
        }
    }

    is_valid = 0;
    while (!is_valid)
    {
        printf("Enter SPECIALISATION (no more than 20 symbols): ");
        getline(&specialization, &len, stdin);
        if (strlen(specialization) < 20)
        {
            is_valid = 1;
        }
        else
        {
            printf("Should be less than 20 symbols\n");
        }
    }
}

void print_student()
{
    printf("\n********************************************************\n");
    printf("\n----------------------- STIDENT-------------------------\n");
    printf("Name - %s", name);
    printf("Surname -  %s", surname);
    printf("Date of Birth -  %s", birthdate);
    printf("Specialisation -  %s", specialization);
    printf("----------------------------------------------------------\n");
}

int main()
{

    input_student();
    print_student();

    return 0;
}