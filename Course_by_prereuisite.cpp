#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    string courses[]={"C#","OOP","Collections","SQL","ASP.net","Web Api"};
    int length = sizeof(courses) / sizeof(courses[0]);
    vector<vector<int>> adj_list(length);
    //course name-key, index-i
    unordered_map<string,int> mp;
    for(int i=0;i<length;i++){
        mp[courses[i]]=i;
        //mp['C#']=0 mp['OOP']=1 etc
    }
    vector<int> indegree(length,0);
    adj_list[mp["C#"]].push_back(mp["OOP"]);
    indegree[mp["OOP"]]++;

    adj_list[mp["OOP"]].push_back(mp["Collections"]);
    indegree[mp["Collections"]]++;

    adj_list[mp["OOP"]].push_back(mp["ASP.net"]);
    indegree[mp["ASP.net"]]++;

    adj_list[mp["SQL"]].push_back(mp["ASP.net"]);
    indegree[mp["ASP.net"]]++;

    adj_list[mp["ASP.net"]].push_back(mp["Web Api"]);
    indegree[mp["Web Api"]]++;
    // using bfs (kahn algorithm to finish all prerequisites first)
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<string> course_order_wise;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        course_order_wise.push_back(courses[node]);
        for(auto nei:adj_list[node]){
            indegree[node]--;
            if(indegree[node]==0){
                q.push(node);
            }
        }
        
        
    }
    for(string course:course_order_wise){
        cout<<course<<" ";
    }
    
}
