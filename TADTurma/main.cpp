#include <iostream>
#include <string>
#include "turma.hpp"

int main() {
   Aluno* a1 = new Aluno("a111", "Joao");
   Aluno* a2 = new Aluno("a222", "Maria");
   Aluno* a3 = new Aluno("a333", "Jose");
   Turma* t1 = new Turma("123","321","2024-1",3);
   
   t1->matricularAluno(a1);
   t1->matricularAluno(a2);
   t1->matricularAluno(a3);

   t1->imprimirAlunos();

   if(t1->cancelarMatricula(a2->getRa()))
      std::cout << "Matricula Cancelada\n" << '\0';

   t1->imprimirAlunos();

   delete t1;

   delete a1;
   delete a2;
   delete a3;

   return 0;
}
