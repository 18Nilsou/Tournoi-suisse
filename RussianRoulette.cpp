/**
 *
 * @file    RussianRoulette.cpp
 *
 * @author  Melon - Saadi Nils - Ceccarelli Luca - Capelier Mathieu - Hugues Mélanie - Valls Marion - Vollaire Mathis
 *
 * @date    28/11/2021
 *
 * @brief   This game is a Russian Roulette Game.
 *          There are two players and the one to win is the one that doesn't get killed.
 *
 **/
#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include "input.h"

using namespace std;


unsigned roulette(const unsigned team1,const unsigned team2){


    //srand(1);


    unsigned whoIsPlayers1=0;
    unsigned whoIsPlayers2=1;

    unsigned player1;
    unsigned player2;
    int playerLive1=3;
    int playerLive2=3;

    // we create the gun
    vector<unsigned> gun;
    gun.resize(6);
    unsigned bullet;

    while (playerLive1>0 && playerLive2>0){

        player1=1;
        player2=1;

        // we reload the gun with one bullet
        bullet=rand()%6;
        for (unsigned i=0;i<6;++i){
            gun[i]=0;
        }
        gun[bullet]=1;


// if the place of the bullet%2 =0 the player one lose one's of his 3 lives
        if (bullet%2==0){
            player1=0;
        }
        else{
            player2=0;
        }

//
        if(player1==0){
            cout<<"le joueurs 1 est mort"<<endl;
            global_files::ofs<<"le joueurs 1 est mort"<<endl;
            playerLive1=playerLive1-1;
        }
        else{
            cout<<"le joueurs 2 est mort"<<endl;
            global_files::ofs<<"le joueurs 2 est mort"<<endl;
            playerLive2=playerLive2-1;
        }
    }


 // the players with a best score win
    if (playerLive1<playerLive2){
        cout<<"joueur 2 Win"<<endl;
        global_files::ofs<<"joueur 2 Win"<<endl;
        return whoIsPlayers2;
    }
    else{
        cout<<"joueur 1 Win"<<endl;
        global_files::ofs<<"joueur 1 Win"<<endl;
        return whoIsPlayers1;
    }

}


unsigned russianRoulette()
{

    return roulette(1,2);
}
