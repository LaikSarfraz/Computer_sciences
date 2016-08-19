/*
 Librairie de graphe :    http://lemon.cs.elte.hu/pub/doc/1.2.3/a00152.html 
   - commentaires en anglais
   -Source de la conception : Jean Noel Vittaut , professeur à Paris 8
*/
#include <mpi.h>
#include <queue>
#include <iostream>
#include <lemon/list_graph.h>
#include <lemon/full_graph.h>
#include <time.h> 
#include<vector>

using namespace lemon;
using namespace std;
#define NODES_NUMBER 500

FullGraph FG(NODES_NUMBER) ; // création du graphe 
FullGraph::EdgeMap<float> ph(FG); /* Phéromones sur chaque arc */
FullGraph::EdgeMap<float> distance_(FG); /* distance en KM sur chaque arc*/ //                                       [1]
FullGraph::EdgeMap<int> ant_passages(FG); /* nbr de passage de fourmis */



/* Struct  ANT ========================================================================================== */

struct Ant{
  vector<int>CityVisited; // 1 = visited, 0 = not visited
  int CurrentCity ; /*  0 to NODES_NUMBER */
  int First_pos; /* First Ant position, it will not change*/
};

void PrintEdges(FullGraph FG)
{

  for (FullGraph::NodeIt n(FG); n != INVALID; ++n)
    {
      cout <<" "<<endl<<endl;
      cout <<"--------------------------Pour le Le noeud  "<<FG.id(n)<<endl;
      for(FullGraph::IncEdgeIt e(FG,n); e!=INVALID; ++e)
	{
	  cout <<"--------------------------------------- "<<endl;
	  cout <<"La distance de l'edge "<<FG.id(e)<<" vaut "<<distance_[e]<<endl;
	  cout <<"Les pheromones de l'edge "<<FG.id(e)<<" valent "<<ph[e]<<endl;
	  cout <<"Le ratio donne "<<ph[e]/distance_[e]<<endl;
	}
    
    }
}

/* verfy that all city are visited or not */ 
int AllVisited(vector<int> CityVisited)
{
  for ( int i = 0; i < NODES_NUMBER ; i++)
    if ( CityVisited[i] == 0 )
      return 0;
  return 1;
}


/* This is the ant's progress, it will choose the next city until the ant visits all cities */
void WhatCityShouldIVisit(FullGraph g, Ant Ant)
{
  vector <pair <int,float> > EdgeIdAndPheromons;

  while( AllVisited(Ant.CityVisited) == 0 ) 
    {

      FullGraph::Node CurrentCity = g.nodeFromId(Ant.CurrentCity);/*I take the current ant position*/ 
      FullGraph::IncEdgeIt IncidentEdge(g,CurrentCity);
      FullGraph::Node OppositeNode = g.oppositeNode(CurrentCity,IncidentEdge);
      for(IncidentEdge  ; IncidentEdge != INVALID ; ++IncidentEdge ) /* Look the incident Edges of the Node */
	{	  
	  OppositeNode= g.oppositeNode(CurrentCity,IncidentEdge);
	  if (Ant.CityVisited[ g.id(OppositeNode)] == 0 ) /* if the opposite city is not visited */
	    {

	      EdgeIdAndPheromons.push_back(make_pair ( g.id(IncidentEdge) , ph[IncidentEdge]/distance_[IncidentEdge] ) ); /* put the Edge's ID and the Pheromons/Distance results in the vector */
	    }
	}
      float HigherPheromonsRatio = EdgeIdAndPheromons[0].second;// [2]
      int EdgeIdWithHigherPheromonsRatio = EdgeIdAndPheromons[0].first;
      for ( int i=1; i<EdgeIdAndPheromons.size(); i++)
	{
	  if (EdgeIdAndPheromons[i].second > HigherPheromonsRatio)
	    {
	      HigherPheromonsRatio = EdgeIdAndPheromons[i].second;
	      EdgeIdWithHigherPheromonsRatio = EdgeIdAndPheromons[i].first;
	    }
	}
      FullGraph::Node CityToGo = g.oppositeNode(CurrentCity,g.edgeFromId( EdgeIdWithHigherPheromonsRatio ));

      /* MAJ of the Ant Current Position / City Visited / Edge Pheromons / Ant Passage*/
      ant_passages[ g.edgeFromId(EdgeIdWithHigherPheromonsRatio)]++;
      Ant.CurrentCity=g.id(CityToGo);
      Ant.CityVisited[g.id(CityToGo)] = 1;

      ph[g.edgeFromId(EdgeIdWithHigherPheromonsRatio)] = ph[g.edgeFromId(EdgeIdWithHigherPheromonsRatio)]/ 2 +100*      ant_passages[ g.edgeFromId(EdgeIdWithHigherPheromonsRatio)];

      /* If the Ant visits all the cities, she have to go back home */
      if ( AllVisited(Ant.CityVisited) )
	{

	  CurrentCity = g.nodeFromId(Ant.CurrentCity);/*I take the current ant position*/ 
	  for(FullGraph::IncEdgeIt e(g,CurrentCity)  ; e != INVALID ; ++e ) /* Look the incident Edges of the final Node */
	    {	  
	      OppositeNode= g.oppositeNode(CurrentCity,e);
	      if ( g.id(OppositeNode) == Ant.First_pos ) /* if the opposite node is the ant's home */
		{
		  FullGraph::Node CityToGo = g.oppositeNode(CurrentCity,e);
		  /* MAJ of the Ant Current Position / City Visited / Edge Pheromons / Ant Passage*/
		  ant_passages[ e]++;
		  Ant.CurrentCity=g.id(CityToGo);
		  Ant.CityVisited[g.id(CityToGo)] = 1;
		  ph[e] = ph[e]/2 + 100* ant_passages[e];

		}
	    }

	    
	}


      EdgeIdAndPheromons.clear();

    } //end while

}




/* ========================================= MAIN ========================================================================================== */


  

int main(int argc, char** argv){





  srand (1);

  /*************** Creation of Ant's Colony, with The First position, the Current city , and a vector of All Cities ********************/

  vector<Ant>AntColony(NODES_NUMBER);
  for ( int i = 0; i <AntColony.size(); i++)
    {
      AntColony[i].CurrentCity=i;
      AntColony[i].First_pos=i;
      AntColony[i].CityVisited.resize(NODES_NUMBER,0);
      AntColony[i].CityVisited[i]=1;
    }

  /******************** Put random pheromons on all edge *********************/
  for (FullGraph::EdgeIt edge(FG); edge != INVALID; ++edge)
    {
      ph[edge]=  (rand() % (10 - 1 + 1)) + 1;
      distance_[edge]= rand() % 100;
      ant_passages[edge] = 0;
    }


  for (int j=0 ; j<10; j ++)
    for (int i=0 ; i<AntColony.size(); i ++){
	WhatCityShouldIVisit(FG,AntColony[i]);
    }






  //   PrintEdges(FG);


  



  return 0;
}














/*  NOTES DE BAS DE PROGRAMME
    [1] I named the map distance_ because distance is already in the library 
    [2] I put the Edge's ID and the Pheromons/Distance result int a vector of <pair> int,float. Then, I cover all the EdgeIdAndPheromons in order to find the Edge with higher pheromons's quantity
*/
