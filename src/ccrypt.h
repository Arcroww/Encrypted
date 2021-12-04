#ifndef CCRYPT_H
#define CCRYPT_H

#include <iostream>
#include <cstring>

#include "sha256.h"
#include "sha512.h"

using namespace std;


class ccrypt
{
public:
    ccrypt();
    string CryptSha256(string word);
    string CryptSha512(string word);
};

#endif // CCRYPT_H
