/**
 *
 * @file    FindThePrice.cpp
 *
 * @author  Melon - Vollaire Mathis - Ceccarelli Luca - Capelier Mathieu - Hugues Mélanie - Saadi Nils - Valls Marion
 *
 * @date    28/11/2021
 *
 * @brief   This file contains the code of a game where you have to find a number beteween 0 and 256.
 *          Two players make suppositions and the first one to find the number wins.
 *          This program tells the player if the number given is too high or too low.
 *
 **/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <fstream>
#include "input.h"

using namespace std;

//ifstream ifs("FichierOracleEntree.txt");
//string line;

void play(const string & squad, unsigned & choice, const unsigned & guessTheNb, const unsigned & turnPlayer, bool & isWin)
{
    cout << squad << " saisissez un nombre (entre 1 et 256): ";
    global_files::ofs<< squad << " saisissez un nombre (entre 1 et 256): ";
    //cin >> choice;
    choice=stoul(global_func::ask4UInput(""));

    /***
     *
     * Condition if the player input a wrong caracter (no digit)
     *
     ***/
    if(cin.fail())
    {
        //If the input is not a number or digit, then an error message is displayed and its turn skips
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Saisie incorrecte, joueur suivant."<<endl;
        global_files::ofs<<"Saisie incorrecte, joueur suivant."<<endl;
        play(squad,choice,guessTheNb,turnPlayer, isWin);
    }

    /***
     *
     * Condition if the player find the secret number
     *
     ***/
    else
    {
        if(choice == guessTheNb){
            cout<<endl;
            global_files::ofs<<endl;
            cout<<"Bravo "<<squad<<" vous avez trouve le juste prix, soit "<<guessTheNb<<" ! GG !"<<endl;
            global_files::ofs<<"Bravo "<<squad<<" vous avez trouve le juste prix, soit "<<guessTheNb<<" ! GG !"<<endl;
            cout<<"Vous avez fini le jeu en " << turnPlayer + 1<< " tour(s) !" << endl;
            global_files::ofs<<"Vous avez fini le jeu en " << turnPlayer + 1<< " tour(s) !" << endl;
            // If the player find the secret number, we congratulate him and we display the number of rounds played
        }

        else if (choice == guessTheNb && choice == 69){
            cout << "Nice... c'est magnifique ! Ah oui, bien joue" <<squad;
            global_files::ofs<< "Nice... c'est magnifique ! Ah oui, bien joue" <<squad;
            cout << " vous avez trouve le juste prix étant "<<guessTheNb<<" ! GG !" <<endl;
            global_files::ofs<< " vous avez trouve le juste prix étant "<<guessTheNb<<" ! GG !" <<endl;
            cout<<"Vous avez fini le jeu en "<<turnPlayer + 1<<" tour(s) !"<<endl;
            global_files::ofs<<"Vous avez fini le jeu en "<<turnPlayer + 1<<" tour(s) !"<<endl;
        }

        /***
     *
     * Condition if the player find the secret number
     *
     ***/
    }
}

