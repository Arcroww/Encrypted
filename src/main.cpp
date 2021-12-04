#include <iostream>
#include <string>

#include "cdecrypt.h"
#include "ccrypt.h"

using namespace std;

int main() {

    void decrypt_choice();
    void crypt_choice();

    string group, crypt_format, decrypt_format, file;

    while(1) {

        bool exit = false;

        while(!exit) {

            system("clear");
            cout << "What do you want ? " << endl << endl;
            cout << "[1] Crypt (sha256/sha512)" << endl;
            cout << "[2] Decrypt - (with wordlist)(sha256/sha512)" << endl;
            cout << "[3] Exit" << endl;
            cout << endl << endl;
            cout << ">> ";
            cin >> group;

            if(group == "1" || group == "2")
                exit = true;

            if(group == "3")
                return 1;
        }

        switch (stoi(group)) {

            case 1:
                crypt_choice();
                break;

            case 2:
                decrypt_choice();
                break;

            default:
                break;

        }
    }
}

void crypt_choice() {

    bool exit = false;
    string crypt_format, word;

    while(!exit) {

        system("clear");
        cout << "What type of encryption do you want ?" << endl << endl;
        cout << "[1] Crypt - Sha256" << endl;
        cout << "[2] Crypt - Sha512" << endl;
        cout << "[3] Back to main" << endl;
        cout << endl << endl;
        cout << ">> ";
        cin >> crypt_format;

        if(crypt_format == "1" || crypt_format == "2")
            exit = true;

        if(crypt_format == "3") return;

    }


    if(crypt_format == "1") {

        system("clear");
        cout << "Enter the word you want to hash :" << endl;
        cout << ">> ";
        cin >> word;
        cout << endl;

        ccrypt crypt;
        cout << "The hash of \"" << word << "\" --> " << crypt.CryptSha256(word);

        cout << endl << endl;
        cout << "Press any key to continue...";

        cin.ignore();
        cin.get();
    }

    if(crypt_format == "2") {

        system("clear");
        cout << "Enter the word you want to hash :" << endl;
        cout << ">> ";
        cin >> word;
        cout << endl;

        ccrypt crypt;
        cout << "The hash of \"" << word << "\" --> " << crypt.CryptSha512(word);

        cout << endl << endl;
        cout << "Press any key to continue...";

        cin.ignore();
        cin.get();
    }

}

void decrypt_choice() {

        bool exit = false;
        string decrypt_format, file, user_sha;

        while(!exit) {

            system("clear");
            cout << "What type of encryption do you want ?" << endl << endl;
            cout << "[1] Decrypt - Sha256 (with wordlist)" << endl;
            cout << "[2] Decrypt - Sha512 (with wordlist)" << endl;
            cout << "[3] Back to main" << endl;
            cout << endl << endl;
            cout << ">> ";
            cin >> decrypt_format;

            if(decrypt_format == "1" || decrypt_format == "2")
                exit = true;

            if(decrypt_format == "3") return;

        }

        system("clear");
        cout << "Enter the password list file :" << endl;
        cout << ">> ";
        cin >> file;
        cout << endl;


        if(decrypt_format == "1") {

            CDecrypt decrypt;

            cout << "Enter the hash256 to decrypt :" << endl;
            cout << ">> ";
            cin >> user_sha;

            decrypt.DecryptSha256(user_sha, file);

        }

        if(decrypt_format == "2") {

            CDecrypt decrypt;

            cout << "Enter the hash512 to decrypt :" << endl;
            cout << ">> ";
            cin >> user_sha;

            decrypt.DecryptSha512(user_sha, file);

        }
}
