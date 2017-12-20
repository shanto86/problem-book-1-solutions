/**
 * Problem: UVa 230 - Borrowers
 * Author: sjsakib
 * Approach: 
**/
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<string, string> > all_books;
map<string, bool> borrowed;
map<string, bool> returned;

int main() {
    char book[85], author[85];
    while (scanf("\"%[^\"]\" by %[^\n]\n", book, author)) {
        all_books.push_back(make_pair(author, book));
        borrowed[book] = 0;
        returned[book] = 0;
    }
    sort(all_books.begin(), all_books.end());

    scanf("%s\n", book);  // eating the END
    
    while (scanf("%s ", book)) {  // using 'book' as buffer to read the command
        string cmd(book);
        if (cmd == "END") break;
        if (cmd == "SHELVE") {
            string last;
            for (auto b: all_books) {
                if(!borrowed[b.second]) last = b.second;
                else if(returned[b.second]) {
                    if(last.length()) printf("Put \"%s\" after \"%s\"\n", b.second.c_str(), last.c_str());
                    else printf("Put \"%s\" first\n", b.second.c_str());
                    borrowed[b.second] = 0;
                    last = b.second;
                }
            }
            printf("END\n");
            returned.clear();
            continue;
        }
        scanf("\"%[^\"]\"\n", book);
        if (cmd == "BORROW") {
            borrowed[book] = 1;
        } else if (cmd == "RETURN") {
            returned[book] = 1;
        }
    }
    return 0;
}