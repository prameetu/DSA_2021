#include<bits/stdc++.h>

using namespace std;

bool my_comp(pair <int,int> p1,pair <int,int> p2){
    return p1.first > p2.first;
}

void max_profit(vector <pair<int,int>> jobs,int num_of_slots){
    sort(jobs.begin(),jobs.end(),my_comp);
    int n(jobs.size());

    vector <int> sequence(num_of_slots);
    vector <bool> slots(num_of_slots);
    int profit(0);
    for(int i=0;i<n;i++){
        slots[i] = false;
    }

    for(int i=0;i<n;i++){
        for(int j=jobs[i].second-1;j>=0;j--){
            if(slots[j]==false)
            {
                profit += jobs[i].first;
                sequence[j] = i;
                slots[j] = true;
                break;
            }
        }
    }
    

    // printing the max profit and the job sequnce 

    cout << "The max profit is " << profit << endl;
    for(auto x :sequence)
        cout << x+1 << " ";

}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector <int> profit(n);
    cout << "Enter the profit of jobs: ";
    for(int i=0;i<n;i++){
        cin >> profit[i];
    }

    vector <int> deadlines(n);
    cout << "Enter the deadlines of jobs: ";
    for(int i=0;i<n;i++){
        cin >> deadlines[i];
    }
    int num_of_slots = *max_element(deadlines.begin(),deadlines.end());
    vector <pair <int,int>> jobs;
    for(int i=0;i<n;i++){
        jobs.push_back({profit[i],deadlines[i]});
    }

    for(int i=0;i<n;i++){
        cout << jobs[i].first << " " << jobs[i].second << endl; 
    }

    max_profit(jobs,num_of_slots);

}