string bingo( string & squad1, string & squad2, unsigned & choice, unsigned & guessTheNb)
{
    /***
     *
     * Rules of the game
     *
     ***/

    cout << ("\t\t\tBienvenue au jeu du Juste Prix !") << endl;
    global_files::ofs<< ("\t\t\tBienvenue au jeu du Juste Prix !") << endl;
    cout << endl;
    global_files::ofs<< endl;
    cout << "Le but du jeu est simple, vous devez trouver le 'juste prix' étant compris entre 1 et 256 !";
    global_files::ofs<< "Le but du jeu est simple, vous devez trouver le 'juste prix' étant compris entre 1 et 256 !";
    cout << " Attention, si vous entrez un nombre supérieure à la limite (256) ";
    global_files::ofs<< " Attention, si vous entrez un nombre supérieure à la limite (256) ";
    cout << "ou un caractère votre tour sautera et ce sera au tour du joueur suivant !" << endl;
    global_files::ofs<< "ou un caractère votre tour sautera et ce sera au tour du joueur suivant !" << endl;
    cout<<endl;
    global_files::ofs<<endl;
    cout<<"Appuyez sur 'entrer' pour lancer le jeu";
    global_files::ofs<<"Appuyez sur 'entrer' pour lancer le jeu";
    //cin.ignore();
    //system("clear");
    cout << endl;
    global_files::ofs<< endl;

    /***
     *
     * Rules of the game
     *
     ***/

    /***
     *
     *  A condition is created to prevent the player(s) entering  the same nickname
     *
     ***/

    while(true)
    {
        // The player(s) are prompted to enter a team name

        cout<<"Equipe 1, choisissez un nom : ";
        global_files::ofs<<"Equipe 1, choisissez un nom : ";
        //cin>>squad1;
        squad1=global_func::ask4UInput("");
        cout<<"Equipe 2, choisissez un nom : ";
        global_files::ofs<<"Equipe 2, choisissez un nom : ";
        //cin>>squad2;
        squad1=global_func::ask4UInput("");

        // If the nicknames are identical then an error message is display and the players must change them

        if (squad1 == squad2){
            cout << "Erreur, vos nom doivent être differents !" << endl;
            global_files::ofs<< "Erreur, vos nom doivent être differents !" << endl;
        }
        else if (squad1 != squad2)
            break;
    }

    /***
     *
     *  A condition is created to prevent the player(s) entering  the same nickname
     *
     ***/

    cout<<endl;
    cout<<endl;

    unsigned turnPlayer = 0;
    // initialization of the player's turn

    /***
     *
     * We initialize the number of turns, the secret number and the choice of the players
     * We give the secret number a value between 256 and 1
     *
     ***/

    const unsigned MAX = 256, MIN = 1;
    srand(1);
    guessTheNb = (rand() % (MAX - MIN + 1)) + MIN;
    cout<<guessTheNb;
    global_files::ofs<<guessTheNb;

    /***
     *
     * We initialize the number of turns, the secret number and the choice of the players
     * We give the secret number a value between 256 and 1
     *
     ***/

    /***
     *
     * While loop since players don't find the secret number
     *
     ***/

    while (choice != guessTheNb)
    {

        bool isWin = false;
        if(turnPlayer%2 == 0)
            // We make sure that each player passes one after the other with a modulo
        {
            play(squad1,choice,guessTheNb,turnPlayer, isWin);
            if(isWin)
            {
                return squad1;
            }
        }

        else
        {
            play(squad2,choice,guessTheNb,turnPlayer, isWin);
            if(isWin)
            {
                return squad2;
            }        }

        ++turnPlayer;
        //        }

        /***
         *
         * Switch players
         *
         ***/

        /********************************************** Checking input **********************************************/

        if (choice < guessTheNb && choice == 69){
            cout << "Oooh !... petit cocain on est pas la pour rire quand meme..." << endl;
            global_files::ofs<< "Oooh !... petit cocain on est pas la pour rire quand meme..." << endl;
            cout << "c'est plus !" << endl;
            global_files::ofs<< "c'est plus !" << endl;
        }

        // A little humour doesn't hurt anyone... DOES IT !?

        else if(choice < guessTheNb){
            cout << "C'est plus !" << endl;
            global_files::ofs<< "C'est plus !" << endl;
        }

        // If the number chose if inferior than the secret one, we display "C'est plus"

        else if (choice > guessTheNb && choice == 69){
            cout << "Oooh !... petit cocain on est pas la pour rire quand meme..." << endl;
            global_files::ofs<< "Oooh !... petit cocain on est pas la pour rire quand meme..." << endl;
            cout << "c'est moins !" << endl;
            global_files::ofs<< "c'est moins !" << endl;
        }

        else if (choice > guessTheNb){
            cout << "C'est moins !" << endl;
            global_files::ofs<< "C'est moins !" << endl;
        }

        // If the number chose if superior than the secret one, we display "C'est moins"
    }
    return squad1;

    /***
     *
     * loop while players don't find the secret number
     *
     ***/

}

unsigned findThePrice()
{
    unsigned choice=0, guessTheNb=0;
    string squad1;
    string squad2;
    string jeuDuPlusOuMoins;
    jeuDuPlusOuMoins=bingo(squad1,squad2,choice,guessTheNb);
    if (jeuDuPlusOuMoins==squad1){
        return 0;
    }
    else{
        return 1;
    }
}
