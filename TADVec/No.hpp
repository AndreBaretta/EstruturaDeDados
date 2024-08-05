

class No{
   public:
      No();
      No(int dado);
      No(int dado, No* ant);
      No(int dado, No* ant, No* prox);
      ~No();
      // Setters
      bool setDado(int dado);
      bool setAnt(No* ant);
      bool setProx(No* prox);

      // Getters
      int getDado();
      No* getAnt();
      No* getProx();

      void print();
   private:
      // Atributos
      int dado;
      No* ant;
      No* prox;
};
