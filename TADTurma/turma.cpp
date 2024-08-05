#include "turma.hpp"
#include <iostream>

Turma::Turma(std::string semestre, int numeroVagas){
   this->semestre = semestre;
   this->numVagas = numeroVagas;
   this->alunos   = new Aluno*[numVagas];
};

Turma::Turma(std::string codigoDisciplina, std::string codigoTurma, std::string semestre, int numeroVagas){
   this->codDisc  = codigoDisciplina;
   this->codTurma = codigoTurma;
   this->semestre = semestre;
   this->numVagas = numeroVagas;
   this->alunos   = new Aluno*[numVagas];
};

Turma::~Turma(){
   delete this->alunos;
   std::cout << "Destruindo turma" << std::endl;
};

void Turma::setCodDisc(std::string codigoDisciplina){
   this->codDisc  = codigoDisciplina;
};

void Turma::setCodTurma(std::string codigoTurma){
   this->codTurma = codigoTurma;
};

bool Turma::matricularAluno(Aluno* Aluno){
   if(this->numAlunos >= this->numVagas)
      return false;
   
   if(Aluno->getRa() == "0")
      return false;
   
   for(int i = 0; i < this->numAlunos; i++)
      if(Aluno == this->alunos[i] || Aluno->getRa() == this->alunos[i]->getRa())
         return false;

   this->alunos[this->numAlunos] = Aluno;
   this->numAlunos++;
   return true;
};

bool Turma::cancelarMatricula(std::string ra){
   bool flag = false;
   for(int i = 0; i < this->numAlunos; i++){
      if(flag){
         this->alunos[i] = this->alunos[i+1];
         continue;
      }
      if(ra == this->alunos[i]->getRa()){
         flag = true;
         this->alunos[i] = this->alunos[i+1];
      }
   }
   if(flag)
      this->numAlunos--;
   return flag;
}

void Turma::imprimirAlunos(){
   for(int i = 0; i < this->numAlunos; i++){
      this->alunos[i]->imprimir();
   }
};


