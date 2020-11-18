#include <iostream>
#include "Graphe.h"
#include "Sommet.h"
#include "Arrete.h"


using namespace std;


    void entete(){ 
        cout<<endl;
        cout<<endl;
        cout<<"       ***************************************    "<<endl;
        cout<<"                                                  "<<endl;
        cout<<"                           GRAPHE NON ORIENTE     "<<endl;
        cout<<"                                                  "<<endl;
        cout<<"       ***************************************    "<<endl;
        cout<<endl;
        cout<<"                           MENU                   "<<endl;
        cout<<endl;
    }

    void menu(){
        cout<<endl;
        cout<<"      1 – Déterminer l’ordre du graphe"<<endl;
        cout<<"      2 – Le degré d’un sommet quelconque"<<endl;
        cout<<"      3 – Afficher la matrice d’adjacence"<<endl;
        cout<<"      4 – Afficher la matrice des cout"<<endl;
        cout<<"      5 – Afficher la liste des composantes connexes"<<endl;
        cout<<"      6 – Déterminer s’il existe un chemin entre deux sommets."<<endl;
        cout<<"      7 – Déterminer si un graphe est eulérien, semi-eulérien "<<endl;
        cout<<"      8 – Déterminer si un graphe est hamiltonien, semi-hamiltonien "<<endl;
        cout<<"      9 – Algorithme de Dijkstra"<<endl;
        cout<<"      10 – Algorithme de Bellman"<<endl;
        cout<<"      11 – Algorithme du parcours en largeur "<<endl;
        cout<<endl;
    }

void aff_solution(int path[]);

/* Une fonction utilitaire permettant de vérifier si le sommet v peut être ajouté à 
l'index 'pos' du cycle hamiltonien construit jusqu'à présent (stocké dans 'path[]') */
bool est_safe(int v, Graphe &G, int path[], int pos) 
{ 
  /* Vérifier si ce sommet est un sommet adjacent du sommet ajouté précédemment. */ 
  if (G.adjMatrix[ path[pos-1]][v] == 0) 
    return false; 
  
  for (int i = 0; i < pos; i++) 
    if (path[i] == v) 
      return false; 
  
  return true; 
}

/*Une fonction utilitaire récursive pour résoudre le problème du cycle hamiltonien */
bool hamilton_cycle_util(Graphe &G, int path[], int pos) 
{ 
  
  if (pos == 5) 
    { 
      
      if ( G.adjMatrix[ path[pos-1]][path[0]] == 1 )
	return true; 
      else
	return false; 
    } 
  
  
  for (int v = 1; v < 5; v++) 
    { 
      
      if (est_safe(v, G, path, pos)) 
        { 
	  path[pos] = v; 
  
	  
	  if (hamilton_cycle_util (G, path, pos+1) == true) 
	    return true; 
  
	 
	  path[pos] = -1; 
        } 
    } 
 
  return false; 
} 


bool hamilton_cycle(Graphe &G) 
{ 
  int *path = new int[5]; 
  for (int i = 0; i < 5; i++) 
    path[i] = -1; 
  
  /* le sommet 0 est mis comme premier sommet du chemin. S'il existe un cycle hamiltonien, 
  le chemin peut débuter à partir de n'importe quel point du cycle car le graphe est non orienté */
  path[0] = 0; 
  if ( hamilton_cycle_util(G, path, 1) == false ) 
    { 
      cout <<"Pas de Solution: Le graphe n'est pas Hamiltonien"<<endl; 
      return false; 
    } 
  
  aff_solution(path); 
  return true; 
} 

void aff_solution(int path[]) 
{ 
  cout <<"Solution Existe: Ceci est un cycle Hamiltonien \n"; 
  for (int i = 0; i < 5; i++) 
    cout << path[i]<<"\t";
		 
  cout <<path[0]<<endl;
	 
} 

int main()
{
  //Creattion du graphe
  Graphe G("undirected_graph");

  //Creation des differents instances de nos sommets
	Sommet<int> s0(0),s1(1),s2(2),s3(3),s4(4),s5(5),s6(6);
  int choix,numS,num1,num2,s;
	
  //Ajout des sommets au graphe
  G.sommet.push_back(s0);
  G.sommet.push_back(s1);
  G.sommet.push_back(s2);
  G.sommet.push_back(s3);
  G.sommet.push_back(s4);
  //G.sommet.push_back(s5);
  //G.sommet.push_back(s6);
  
  //Creation des liaisons entre les sommets
  G.add_arrete(s0.get_numS(),s1.get_numS(),2);
  G.add_arrete(s1.get_numS(),s2.get_numS(),1);
  G.add_arrete(s0.get_numS(),s3.get_numS(),5);
  G.add_arrete(s2.get_numS(),s4.get_numS(),3);
  G.add_arrete(s1.get_numS(),s3.get_numS(),2);
  G.add_arrete(s1.get_numS(),s4.get_numS(),7);
  G.add_arrete(s3.get_numS(),s4.get_numS(),9);

  entete();
  menu();
  cout << "Entrer votre choix \n";
  cin>>choix;
  switch(choix){
            case 1:
              cout <<"L'ordre du Graphe est "<<G.ordreG()<<endl;    
            break;
            case 2:
              cout << "Entrer le numéro du sommet \n";
              cin>>numS;
              cout <<"Le degré du sommet est "<<G.findDegree(numS)<<endl;  
            break;
            case 3:
              cout << "Affichage de la matrice d'adjacence \n";
              G.toString();
            break;
            case 4:
              cout << "Affichage de la matrice des couts \n";
              G.tooString();
            break;
            case 5:
              cout << "Affichage de la liste des composantes connexes \n"; 
              G.connectComposant();
            break;
            case 6:
              cout << "Entrer le numéro du premier sommet \n";
              cin>>num1;
              cout << "Entrer le numéro du second sommet \n";
              cin>>num2;
              if(G.exist_chemin(num1,num2)) 
                cout<< "Il existe un chemin entre " << num1 << " et " << num2<<endl; 
              else
                cout<< "Il n'existe pas de chemin entre " << num1 << " et " << num2<<endl;
            break;
            case 7:
              if (G.est_Eulerien() == 0){
                cout <<""<<endl;
                cout << "Le Graphe n'est pas Eulerien \n";
              }
              else if (G.est_Eulerien() == 1){
                cout <<""<<endl;
                cout << "Le Graphe est Semi-Eulerien \n";
              }
              else{
                cout <<""<<endl;
                cout << "Le Graphe est Eulerien \n";
              }
            break;
            case 8:
              hamilton_cycle(G);  
            break;
            case 9:
              
              cout << "Algorithme de Dijkstra \n";
              G.Dijkstra(0);
            break;
            case 10:
              
              cout << "Algorithme de Bellman \n";
              G.bell_ford(0);
            break;
            case 11:
              cout << "Entrer le numéro de la source \n";
              cin>>s;
              cout << "Parcours en Largeur \n";
              G.BFS(s);
            break;
        }
  

  return 0;
}
