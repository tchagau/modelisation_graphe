#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <limits.h>
#include "Arrete.h"
#include "Sommet.h"
#include<bits/stdc++.h>
using namespace std; 
#define INF 0x3f3f3f3f 


class Graphe{


 public:
  std::string nomG;
  std::vector<Sommet<int> > sommet;
  std::vector<Arrete> arrete;
  bool** adjMatrix;
  int** coutMatrix;
  std::list<int> *adj;
  std::list< pair<int, int> > *adjDjikstra;
     
  
 public:
  Graphe(std::string n);
  Graphe(const Graphe& g);
  ~Graphe();
  int findDegree(int s); // Détermine le dégrée d'un sommet quelconque
  void add_som(Sommet<int> *);
  int ordreG(); // Ordre du graphe
  void add_arrete(int u, int v, int cout);
  void toString(); // Affiche la matrice d’adjacence
  void tooString(); //Affiche la matrice des couts
  void DFS_Util(int v, bool visit[]);
  void connectComposant(); // Affichage de la liste des composantes connexes
  bool exist_chemin(int s, int d);// Déterminer s’il existe un chemin entre deux sommets
  int est_Eulerien(); // Déterminer si un graphe est eulérien
  void BFS(int s); // Algorithme de parcours en largeur
  void Dijkstra(int s); // Algorithme de Dijkstra
  void bell_ford(int s); // Algorithme de Bellman
  bool est_Connect(); // Fonction permettant de vérifier si tous les sommets non nuls sont connectés.
    
    


};


#endif // GRAPHE_H_INCLUDED
