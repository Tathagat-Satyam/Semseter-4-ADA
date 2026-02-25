#include <iostream>
#include <algorithm>
using namespace std;

struct Object {
    float mass, price, ratio;
};

bool compare(Object a, Object b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    float maxMass;
    
    cout << "Enter number of objects: ";
    cin >> n;
    
    Object obj[n];
    
    cout << "\nEnter mass and price for each object:\n";
    for(int i = 0; i < n; i++) {
        cout << "Object " << i+1 << " (mass price): ";
        cin >> obj[i].mass >> obj[i].price;
        obj[i].ratio = obj[i].price / obj[i].mass;
    }
    
    cout << "\nEnter total mass to purchase: ";
    cin >> maxMass;
    
    // Sort by price/mass ratio (highest first)
    sort(obj, obj + n, compare);
    
    // Greedy selection
    float remaining = maxMass;
    float totalProfit = 0;
    
    cout << "\n--- Selected Objects ---\n";
    for(int i = 0; i < n && remaining > 0; i++) {
        if(obj[i].mass <= remaining) {
        
            cout << "Take Object (Full): " << obj[i].mass << " kg, Price: Rs" << obj[i].price << endl;
            totalProfit += obj[i].price;
            remaining -= obj[i].mass;
        } else {
          
            float fraction = remaining / obj[i].mass;
            float profit = obj[i].price * fraction;
            cout << "Take Object (Partial): " << remaining << " kg, Price: Rs" << profit << endl;
            totalProfit += profit;
            remaining = 0;
        }
    }
    
    cout << "\nTotal Profit: Rs" << totalProfit << endl;
    
    return 0;
}