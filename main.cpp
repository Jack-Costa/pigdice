#include <iostream>
#include <cstdlib>
#include <ctime>

struct gameState {
    bool game_over;
    bool turn_over;
    int turn;
    int score_this_turn;
    int score ;
};
using namespace std;
void play_game(gameState &g);
void display_rules();
void take_turn(gameState &g);
void roll(gameState &g);
void hold(gameState &g);



int main() {
    gameState game;
    game.game_over = false;
    game.turn_over = false;
    game.turn = 1;
    game.score_this_turn = 0;
    game.score = 0;

    display_rules();
    play_game(game);

};
void display_rules(){
    cout << "Let's Play PIG Dice!" << endl;
    cout << "* See how many turns it takes you to get to 20." << endl;
    cout << "*Turn ends when you hold or roll a 1." << endl;
    cout << "*If you roll a 1, you lose all points for the turn." << endl;
    cout << "*If you hold, you save all points for the turn" << endl;
    cout << endl;
    cout << "turn: 1" << endl;
};
void play_game(gameState &g){
    while (g.game_over == false) {
        take_turn(g);
    }

    if(g.game_over == true) {
        cout << endl;
        cout << "You finished with a final score of 20 or more in " << g.turn << " turns!" << endl;
    }

};
void take_turn(gameState &g){
    g.turn_over = false;
    char choice = 'a';
    cout << "roll or hold? (r/h): ";
    cin >> choice;
    if (choice == 'r') {
        roll(g);
        if (g.turn_over == true) {
            g.turn ++;
            cout << "turn: " << g.turn << endl;
        }
    }
    else if (choice == 'h') {
        hold(g);
        if (g.score < 20) {
            g.turn ++;
            cout << "turn: " << g.turn << endl;
        }
    }
    else {
        cout << "Invalid choice! Try again." << endl;

    }
};
void roll(gameState &g){
    int die;
    srand(time(0));
    die =rand() % 6 +1;
    cout << "Die: "<< die << endl;
    g.score_this_turn = g.score_this_turn + die;
    if (die == 1) {
        cout << "Turn over. No score."<< endl;
        cout << endl;
        g.score_this_turn = 0;
        g.turn_over = true;

    }

};
void hold(gameState &g){
    g.score = g.score + g.score_this_turn;
    cout << "Score for turn:"<< g.score_this_turn << endl;
    cout << "Game score: " << g.score << endl;
    cout << endl;
    g.score_this_turn = 0;
    g.turn_over = true;
    if (g.score >= 20) {
        g.game_over = true;
    }
}