#include <iostream>
#include <vector>       //For Resizeable arrays
using namespace std;

class Criteria {
public:
    string name;
    float weight;

    Criteria(string n, float w) {
        name = n;
        weight = w;
    }
};

class Option {
public:
    string name;
    vector<float> scores;

    Option(string n, vector<float> s) {
        name = n;
        scores = s;
    }
};

class DecisionEngine {
private:
    vector<Criteria> criteria;
    vector<Option> options;

public:
    void showHeading() {
    cout << "=====================================" << endl;
    cout << "      INTERNSHIP DECISION FORGE      " << endl;
    cout << "=====================================" << endl;
    cout << "Welcome to the Internship Decision Forge!" << endl;
    cout << "This program helps you choose the best option based on multiple Internship option based on various criteria." << endl;
    cout << "Enter criteria with their importance and score each option to find the best decision." << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    }
    void inputCriteria() {
        int n;
        cout << "\nEnter number of criterias: ";
        cin >> n;
        cout << " \n*Importance percentage of 100 % *\n";

        for (int i = 0; i < n; i++) {
            string name;
            int percent;

            cout << "\nEnter criteria name: ";
            cin >> name;

            cout << "Enter Imporatnce Percentage: ";
            cin >> percent;
            float weight;
            weight = percent / 100.00;

            criteria.push_back(Criteria(name, weight));
        }
    }

    void inputOptions() {
        int m;
        cout << "\nEnter number of options: ";
        cin >> m;
        cout << "**Score of criteria out of 10**\n";

        for (int i = 0; i < m; i++) {
            string name;
            cout << "\nEnter option name: ";
            cin >> name;

            vector<float> scores;

            for (int j = 0; j < criteria.size(); j++) {
                float score;
                cout << "Score for " << criteria[j].name << ": ";
                cin >> score;
                scores.push_back(score);
            }

            options.push_back(Option(name, scores));
        }
    }

    void evaluate() {
        float bestScore = -1;
        string bestOption;

        cout << "\nDecision Results\n";

        for (auto &opt : options) {
            float total = 0;

            for (int i = 0; i < criteria.size(); i++) {
                total += opt.scores[i] * criteria[i].weight;
            }

            cout << opt.name << " Score: " << total << endl;

            if (total > bestScore) {
                bestScore = total;
                bestOption = opt.name;
            }
        }

        cout << "\nBest Decision: " << bestOption << endl;
         cout << "\nAll the best for your internship! Wishing you great learning and success ahead";
    }
};

int main() {
    DecisionEngine engine;
    
    engine.showHeading();

    engine.inputCriteria();
    engine.inputOptions();
    engine.evaluate();

    return 0;
}
