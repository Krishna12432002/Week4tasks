#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Control
{
    int id;
    string type;
    string state;

    Control( int id,const string& type,const string state)
    {
        this->id = id;
        this->type = type;
        this->state = state;


    }
     bool operator==(const Control& other) const
    {
        return this->id == other.id;
    }

};

class Icontrol
{
    public:
    vector<Control> controls;
    void ElementsInsertion(Control&& Data)
    {
        controls.push_back(Data);
    }
    void PrintingEle()
    {
        for_each(controls.begin(),controls.end(),[](const Control& data){
            cout<<"["<<data.id<<" ,"<<data.type<<" ,"<<data.state<<"]"<<endl;
            });
    }
    void findEleById(int  id)
    {
        auto it=find(controls.begin(),controls.end(),Control(id,"",""));
        if(it!=controls.end())
        {
            cout<<"found using Find["<<it->id<<" ,"<<it->type<<" ,"<<it->state<<"]"<<endl;
        }
    }

void find_if_EleBystate(string& state)
    {
        auto it=find_if(controls.begin(),controls.end(),[&](const Control& data){return data.state==state;});
        if(it!=controls.end())
        {
            cout<<"found using Find["<<it->id<<" ,"<<it->type<<" ,"<<it->state<<"]"<<endl;
        }
    }
    void find_adj_EleBystate()
    {
        auto it=adjacent_find(controls.begin(),controls.end(),[](const Control& data1,const Control& data2){return data1.state==data2.state;});
        if(it!=controls.end() && (it+1)!=controls.end())
        {
            cout<<endl<<"found usinnng Find["<<it->id<<" ,"<<it->type<<" ,"<<it->state<<"]"<<endl;
            cout<<"found usinnng Find["<<(it+1)->id<<" ,"<<(it+1)->type<<" ,"<<(it+1)->state<<"]"<<endl;
        }
    }

void find_count_EleBystate(const string& stat)
    {
        // auto it=count(controls.begin(),controls.end(),[](Control& data){return data.state==stat});
        // if(it!=controls.end() && (it+1)!=controls.end())
        // {   cout << "Count of elements with state '" << stat << "': " << it << endl;
        //     }
         vector<string> states;
        for (const auto& control : controls) {
            states.push_back(control.state);
        }

        int countState = std::count(states.begin(), states.end(), stat);

        cout << "Count of elements with state '" << stat << "': " << countState << endl;
    }
    
void find_count_if_EleBystate(const string& type,const string& state)
    {
        auto it=count_if(controls.begin(),controls.end(),[& type,& state](Control& data){return data.state==state && data.type==type;});
        cout << "Count of elements with state '" << state << "': " << it << endl;
            }





    void compare_ranges(int start1, int end1, int start2, int end2)
    {
        

        auto begin1 = controls.begin() + start1;
        auto endRange1 = controls.begin() + end1;
        auto begin2 = controls.begin() + start2;
        auto endRange2 = controls.begin() + end2;

        bool areEqual = equal(begin1, endRange1, begin2, endRange2, [](const Control& a, const Control& b) {
            return a.id == b.id && a.type == b.type && a.state == b.state;
        });

        if (areEqual)
        {
            cout << "The specified ranges are identical." << endl;
        }
        else
        {
            cout << "The specified ranges are not identical." << endl;
        }
    }
    
};


int main()
{
    Icontrol ic;
     ic.ElementsInsertion(Control(1, "Button", "visible"));
    ic.ElementsInsertion(Control(2, "Button", "invisible"));
    ic.ElementsInsertion(Control(3, "Slider", "visible"));
    ic.ElementsInsertion(Control(4, "Button", "invisible"));
    ic.ElementsInsertion(Control(5, "Slider",  "disabled"));
    ic.ElementsInsertion(Control(6, "Button", "visible"));
    ic.ElementsInsertion(Control(7, "Button", "invisible"));
    ic.ElementsInsertion(Control(8, "Slider", "invisible"));
    ic.ElementsInsertion(Control(9, "Button", "visible"));
    ic.ElementsInsertion(Control(10, "Button", "disabled"));
    ic.PrintingEle();
    ic.findEleById(3);
    string s="invisible";
    string s1="visible";
    string type="sliders";
    string s2="disabled";
    ic.find_if_EleBystate(s);
    ic.find_adj_EleBystate();
    ic.find_count_EleBystate(s1);
    ic.find_count_if_EleBystate(type,s2);

    cout << "\nComparing ranges:" << endl;
    ic.compare_ranges(0, 3, 7, 10); 
}