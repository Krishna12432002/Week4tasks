#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

string randomState() {
    vector<string> states = {"visible", "invisible", "disabled"};
    return states[rand() % states.size()];
}

int main() {
    vector<string> controls = {"Slider1", "Button1", "Slider2", "Button2"};

    vector<string> backupControls(controls.size());
    copy(controls.begin(), controls.end(), backupControls.begin());
    cout << "Backup Controls: ";
    for (const auto& control : backupControls) {
        cout << control << " ";
    }
    cout << endl;

    fill(controls.begin(), controls.end(), "disabled");
    cout << "After Fill: ";
    for (const auto& control : controls) {
        cout << control << " ";
    }
    cout << endl;

    generate(controls.begin(), controls.end(), randomState);
    cout << "After Generate: ";
    for (const auto& control : controls) {
        cout << control << " ";
    }
    cout << endl;

    transform(controls.begin(), controls.end(), controls.begin(), [](const string& state) {
        return (state == "Slider1" || state == "Slider2") ? "invisible" : state;
    });
    cout << "After Transform: ";
    for (const auto& control : controls) {
        cout << control << " ";
    }
    cout << endl;

    replace(controls.begin(), controls.end(), string("disabled"), string("enabled"));
    cout << "After Replace: ";
    for (const auto& control : controls) {
        cout << control << " ";
    }
    cout << endl;

    controls.erase(remove_if(controls.begin(), controls.end(), [](const string& state) {
        return state == "invisible";
    }), controls.end());
    cout << "After Remove If: ";
    for (const auto& control : controls) {
        cout << control << " ";
    }
    cout << endl;

    reverse(controls.begin(), controls.end());
    cout << "After Reverse: ";
    for (const auto& control : controls) {
        cout << control << " ";
    }
    cout << endl;

    partition(controls.begin(), controls.end(), [](const string& state) {
        return state == "visible";
    });
    cout << "After Partition: ";
    for (const auto& control : controls) {
        cout << control << " ";
    }
    cout << endl;

    return 0;
}
