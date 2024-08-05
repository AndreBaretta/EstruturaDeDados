#include "No.hpp"
#include <iostream>

No::No(){
   this->dado = 0;
   this->ant  = nullptr;
   this->prox = nullptr;
};

No::No(int dado){
   this->dado = dado;
   this->ant  = nullptr;
   this->prox = nullptr;
};

No::No(int dado, No* ant){
   this->dado = dado;
   this->ant  = ant;
   this->prox = nullptr;
};

No::No(int dado, No* ant, No* prox){
   this->dado = dado;
   this->ant  = ant;
   this->prox = prox;
};

No::~No(){};
// Setters

bool No::setDado(int dado){
   this->dado = dado;
   return true;
};

bool No::setAnt(No* ant){
   this->ant = ant;
   return true;
};

bool No::setProx(No* prox){
   this->prox = prox;
   return true;
};

// Getters

int No::getDado(){
   return this->dado;
};

No* No::getAnt(){
   return this->ant;
};

No* No::getProx(){
   return this->prox;
};

void No::print(){
   std::cout << this->dado;
}




