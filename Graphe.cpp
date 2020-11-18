#include "Graphe.h"
#include "Sommet.h"
#include "Arrete.h"
#define V 100

using namespace std;

Graphe::Graphe(string n){

  nomG=n;
  coutMatrix = new int*[V];
  adj = new list<int>[V];
  adjDjikstra = new list< pair<int, int> >[V];
  adjMatrix = new bool*[V];
  for (int i = 0; i < V; i++) {
    coutMatrix[i] = new int[V];
    adjMatrix[i] = new bool[V];
    for (int j = 0; j < V; j++){
      adjMatrix[i][j] = false;
      coutMatrix[i][j] = 0;
    }
  }
 ;

}

Graphe::~Graphe(){
  delete[] adj;
}

Graphe::Graphe(const Graphe& g){

  this->nomG= g.nomG;

}



void Graphe::add_arrete(int u, int v, int cout){
  adjMatrix[u][v]=true;
  adjMatrix[v][u]=true;
  coutMatrix[u][v]=cout;
  coutMatrix[v][u]=cout;
  adj[u].push_back(v); 
  adj[v].push_back(u);
  adjDjikstra[u].push_back(make_pair(v, cout)); 
  //adjDjikstra[v].push_back(make_pair(u, cout)); 
            
}

// Affiche la matrice d’adjacence
void Graphe::toString() {
  for (int i = 0; i < this->sommet.size(); i++) {
    cout << i << " : ";
    for (int j = 0; j < this->sommet.size(); j++)
      cout <<  adjMatrix[i][j]<< " ";
    cout << "\n";
  }

}

// Affichage de la matrice des couts
void Graphe::tooString() {
  for (int i = 0; i < this->sommet.size(); i++) {
    cout << i << " : ";
    for (int j = 0; j < this->sommet.size(); j++)
      cout <<  coutMatrix[i][j]<< " ";
    cout << "\n";
  }

}


// Afficher la liste des composantes connexes 
void Graphe::connectComposant() 
{ 
  // Marquer tous les sommets comme non visités 
  bool *visit = new bool[this->sommet.size()]; 
  for(int v = 0; v < this->sommet.size(); v++) 
    visit[v] = false; 
  
  for (int v=0; v<this->sommet.size(); v++) 
    { 
      if (visit[v] == false) 
        { 
	  // affiche tous les sommets accessibles de v 
	  DFS_Util(v, visit); 
  
	  cout << "\n"; 
        } 
    } 
}

void Graphe::DFS_Util(int v, bool visit[]) 
{ 
  // Marquez le nœud actuel comme visité et imprimez-le 
  visit[v] = true; 
  cout << v << " "; 
  
  // Reproduire pour tous les sommets adjacents à ce sommet 
  list<int>::iterator i; 
  for(i = adj[v].begin(); i != adj[v].end(); ++i) 
    if(!visit[*i]) 
      DFS_Util(*i, visit); 
} 

// Déterminer s’il existe un chemin entre deux sommets
bool Graphe::exist_chemin(int s, int d)
{ 
  
  if (s == d) 
    return true; 
  
  // Marquer tous les sommets comme non-visité
  bool *visit = new bool[this->sommet.size()]; 
  for (int i = 0; i < this->sommet.size(); i++) 
    visit[i] = false; 
  
  // Créer une file d'attente pour BFS 
  list<int> queue; 
  
  // Marque le nœud actuel comme visité et le met en file d'attente 
  visit[s] = true; 
  queue.push_back(s); 
  
  // Utilisé pour obtenir tous les sommets adjacents d'un sommet
  list<int>::iterator i; 
  
  while (!queue.empty()) 
    { 
      // Supprimer un sommet de la file d'attente et l'imprimer
      s = queue.front(); 
      queue.pop_front(); 
  
      
      for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
	  // Si ce noeud adjacent est le noeud de destination, retournez true
	  if (*i == d) 
	    return true; 
  
	  // Sinon, continuez à faire BFS
	  if (!visit[*i]) 
            { 
	      visit[*i] = true; 
	      queue.push_back(*i); 
            } 
        } 
    } 
      
  // Si BFS est complet sans visite de d
  return false; 
} 

// Algorithme de parcours en largeur
void Graphe::BFS(int s) 
{ 
  // Marquer tous les sommets comme non-visité 
  bool *visit = new bool[this->sommet.size()]; 
  for(int i = 0; i < this->sommet.size(); i++) 
    visit[i] = false; 
  
  // Créer une file d'attente pour BFS 
  list<int> queue; 
  
  // Marque le nœud actuel comme visité et le met en file d'attente 
  visit[s] = true; 
  queue.push_back(s); 
   
  list<int>::iterator i; 
  
  while(!queue.empty()) 
    { 
      // Supprimer un sommet de la file d'attente et l'imprimer 
      s = queue.front(); 
      cout << s << " "; 
      queue.pop_front(); 
  
      //Obtient tous les sommets adjacents du sommet supprimé. 
      //Si une visite adjacente n'a pas été visitée, 
      //marquez-la visite et mettez-la en file d'attente. 
      for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
	  if (!visit[*i]) 
            { 
	      visit[*i] = true; 
	      queue.push_back(*i); 
            } 
        } 
    } 
  cout<<""<<endl;
} 

