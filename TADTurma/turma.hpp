#include "aluno.hpp"

class Turma {
   private:
      std::string codDisc;
      std::string codTurma;
      std::string semestre;
      Aluno** alunos;
      int numAlunos;
      int numVagas;

   public:
      Turma(std::string semestre, int numeroVagas);
      Turma(std::string codigoDisciplina, std::string codigoTurma, std::string semestre, int numeroVagas);
      ~Turma();
      void setCodDisc(std::string codigoDisciplina);
      void setCodTurma(std::string codigoTurma);
      std::string getCodDisc();
      std::string getCodTurma();
      bool matricularAluno(Aluno* Aluno);
      bool cancelarMatricula(std::string ra);
      void imprimirAlunos();
};

