#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void decimalToBinary(int);
void decimalToOctal(int);
void decimalToHexadecimal(int);
int binaryToDecimal(string);
int octalToDecimal(string);
int hexadecimalToDecimal(string);
int powerOf(int, int);
int stringLength(string);
void encryptMessage(string, int);
void decryptMessage(string, int);
void showMainMenu();

int main()
{
    int base, choice;
    string number, message;

    while (choice != 4)
    {
        system("cls");
        showMainMenu();
        cin >> choice;

        if (choice == 1)
        {
            Sleep(1000);
            cout << "\nProcessing, please wait...." << endl;
            Sleep(1000);
            system("cls");
            cout << "Enter the base of the number (2, 8, 10, 16) for conversion: ";
            while (true)
            {
                cin >> base;
                if (base == 2 || base == 8 || base == 10 || base == 16)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Base! Please choose from 2, 8, 10, 16...." << endl;
                }
            }
            cout << "Enter the number to convert: ";
            cin >> number;
            cout << "\n\nEquivalent Numbers:" << endl;

            if (base == 10)
            {
                int num = stoi(number);
                cout << "\nBinary: ";
                decimalToBinary(num);
                cout << "\nOctal: ";
                decimalToOctal(num);
                cout << "\nHexadecimal: ";
                decimalToHexadecimal(num);
            }
            else if (base == 2)
            {
                int result = binaryToDecimal(number);
                if (result != -1)
                {
                    cout << "\nDecimal: " << result;
                    cout << "\nOctal: ";
                    decimalToOctal(result);
                    cout << "\nHexadecimal: ";
                    decimalToHexadecimal(result);
                }
            }
            else if (base == 8)
            {
                int result = octalToDecimal(number);
                if (result != -1)
                {
                    cout << "\nDecimal: " << result;
                    cout << "\nBinary: ";
                    decimalToBinary(result);
                    cout << "\nHexadecimal: ";
                    decimalToHexadecimal(result);
                }
            }
            else if (base == 16)
            {
                int result = hexadecimalToDecimal(number);
                if (result != -1)
                {
                    cout << "\nDecimal: " << result;
                    cout << "\nBinary: ";
                    decimalToBinary(result);
                    cout << "\nOctal: ";
                    decimalToOctal(result);
                }
            }
            else
            {
                cout << "Invalid Base Entered!!";
            }
            Sleep(1000);
            cout << "\n-------------------------------------------------------------------" << endl;
            cout << "Press any key to go back...." << endl;
            getch();
        }
        else if (choice == 2)
        {
            Sleep(1000);
            cout << "Processing Please Wait..." << endl;
            Sleep(1000);
            system("cls");

            cout << "Enter the message to encrypt: ";
            cin.ignore();
            getline(cin, message);
            cout << "Select the base to encrypt the message into (2, 8, 10, 16): ";
            while (true)
            {
                cin >> base;
                if (base == 2 || base == 8 || base == 10 || base == 16)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Base! Please choose from 2, 8, 10, 16...." << endl;
                }
            }
            Sleep(1000);
            cout << "\n\nEncrypted message: ";
            encryptMessage(message, base);
            Sleep(1000);
            cout << "\n\n-------------------------------------------------------------------" << endl;
            cout << "Press any key to go back...." << endl;
            getch();
        }
        else if (choice == 3)
        {
            Sleep(1000);
            cout << "Processing Please Wait..." << endl;
            Sleep(1000);
            system("cls");

            cout << "Enter the encrypted message to decrypt: ";
            cin.ignore();
            getline(cin, message);
            cout << "Enter the base of the encrypted message (2, 8, 10, 16): ";
            while (true)
            {
                cin >> base;
                if (base == 2 || base == 8 || base == 10 || base == 16)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Base! Please choose from 2, 8, 10, 16...." << endl;
                }
            }
            Sleep(1000);
            cout << "\n\nDecrypted message: ";
            decryptMessage(message, base);
            Sleep(1000);
            cout << "\n-------------------------------------------------------------------" << endl;
            cout << "Press any key to go back...." << endl;
            getch();
        }
        else if (choice == 4)
        {
            Sleep(1000);
            cout << "\nExiting the program.....\n\n\n";
        }
        else
        {
            cout << "Invalid input, please choose from 1 to 4...." << endl;
        }
    }
}

