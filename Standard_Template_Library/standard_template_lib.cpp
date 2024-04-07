//
// Created by Gaurav Kesh Roushan on 22/01/24.
//
#include <iostream>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

/// PAIR
void explainPair() {
    pair<int, int> p = {1, 2};
    cout << p.first;
    cout << endl;

    // for storing  pair in ARRAY

    pair<int, int> arr[] = {{1, 2},
                            {8, 9},
                            {7, 3}};
    cout << arr[1].second;
    cout << endl;

    // storing pair into a pair;

    pair<int, pair<int, int>> p1 = {1, {2, 4}};
    cout << p1.first << endl << p1.second.first;

}

/// VECTOR
/* Vector is  a  Dynamic */

void explainVector() {
    vector<int> v;
    v.push_back(3); // storing data in the vector;
    v.emplace_back(4); // storing data in vector;


    // we can also store pair in vector ;

//    vector<int,pair<int,int>>vPair;
//    vPair.push_back({1,2});
//    vPair.emplace_back(3,4);
    // storing the 100 value 5 times
    vector<int> vSize(5, 100);
    // designing the size of the vector
    vector<int> vSizen(5);
    vector<int> vSStore(5, 20);

    // copying the data from one vector to other vector;
    vector<int> vCopy(vSStore);


    // Now accessing the element from vector

    // using iterator

    // vector<dataType>::iterator variableNameForIterator = declaredVectorVariable.begin();
    // so this will point to the memory address of the vector element
    auto iit = vCopy.begin();

    /*
      "vector<dataType>::iterator variableNameForIterator" can be replaced with
      auto iteratorVariableName = declaredVectorVariable.begin();

      */

    iit++;
    // so to get the element form the memory address we need to use *(iteratorVariableName)
    cout << *(iit);

    iit += 2;
    cout << *(iit);
/*
    // pointing to the memory location of right  last stored element of the vector
    auto it = vCopy.end();

    // This points to the memory location of the left of first element stored  in the vector;
    rend --->> ReverseEnd
    auto it = vCopy.rend();

    // pointing to the pointer to last stored element of the vector
    // We can use this to access element  in reverse direction ;
    rbegin ---->> ReverseBegin
    auto it = vCopy.rbegin();

    OR USE

    cout<<vCopy[0]; or
    cout<<v.at(0);

 */

    for(vector<int>::iterator it=vCopy.begin();it!=vCopy.end();it++){
        cout<<*(it)<<endl;
    }

    /*
     * // using auto
     * auto assign the datatype according the data is stored
     * means if it's a int then it will automatically assign the datatype int to vector and in iterator
     *
    */
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<endl;
    }

    // Here this will directly point to element not to their memory location
    for(auto it:v){
        cout<<(it)<<endl;
    }

}

void vectorErase(){
    // erase() – it is used to delete a specific element
    // StartPoint = v2.begin()+n;
    // EndPoint = v2.begin+n
    //  v1.erase("StartPoint","EndPoint");
    vector<int> v1 = {1,2,3,4,5,6};

    // for removing single element
    v1.erase(v1.begin()+3);

    // for removing multiple stored elements from v1;
    v1.erase(v1.begin(),v1.begin()+4);


    for(auto i:v1){
        cout<<i<<endl;
    }

}

void vectorInsert(){
    vector<int> v = {1,2,3,4,5,6};
    for(auto i:v){
        cout<<i<<endl;
    }
    cout<<"@@@@\n";

    // inserting only one element in beginning
    v.insert(v.begin(),10);

    cout<<"@@@@\n";

    // Inserting  Elements at specific index;
    v.insert(v.begin()+1,100);

    cout<<"@@@@\n";

    // inserting same  multiple elements;
    //v.insert(start position, no. of times, the number);
    v.insert(v.begin()+2,2,15);

    for(auto i:v) {
        cout << i << endl;
    }

}

