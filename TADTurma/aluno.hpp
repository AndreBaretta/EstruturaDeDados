#include <string>

using namespace std;

class Aluno {
  private:
   string ra;
   string nome;

  public:
   Aluno();

   Aluno(string _ra, string _nome);

   ~Aluno();

   string getRa();
   void setRa(string ra);

   void imprimir();
};
