/* 
19.02.21
<Tree implemented with vector>

Sample Input
8
-1
0
0
1
1
2
2
3

Sample Output
0 1 3 7 4 2 5 6
1 3 7 4 0 2 5 6
7 3 4 1 5 6 2 0
*/

#include <iostream>
#include <vector>
using namespace std;

const int TREE_MAX_SIZE = 10000;
vector <int> child[TREE_MAX_SIZE];

void insert(int p,int c) {
    if (p == -1) {
        return;
    }
    child[p].push_back(c);
}

void pre_order(int cur) {
    cout << cur << ' ';
    for (int i = 0; i < child[cur].size(); i++) {
        pre_order(child[cur][i]);
    }
}
void post_order(int cur) {
    for (int i = 0; i < child[cur].size(); i++) {
        post_order(child[cur][i]);
    }
    cout << cur << ' ';
}
int main() {
    insert(-1,0);
    insert(0, 1);
    insert(0, 2);
    insert(1, 3);
    insert(1, 4);
    pre_order(0);
    puts("");
    post_order(0);
}
