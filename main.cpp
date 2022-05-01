/**
 *
 * @file    main.cpp
 *
 * @author  Melon - Ceccarelli Luca - Capelier Mathieu - Hugues Mélanie - Saadi Nils - Valls Marion - Vollaire Mathis
 *
 * @date    28/11/2021
 *
 * @brief   Master File
 *
 **/
//ordre inputs dans fichier
//l3 - l12 rockPaperScissors
//l13 - l47 connectFour
//l48 - l72 findThePrice
//l73 - l107 headsOrTail
//l108 - l189 ticTacToe
//l190 - 297 memory

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "connectFour.h"
#include "FindThePrice.h"
#include "HeadsOrTail.h"
#include "memory.h"
#include "rockPaperScissors.h"
#include "RussianRoulette.h"
#include "ticTacToe.h"
#include "input.h"

using namespace std;

struct squad {
    vector<string> playersNames;
    unsigned score;
};

unsigned checkPlayerInput(){
    /***
     * Function that asks a user input
     * If the user input its a character or a number inferior to 10, or uneven
     * asks the user a new input
     * If the user passes all the tests the value will be returned and assigned
    ***/
    unsigned userValue;

    while(true){
        //cin>>userValue;
        userValue=stol(global_func::ask4UInput());
        if(cin.fail())
        {
            cout<<"Vous avez saisi autre chose qu'un nombre, veuillez resseyer"<<endl;
            global_files::ofs<<"Vous avez saisi autre chose qu'un nombre, veuillez resseyer"<<endl;
            cout<<"Entrez la valeur "<<endl;
            global_files::ofs<<"Entrez la valeur "<<endl;
        }
        if(not(cin.fail()))
        {
            if (userValue>=10 && (userValue%2==0)){
                break;
            }
            else{
                cout<<"Vous avez saisi un nombre inferieur a 10 ou impair, veuillez resseyer"<<endl;
                global_files::ofs<<"Vous avez saisi un nombre inferieur a 10 ou impair, veuillez resseyer"<<endl;
            }
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return userValue;
}

vector<squad> squadsGenerator(){
    /***
     * Function to generate a list of struct containing the information of each squad
    ***/
    ifstream ifs("nom_etud.txt");
    string line;

    cout<<"Entrez un nombre d'equipes pair et superieur ou egale à 10"<<endl;
    global_files::ofs<<"Entrez un nombre d'equipes pair et superieur ou egale à 10"<<endl;
    unsigned squadsNb = checkPlayerInput();
    vector<squad> squads;

    for(unsigned i = 0; i<squadsNb; ++i){
        vector<string> squadPlayersNames;
        for(unsigned j = 0; j<120/squadsNb; ++j){
            string player="";
            for(unsigned z = 0; z<2; ++z){
                getline(ifs,line);
                player=player + line + ' ';
            }
            squadPlayersNames.push_back(player);
        }
        squads.push_back({squadPlayersNames, 0});
    }
    return squads;
}
vector<squad> pop(const vector<squad> & arrayToChange, const unsigned & indexToPop){
    /***
     * Function to pop a value from a index indicated
    ***/
    vector<squad> newArray;
    for(unsigned i = 0; i<arrayToChange.size(); ++i){
        if(i != indexToPop){
            newArray.push_back(arrayToChange[i]);
        }
    }
    return newArray;
}
vector<squad> sortArrayByScores(vector<squad> & squads){
    /***
     * Function to sort de vector of structs containing the squads
     * ranked by their points
    ***/
    vector<squad> sortedArray;
    bool flag = true;

    while(flag){
        unsigned maxIndex = 0;
        for(unsigned i = 0; i<squads.size();++i){
            if(squads[maxIndex].score<squads[i].score){
                maxIndex = i;
            }
        }
        sortedArray.push_back(squads[maxIndex]);
        squads=pop(squads,maxIndex);
        if(squads.size()==0)
            flag=false;
    }
    return sortedArray;
}

void displayTeamsAndScores(const vector<squad> & squads){
    /***
     * Function to print the list of teams
    ***/
    for(unsigned i = 0; i<squads.size();++i){
        cout<<"################################################"<<endl;
        global_files::ofs<<"################################################"<<endl;
        cout<<"L equipe a la place numero : "<<i+1<<" est forme par :"<<endl;
        global_files::ofs<<"L equipe a la place numero : "<<i+1<<" est forme par :"<<endl;
        for(unsigned j=0; j<squads[i].playersNames.size(); ++j){
            cout<<squads[i].playersNames[j]<<endl;
            global_files::ofs<<squads[i].playersNames[j]<<endl;
        }
        cout<<"avec un score de : "<<squads[i].score<<" points"<<endl;
        global_files::ofs<<"avec un score de : "<<squads[i].score<<" points"<<endl;
    }
}

unsigned game(const unsigned & roundNumber){
    switch (roundNumber) {
        case 1:
            return rockPaperScissors();
            break;
        case 2:
            return connectFour();
            break;
        case 3:
            return findThePrice();
            break;
        case 4:
            return headsOrTail();
            break;
        case 5:
            return russianRoulette();
            break;
        case 6:
            return ticTacToe ();
            break;
        case 7:
            return memory();
            break;
    }
}

vector<squad> tournament(vector<squad> & squads , const unsigned & roundNumber){
    /***
     * Function to begin the round on a selected game
     * where the teams will face each others on a 1vs1
     * the winner gets +1 on his score
    ***/
    for(unsigned i = 0; i<squads.size();i+=2){
        unsigned winner=game(roundNumber);
        if(winner == 0){
            squads[i].score+=1;
        }
        else{
            squads[i+1].score+=1;
        }
    }
    squads=sortArrayByScores(squads);
    return squads;
}

int main()
{
    global_files::ifs.open("FichierEntree");
    global_files::ofs.open("FichierSortie");

    srand(stoul(global_func::ask4UInput("seed : ")));

    vector<squad> squads= squadsGenerator();
    displayTeamsAndScores(squads);

    for(unsigned i = 1; i<8;++i){
        squads=tournament(squads,i);
        displayTeamsAndScores(squads);
    }

    cout<<endl<<"L equipe gagnante est forme par : "<<endl;
    global_files::ofs<<endl<<"L equipe gagnante est forme par : "<<endl;
    for(unsigned i=0; i<squads[0].playersNames.size(); ++i){
        cout<<squads[0].playersNames[i]<<endl;
        global_files::ofs<<squads[0].playersNames[i]<<endl;
    }
    cout<<"avec un score de "<<squads[0].score<<" poitns"<<endl;
    global_files::ofs<<"avec un score de "<<squads[0].score<<" poitns"<<endl;
    return 0;
    global_files::ifs.close();
    global_files::ofs.close();
}