void vectorCopyInsert(){
    vector<int> v = {1,2,3,4,5,6};
    for(auto i:v){
        cout<<i<<endl;
    }
    vector<int> v1(2,30);

    // copying the one vector to another using insert function;
    v.insert(v.begin(),v1.begin(),v1.end());

    for(auto i:v){
        cout<<i<<endl;
    }
}

void vectorSize(){
    // gives the size of the array
    vector<int> v = {1,2,3,4,5,6};
    cout<<v.size();
    // 6
}

void vectorPopBack(){
    vector<int> v = {1,2,3,4,5,6};
    //removes the last element of the array
    v.pop_back();

}

void vectorSwap(){
    vector<int> v1 = {1,2,3,};
    vector<int> v2 = {4,3,2};
    // it'll interchange the array elemnts
    v1.swap(v2);
   // v1 --> {4,3,2} ; v2 --> {1,2,3}
}

void vectorClear(){
    vector<int> v = {1,2,3,4,5,6};
    v.clear();
    // it 'll erase the all elements of the given vector and make an empty vector
}

void vectorEmpty(){
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v1 = {1};
    vector<int> v2 = {};

    cout<<v.empty();  //False
    cout<<v1.empty();  //False
    cout<<v2.empty(); //True

}

/// List
void explainList(){
    list<int> l;

    // add element in front
    l.push_back(2);
    // l = {2}

    // add element in last;
    l.emplace_back(6);
    // l = {2,4};

    // insert the element in beginning
    l.push_front(5);
    // l = {5,2,4}

    /// rest function is similar to the function of VECTOR
    ///begin, end,swap,clear,size,rbegin,rend,insert

}

/// Deque
void explainDeque(){
    deque<int> dq ;

    // add element in front
    dq.push_back(2);
    // dq = {2}

    // add element in last;
    dq.emplace_back(6);
    // dq = {2,4};

    // insert the element in beginning
    dq.push_front(5);
    // dq = {5,2,4}

    // removes last element
    dq.pop_back();
    // dq = {5,2}

    // removes first element from beginning
    dq.pop_front();
    // d1 = {2};

    /// rest function is similar to the function of VECTOR
    ///begin, end,swap,clear,size,rbegin,rend,insert



}

/// Stack
void explainStack(){
    //LIFO --> LAST IN FIRST OUT;
    // push, pop, top
    stack<int> s;
    s.push(1); //s = {1}
    s.push(2); //s = {2,1}
    s.push(3); //s = {3,2,1}
    s.push(4); //s = {4,3,2,1}
    s.emplace(4); //s = {5,4,3,2,1}  // same as push

    /// output will be 5;
    s.top();

    /// it'll remove the last pushed element in the stack
    s.pop();
     //s = {4,3,2,1};

     /// shows the size of the STACK
     int sizeStack = s.size();
     cout<<sizeStack<<endl;

    bool c = s.empty(); // will return true/1 or false/0
    cout<<c<<endl;

    stack<int> s1 ;
    stack<int> s2;
    s1.swap(s2);
    // s1 = {4,4,3} && s2 = {4,4,3}

}

/// Queue
void explainQueue(){
    //FIFO - First In First Out
    queue<int> q;
    q.push(1); //q ={1}
    q.push(2); //q={1,2}
    q.push(3); //q={1,2,3}
    q.emplace(4); //q={1,2,3,4}

    // this will change the last element value to 9 and don't print
    q.back()+=5;

    // only using q.back will return the last element for now will be 9
    cout<<q.back(); // prints 9;

    // print the first element;
    cout<<q.front(); // prints 1;

    // removes the first entered element
    q.pop();

    /// size, swap,empty same as stack


}

