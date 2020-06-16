#include <iostream>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    return 0;
}
/*
input
5 1
2 9
4 8
10 9
15 2
19 1
output
11 19 -1 21 22 

Note
Consider the first sample.

The server will start to process first query at the moment 2 and will finish to process it at the moment 11.
At the moment 4 second query appears and proceeds to the queue.
At the moment 10 third query appears. However, the server is still busy with query 1, b = 1 and there is already query 2 pending in the queue, so third query is just rejected.
At the moment 11 server will finish to process first query and will take the second query from the queue.
At the moment 15 fourth query appears. As the server is currently busy it proceeds to the queue.
At the moment 19 two events occur simultaneously: server finishes to proceed the second query and the fifth query appears. As was said in the statement above, first server will finish to process the second query, then it will pick the fourth query from the queue and only then will the fifth query appear. As the queue is empty fifth query is proceed there.
Server finishes to process query number 4 at the moment 21. Query number 5 is picked from the queue.
Server finishes to process query number 5 at the moment 22.
*/
