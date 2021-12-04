#include "cdecrypt.h"

CDecrypt::CDecrypt() {}


void CDecrypt::DecryptSha256(string user_sha256, string wordlist) {

    system("clear");
    cout << "Starting... " << endl;

    sleep(2);

    fstream passwordlist;
    passwordlist.open(wordlist.c_str());

    if (passwordlist.is_open()){
        string word;

        while(passwordlist >> word) {

            SHA256 sha256;
            string mot = sha256(word);

            cout << "Compare: " << user_sha256 << " to: " << mot << " // word tested: " << word << "\n";

            if(mot == user_sha256) {
                cout << endl;
                cout << "#################################" << endl;
                cout << "Password found : " << word << endl;
                cout << "#################################" << endl;
                cout << endl;
                exit(1);
            }
        }

        cout << "No match ..." << endl;

        passwordlist.close();

        exit(1);

    } else
        cout << "Failed to open file!" << endl;
        exit(1);

}

void CDecrypt::DecryptSha512(string user_sha512, string wordlist) {


    system("clear");
    cout << "Starting... " << endl;

    sleep(2);

    fstream passwordlist;
    passwordlist.open(wordlist.c_str());

    if (passwordlist.is_open()){
        string word;

        while(passwordlist >> word) {

            SHA512 sha512;
            string mot = sha512.hash(word);

            cout << "Compare: " << user_sha512 << " to: " << mot << " // word tested: " << word << "\n";

            if(mot == user_sha512) {
                cout << endl;
                cout << "#################################" << endl;
                cout << "Password found : " << word << endl;
                cout << "#################################" << endl;
                cout << endl;
                exit(1);
            }
        }

        cout << "No match ..." << endl;

        passwordlist.close();

        exit(1);

    } else
        cout << "Failed to open file!" << endl;
        exit(1);

}
