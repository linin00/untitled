#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

class solver {
public:
    vector<double> getFlow() {
        string flow;
        ifstream FILE("./flow.txt");
        vector<double> Flow;
        double a;
        char b;
        while (getline(FILE, flow)) {
            stringstream ss(flow);
            ss >> a;
            Flow.push_back(a);
        }
        FILE.close();
        return Flow;
    }
    void run() {
        while (true) {
            cout << "press B to begin\nor press Q to quit\n";
            vector<double> Flow = getFlow();
            string cmd;
            getline(cin, cmd);
            if (cmd == "q" || cmd == "Q")
                return;
            if (cmd == "B" || cmd == "b") {
                double sum = 0;
                double k = 0;
                int i = 0;
                for(i = 0; i < Flow.size(); i++, k++) {
                    sum += Flow[i];
                    if(sum >= 0)
                        break;
                    if(sum < 0 && i == Flow.size() - 1) {
                        cout << "sorry!\n";
                        return;
                    }
                }
                k += ((0 - sum) / Flow[i]);
                cout << "years: " << k << endl;
                return;
            }
        }
    };
};
int main()
{
    solver my;
    my.run();
    for (int i = 1; i <= 10; i++) {
        cout << "close after "<< 10 -i << "seconds\n";
        Sleep(1000);
    }
    return 0;
}
