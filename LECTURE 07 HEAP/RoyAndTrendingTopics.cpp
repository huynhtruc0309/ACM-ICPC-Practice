#include <iostream>
using namespace std;

int main ()
{
    return 0;
}
/*
class Topic:
    def __init__(self, old_score, new_score, ID):
        self.old_score = old_score
        self.new_score = new_score
        self.ID = ID
        self.change = new_score - old_score
    def __lt__(self, others):
        if (self.change > others.change):
            return True
        else if (self.change == others.change):
            return self.ID > others.ID
        return False

    pq = priority Queue()
    n = int(input())
    for i in range(n):
        read(ID, old_score, p, l, c, s)
        new_score = p*50+e*5...
        pq.put(Topic (old_score, new_score, ID))
    for i in range(5):
        top = pq.get()
        print(top.ID, top.new_score)

    O(nlogn)
*/