//cpp
#include<string>
#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
#include "tic_tac_toe_data.h"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
using std::string;
using namespace std;

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{
    ofstream myfile("saved_data.txt");
    if (myfile.is_open()) {
        for (auto it = games.begin(); it != games.end(); ++it) {
            for (auto p: (*it)->get_pegs()) {
                myfile << p;
            }

            myfile << (*it)->get_winner();
            myfile << "\n";
        }

        myfile.close();
    }
    else cout << "Unable to open file.\n";
}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    vector<unique_ptr<TicTacToe>> games;
    string line;
    string winner;
    ifstream myfile ("saved_data.txt");

    if(myfile.is_open()) {
        while(getline(myfile, line)) {
            vector<string> pegs;
            int i, len = line.length();
            for (i=0;i<len-1;i++){
                string c = "";
                c += line[i];
                pegs.push_back(c);
            }
            winner = line[i];
            unique_ptr<TicTacToe> ttc;

            if (pegs.size() == 9) {
                ttc = make_unique<TicTacToe3>(pegs, winner);
            } else if (pegs.size() == 16) {
                ttc = make_unique<TicTacToe4>(pegs, winner);
            }
            games.push_back(move(ttc));
        }

        myfile.close();
    }
    else cout << "No saved file found.\n"; 

    return games;
}