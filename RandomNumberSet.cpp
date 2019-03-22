#include "RandomNumberSet.h"

RandomNumberSet::RandomNumberSet(){
    myBitSet.reset();
    range = 39;
}

RandomNumberSet::RandomNumberSet(int N){
    if(N > 999){
        cout << " ERROR : Cannot construct with range exceeding 1-999 but got N = " << N << ". Terminating program" <<  endl;
        exit(EXIT_FAILURE);
    }
    myBitSet.reset();
    range = N;
}

void RandomNumberSet::reset(){
    myBitSet.reset();
}

bool RandomNumberSet::set(int num){
    if(!((num >= 1) && (num <= range))){
        
        cout << "Error : number not in range initialized with. num = " << num << "range = 1 to " << range << endl;
        return false;
    }
    // Max range is assumed here based on the assignment description where , the numbers are to be printed within 3 
    // spaces. So assuming maximum number is 999
    if(!((num >= 1) && (num <= 999))){
    
        cout << "Error : number not in max range. num = " << num << "range = 1 to 999" << endl;
        return false;
    }

    if (size() == 5){
        cout << "Already 5 elements stored . set(" << num << ") failed " << endl;
        return false;
    }
    if(myBitSet[num - 1] == false){
        
        myBitSet[num - 1] = true;
        return true;
    }else{

        cout << "Number " << num << "already is stored . set() failed " << endl; 
        return false;
    }
}

int RandomNumberSet::size(){
    int size = 0;
    for(int i = 0; i < range; i++){
        if(myBitSet[i] == true){
            size++;
        }
    }
    return size;
}

int RandomNumberSet::operator -(RandomNumberSet & rns){
    
    bitset<999> localBitSet;
    int difference = 0;
    // This should happen in constant time since the size of bitset is fixed
    localBitSet = rns.getBitSet() ^ myBitSet;

    int localRange = max(rns.getRange(), range);

    // Couldn't come up with linear complexity to search for set bits.
    // Just making an optimization to just only look for range number of bits
    for(int i = 0; i < localRange; i++){
        if(localBitSet[i] == true){
            difference++;
        }
    }
    return difference;    
}

ostream& operator<<(ostream& os, const RandomNumberSet & rns)  
{  
    for(int i = 0; i < rns.range; i++){
        if(rns.myBitSet[i] == true){
            os.width(3);
            os << right << i + 1 ;
        }
    }
    os << endl;
    return os;  
}  

int main(){
    
    // Test code
    /*RandomNumberSet rs1(600);
    
    cout << "Setting rs1 " << endl;
    cout << rs1.set(501) << endl;
    cout << rs1.set(502) << endl;
    cout << rs1.set(503) << endl;
    cout << rs1.set(504) << endl;
    cout << rs1.set(505) << endl;
    cout << "rs1.size = " << endl;
    cout << rs1.size() << endl;

    RandomNumberSet rs2(999);
    cout << "Setting rs2 " << endl;
    cout << rs2.set(601) << endl;
    cout << rs2.set(602) << endl;
    cout << rs2.set(603) << endl;
    cout << rs2.set(604) << endl;
    cout << rs2.set(00) << endl;
    cout << rs2.set(11) << endl;
    cout << rs2.set(12) << endl;
    cout << rs2.set(13) << endl;
    cout << rs2.set(14) << endl;
    cout << rs2.set(30) << endl;
    cout << "rs2.size = " << endl;
    cout << rs2.size() << endl;

    cout << " differrence is " << endl;
    cout << rs1 - rs2 << endl;

    cout << " Displaying rs1 " << endl;
    cout << rs1;

    cout << " Displaying rs2 " << endl;
    cout << rs2;

    rs1.reset();
    rs2.reset();
    cout << "after reset " << endl; 
    cout << rs1 - rs2 << endl;
    cout << rs1.size() << endl;
    cout << rs2.size() << endl;*/
}
