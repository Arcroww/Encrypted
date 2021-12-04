#include "ccrypt.h"

ccrypt::ccrypt() {}


string ccrypt::CryptSha256(string word) {

    SHA256 sha256;
    return sha256(word);

}

string ccrypt::CryptSha512(string word) {

    SHA512 sha512;
    return sha512.hash(word);

}

