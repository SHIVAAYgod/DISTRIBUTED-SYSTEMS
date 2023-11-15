#include <bits/stdc++.h>
using namespace std;

int p, e, src, dest;
char e_type;

struct Event{
	char type;
	int src, dest;
};

int main(){
	cout<<"Enter the number of processes: ";
	cin>>p;
	vector<int> ts(p, 0); // timestamps
	cout<<"Enter the number of events: ";
	cin>>e;
	queue<Event> q;
	for(int i=0; i<e; i++){
		cout<<"Enter the type of event[s(send)/ r(receive)/ e(event)]: ";
		cin>>e_type;
		assert(e_type=='s' || e_type=='r' || e_type=='e');
		if(e_type=='s'){
			cout<<"Enter the source and destination process: ";
			cin>>src>>dest;
			src--, dest--;
			Event evt;
			evt.type = e_type;
			evt.src = src;
			evt.dest = dest;
			q.push(evt);
		}else if(e_type=='r'){
			cout<<"Enter the destination and source process: ";
			cin>>dest>>src;
			src--, dest--;
			Event evt;
			evt.type = e_type;
			evt.src = src;
			evt.dest = dest;
			q.push(evt);
		}else if(e_type=='e'){
			cout<<"Enter the process where event occured: ";
			cin>>src;
			src--;
			dest = -1;
			Event evt;
			evt.type = e_type;
			evt.src = src;
			evt.dest = dest;
			q.push(evt);
		}
	}
	cout<<"********************************************************\n";
    int curr_evt[p];
    fill_n(curr_evt, p, 0);
	cout<<"Timestamp updates are as follows: \n";
    priority_queue<int, vector<int>, greater<int>> pq[e+5];
	while(!q.empty()){
		Event evt = q.front();
		q.pop();
		if(evt.type=='s'){
			ts[evt.src]++;
            pq[ts[evt.src]].push(evt.src);
			cout<<"Timestamp of "<<evt.src+1<<" process send event: "<<ts[evt.src]<<"\n";
		}else if(evt.type=='r'){
			ts[evt.dest] = max(ts[evt.dest], ts[evt.src]) + 1;
            pq[ts[evt.dest]].push(evt.dest);
			cout<<"Timestamp of "<<evt.dest+1<<" process receive event: "<<ts[evt.dest]<<"\n";
		}else if(evt.type=='e'){
			ts[evt.src]++;
            pq[ts[evt.src]].push(evt.src);
			cout<<"Timestamp of "<<evt.src+1<<" process event: "<<ts[evt.src]<<"\n";
		}
	}
    vector<string> ans;
    for(auto i: pq){
        while(!i.empty()){
            int prc = i.top();
            i.pop();
            curr_evt[prc]++;
            ans.push_back("e"+to_string(prc+1)+to_string(curr_evt[prc]));
        }
    }
    cout<<"************ Total ordering **************\n";
    for(string i: ans) cout<<i<<" -> ";
    cout<<"\n";
    return 0;
}

