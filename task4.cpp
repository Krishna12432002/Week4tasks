#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;

struct Control {
    int id;
    string name;

    bool operator<(const Control& other) const {
        return id < other.id;
    }
};

int main() {
    vector<Control> controlsA = {{3, "Slider"}, {1, "Button"}, {5, "Checkbox"}};
    vector<Control> controlsB = {{2, "Switch"}, {4, "RadioButton"}, {5, "Checkbox"}};

    sort(controlsA.begin(), controlsA.end());
    sort(controlsB.begin(), controlsB.end());

    cout << "Sorted Controls A: ";
    for (const auto& control : controlsA) {
        cout << "(" << control.id << ", " << control.name << ") ";
    }
    cout << endl;

    cout << "Sorted Controls B: ";
    for (const auto& control : controlsB) {
        cout << "(" << control.id << ", " << control.name << ") ";
    }
    cout << endl;

    auto combinedControls = controlsA;
    combinedControls.insert(combinedControls.end(), controlsB.begin(), controlsB.end());

    stable_sort(combinedControls.begin(), combinedControls.end());

    cout << "Combined and Stable Sorted: ";
    for (const auto& control : combinedControls) {
        cout << "(" << control.id << ", " << control.name << ") ";
    }
    cout << endl;

    int searchID = 5;
    auto lower = lower_bound(combinedControls.begin(), combinedControls.end(), Control{searchID, ""});
    auto upper = upper_bound(combinedControls.begin(), combinedControls.end(), Control{searchID, ""});

    if (lower != combinedControls.end() && lower->id == searchID) {
        cout << "Control Found with ID " << searchID << ": " << lower->name << endl;
    } else {
        cout << "Control with ID " << searchID << " not found." << endl;
    }

    vector<Control> mergedControls;
    merge(controlsA.begin(), controlsA.end(), controlsB.begin(), controlsB.end(), back_inserter(mergedControls));

    cout << "Merged Controls: ";
    for (const auto& control : mergedControls) {
        cout << "(" << control.id << ", " << control.name << ") ";
    }
    cout << endl;

    inplace_merge(combinedControls.begin(), combinedControls.begin() + controlsA.size(), combinedControls.end());

    cout << "Inplace Merged: ";
    for (const auto& control : combinedControls) {
        cout << "(" << control.id << ", " << control.name << ") ";
    }
    cout << endl;

    vector<Control> unionControls, intersectionControls;
    set_union(controlsA.begin(), controlsA.end(), controlsB.begin(), controlsB.end(), back_inserter(unionControls));
    set_intersection(controlsA.begin(), controlsA.end(), controlsB.begin(), controlsB.end(), back_inserter(intersectionControls));

    cout << "Union of Controls: ";
    for (const auto& control : unionControls) {
        cout << "(" << control.id << ", " << control.name << ") ";
    }
    cout << endl;

    cout << "Intersection of Controls: ";
    for (const auto& control : intersectionControls) {
        cout << "(" << control.id << ", " << control.name << ") ";
    }
    cout << endl;

    return 0;
}
