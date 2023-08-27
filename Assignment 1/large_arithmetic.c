#include<stdio.h>

void addNumbers(char numberOne[], char numberTwo[]);
void printAddition(char numberOne[], char numberTwo[]);
int numberLength(char number[]);
void numberReverse(char number[], int numberLength);
void addNumbers(char numberOne[], char numberTwo[]);
void printProduct(char numberOne[], char numberTwo[]);
void printDivision(char numberOne[], long long int divisor);

const int g_MAX_LENGTH = 1024;

int main()
{
    char numberOne[g_MAX_LENGTH];
    char numberTwo[g_MAX_LENGTH];
    
    printf("Enter first number: ");
    scanf("%s", numberOne);

    printf("Enter second number: ");
    scanf("%s", numberTwo);

    long long int divisor = 0;

    int l1 = numberLength(numberTwo);
    int prod = 1;
    for(int i = l1 - 1; i >= 0; i--)
    {
        divisor += (numberTwo[i] - '0') * prod;
        prod *= 10; 
    }
    addNumbers(numberOne, numberTwo);
    printProduct(numberOne, numberTwo);
    printDivision(numberOne, divisor);
}

void printDivision(char numberOne[], long long int divisor)
{
    char result[g_MAX_LENGTH];
    int id = 0;
    int counter = 0;
    int temp = numberOne[id] - '0';
    int l1 = numberLength(numberOne);
    while (temp < divisor) temp = temp * 10 + (numberOne[++id] - '0');
    while (l1 > id)
    {
        result[counter] = (temp / divisor) + '0';
        counter++;
        temp = (temp % divisor) * 10 + numberOne[++id] - '0';
    }
    result[counter] = '\0';
    printf("Quotient: ");
    if (numberLength(result) == 0) printf("0\n");
    for(int i = 0; result[i] != '\0'; i++) printf("%c", result[i]);
    printf("\n");
}

void printProduct(char numberOne[], char numberTwo[])
{
    int result[2 * g_MAX_LENGTH];
    for(int i = 0; i < g_MAX_LENGTH; i++) result[i] = 0;
    int a[g_MAX_LENGTH]; int b[g_MAX_LENGTH];
    int l1 = numberLength(numberOne);
    int l2 = numberLength(numberTwo);
 
    int i, j, tmp;
    for (i = l1 - 1, j = 0; i >= 0; i--, j++)
    {
        a[j] = numberOne[i] - '0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        b[j] = numberTwo[i]-'0';
    }
    for(i = 0; i < l2; i++)
    {
        for(j = 0; j < l1; j++)
        {
            result[i+j] += b[i] * a[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        tmp = result[i]/10;
        result[i] = result[i] % 10;
        result[i+1] = result[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--)
    {
        if(result[i] > 0)
            break;
    }
    printf("Product : ");
    for(;i >= 0;i--)
    {
        printf("%d",result[i]);
    }
    printf("\n");
}

void addNumbers(char numberOne[], char numberTwo[])
{
    if (numberLength(numberOne) > numberLength(numberTwo)) printAddition(numberTwo, numberOne);
    else printAddition(numberOne, numberTwo);
}

void printAddition(char numberOne[], char numberTwo[])
{
    char result[g_MAX_LENGTH];
    int counter = 0;
    
    int l1 = numberLength(numberOne);
    int l2 = numberLength(numberTwo);

    numberReverse(numberOne, l1);
    numberReverse(numberTwo, l2);
    
    int carry = 0;
    for(int i = 0; i < l1; i++)
    {
        int sum = ((numberOne[i] - '0') + (numberTwo[i] - '0') + carry);
        result[counter] = (sum % 10) + '0'; 
        counter++;
        carry = sum / 10;
    }

    for (int i = l1; i < l2; i++)
    {
        int sum = ((numberTwo[i] - '0') + carry);
        result[counter] = (sum % 10) + '0';
        counter++;
        carry = sum / 10;
    }

    if(carry)
    {
        result[counter] = carry + '0';
        counter++;
    }

    result[counter] = '\0';
    

    numberReverse(result, numberLength(result));

    printf("Addition: ");

    for(int i = 0; result[i] != '\0'; i++)
    {
        printf("%c", result[i]);
    }
    printf("\n");
    numberReverse(numberOne, l1);
    numberReverse(numberTwo, l2);
}

int numberLength(char number[])
{
    int length;
    for(length = 0; number[length] != '\0'; length++);
    return length;
}

void numberReverse(char number[], int numberLength)
{
    for(int i = 0; i < numberLength / 2; i++)
    {
        char temp = number[i];
        number[i] = number[numberLength - i - 1];
        number[numberLength - i - 1] = temp;
    }
}
