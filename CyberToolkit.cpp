#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations
void passwordChecker();
void encryptText();
void decryptText();
void passwordGenerator();
void loginSystem();
void portScannerSimulation();

//  PASSWORD CHECKER
void passwordChecker()
{
    string password;

    cout << "\nEnter Password: ";
    cin >> password;

    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;

    for(char c : password)
    {
        if(isupper(c))
            upper = true;

        else if(islower(c))
            lower = true;

        else if(isdigit(c))
            digit = true;

        else
            special = true;
    }

    int score = 0;

    if(password.length() >= 8)
        score++;

    if(upper)
        score++;

    if(lower)
        score++;

    if(digit)
        score++;

    if(special)
        score++;

    cout << "\nPassword Analysis:\n";

    if(score <= 2)
        cout << "Weak Password\n";

    else if(score <= 4)
        cout << "Medium Password\n";

    else
        cout << "Strong Password\n";
}

//  ENCRYPTION
void encryptText()
{
    string text;
    int shift;

    cin.ignore();

    cout << "\nEnter Text: ";
    getline(cin, text);

    cout << "Enter Shift Value: ";
    cin >> shift;

    for(int i = 0; i < text.length(); i++)
    {
        char c = text[i];

        if(isupper(c))
        {
            text[i] = ((c - 'A' + shift) % 26) + 'A';
        }

        else if(islower(c))
        {
            text[i] = ((c - 'a' + shift) % 26) + 'a';
        }
    }

    cout << "\nEncrypted Text: " << text << endl;
}

//  DECRYPTION
void decryptText()
{
    string text;
    int shift;

    cin.ignore();

    cout << "\nEnter Encrypted Text: ";
    getline(cin, text);

    cout << "Enter Shift Value: ";
    cin >> shift;

    for(int i = 0; i < text.length(); i++)
    {
        char c = text[i];

        if(isupper(c))
        {
            text[i] = ((c - 'A' - shift + 26) % 26) + 'A';
        }

        else if(islower(c))
        {
            text[i] = ((c - 'a' - shift + 26) % 26) + 'a';
        }
    }

    cout << "\nDecrypted Text: " << text << endl;
}

//  PASSWORD GENERATOR
void passwordGenerator()
{
    string chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!@#$%^&*";

    int length;

    cout << "\nEnter Password Length: ";
    cin >> length;

    string password = "";

    for(int i = 0; i < length; i++)
    {
        password += chars[rand() % chars.length()];
    }

    cout << "\nGenerated Password: " << password << endl;
}

// ---------------- LOGIN SYSTEM ----------------
void loginSystem()
{
    string username;
    string password;

    string correctUser = "admin";
    string correctPass = "Cyber123";

    cout << "\nUsername: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if(username == correctUser && password == correctPass)
    {
        cout << "\nLogin Successful\n";
    }

    else
    {
        cout << "\nAccess Denied\n";
    }
}

//  PORT SCANNER SIMULATION
void portScannerSimulation()
{
    int startPort, endPort;

    cout << "\nEnter Start Port: ";
    cin >> startPort;

    cout << "Enter End Port: ";
    cin >> endPort;

    cout << "\nScanning Ports...\n";

    for(int port = startPort; port <= endPort; port++)
    {
        if(rand() % 2 == 0)
        {
            cout << "Port " << port << " : OPEN\n";
        }

        else
        {
            cout << "Port " << port << " : CLOSED\n";
        }
    }
}

// MAIN FUNCTION
int main()
{
    srand(time(0));

    int choice;

    do
    {
        cout << "\n     CYBER SECURITY TOOLKIT \n";

        cout << "1. Password Strength Checker\n";
        cout << "2. Encrypt Text\n";
        cout << "3. Decrypt Text\n";
        cout << "4. Password Generator\n";
        cout << "5. Login System\n";
        cout << "6. Port Scanner Simulation\n";
        cout << "7. Exit\n";
cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                passwordChecker();
                break;

            case 2:
                encryptText();
                break;

            case 3:
                decryptText();
                break;

            case 4:
                passwordGenerator();
                break;

            case 5:
                loginSystem();
                break;

            case 6:
                portScannerSimulation();
                break;

            case 7:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice\n";
        }

    } while(choice != 7);

    return 0;
}