#include <iostream>
using namespace std;

int main() {
    double distance, time, velocity;
    
    cout << "Enter distance (in meters): ";
    cin >> distance;
    cout << "Enter time (in seconds): ";
    cin >> time;
    
    if (time > 0) {
        velocity = distance / time;
        cout << "Velocity = " << velocity << " m/s" << endl;
    } else {
        cout << "Time must be greater than zero." << endl;
    }
    
    return 0;
}
