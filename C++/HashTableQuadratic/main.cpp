// Assignment 6
// Matthew Lynn
// IDE: CLion by Jet Brains
    //Implement Hash table.
    //Pick 20 random words. Each word must be of different lengths, maximum length 8 and minimum length 3.
    //The words will be of letters a-zA-Z and the space character.
    //Insert them into a hash table.
    //You can use a library for only the hash function.
    //The collision resolution scheme should be open addressing - quadratic.
    //Initially the table size is 31. The program should increase the table size and rehash at load factor of .5
    //At the end print the total number of collisions you get.
//Submit your code.
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class hashy
{
private:
    struct item{
        string word;
    };

public:
    void emptyTable();
    int Hash(string key);
    void AddItem(string word);
    void QuadProbe(int index, string word);
    int isPrime(int val);
    int nextPrime(int val);
    void rehash();
    int collision = 0;
    float loadFactor = 0;
    int reHashes = 0;
    int count = 0;
//    cout << "count = " << count << endl; // For debugging
    void PrintTable();
    int tableSize = 31; // initial table size
    static const int radix = 53; // 26 lower + 26 upper + 1 space = 53 radix
    item* HashTable = new item[tableSize];
    float computeLoadFactor();
};

// computes the load factor
float hashy::computeLoadFactor()
{
    int loads = 0;
    for (int i = 0; i  < tableSize; i++)
        if (HashTable[i].word != "empty")
        {
            loads++;
        }
    loadFactor = (float)loads / tableSize;
    cout << "current load factor is " << loadFactor << endl;
    return loadFactor;
}

// function to convert our strings into integers
int hashy::Hash(string key)
{
    int hash = 0;
    int index;

    for (char i : key) {
        hash = radix * hash + (int) i;
//        cout << "hash is " << hash << endl; // check if hash goes negative
    }

    index = hash % tableSize;
    if (index < 0) index = abs(index); // fixes cases when index goes negative
    return index;
}

// empties our table, to be used at the beginning and only once
void hashy::emptyTable()
{
    // initialize all indices to NULL
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i].word = "empty";
    }
}

// function to add words to our table
void hashy::AddItem(string word)
{
    // I think AddItem can go here and make rehash shorter as well as auto initialize values to null
    // Need an if condition for load factor == 0
    if (loadFactor == 0) emptyTable();
    if (loadFactor >= 0.5)
    {
        rehash();
        AddItem(word);
    }
    else
    {
        int index = Hash(word);
        count++; cout << "index = " << index << endl;
        if(HashTable[index].word == "empty")
        {
            HashTable[index].word = word;
            computeLoadFactor();
        }
        else
        {
            QuadProbe(index, word);
        }
    }
}

// Quadratically leaps though the table til it find an empty spot
void hashy::QuadProbe(int index, string word)
{
    int leap = 1; // start at 1 because the 0th leap is accounted for in AddItem
    int hashVal = index;

    while (HashTable[hashVal].word != "empty") // prime tableSize + load factor helps us negate making stopping criteria
    {
        hashVal = index + leap*leap % tableSize;
//        hashVal = (hashVal + 2*index - 1) % tableSize;
//        cout << "leap = " << leap << " and collision = " << collision << endl;
        collision++;
        leap++;
    }
    HashTable[hashVal].word = word;
    cout << "Total leaps for " << HashTable[hashVal].word << " is " << leap;
    cout << " and current collisions is " << collision << endl;
    computeLoadFactor();
}

// Checks if our new table size is prime
int hashy::isPrime(int val) {
    bool flag=true;
    for (int i = 2; i <= (float)val/2; i++)
    {if (val % i == 0) {flag = false; break;}}
    return flag;
}

// finds the next available prime number
int hashy::nextPrime(int val){
    while (true)
    {
        val++;
        if (isPrime(val)) return val;
    }
}

// counts number of rehashes and rehashes to a new table of a bigger size
void hashy::rehash()
{
    reHashes++;
    loadFactor = 0;
    int newSize = nextPrime(tableSize * 2);

    cout << "Resizing table from " << tableSize << " to " << newSize << "." << endl;

    // the ol switcharooni
    int oldSize = tableSize;
    tableSize = newSize;
    item* newTable = new item[tableSize];
    item* oldTable = this->HashTable;
    this->HashTable = newTable;

    // initialize all indices to NULL
//    for(int i = 0; i < tableSize; i++)
//    {
//        HashTable[i].word = "empty";
//    }

    // re-add previous words into new hash table
    for (int i = 0; i  < oldSize; i++)
        if (oldTable[i].word != "empty")
        {
            AddItem(oldTable[i].word);
        }
}

// Print out of end result information and positions of each word in table
void hashy::PrintTable()
{
    cout << "HashTable Contents with:\n";
    cout << collision << " collisions\n";
    cout << reHashes << " rehashes\n";
    cout << loadFactor << " final load factor\n";
    cout << tableSize << " final table size\n";
    cout << "--------------------\n";
    for (int i = 0; i  < tableSize; i++)
        if (HashTable[i].word != "empty")
        {
            cout << HashTable[i].word << endl;
        }
}

// Grader: You can simply change out the words if you like
int main()
{
    hashy feet;
//    feet.emptyTable(); // Need to manually do this in the beginning for mine
    feet.AddItem("lucky");
    feet.AddItem("Grip");
    feet.AddItem("ykcul");
    feet.AddItem("Carry");
    feet.AddItem("HolyMoly");
    feet.AddItem("Opposite");
    feet.AddItem("magenta");
    feet.AddItem("Lace");
    feet.AddItem("burst");
    feet.AddItem("Sniff");
    feet.AddItem("minute");
    feet.AddItem("Freezing");
    feet.AddItem("nebulous");
    feet.AddItem("Act");
    feet.AddItem("ziP Per");
    feet.AddItem("Sister");
    feet.AddItem("better");
    feet.AddItem("Re Use");
    feet.AddItem("surpass");
    feet.AddItem("Consign");
    feet.PrintTable();
}

