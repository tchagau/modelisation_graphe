#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED
#include <iostream>
#include <vector>
#include "Sommet.h"
//#include "Graphe.h"


class Arrete{

 
 public:
  int numA;
  int valA;
  Sommet<int> *somA;
  Sommet<int> *somB;
  std::vector<Sommet<int> > sommet_rel;
 public:
  Arrete();
  Arrete(Sommet<int> *sA, Sommet<int> *sB, int vA);
  Arrete(int nA, int vA);
  Arrete(const Arrete& a);

  void set_numA(int);
  int get_numA();
  void set_valA(int);
  int get_valA();
  void ajout_som(int, int, int);

};


#endif // ARRETE_H_INCLUDED
