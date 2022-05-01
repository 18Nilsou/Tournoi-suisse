/**
 *
 * @file    ticTacToe.cpp
 *
 * @author  Melon - Hugues Mélanie - Capelier Mathieu - Ceccarelli Luca - Saadi Nils  - Valls Marion - Vollaire Mathis
 *
 * @date    28/11/2021
 *
 * @brief   This game is a tic tac toe.
 * ²        Two players share one grid and the have to align 3 of their symbols.
 *
 **/
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include "input.h"

using namespace std;

//ifstream ifs("FichierOracleEntree.txt");
//string line;

void initialiseGrille(char grid[3][3]) // Creation of the grid to say how many case it is composed
{
     int i, j;
     for (i=0; i<3; ++i)
     {
         for (j=0; j<3; ++j)
         {
             grid[i][j] ='_';
         }
     }
}

void afficheGrille(char grid[3][3]) // Display the grid of the tic tac toe
{
   int i,j;
   for (i=0; i<3; ++i)
   {
         for (j=0; j<3; ++j)
         {
             cout<<grid[i][j]<<" ";
             global_files::ofs<<grid[i][j]<<" ";
         }
         cout<<endl;
   }
}

void metUnPionSurLaGrille(char grid[3][3], char & next_player)
{
     int row, column;
     if (next_player == 'O') // If the player is O so it display "player 1 c'est a vous !"
     {
         cout<< "Player 1 c'est a vous !"<<endl;
         global_files::ofs<< "Player 1 c'est a vous !"<<endl;
     }
     else //Else display "player 2 c'est à vous !"
     {
         cout<< "Player 2 c'est a vous !"<<endl;
         global_files::ofs<< "Player 2 c'est a vous !"<<endl;
     }
     cout<<"Quelle ligne ?"<<endl; // Ask the row of the grid to the player
     global_files::ofs<<"Quelle ligne ?"<<endl;
     //cin>>row;
     row=stoi(global_func::ask4UInput(""));
     if(cin.fail() || !(row >= 1 && row <= 3)) // if incorrect entry of the row
     {
         cout<<"Mauvaise saisie"<<endl;
         global_files::ofs<<"Mauvaise saisie"<<endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         metUnPionSurLaGrille(grid, next_player);
     }
     else
     {
         cout<<"Quelle colonne ?"<<endl; // Ask the column of the grid to the player
         global_files::ofs<<"Quelle colonne ?"<<endl;
         //cin>>column;
         column=stoi(global_func::ask4UInput(""));
         if(cin.fail() || !(row >= 1 && row <= 3)) // if incorrect entry of the column
         {
             cout<<"Mauvaise saisie"<<endl;
             global_files::ofs<<"Mauvaise saisie"<<endl;
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(),'\n');
             metUnPionSurLaGrille(grid, next_player);
         }
         grid[row-1][column-1]=next_player;
     }
}

void JoueurSuivant( char & player) // A player is O and the other is X
{
  if (player == 'O') // If the player is O so the next player is X
  {
      player = 'X';
  }
  else //else the player is O
  {
      player = 'O';
  }
}

int testeFinJeu(char T[3][3], char next_play) //Test if there is a winner or not and if there is a winner display it
{
    if ((T[1][1]==T[2][1])&&(T[0][1]==T[1][1])&&(T[1][1]==next_play))
    {
        return 1;
    }
    if ((T[1][2]==T[2][2])&&(T[0][2]==T[1][2])&&(T[1][2]==next_play))
    {
        return 1;
    }
    if ((T[1][0]==T[2][0])&&(T[0][0]==T[1][0])&&(T[1][0]==next_play))
    {
        return 1;
    }
    if ((T[1][1]==T[1][2])&&(T[1][0]==T[1][1])&&(T[1][1]==next_play))
    {
       return 1;
    }
    if ((T[2][1]==T[2][2])&&(T[2][0]==T[2][1])&&(T[2][1]==next_play))
    {
        return 1;
    }
    if ((T[0][1]==T[0][2])&&(T[0][0]==T[0][1])&&(T[0][1]==next_play))
    {
        return 1;
    }
    if ((T[1][1]==T[2][2])&&(T[0][0]==T[1][1])&&(T[1][1]==next_play))
    {
        return 1;
    }
    if ((T[0][1]==T[2][2])&&(T[1][0]==T[2][2])&&(T[2][2]==next_play))
    {
        return 1;
    }
    if ((T[0][2]==T[2][0])&&(T[0][2]==T[2][0])&&(T[2][0]==next_play))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

unsigned ticTacToe ()
{
    char grid[3][3];
    int b;
    char nextplayer;
    nextplayer = 'O';
    initialiseGrille(grid);
    b = testeFinJeu(grid, nextplayer);
    while(b==0)     //Verify if there is end of game with testeFinJeu
    {
        afficheGrille(grid);
        metUnPionSurLaGrille(grid, nextplayer);
        b = testeFinJeu(grid, nextplayer);
        JoueurSuivant(nextplayer);
    }
    afficheGrille(grid);
    if (nextplayer == 'X') // If the player is O so it display "player 1 a gagne !"
    {
        cout<< "Player 1 a gagne !"<<endl;
        global_files::ofs<< "Player 1 a gagne !"<<endl;
    }
    else //else display "player 2 a gagne !"
    {
        cout<< "Player 2 a gagne !"<<endl;
        global_files::ofs<< "Player 2 a gagne !"<<endl;
    }
    cout<<"Partie finie"<<endl;
    global_files::ofs<<"Partie finie"<<endl;
    return 0;
}
