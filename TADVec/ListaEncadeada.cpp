#include "ListaEncadeada.hpp"
#include <iostream>

#define ERROR_INT 999999

ListaEncadeada::ListaEncadeada(){};

ListaEncadeada::~ListaEncadeada(){
   this->clear();
};

// Insere o elemento e na última posição
bool ListaEncadeada::push_back(int e){
   if(!this->size){
      No* novoNo  = new No(e);
      this->first = novoNo;
      this->last  = novoNo;
      size++;
      return true;
   }
   this->size++;
   No* novoNo = new No(e, this->last, nullptr);
   this->last->setProx(novoNo);
   this->last = novoNo;
   return true;
};

// Insere o elemento e na primeira posição
bool ListaEncadeada::push_front(int e){
   if(!this->size){
      No* novoNo  = new No(e);
      this->first = novoNo;
      this->last  = novoNo;
      size++;
      return true;
   }
   this->size++;
   No* novoNo  = new No(e, nullptr, this->first);
   this->first->setAnt(novoNo);
   this->first = novoNo;
   return true;
};

// Insere o elemento e na posição pos
bool ListaEncadeada::insert(int pos, int e){
   if(!validatePos(pos))
      return ERROR_INT;
   No* temp = this->first;
   for(int i = 1; i < pos; i++){
      temp = temp->getProx();
   }
   No* novoNo = new No(e, temp->getAnt(), temp);
   temp->getAnt()->setProx(novoNo);
   temp->setAnt(novoNo);
   this->size++;
   return true;
};

// Remove o último elemento
int ListaEncadeada::pop_back(){
   if(!validatePos())
      return ERROR_INT;
   No* temp   = this->last;
   int answer = temp->getDado();
   temp->getAnt()->setProx(nullptr);
   this->last = temp->getAnt();
   this->size--;
   delete temp;
   return answer;
};

// Remove o primeiro elemento
int ListaEncadeada::pop_front(){
   if(!validatePos())
      return ERROR_INT;
   No* temp     = this->first;
   int answer	= temp->getDado();
   temp->getProx()->setAnt(nullptr);
   this->first  = temp->getProx();
   this->size--;
   delete temp;
   return answer;
};

// Remove o elemento da posição pos e retorna o elemento removido
int ListaEncadeada::erase(int pos){
   if(!validatePos(pos))
      return ERROR_INT;
   No* temp = goTo(pos);
   temp->getAnt()->setProx(temp->getProx());
   temp->getProx()->setAnt(temp->getAnt());
   this->size--;
   int answer = temp->getDado();
   delete temp;
   return answer;
};

// Retorna o primeiro elemento
int ListaEncadeada::front(){
   if(!validatePos())
      return ERROR_INT;
   return this->first->getDado();
};

// Retorna o último elemento
int ListaEncadeada::back(){
   if(!validatePos())
      return ERROR_INT;
   return this->last->getDado();
};

// Retorna o elemento da posição pos
int ListaEncadeada::at(int pos){
   if(!validatePos(pos))
      return ERROR_INT;
   return goTo(pos)->getDado();
};

// Torna a lista vazia
void ListaEncadeada::clear(){
   if(!this->size)
      return;
   No* temp = this->last;
   for(int i = this->size-1; i > 0; i--){
      temp = temp->getAnt();
      delete temp->getProx();
   }
   delete temp;
   this->size  = 0;
   this->last  = nullptr;
   this->first = nullptr;
};

// Verifica se o vetor está vazio
bool ListaEncadeada::empty(){
   return !this->size;
};

// Devolve a quantidade de elementos
int ListaEncadeada::getSize(){
   return this->size;
};

// Substitui o elemento da posição pos pelo elemento e
bool ListaEncadeada::replace(int pos, int e){
   if(!validatePos(pos))
      return false;
   No* temp = goTo(pos);
   temp->setDado(e);
   return true;
};

// Imprime todos os elementos no formato [1,2,3]
void ListaEncadeada::print(){
   if(this->size == 0)
      return;
   No* temp = this->first;
   std::cout << "[";
   temp->print();
   std::cout << ", ";
   for(int i = 1; i < this->size; i++){
      temp = temp->getProx();
      temp->print();
      std::cout << ", ";
   }
   std::cout << "\b\b]" << "\n";
};

No* ListaEncadeada::goTo(int pos){
   No* temp;
   if(pos > this->size/2){
      temp = this->last;
      for(int i = this->size - 1; i > pos; i--)
         temp = temp->getAnt();
      return temp;
   }
   temp = this->first;
   for(int i = 1; i < pos; i++)
      temp = temp->getProx();
   return temp;
};

bool ListaEncadeada::validatePos(int pos){
   if(pos >= this->size)
      return false;
   if(pos < 0)
      return false;
   if(!this->size)
      return false;
   return true;
};

bool ListaEncadeada::validatePos(){
   if(!this->size)
      return false;
   return true;
};
