#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED


template <class T>
class Sommet{

 public:
  T numS;
  int degre;

 public:
    
  Sommet(T nS, int deg){
    numS=nS;
    degre=deg;
    
  }

  Sommet(T nS){
    numS=nS;
    
  }

  Sommet(const Sommet& s){

    this->numS= s.numS;
    this->degre= s.degre;
   

  }

    
  void set_numS(T n){

    numS=n;

  }
  int get_numS(){

    return numS;

  }

};




#endif // SOMMET_H_INCLUDED