/// Priority_Queue
void explainPriorityQueue(){
    ///MAXIMUM HEAP
            // it keeps the largest element on top of all ;
    priority_queue<int> pq;
    pq.push(1); // pq = {1}
    pq.push(4); // pq = {4,1}
    pq.push(3); // pq = {4,3,1}
    pq.push(10); // pq = {10,4,3,1}
    pq.push(15); // pq = {15,10,4,3,2,1}
    pq.emplace(16); // pq = {16,15,,10,4,3,2,1}

    // returns the maximum value means the top one
    cout<<pq.top(); // 16

    pq.pop();  // now pq = {15,10,4,3,2,1}

    cout<<pq.top(); // 15

    /// size, swap, empty,  all same as stack or queue

    // ***************************************************** //

    ///MINIMUM HEAP
            // It keeps the smallest one on top
     priority_queue<int , vector<int>,greater<>> pqm;
    pqm.push(1); // pq = {1}
    pqm.push(4); // pq = {1,4}
    pqm.push(3); // pq = {1,3,4}
    pqm.push(0); // pq = {0,1,3,4}

    cout<<pqm.top(); // 0;

    pq.pop(); // pq = {1,3,4}

    cout<<pqm.top(); // 1;


}

/// SET
void explainSet(){
    // set only have unique elements
    // not linear
    //
    set<int> s;
    s.insert(2); //s = {2};
    s.emplace(1); //s={1,2};
    s.insert(4); //s ={1,2,4};
    s.insert(5); //s ={1,2,4,5};
    s.insert(6); //s ={1,2,4,5,6};


    /*

     * functionality in vector can also be used also , that only increases
     efficiency
     * begin(),empty(),swap(),erase,rbegin(),rend(),
     * size(), are same as above

    */

    // finding element from set

    //s ={1,2,4,5,6};
    auto is = s.find(1);

    auto iss = s.find(1);
    auto issh = s.find(7); // return right after last element

    auto ir = s.find(2);
    //s ={1,2,4,5,6};
    s.erase(ir);
    //s ={1,4,5,6};

    /// count says number of times the element occurred in the set
    // if exist say 1 and not says 0;
    //s ={1,4,5,6};
    cout<<s.count(4); /// returns 1;
    cout<<s.count(7); /// return 0;
    s.erase(6); /// we can also pass element to delete rather than address too;
    //s ={1,4,5};
    set<int> s1;
    s1 = {1,2,3,4,5,6,7,8};
    auto it1 = s1.find(2);
    auto it2 = s1.find(6);
    s1.erase(it1,it2);
    // s1 = {1,6,7,8}

    /// Upper_Bound() and Lower_Bound() function works same way asin vector it does

    auto itt1 = s1.lower_bound(6);
    auto itt2 = s1.upper_bound(8);

}

void explainMultipleSet(){
    // it can store multiple occurrence of the same element ;
    // it's store in sorted way
    // no uniqueness like set

    multiset<int> ms;
    ms.insert(1); // ms = {1};
    ms.insert(1); // ms = {1,1};
    ms.insert(2); // ms = {1,1,2};
    ms.insert(3); // ms = {1,1,2,3};
    ms.insert(3); // ms = {1,1,2,3,3};
    ms.insert(4); // ms = {1,1,2,3,3,4};

    //  erase

    ms.erase(3); // it'll increase all the occurring  elements passed to erase

    // if address is passed so the specific element is only deleted

    auto it = ms.find(1);
    ms.erase(it); // erases only first occurrence

//    ms.erase(ms.find(1),ms.find(1)+2);

    // all remaining functions are same





}

/// unordered_Set
void explainUnorderedSet(){
    /* lower_bound() and upper_bound() functions doesn't work
     * all other functions are same as it is like above
     * data is stored in ay order there is no specific way to store data
     * Randomized order
     * it have better complexity than set in most cases except some when
       collision happens
     * */

    unordered_set<int> ust;


}

