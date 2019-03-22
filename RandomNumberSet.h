#include <stdio.h>
#include <bitset>
#include <iostream>
#include <stdlib.h> 
#include <algorithm>

using namespace std;

class RandomNumberSet {

    public :
        RandomNumberSet();
        RandomNumberSet(int N);
        void reset();
        bool set(int num);
        int size();
        int operator -(RandomNumberSet & rns);
        friend ostream& operator<<(ostream& os, const RandomNumberSet & rns);  
        int getRange(){return range;}
        bitset<999> & getBitSet(){return myBitSet;}

    private:
        // Max range is assumed here based on the assignment description where , the numbers are to be printed within 3 
        // spaces. So assuming maximum number is 999
        bitset<999> myBitSet;
        int range;
};

