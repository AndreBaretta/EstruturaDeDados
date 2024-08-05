#include <stdlib.h>
#include <iostream>
#include <string>
#include "aluno.hpp"

using namespace std;

Aluno::Aluno() {
   this->ra = "0";
   this->nome = "undefined";
};

Aluno::Aluno(string _ra, string _nome) {
   // ra = _ra;
   // nome = _nome;
   this->ra = _ra;
   this->nome = _nome;
};

Aluno::~Aluno() { cout << "Destruindo" << endl; };

string Aluno::getRa() { return this->ra; };

void Aluno::setRa(string ra) { this->ra = ra; };

void Aluno::imprimir() {
   cout << "(" << this->ra << ", " << this->nome << ")" << endl;
};