/// Map
void explainMap(){
    // stores data in form of a pair of key and value;
    // key is always unique
    // data stored in sorted order


    map<int ,int> m;
    map<pair<int,int> ,int> mkp; // key in form of pair and value in form of number or digits
    map<int ,pair<int,int>> mvp; // key in form of digit and value in form of pair
    m.insert({1,2}); // inserting value 2 at key 1;

    m[2] = 3;  // adding a value at key 2
    m.insert({7,8});

    mkp[{10,14}] = 20; // this will store key as a pair and value as a single number

    cout<<mkp[{10,14}]<<endl; // value = 20

    /// for storing value as a pair and key as a number;
    mvp.insert({1,{2,3}});
    cout<<mvp[1].first<<endl;



    cout<<m[1];
    cout<<endl;
    cout<<m[2];
    cout<<endl;
    cout<<m[3]; // returns 0 if no data is stored
    cout<<endl;



    for (auto it: m){
        cout<<"\tkey => "<<it.first<<" && "<<"value => "<<it.second<<endl;
    }

    auto ite = m.find(2);
    cout<< ite->second;
    auto itU = m.upper_bound(2);
    auto itL = m.lower_bound(2);

    // rest of the function are same

}

/// MultiMap
void multiMap(){
    // it stores same keys duplicate
    // sorted order
    // map[key] not valid function
    // all other function valid

}

/// UnOrderedMap
void explainUnorderedMap(){
    //same as set an unordered set;
    // unique keys
    // not sorted
}

/// custom comparison
bool compa(pair<int,int> p1,pair<int,int> p2){
    /// for ascending of value
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    if(p1.first>p2.first) return true;
    return false;
}
/// custom comparison
bool compd(pair<int,int> p1,pair<int,int> p2){
    /// for ascending of value
    if(p1.second<p2.second) return false;
    if(p1.second>p2.second) return true;
    if(p1.first>p2.first) return true;
    return true;
}

void sortArrayUsingStl(){
    vector<int> arr ;

    /// it'll sort the given array in ascending order using STL
    /// sort(start_point,end_point);
    arr={200,30,2,7,1,10,11,9,8};

    auto a = arr.begin(); // start point
    auto b = arr.end(); // emd point

    /// sort(a+n,a+n);
    /// n must be any number for some specific element sort
    sort(a+0,a+4); ///2<7<30<200<1<10<11<9<8<
    for(auto it:arr){
        ///1<2<7<8<9<10<11<30<200<
        cout<<it<<"<";
    }

    cout<<endl;

    sort(a,b);
    for(auto it:arr){
        cout<<it<<"<";
    }

    /// sorting in descending order
    /// sort((start_point,end_point,greater());
    sort(a,b,greater());
    cout<<endl;
    for(auto it:arr){
        cout<<it<<"<";
    }

    /// PAIR ARRAY SORTING
    pair<int,int> arrt[]={{1,9},{3,4},{7,9},{10,5},{12,2},{11,6}};

    // first sort it in ascending order  comparing second value;
    //if second element is same
    // then sort it by comparing first element
    cout<<endl;
    // ascending
    sort(arrt,arrt+5,compa);
    for(auto i : arrt){
        cout<<"{"<<i.first<<","<<i.second<<"}"<<"<";
    }
    // descending
    sort(arrt,arrt+5,compd);
    cout<<endl;
    for(auto i : arrt){
        cout<<"{"<<i.first<<","<<i.second<<"}"<<"<";
    }

    int num = 7;
    int cun = __builtin_popcount(num);
    cout<<endl<<cun;
    long long lnu = 762387468723864723;
    int cul = __builtin_popcountll(lnu);
    cout<<endl<<cul<<endl;

    // getting maximum possible pairs if the digits;
    string s = "12463";
    sort(s.begin(),s.end());
    do{
        cout<<s<<" ";
    } while (next_permutation(s.begin(),s.end()));

    // gives maximum number from the array
    int maxi = *(max_element(a,b));
    cout<<endl<<maxi;


}


int main() {
    sortArrayUsingStl();

}