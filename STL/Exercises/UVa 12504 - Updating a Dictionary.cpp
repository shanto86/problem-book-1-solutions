/**
 * Problem: UVa 12504 - Updating a Dictionary
 * Author: sjsakib
 * Approach: Implementation
**/
#include <cstdio>
#include <string>
#include <map>

using namespace std;

void read_map(map<string, string> &mp) {
    char buff[103];
    scanf("%s", buff);
    int i = 1;
    while(buff[i] != '\0' && buff[i] != '}'){
        string key;
        while(buff[i] != ':') {
            key += buff[i++];
        }
        i++;
        string val;
        while(buff[i] != ',' && buff[i] != '}') {
            val += buff[i++];
        }
        mp[key] = val;
        i++;
    }

}

void print_diff(map<string, string> &mp1, map<string, string> &mp2) {
    int count = 0,total;
    for (auto item: mp2) {
        if(mp1.count(item.first) == 0) {
            if(count == 0) printf("+");
            else printf(",");
            printf("%s", item.first.c_str());
            count++;
        }
    }
    if(count) printf("\n");
    total = count;
    count = 0;
    for (auto item: mp1) {
        if(mp2.count(item.first) == 0) {
            if(count == 0) printf("-");
            else printf(",");
            printf("%s", item.first.c_str());
            count++;
        }
    }
    if(count) printf("\n");
    total += count;
    count = 0;
    for (auto item: mp2) {
        if(mp1.count(item.first) != 0 && mp1[item.first] != mp2[item.first]) {
            if(count == 0) printf("*");
            else printf(",");
            printf("%s", item.first.c_str());
            count++;
        }
    }
    if(count) printf("\n");
    total += count;
    if(!total) printf("No changes\n");
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        map<string, string> mp1;
        map<string, string> mp2;
        read_map(mp1);
        read_map(mp2);
        print_diff(mp1,mp2);
    }
    return 0;
}