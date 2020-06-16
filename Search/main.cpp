//
//  main.cpp
//  Search
//
//  Created by Leandro Smirnovff on 6/16/20.
//  Copyright © 2020 Leandro Igor Estrada Santos. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include <vector>
#include <stack>

#include <iostream>
 
using namespace std;
#define MAX  100
 
vector<int> ady[MAX];
 bool visitado[MAX];
 

void dfs(){
   int ini;
   printf("Nodo raiz: ");
   scanf( "%d" , &ini );
   
   memset(visitado, 0, sizeof(visitado));

   stack<int> S;
   S.push(ini);
   visitado[ini] = true;

   while(!S.empty()){
     int actual = S.top();
     S.pop();
     visitado[actual] = true;

     for( int i = 0 ; i < ady[ actual ].size() ; ++i ){
       
       if( !visitado[ ady[ actual ][ i ] ] ){
         printf("%d --> %d\n" , actual , ady[ actual ][ i ] );
         S.push( ady[ actual ][ i ] );
       }
     }

   }
  
 
 
}
 
int main() {
   int V , E , x , y;
   scanf( "%d %d" , &V , &E ); //Numero de vertices y numero de aristas
 
 
   for( int i = 1 ; i <= E ; ++i ){
       scanf( "%d %d" , &x , &y );  //Origen y destino
 
       ady[ x ].push_back( y );
       ady[ y ].push_back( x );
   }
 
   dfs();
 
}


