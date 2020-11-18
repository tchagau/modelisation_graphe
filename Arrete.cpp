#include "Arrete.h"


using namespace std;


Arrete::Arrete(){
}

Arrete::Arrete(int nA, int vA){
  numA=nA;
  valA=vA;
  }

  Arrete::Arrete(Sommet<int> *sA, Sommet<int> *sB, int vA){

  somA=sA;
  somB=sB;
  valA=vA;

  }


  Arrete::Arrete(const Arrete& a){

  this->numA=a.numA;
  this->somA=a.somA;
  this->somB=a.somB;
  this->valA=a.valA;

  }



void Arrete::set_numA(int n){

  numA=n;

}

void Arrete::set_valA(int v){

  valA=v;

}

int Arrete::get_numA(){

  return numA;

}

int Arrete::get_valA(){

  return valA;

}




