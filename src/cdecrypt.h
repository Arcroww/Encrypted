#ifndef CDECRYPT_H
#define CDECRYPT_H

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

#include "sha256.h"
#include "sha512.h"

using namespace std;

class CDecrypt {

public:
    CDecrypt();
    void DecryptSha256(string sha256, string wordlist);
    void DecryptSha512(string sha512, string wordlist);
};

#endif // CDECRYPT_H
