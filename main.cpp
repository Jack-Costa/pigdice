#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void play_game();
void display_rules();
void take_turn(int& score, int& score_this_turn, int& turn, bool& turn_over, bool& game_over);
void roll(int& score_this_turn, bool& turn_over);
void hold(int& score, int& score_this_turn, bool& turn_over, bool& game_over);



int main() {
    display_rules();
    play_game();

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
void play_game(){
    bool game_over = false;
    bool turn_over = false;
    int turn = 1;
    int score_this_turn = 0;
    int score = 0;
    while (game_over == false) {
        take_turn(score,score_this_turn, turn, turn_over, game_over);
    }

    if(game_over == true) {
        cout << endl;
        cout << "You finished with a final score of 20 or more in " << turn << " turns!" << endl;
    }

};
void take_turn(int& score, int& score_this_turn, int& turn, bool& turn_over, bool& game_over){
    turn_over = false;
    char choice = 'a';
    cout << "roll or hold? (r/h): ";
    cin >> choice;
    if (choice == 'r') {
        roll(score_this_turn, turn_over);
        if (turn_over == true) {
            turn ++;
            cout << "turn: " << turn << endl;
        }
    }
    else if (choice == 'h') {
        hold( score, score_this_turn, turn_over, game_over);
        if (score < 20) {
            turn ++;
            cout << "turn: " << turn << endl;
        }
    }
    else {
        cout << "Invalid choice! Try again." << endl;

    }
};
void roll(int& score_this_turn, bool& turn_over){
    int die;
    srand(time(0));
    die =rand() % 6 +1;
    cout << "Die: "<< die << endl;
    score_this_turn = score_this_turn + die;
    if (die == 1) {
        cout << "Turn over. No score."<< endl;
        cout << endl;
        score_this_turn = 0;
        turn_over = true;

    }

};
void hold(int& score, int& score_this_turn, bool& turn_over, bool& game_over){
    score = score + score_this_turn;
    cout << "Score for turn:"<< score_this_turn << endl;
    cout << "Game score: " << score << endl;
    cout << endl;
    score_this_turn = 0;
    turn_over = true;
    if (score >= 20) {
        game_over = true;
    }
}