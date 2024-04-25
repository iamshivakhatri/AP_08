#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <forward_list>

/**
 Shiva Khatri
 CSC 402
 DR GARY
 Programming Assignment 08
 */

using namespace std;

// Part A - Heap Sort using priority_queue
void heapSort(const  string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath <<  endl;
        return;
    }

    priority_queue<double> pq;
    double value;
    while (file >> value) {
        pq.push(value);
    }


    while (!pq.empty()) {
        cout << pq.top() <<  endl;
        pq.pop();
    }
}

// Part B - Multisets and sets
void countNumbers(const  string& filePath) {
       ifstream file(filePath);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filePath <<  endl;
            return;
        }

        set<int> mySet;
        multiset<int> myMultiSet;

        int num;
        while (file >> num) {
            mySet.insert(num);
            myMultiSet.insert(num);
        }


        for (int i = 1; i <= 20; ++i) {
            cout << "Count of Set " << i << " is: " << mySet.count(i)
                      << " Count of Multiset " << i << " is: " << myMultiSet.count(i) <<  endl;
        }
    }

// Part C - Forward List and remove_if()
void processForwardList(const string& filePath) {
    ifstream file(filePath);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    forward_list<int> myList;
    int num;
    while (file >> num) {
        myList.push_front(num); // Inserting at the front
    }

    cout << "\nInitial Forward List Contents" << endl;
    for (int n : myList) {
        cout << n << endl;
    }
    cout << endl;

    // Remove multiples of 5
    myList.remove_if([](int x) { return x % 5 == 0; });

    cout << "After removing multiples of 5:" << endl;
    for (int n : myList) {
        cout << n << endl;
    }
    cout << endl;

    // Remove all instances of 99
    myList.remove(99);

    // Sort the list
    myList.sort();

    cout << "Sorted list after removing 99:" << endl;
    for (int n : myList) {
        cout << n << endl;
    }
    cout << endl;
}

// Part D - Maps and Multimaps
void mapOperations(const  string& filePath) {
         ifstream file(filePath);
        if (!file.is_open()) {
             cerr << "Error opening file: " << filePath <<  endl;
            return;
        }

         map< string, int> myMap;
         multimap< string, int> myMultiMap;

         string name;
        int num;
        while (file >> name >> num) {
            myMap[name] = num;
            myMultiMap.insert( make_pair(name, num));
        }


         cout << "MAP Contents" <<  endl;
        for (const auto& entry : myMap) {
             cout << entry.first << " " << entry.second <<  endl;
        }

       cout << "\nMULTIMAP Contents" <<  endl;
        for (const auto& entry : myMultiMap) {
            cout << entry.first << " " << entry.second << endl;
        }
    }

class myClass {
public:
    string ID;
    int DEPT;

    // Constructor
    myClass(const string& id, int dept) : ID(id), DEPT(dept) {}

    // Overloading < operator for sorting
    bool operator<(const myClass& other) const {
        if (ID == other.ID) {
            return DEPT < other.DEPT;
        }
        return ID < other.ID;
    }

    // Overloading == operator for uniqueness
    bool operator==(const myClass& other) const {
        return (ID == other.ID && DEPT == other.DEPT);
    }
};

void processList(list<myClass>& myList, const string& filePath) {
    ifstream file(filePath);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    string id;
    int dept;
    while (getline(file, id)  && file >> dept) {
        myList.push_back(myClass(id, dept));
        // Consume the newline character left in the input stream
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Sorting the list
    myList.sort();

    cout << "\nSORTED List:" << endl;
    for (const auto& obj : myList) {
        cout << obj.ID << " " << obj.DEPT << endl;
    }

    // Removing duplicate objects
    myList.unique();

    cout << "\nList WITHOUT DUPLICATES:" << endl;
    for (const auto& obj : myList) {
        cout << obj.ID << " " << obj.DEPT << endl;
    }
}


int main() {
     string filePath;
     list<myClass> myList;


    cout << "\nPART A. - HEAP SORT\n" <<  endl;
    cout << "Please enter a path for the next data file: ";
     cin >> filePath;
    heapSort(filePath);

     cout << "\nPART B. Sets and Multisets\n" <<  endl;
     cout << "Please enter a path for the next data file: ";
     cin >> filePath;
    countNumbers(filePath);


    cout << "\nPART C. Forward Lists\n" <<  endl;
     cout << "Please enter a path for the next data file: ";
     cin >> filePath;
    processForwardList(filePath);

    cout << "\nPART D. Maps and Multimaps\n " <<  endl;
     cout << "Please enter a path for the next data file: ";
     cin >> filePath;
     mapOperations(filePath);

    cout << "\nPART E. LISTS of user-defined objects\n " <<  endl;
    cout << "Please enter a path for the next data file: ";
    cin >> filePath;
    processList(myList, filePath);

    return 0;
}
