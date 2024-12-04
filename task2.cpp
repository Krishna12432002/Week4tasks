#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> dynamicWidgets = {"Speedometer", "Tachometer", "Odometer"};
    set<string> staticWidgets = {"Logo", "WarningLights"};

    for (auto it = dynamicWidgets.begin(); it != dynamicWidgets.end(); ++it) {
        cout << "Dynamic Widget: " << *it << endl;
    }

    auto searchStatic = staticWidgets.find("WarningLights");
    if (searchStatic != staticWidgets.end()) {
        cout << "Static Widget Found: " << *searchStatic << endl;
    } else {
        cout << "Static Widget Not Found" << endl;
    }

    vector<string> combinedWidgets;
    copy(dynamicWidgets.begin(), dynamicWidgets.end(), back_inserter(combinedWidgets));
    copy(staticWidgets.begin(), staticWidgets.end(), back_inserter(combinedWidgets));

    auto searchCombined = find(combinedWidgets.begin(), combinedWidgets.end(), "Tachometer");
    if (searchCombined != combinedWidgets.end()) {
        cout << "Found in Combined Widgets: " << *searchCombined << endl;
    } else {
        cout << "Not Found in Combined Widgets" << endl;
    }

    for (const auto& widget : combinedWidgets) {
        cout << "All Widgets: " << widget << endl;
    }

    return 0;
}
