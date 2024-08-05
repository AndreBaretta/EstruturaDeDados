#include "Vetor.hpp"

Vetor::Vetor(){
   this->size = 0;
   this->capacity = 1;
   this->array = new int[capacity];
};

Vetor::~Vetor(){
   delete[] this->array;
};

bool Vetor::push_back(int e){
   this->array[this->size] = e;
   this->size++;
   this->gerenciaCapacidade();
   return true;
};

bool Vetor::push_front(int e){
   for(int i = this->size-1; i >= 0; i--){
      this->array[i+1] = this->array[i];
   }
   this->array[0] = e;
   this->size++;
   this->gerenciaCapacidade();
   return true;
};

bool Vetor::insert(int pos, int e){
   if(pos > this->size)
      return false;
   for(int i = this->size-1; i >= pos; i--){
      this->array[i+1] = this->array[i];
   }
   this->array[pos] = e;
   this->size++;
   this->gerenciaCapacidade();
   return true;
};

int Vetor::pop_back(){
   int temp = this->array[this->size-1];
   this->array[size-1] = 0;
   this->size--;
   this->gerenciaCapacidade();
   return temp;
};

int Vetor::pop_front(){
   int temp = this->array[0];
   for(int i = 0; i < this->size-1; i++){
      this->array[i] = this->array[i+1];
      this->array[i+1] = 0;
   }
   this->size--;
   this->gerenciaCapacidade();
   return temp;
};

int Vetor::erase(int pos){
   int temp = this->array[pos];
   for(int i = pos; i < this->size-1; i++){
      this->array[i] = this->array[i+1];
      this->array[i+1] = 0;
   }
   this->size--;
   this->gerenciaCapacidade();
   return temp;
};

int Vetor::front(){
   return this->array[0];
};

int Vetor::back(){
   return this->array[this->size-1];
};

int Vetor::at(int pos){
   if(pos > size)
      return 0;
   return this->array[pos];
};

void Vetor::clear(){
   for(int i = 0; i < this->size-1; i++){
      this->array[i] = 0;
   }
   this->size = 0;
   this->gerenciaCapacidade();
};

bool Vetor::empty(){
   for(int i = 0; i < this->size; i++){
      if(this->array[i] != 0)
         return false;
   }
   return true;
};

int Vetor::getSize(){
   return this->size;
};

bool Vetor::replace(int pos, int e){
   if(this->array[pos] == 0)
      return false;
   if(pos >= this->size)
      return false;
   this->array[pos] = e;
   return true;
};

void Vetor::print(){
   if(this->size == 0)
      return;
   std::cout << "[";
   for(int i = 0; i < this->size; i++){
      std::cout << this->array[i] << ", ";
   }
   std::cout << "\b\b]" << "\n";
};

void Vetor::gerenciaCapacidade(){
   int newCapacity = this->capacity;
   if(this->size == 0)
      newCapacity = 1;
   if(this->size < newCapacity/4)
      newCapacity /= 2;
   if(this->size == newCapacity)
      newCapacity *= 2;
   int *newArray = new int[newCapacity];
   for(int i = 0; i < size; i++){
      newArray[i] = this->array[i];
   }
   delete[] this->array;
   this->array = newArray;
   this->capacity = newCapacity;
};


