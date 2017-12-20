/**
 * Problem: UVa 511 - Do You Know the Way to San Jose?
 * Author: sjsakib
 * Approach: Naive Implementation
**/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double eps = 1e-6;

struct Map {
    string name;
    double x1,x2,y1,y2;
    double ratio;

    Map(string name_, double x1_, double y1_, double x2_, double y2_) {
        name = name_;
        x1 = max(x1_,x2_);
        y1 = max(y1_,y2_);
        x2 = min(x1_,x2_);
        y2 = min(y1_,y2_);

        ratio = 0.75 - (y1-y2)/(x1-x2);
    }
    bool operator<(Map rhs) {
        return (x1-x2)*(y1-y2) > (rhs.x1-rhs.x2)*(rhs.y1-rhs.y2);
    }
};

struct Location {
    string name;
    double x,y;
    vector<int> maps;

    Location(string name_, double x_, double y_) {
        name = name_;
        x = x_;
        y = y_;
    }

    bool in(Map& mp) {
        return x <= mp.x1+eps && x+eps >= mp.x2 && y <= mp.y1+eps && y+eps >= mp.y2;
    }
    double dist(Map& mp) {
        double cx = (mp.x1-mp.x2)/2;
        double cy = (mp.y1-mp.y2)/2;
        return (x-cx)*(x-cx) + (y-cy)*(y-cy);
    }
    double cdist(Map& mp) {
        return (x-mp.x2)*(x-mp.x2) + (y-mp.y2)*(y-mp.y2);
    }
};


vector<Map> maps;
vector<Location> locations;

void set_maps() {
    for(auto& loc: locations) {
        int mpidx = -1;
        double dist, ratio, cdist, xcord;
        for(int i = 0; i < (int) maps.size(); i++) {
            if(loc.in(maps[i])) {
                if(mpidx == -1) {
                    mpidx = i;
                    dist = loc.dist(maps[i]);
                    ratio = maps[i].ratio;
                    cdist = loc.cdist(maps[i]);
                    xcord = maps[i].x1 - maps[i].x2;
                    continue;
                }
                if(maps[mpidx] < maps[i]) {  // '<' works as '>'; path to hell
                    loc.maps.push_back(mpidx);
                    mpidx = i;
                    continue;
                }
                if(loc.dist(maps[i])+eps < dist) {
                    loc.maps.push_back(mpidx);
                    mpidx = -1;
                    continue;
                }
                if(abs(loc.dist(maps[i]) - dist) < eps && maps[i].ratio+eps < ratio) {
                    loc.maps.push_back(mpidx);
                    mpidx = -1;
                    continue;
                }
                if(abs(maps[i].ratio - ratio) < eps && loc.cdist(maps[i])+eps < cdist) {
                    loc.maps.push_back(mpidx);
                    mpidx = -1;
                    continue;
                }
                if(abs(loc.cdist(maps[i]) - cdist) < eps && xcord > (maps[i].x1 - maps[i].x2)) {
                    loc.maps.push_back(mpidx);
                    mpidx = -1;
                }
            }
        }
        if(mpidx != -1) loc.maps.push_back(mpidx);
    }
}

void print_lev(string name, int lev) {
    cout<<name<<" at detail level "<<lev<<" ";
    for(auto& loc: locations) {
        if(loc.name != name) continue;
        if((int) loc.maps.size() >= lev) {
            cout<<"using "<<maps[loc.maps[lev-1]].name<<endl;
            return;
        } else if (loc.maps.size()) {
            cout<<"no map at that detail level; using "<<maps[loc.maps.back()].name<<endl;
            return;
        } else {
            cout<<"no map contains that location"<<endl;
            return;
        }
    }
    cout<<"unknown location"<<endl;
}

int main() {
    string cmd;
    cin>>cmd;
    string name;
    double x1,x2,y1,y2;
    while ((cin>>name) && name != "LOCATIONS") {
        cin>>x1>>y1>>x2>>y2;
        maps.push_back(Map(name, x1, y1, x2, y2));
    }
    sort(maps.begin(), maps.end());
    while ((cin>>name) && name != "REQUESTS") {
        cin>>x1>>y1;
        locations.push_back(Location(name, x1, y1));
    }
    set_maps();
    int lev;
    while ((cin>>name) && name != "END") {
        cin>>lev;
        print_lev(name, lev);
    }
    return 0;
}
