#include "validation.hpp"
// TODO: Put implementations here
bool isspecial(char ch) {
    if (isalpha(ch)) {
		return false;
    }
	if (isdigit(ch)) {
		return false;
    }
	return true;
}

std::string getErrorMessage(const ErrorCode& errCode) {
    switch(errCode) {
        case Ok: 
            return "Ok";
        case PasswordNeedsAtLeastNineCharacters: 
            return "Password needs to have at least nine characters";
        case PasswordNeedsAtLeastOneNumber: 
            return "Password needs to have at least one number";
        case PasswordNeedsAtLeastOneSpecialCharacter: 
            return "Password needs to have at least one special character";
        case PasswordNeedsAtLeastOneUppercaseLetter: 
            return "Password needs to have at least one uppercase letter";
        case PasswordsDoNotMatch: 
            return "Passwords do not match";
        
        default: return "Wrong code";
    }
}

bool doPasswordsMatch(const std::string& password1, const std::string& password2) {
    if (password1 == password2) {
        return true;
    }
    return false;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < 9) {
        return PasswordNeedsAtLeastNineCharacters;
    }
    if (std::none_of(password.begin(), password.end(), isdigit)) {
        return PasswordNeedsAtLeastOneNumber;
    }
    if (std::none_of(password.begin(), password.end(), isspecial)) {
        return PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::none_of(password.begin(), password.end(), isupper)) {
        return PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return Ok;
    //return static_cast<ErrorCode>(rand() % 5);
}

ErrorCode checkPassword(const std::string& password1, const std::string& password2) {
    if (doPasswordsMatch(password1, password2)) {
        return checkPasswordRules(password1);
    }
    return PasswordsDoNotMatch;
}