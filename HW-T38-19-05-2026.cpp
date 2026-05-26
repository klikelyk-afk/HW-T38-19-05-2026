#include <iostream>
#include <string>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Ingredient.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    cout << "=================== TASK 1 ===================" << endl;
    myQueue::Queue<string> stringQueue;

    stringQueue.push_back("one");
    stringQueue.push_back("two");
    stringQueue.push_back("three");
    stringQueue.push_back("four");
    stringQueue.push_back("five");
    stringQueue.push_back("six");

    cout << "Initial queue: ";
    stringQueue.show();

    stringQueue.pop_front();
    stringQueue.pop_front();

    stringQueue.push_back("seven");

    cout << "Queue after modifications: ";
    stringQueue.show();

    int count = 0;
    myQueue::Queue<string> tempQueue;

    while (!stringQueue.isEmpty()) {
        string currentStr = stringQueue.first();
        if (!currentStr.empty() && (currentStr[0] == 'f' || currentStr[0] == 't')) {
            count++;
        }
        tempQueue.push_back(currentStr);
        stringQueue.pop_front();
    }

    while (!tempQueue.isEmpty()) {
        stringQueue.push_back(tempQueue.first());
        tempQueue.pop_front();
    }

    cout << "Count of strings starting with 'f' or 't': " << count << endl;
    cout << "==============================================\n" << endl;


    cout << "=========== TASK 2: MULTICOOKER ===========" << endl;
    myQueue::PriorityQueue<Ingredient> multicooker;
    int choice;

    while (true) {
        cout << "Enter what you want to do:" << endl;
        cout << "1 - Add ingredient" << endl;
        cout << "2 - Cook a dish" << endl;
        cout << "3 - Exit" << endl;
        cout << "> ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int time;

            cout << "Enter name of ingredient: ";
            cin.ignore();
            std::getline(cin, name);

            cout << "Enter time of cooking(seconds): ";
            cin >> time;

            multicooker.push_back(Ingredient(name, time));
            cout << "Current cooker queue: ";
            multicooker.show();
            cout << "--------------------------------" << endl;
        }
        else if (choice == 2) {
            if (multicooker.isEmpty()) {
                cout << "No ingredients in the multicooker! Queue is empty!" << endl;
            }
            else {
                cout << "Cooking in progress..." << endl;
                while (!multicooker.isEmpty()) {
                    Ingredient current = multicooker.first();
                    cout << "Processing: " << current.getName() << " for " << current.getCookTime() << " seconds." << endl;
                    multicooker.pop_front();
                }
                cout << "Dish is ready!" << endl;
            }
            cout << "--------------------------------" << endl;
        }
        else if (choice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
            cout << "--------------------------------" << endl;
        }
    }

    return 0;
}