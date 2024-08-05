#include "Vetor.hpp"
#include "ListaEncadeada.hpp"

int main(int argc,char *argv[]){

   Vetor v1;
   ListaEncadeada* v2 = new ListaEncadeada();

   for(int i = 1; i < argc; i++){
      v1.push_back(atoi(argv[i]));
      v2->push_back(atoi(argv[i]));
   }
   printf("Vetor:\n");
   v1.print();
   printf("Lista Encadeada:\n");
   v2->print();
   v1.clear();
   v2->clear();
   delete v2;

   return 0;

}
