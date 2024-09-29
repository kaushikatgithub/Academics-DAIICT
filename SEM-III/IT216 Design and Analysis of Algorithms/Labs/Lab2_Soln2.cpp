#include<bits/stdc++.h>
using namespace std;

int main() {
   
    int n;
    cout << "Enter the number of jobs : ";
    cin >> n;
    vector<pair<int, int>> jobs;
    for(int i = 0 ; i < n ; ++i) {
        int si;
        cout << "Enter Start time for job " << i+1 << " : ";
        cin >> si;
        
        int fi;
        cout << "Enter End time for job " << i+1 << " : ";
        cin >> fi;
        
        jobs.push_back(make_pair(si, fi));
    }
    
    sort(jobs.begin(), jobs.end());
    
    int k = 0;
    priority_queue <int, vector<int>, greater<int>> priq;
    
    for(int i = 0 ; i < n ; ++i) {
        
        if(priq.empty()) {
            
            priq.push(jobs[i].second);
            k++;
            
        } else if(priq.top() <= jobs[i].first) {
          
            priq.pop();
            priq.push(jobs[i].second);
            
        } else if(priq.top() > jobs[i].first) {
        
            priq.push(jobs[i].second);
            k++;
          
        }
    }
    
    cout << k << endl;
    return 0;
}