void showMainMenu()
{
    cout << "Choose an option from the following:" << endl;
    cout << "\n1. Number Conversion." << endl;
    cout << "2. Encrypt Message." << endl;
    cout << "3. Decrypt Message." << endl;
    cout << "4. Exit" << endl;
    cout << "\n\nEnter an option...." << endl;
}

void decimalToBinary(int num)
{
    int index = 0;
    int digits[100];

    while (num != 0)
    {
        digits[index] = num % 2;
        num = num / 2;
        index++;
    }

    if (index == 0)
    {
        cout << "0"; 
    }
    for (int i = index - 1; i >= 0; i--)
    {
        cout << digits[i];
    }
}

void decimalToOctal(int num)
{
    int index = 0;
    int digits[100];

    while (num != 0)
    {
        digits[index] = num % 8;
        num = num / 8;
        index++;
    }
    if (index == 0)
    {
        cout << "0"; 
    }
    for (int i = index - 1; i >= 0; i--)
    {
        cout << digits[i];
    }
}

void decimalToHexadecimal(int num)
{
    int index = 0;
    char digits[100];

    while (num != 0)
    {
        int remainder = num % 16;

        if (remainder < 10)
            digits[index] = remainder + '0'; 
        else
            digits[index] = remainder - 10 + 'A'; 

        num = num / 16;
        index++;
    }
    if (index == 0)
    {
        cout << "0"; 
    }

    for (int i = index - 1; i >= 0; i--)
    {
        cout << digits[i];
    }
}

int binaryToDecimal(string number)
{
    int decimal = 0;
    int length = stringLength(number);

    for (int i = 0; i < length; i++)
    {
        if (number[i] != '1' && number[i] != '0')
        {
            cout << "Invalid input! The digit is not binary.";
            return -1;
        }
        else if (number[i] == '1')
        {
            decimal += powerOf(2, length - i - 1);   
        }
    }
    return decimal;
}

int octalToDecimal(string number)
{
    int decimal = 0;
    int length = stringLength(number);
    for (int i = 0; i < length; i++)
    {
        int digit = number[i] - '0';
        if (digit >= 0 && digit <= 7)
        {
            decimal += digit * powerOf(8, length - i - 1);
        }
        else
        {
            cout << "Invalid input! The digit is not octal." << endl;
            return -1;
        }
    }
    return decimal;
}

int hexadecimalToDecimal(string number)
{
    int decimal = 0;
    int length = stringLength(number);
    for (int i = 0; i < length; i++)
    {
        int digit;
        if (number[i] >= '0' && number[i] <= '9')
        {
            digit = number[i] - '0'; 
        }
        else if (number[i] >= 'A' && number[i] <= 'F')
        {
            digit = number[i] - 'A' + 10;   
        }
        else if (number[i] >= 'a' && number[i] <= 'f')
        {
            digit = number[i] - 'a' + 10;
        }
        else
        {
            cout << "Invalid input! The digit is not hexadecimal" << endl;
            return -1;
        }

        decimal += digit * powerOf(16, length - i - 1);
    }
    return decimal;
}

int powerOf(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int stringLength(string number)
{
    int count = 0;
    for (int i = 0; number[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void encryptMessage(string message, int base)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        int asciiValue = int(message[i]);
        if (base == 2)
        {
            decimalToBinary(asciiValue);
        }
        else if (base == 8)
        {
            decimalToOctal(asciiValue);
        }
        else if (base == 10)
        {
            cout << asciiValue;
        }
        else if (base == 16)
        {
            decimalToHexadecimal(asciiValue);
        }
        else
        {
            cout << "\nInvalid Base! Please select from 2, 8, or 16." << endl;
        }
        cout << " ";  
    }
}

void decryptMessage(string message, int base)
{
    string num = "";
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] == ' ') 
        {
            if (base == 2)
            {
                cout << char(binaryToDecimal(num));
            }
            else if (base == 8)
            {
                cout << char(octalToDecimal(num));
            }
            else if (base == 10)
            {
                cout << char(stoi(num)); 
            }
            else if (base == 16)
            {
                cout << char(hexadecimalToDecimal(num));
            }
            num = ""; 
        }
        else
        {
            num += message[i]; 
        }
    }

    if (base == 2)
    {
        cout << char(binaryToDecimal(num));
    }
    else if (base == 8)
    {
        cout << char(octalToDecimal(num));
    }
    else if (base == 10)
    {
        cout << char(stoi(num));
    }
    else if (base == 16)
    {
        cout << char(hexadecimalToDecimal(num));
    }
}
