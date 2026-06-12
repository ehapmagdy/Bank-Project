#pragma once
#include <string>
using namespace std;

class Validation {
public:

    static bool validateName(const std::string& name) {
        if (name.length() < 3 || name.length() > 20)
            return false;

        for (char c : name) {
            if (!((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                c == ' '))
                return false;
        }
        return true;
    }

    static bool validatePassword(const std::string& password) {
        if (password.length() < 8 || password.length() > 20)
            return false;

        for (char c : password) {
            if (c == ' ')
                return false;
        }
        return true;
    }
};