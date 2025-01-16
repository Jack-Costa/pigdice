#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    cout << "Let's Play PIG Dice!" << endl;
    cout << "* See how many turns it takes you to get to 20." << endl;
    cout << "*Turn ends when you hold or roll a 1." << endl;
    cout << "*If you roll a 1, you lose all points for the turn." << endl;
    cout << "*If you hold, you save all points for the turn" << endl;
    cout << endl;
    bool game_over = false;
    bool turn_over = false;
    int turn_count = 1;
    int die_val = 0;
    char choice = 'a';
    int score_this_turn = 0;
    int game_score = 0;

    while (game_over == false){
        if (game_score <=19 ) {
            turn_over = false;
            cout << "Turn " << turn_count << endl;
            turn_count ++;
        }
        else if (game_score >= 20) {
            game_over = true;
            cout << endl;
            cout << "You finished with a final score of 20 or more in " << turn_count << " turns!" << endl;
        }
        score_this_turn = 0;
        while (turn_over == false) {
            cout << "roll or hold? (r/h): ";
            cin >> choice;
            if (choice == 'r') {
                srand(time(0));
                die_val =rand() % 6 +1;
                cout << "Die: "<< die_val << endl;
                score_this_turn = score_this_turn + die_val;
                if (die_val == 1) {
                    cout << "Turn over. No score."<< endl;
                    cout << endl;
                    turn_over = true;
                }
            }
            else if (choice == 'h' || turn_over == true) {
                game_score = game_score + score_this_turn;
                cout << "Score for turn:"<< score_this_turn << endl;
                cout << "Game score: " << game_score << endl;
                cout << endl;
                score_this_turn = 0;
                turn_over = true;
            }
            else {
                cout << "Invalid choice! Try again." << endl;
            }
        };
    };
    return 0;
}