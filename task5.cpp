#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// Singleton: HMISystem to manage HMI states
class HMISystem {
private:
    static HMISystem* instance;
    string mode;

    HMISystem() : mode("Day") {}

public:
    static HMISystem* getInstance() {
        if (!instance)
            instance = new HMISystem();
        return instance;
    }

    void setMode(const string& newMode) {
        mode = newMode;
    }

    string getMode() const {
        return mode;
    }
};

HMISystem* HMISystem::instance = nullptr;

// Factory: Create different types of controls
class Control {
public:
    virtual void render() const = 0;
    virtual ~Control() {}
};

class Button : public Control {
public:
    void render() const override {
        cout << "Rendering Button\n";
    }
};

class Slider : public Control {
public:
    void render() const override {
        cout << "Rendering Slider\n";
    }
};

class ControlFactory {
public:
    static unique_ptr<Control> createControl(const string& type) {
        if (type == "Button")
            return make_unique<Button>();
        if (type == "Slider")
            return make_unique<Slider>();
        return nullptr;
    }
};

// Observer: Notify widgets about mode changes
class ModeObserver {
public:
    virtual void update(const string& mode) = 0;
    virtual ~ModeObserver() {}
};

class Widget : public ModeObserver {
    string name;

public:
    Widget(const string& widgetName) : name(widgetName) {}

    void update(const string& mode) override {
        cout << "Widget " << name << " updated to " << mode << " mode.\n";
    }
};

class ModeNotifier {
    vector<ModeObserver*> observers;

public:
    void addObserver(ModeObserver* observer) {
        observers.push_back(observer);
    }

    void notifyObservers(const string& mode) {
        for (auto observer : observers)
            observer->update(mode);
    }
};

// Strategy: Different rendering behaviors
class RenderingStrategy {
public:
    virtual void render() const = 0;
    virtual ~RenderingStrategy() {}
};

class Render2D : public RenderingStrategy {
public:
    void render() const override {
        cout << "Rendering in 2D mode\n";
    }
};

class Render3D : public RenderingStrategy {
public:
    void render() const override {
        cout << "Rendering in 3D mode\n";
    }
};

class RenderingContext {
    unique_ptr<RenderingStrategy> strategy;

public:
    void setStrategy(unique_ptr<RenderingStrategy> newStrategy) {
        strategy = move(newStrategy);
    }

    void render() const {
        if (strategy)
            strategy->render();
    }
};

int main() {
    // Singleton
    HMISystem* hmi = HMISystem::getInstance();
    cout << "Current HMI Mode: " << hmi->getMode() << endl;

    hmi->setMode("Night");
    cout << "Updated HMI Mode: " << hmi->getMode() << endl;

    // Factory
    auto button = ControlFactory::createControl("Button");
    auto slider = ControlFactory::createControl("Slider");

    button->render();
    slider->render();

    // Observer
    ModeNotifier notifier;
    Widget speedometer("Speedometer");
    Widget tachometer("Tachometer");

    notifier.addObserver(&speedometer);
    notifier.addObserver(&tachometer);

    notifier.notifyObservers(hmi->getMode());

    // Strategy
    RenderingContext context;
    context.setStrategy(make_unique<Render2D>());
    context.render();

    context.setStrategy(make_unique<Render3D>());
    context.render();

    return 0;
}