// Fonction permettant de vérifier si tous les sommets non nuls sont connectés.
bool Graphe::est_Connect()
{
  // Marquer tous les sommets comme non-visité
  bool visit[this->sommet.size()];
  int i;
  for (i = 0; i < this->sommet.size(); i++)
    visit[i] = false;

  // Trouver un sommet avec un degré différent de zéro
  for (i = 0; i < this->sommet.size(); i++)
    if (adj[i].size() != 0)
      break;
  // S'il n'y a pas d'arêtes dans le graphe, retourne true
  if (i == this->sommet.size())
    return true;
  // Démarrer le DFS à partir d'un sommet avec un degré différent de zéro

  DFS_Util(i, visit);
  // Vérifiez si tous les sommets non nuls sont visités
  for (i = 0; i < this->sommet.size(); i++)
    if (visit[i] == false && adj[i].size() > 0)
      return false;

  return true;
}

// Déterminer si un graphe est eulérien
int Graphe::est_Eulerien()
{
  // Vérifier si tous les sommets non nuls sont connectés
  if (est_Connect() == false)        
    return 0;
  //Compter les sommets avec un degré impair
  int odd = 0;
  for (int i = 0; i < this->sommet.size(); i++)
    if (adj[i].size() & 1)
      odd++;
      // Si le nombre est supérieur à 2, le graphe n'est pas eulérien
      if (odd > 2)

      	return 0;

      // Si odd est 2, alors semi-eulérien.
      // Si odd est 0, alors eulérien
      return (odd) ? 1 : 2;

}

// Algorithme de Dijkstra
void Graphe::Dijkstra(int src) 
{ 
  // Créer un ensemble pour stocker les sommets en cours de pré-traitement 
  set< pair<int, int> > setds; 
  
  // Créer un vector pour les distances et initialiser toutes les distances à l'infini (INF)
  vector<int> dist(this->sommet.size(), INF); 
  
  // Insérez la source elle-même dans Set et initialisez sa distance à 0. 
  setds.insert(make_pair(0, src)); 
  dist[src] = 0; 
  
  /*En boucle jusqu'à ce que toutes les distances les plus courtes soient finalisées, 
  les paramètres deviendront vides */
  while (!setds.empty()) 
    { 
      
      //Le premier sommet de l'ensemble est le sommet de distance minimale, extrayez-le de l'ensemble. 
      pair<int, int> tmp = *(setds.begin()); 
      setds.erase(setds.begin()); 
   
      int u = tmp.second; 
   
      list< pair<int, int> >::iterator i; 
      for (i = adjDjikstra[u].begin(); i != adjDjikstra[u].end(); ++i) 
        { 
	   
	  int v = (*i).first; 
	  int weight = (*i).second; 
   
	  if (dist[v] > dist[u] + weight) 
            { 
	      
	      if (dist[v] != INF) 
		      setds.erase(setds.find(make_pair(dist[v], v))); 
   
	      dist[v] = dist[u] + weight; 
	      setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
   
  cout<< "Sommet   Distance de la Source \n"; 
  for (int i = 0; i < this->sommet.size(); ++i) 
    cout<< i <<"\t\t" <<dist[i]<<"\n";
     
} 


// Algorithme de Bellman
void Graphe::bell_ford(int src)
{
  int dist[this->sommet.size()];
  for (int i = 0; i < this->sommet.size(); i++)
    dist[i] = INT_MAX;
  dist[src] = 0;
  for (int u = 0; u < this->sommet.size(); u++)
    {
      list< pair<int, int> >::iterator i;
      if (dist[u] != INT_MAX)
        {
	  for (i = adjDjikstra[u].begin(); i != adjDjikstra[u].end(); ++i){
	    int v = (*i).first; 
	    int weight = (*i).second;
	    if (dist[v] > dist[u] + weight)
	      {
		      dist[v] = dist[u] + weight;
	      }
	  }
        }
    }
  cout<<"Sommet   Distance"<<endl;
  for(int i=0;i<this->sommet.size();i++)
    {
      cout<<i<<"\t\t"<<dist[i]<<"\t\t";
      cout<<endl;
    }
}

// Donne l'ordre d'un graphe
int Graphe::ordreG(){

  return this->sommet.size();

}


// Trouve le dégré d'un sommet quelconque
int Graphe::findDegree(int s) 
{     
  int degre=0;        
  for (int i=0; i<this->sommet.size(); i++)      
   
    if (adjMatrix[s][i] == 1)  
      
      degre++;             
      
  
  return degre;          
} 

 






    
