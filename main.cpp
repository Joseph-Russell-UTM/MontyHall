/**
 * @file main.cpp
 * @author Joseph Russell
 * @date 2026-10-26
 */

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;



void monty_hall(){
    int player_door;
    int car_door;
    int opened_door;
    char switch_choice;

    cout << "Choose a door 1 - 3: ";
    cin >> player_door;
    srand(time(0));
    car_door = rand() % 3 + 1;

    for (int i = 1; i <= 3; ++i) {
        if (i != player_door && i != car_door) {
            opened_door = i;
            cout << "Host opens door " << opened_door << " and reveals a goat." << endl;
            break;
        }
    }

    cout << "Do you want to switch doors? (y/n): ";
    cin >> switch_choice;

    if (switch_choice == 'y' || switch_choice == 'Y') {
        player_door = 6 - player_door - opened_door;
        }
    
    if (player_door == car_door) {
        cout << "Congratulations! You won the car!" << endl;
    } else {
        cout << "Sorry, you got a goat." << endl;
    }

    return;
}


void simulate(int num_iterations){
    int player_door;
    int car_door;
    int opened_door;
    char switch_choice;
    int iteration = 0;
    int wins = 0;
    int losses = 0;
    float win_percentage;
    float loss_percentage;

    srand(time(0)); // Seed the random number generator

    cout << "Will the simulation switch doors? (y/n): ";
    cin >> switch_choice;

    while (iteration < num_iterations) {
        iteration++;
        player_door = rand() % 3 + 1;
        car_door = rand() % 3 + 1;
       // cout << "Car is behind door " << car_door << endl;
       // cout << "Player chose door " << player_door << endl;

        for (int i = 1; i <= 3; ++i) {
            if (i != player_door && i != car_door) {
                opened_door = i;
                break;
            }
        }


        if (switch_choice == 'y' || switch_choice == 'Y') {
            player_door = 6 - player_door - opened_door;
           // cout << "Player switched to door " << player_door << endl;
            }

        
        if (player_door == car_door) {
            wins++;
            // cout << "Player won the car!" << endl;
        } else {
            losses++;
            // cout << "Player got a goat." << endl;
        }
    }

    win_percentage = (float)wins / num_iterations * 100;
    loss_percentage = (float)losses / num_iterations * 100;

    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Win Percentage: " << win_percentage << "%" << endl;
    cout << "Loss Percentage: " << loss_percentage << "%" << endl;
    return;
}




int main() {
    int choice;
    int num_iterations;
    
    cout << "Choose 1 for Monty Hall or 2 for auto simulation, press 3 to end: ";
    cin >> choice;

    while (choice != 3){

        if (choice == 1){
            monty_hall();
            cout << "Please choose again: ";
            cin >> choice;
        }
        else if (choice == 2){
            cout << "How many iterations? ";
            cin >> num_iterations;
            simulate(num_iterations);
            cout << "Please choose again: ";
            cin >> choice;
        }
        else{
            cout << "Invalid choice, please try again." << endl;
            cout << "Please choose again: ";
            cin >> choice;
        }


    }
}
