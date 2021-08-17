#include<bits/stdc++.h>

using namespace std;

bool my_comp(pair <double,double> p1,pair <double,double> p2)
{
    double value_by_weight_1 = (double)p1.first/p1.second;
    double value_by_weight_2 = (double)p2.first/p2.second;

    return value_by_weight_1 > value_by_weight_2;
}

double knaspack_prob(vector <pair <double,double>> items,double knapscak_quant)
{
    sort(items.begin(),items.end(),my_comp);
    double value(0);
    for(double i=0;i<items.size();i++)
    {
        if(items[i].second <= knapscak_quant)
        {
            value += items[i].first;
            knapscak_quant -= items[i].second;
        }
        else{
            value += (items[i].first/items[i].second)*(double)knapscak_quant;
            break;
        }
    }    
    return value;
}




int main()
{
    double n;
    cout << "Enter number of items: ";
    cin >> n;
    double knapsack_quant;
    cout << "Enter the knapsack quantity: ";
    cin >> knapsack_quant;
    vector <double> weights(n);
    cout << "Enter the weights of items: ";
    for(double i=0;i<n;i++){
        cin >> weights[i];
    }

    vector <double> values(n);
    cout << "Enter the values of items: ";
    for(double i=0;i<n;i++){
        cin >> values[i];
    }
    vector <pair <double,double>> items;
    for(double i=0;i<n;i++){
        items.push_back({values[i],weights[i]});
    }

    for(double i=0;i<n;i++){
        cout << items[i].first << " " << items[i].second << endl; 
    }

    cout << "The maximum value of knapsack can be: " << knaspack_prob(items,knapsack_quant);



}