#ifndef MODELS_H
#define MODELS_H
#include <string>

struct StudentA {
    char code[5];
    char name[11];
    char lastName[20];
    char career[15];
    int cycle;
    float monthlyPayment;
};

struct StudentB {
    std::string name;
    std::string lastName;
    std::string career;
    float monthlyPayment;
};

struct Register {
    std::string code;
    int cycle;
    float monthlyPayment;
    std::string comments;
};
#endif //MODELS_H
