/**
 *
 * @file    HeadsOrTails.cpp
 *
 * @author  Melon - Saadi Nils - Ceccarelli Luca - Capelier Mathieu - Hugues Mélanie - Valls Marion - Vollaire Mathis
 *
 * @date    28/11/2021
 *
 * @brief   In this game two player have to guess if the machine will chose head or tail.
 *          If they guessed right,they got 1 point.
 *          The first one to get more points than the other wins.
 *
 **/

#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "input.h"
using namespace std;

//ifstream ifs("FichierOracleEntree.txt");
//string line;

unsigned headsortails (unsigned const & j1, unsigned const & j2){

    cout<<"c'est pile ou face si tu ne connais pas voici les regles"<<endl;
    global_files::ofs<<"c'est pile ou face si tu ne connais pas voici les regles"<<endl;
    cout<<"un joueurs X choisi une face d'une piece pile ou face"<<endl;
    global_files::ofs<<"un joueurs X choisi une face d'une piece pile ou face"<<endl;
    cout<<"on lance la piece et si la face qui est qu'on voit "<<endl<<"est la meme que joueurs X a choisit il gagne aussi non c'est le joureur Y gagne"<<endl;
    global_files::ofs<<"on lance la piece et si la face qui est qu'on voit "<<endl<<"est la meme que joueurs X a choisit il gagne aussi non c'est le joureur Y gagne"<<endl;

    // the score of the player
    unsigned scoreJ1=0;
    unsigned scoreJ2=0;

    // chose who play
    unsigned whoplay=0;

    // the number of the lap
    unsigned lap=0;

    // the var to store the head chose
    unsigned headJ1, headJ2, headpiece;
    // init rand
    //srand(1); //2


    while(lap!=7){

        // chose who plays and the player can chose the head
        if (whoplay%2==0){
            cout<<"joueur 1 pile(1) ou face(2):"<<endl;
            global_files::ofs<<"joueur 1 pile(1) ou face(2):"<<endl;
            //cin>>headJ1;
            headJ1=stoul(global_func::ask4UInput(""));
            if(headJ1==1){
                headJ2=2;
            }
            else{
                headJ2=1;
            }
        }
        else{
            cout<<"joueur 2 pile(1) ou face(2):"<<endl;
            global_files::ofs<<"joueur 2 pile(1) ou face(2):"<<endl;
            //cin >>headJ2;
            headJ2=stoul(global_func::ask4UInput(""));
            if(headJ2==1){
                headJ1=2;
            }
            else{
                headJ1=1;
            }
        }
        // chose the head of the piece
        headpiece=rand()%2+1;
        if (headpiece==1){
            if(headJ1==1){
                ++scoreJ1;
                cout<<"PILE 1 point pour le Joueur1 "<<endl<<"score joueur 1 ="<<scoreJ1<<endl<<"score joueur 2 ="<<scoreJ2<<endl<<endl;
                global_files::ofs<<"PILE 1 point pour le Joueur1 "<<endl<<"score joueur 1 ="<<scoreJ1<<endl<<"score joueur 2 ="<<scoreJ2<<endl<<endl;
            }
            else {
                ++scoreJ2;
                cout<<"PILE 1 point pour le Joueur2 "<<endl<<"score joueur 1 ="<<scoreJ1<<endl<<"score joueur 2 ="<<scoreJ2<<endl<<endl;
                global_files::ofs<<"PILE 1 point pour le Joueur2 "<<endl<<"score joueur 1 ="<<scoreJ1<<endl<<"score joueur 2 ="<<scoreJ2<<endl<<endl;
            }
        }
        else {
            if(headJ1==2){
                ++scoreJ1;
                cout<<"FACE 1 point pour le Joueur1 "<<endl<<"score joueur 1 ="<<scoreJ1<<endl<<"score joueur 2 ="<<scoreJ2<<endl<<endl;
                global_files::ofs<<"FACE 1 point pour le Joueur1 "<<endl<<"score joueur 1 ="<<scoreJ1<<endl<<"score joueur 2 ="<<scoreJ2<<endl<<endl;
            }
            else {
                ++scoreJ2;
                cout<<"FACE 1 point pour le Joueur2 "<<endl<<"score joueur 1 ="<<scoreJ1<<endl<<"score joueur 2 ="<<scoreJ2<<endl<<endl;
                global_files::ofs<<"FACE 1 point pour le Joueur2 "<<endl<<"score joueur 1 ="<<scoreJ1<<endl<<"score joueur 2 ="<<scoreJ2<<endl<<endl;
            }
        }
        ++whoplay;
        ++lap;


    }
    if(scoreJ1>scoreJ2){
        cout<<endl<<"---------------"<<endl<<"Joueur1 WIN"<<endl<<"---------------------"<<endl;
        global_files::ofs<<endl<<"---------------"<<endl<<"Joueur1 WIN"<<endl<<"---------------------"<<endl;
        return j1;
    }
    else{
        cout<<endl<<"---------------"<<endl<<"Joueur2 WIN"<<endl<<"---------------------"<<endl;
        global_files::ofs<<endl<<"---------------"<<endl<<"Joueur2 WIN"<<endl<<"---------------------"<<endl;
        return j2;
    }
}



unsigned headsOrTail()
{
    unsigned j1 =1;
    unsigned j2 =2;
    return headsortails(j1,j2);;
}
