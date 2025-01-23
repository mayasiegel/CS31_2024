#include <iostream>
#include <string>
using namespace std;

int main() {

    string model = "";
    string kind = "";
    string color = "";
    int wheel = 0;
    string interior = "";
    string autopilot = "";
    
    double total = 0;
    
    // Question 1 - model
    cout << "Which vehicle would you like to order? ";
    getline(cin, model);
    if (model == "3" || model == "Y" || model == "X" || model == "S") {
        // empty condition
    }
    
    // Question 2 - kind
    cout << "Which kind would you like? ";
    getline (cin, kind);
    if (kind == "Base" && model == "3") {
        total += 35990;
    }
    else if (kind == "Base" && model == "S") {
        total += 74990;
    }
    else if (kind == "Base" && model == "X") {
        total += 68590;
    }
    else if (kind == "Base" && model == "Y") {
        total += 32890;
    }
    else if (kind == "All Wheel" && model == "3") {
        total += 44740;
    }
    else if (kind == "All Wheel" && model == "Y") {
        total += 37890;
    }
    else if (kind == "All Wheel" && model == "S") {
        total += 89990;
    }
    else if (kind == "All Wheel" && model == "X") {
        total += 91090;
    }
    
    
    // Question 3 - color
    cout << "Which exterior color would you like? ";
    getline(cin, color);
    if (color == "Grey") {
        // empty condition
    }
    if ((color == "Black") || (color == "Blue" && (model == "S" || model == "X")) || ((color == "White") && (model == "S" || model == "X"))) {
        total += 1500;
    }
    if ((color == "Blue" || color == "White") && (model == "3" || model == "Y")) {
        total += 1000;
    }
    if ((color == "Red") && (model == "3" || model == "Y")) {
        total += 2000;
    }
    if ((color == "Red") && (model == "S" || model == "X")) {
        total += 2500;
    }
    
    
    // Question 4 - wheel
    cout << "Which wheels would you like? ";
    cin >> wheel;
    if ((wheel == 18 && model == "3") || (wheel == 19 && (model == "Y" || model == "S")) || (wheel == 20 && model == "X")) {
        // empty condition
    }
    if (wheel == 19 && model == "3") {
        total += 1500;
    }
    if (wheel == 20 && model == "Y") {
        total += 2000;
    }
    if (wheel == 21 && model == "S") {
        total += 4500;
    }
    if (wheel == 22 && model == "X") {
        total += 5500;
    }

    // Question 5 - interior
    cout << "Which interior color interior would you like? ";
    cin.ignore (10000, '\n');
    getline (cin, interior);
    if (interior == "Black") {
        // empty condition
    }
    if ((interior == "White" || interior == "Cream") && (model == "3" || model == "Y")) {
        total += 1500;
    }
    if ((interior == "White" || interior == "Cream") && (model == "S" || model == "X")) {
        total += 2000;
    }
    
    // Quesiton 6 - autopilot
    cout << "Want Auto-Pilot? ";
    getline (cin, autopilot);
    if (autopilot == "Yes") {
        total += 6000;
    }
    if (autopilot == "No") {
        // empty condition
    }

    // cout << "The price is: $" << total << endl;
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);
    
    // model error
    if (model != "3" && model != "S" && model != "X" && model != "Y") {
        cout << "Error - Incorrect model choice. ";
        return (1);
        // how do I get to next question?
        // experiment with a not inside of condition !!!
        // warp with () add NOT
    }
    
    // kind error
    if (kind != "Base" && kind != "All Wheel") {
        cout << "Error - Incorrect kind choice. ";
        return (1);
    }
    
    // color error
    if (color != "Grey" && color != "Black" && color != "Blue" && color != "White" && color != "Red") {
        cout << "Error - Incorrect color choice. ";
        return (1);
    }
    
    // wheel error
    if (model == "3" && (wheel != 18 && wheel != 19)) {
        cout << "Error - Incorrect wheel choice. ";
        return (1);
    }
    if (model == "Y" && (wheel != 19 && wheel != 20)) {
        cout << "Error - Incorrect wheel choice. ";
        return (1);
    }
    if (model == "S" && (wheel != 19 && wheel != 21)) {
        cout << "Error - Incorrect wheel choice. ";
        return (1);
    }
    if (model == "X" && (wheel != 20 && wheel != 22)) {
        cout << "Error - Incorrect wheel choice. ";
        return (1);
    }

    // interior error
    if ((model == "3" || model == "Y") && (interior != "White" && interior != "Cream" && interior != "Black")) {
        cout << "Error - Incorrect interior choice. ";
        return (1);
    }
    if ((model == "S" || model == "X") && (interior != "White" && interior != "Cream" && interior != "Black")) {
        cout << "Error - Incorrect interior choice. ";
        return (1);
    }
     
    // autopilot error
    if (autopilot != "Yes" && autopilot != "No") {
        cout << "Error - Incorrect autopilot choice. ";
        return (1);
    }

    cout << "Enjoy your new $" << total << " " << color << " " << "Model" << " " << model << "!";
    
    return 0;
}
