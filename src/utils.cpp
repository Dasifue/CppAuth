#include <string>
#include <openssl/evp.h>
#include <iomanip>
#include <sstream>

#include "../headers/utils.h"

std::string hashPassword(const std::string& password) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int lengthOfHash = 0;
    EVP_MD_CTX* context = EVP_MD_CTX_new();

    if(context != nullptr) {
        if(EVP_DigestInit_ex(context, EVP_sha256(), nullptr)) {
            if(EVP_DigestUpdate(context, password.c_str(), password.size())) {
                if(EVP_DigestFinal_ex(context, hash, &lengthOfHash)) {
                    std::stringstream ss;
                    for(unsigned int i = 0; i < lengthOfHash; ++i) {
                        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
                    }
                    EVP_MD_CTX_free(context);
                    return ss.str();
                }
            }
        }
        EVP_MD_CTX_free(context);
    }

    return "";
}