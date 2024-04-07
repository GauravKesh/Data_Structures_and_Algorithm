//
// Created by Gaurav Kesh Roushan on 30/01/24.
//

#include <iostream>
#include <map>

using namespace std;

void numHashing() {
    // storing data in array
    int n;
    cout << "Enter Size:- ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i << " element of array :- ";
        cin >> arr[i];
    }

    // precompute
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
        // here the array element will be considered as a index of heap
        // whenever the same number is repeated
        // it'll increase the value of index of number with 1;
        hash[arr[i]] += 1;


    // now checking the data multiple occurrence
    int q;
    cout << "Enter the length of queue you want to check:-";
    cin >> q;
    while (q--) {
        int num;
        cout << "Enter Number to check:-";
        cin >> num;
        //fetching
        cout << hash[num] << endl;
    }
}

void charHashing() {
    // storing string
    string s;
    cout << "Enter the string ";
    cin >> s;

    // precomputing
    int heap[13] = {0};
    for (int i = 0; i < s.size(); i++) {
        heap[s[i] - 'a']++;
    }


    int q;
    cout << "check number times :- ";
    cin >> q;
    while (q--) {
        char ch;
        cout << "Enter character to check:-";
        cin >> ch;
        cout << endl << heap[ch - 'a'] << endl;

    }

}

void characterHeap() {
    // can be used to check how many times a
    // character is repeated in given string

    // taking input from user or declaring a string

    string str;
    cout << "Enter the string : -";
    cin >> str;

    // pre  computation;

    //declaring an heap for storing
    // occurrence 256 character;
    int heap[256] = {0};
    for (int i = 0; i < str.size(); ++i) {
        heap[str[i]]++;
    }
    // checking
    int q;
    cout << "Enter how many times you want to check :- ";
    cin >> q;


    while (q--) {
        char ch;
        cout << "Enter the 'character' you want to check :- ";
        cin >> ch;
        cout << heap[ch] << endl;
    }
}

// hashing 1e9,8,7

void largeIntHash() {
    int n;
    cout << "Enter the size of array :- ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of " << i + 1 << " element :- ";
        cin >> arr[i];

    }
    // pre map
    map<int, int> mapp;
    for (int i = 0; i < n; i++) {
        mapp[arr[i]]++;

    }
    for (auto it: mapp) {
        cout << it.first << "->" << it.second << endl;
    }

    //fetch
    int q;
    cout << "check number times :- ";
    cin >> q;
    while (q--) {
        int num;
        cout << "Enter character to check:-";
        cin >> num;
        cout << endl << mapp[num] << endl;

    }
}

void highLowFreq() {
    int n;
    cout << "Enter the size of array :- ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of " << i + 1 << " element :- ";
        cin >> arr[i];
    }
    // pre map
    map<int, int> mapp;
    for (int i = 0; i < n; i++) {
        mapp[arr[i]]++;

    }
    int maxElement; int maxFreq =0;
    int minElement; int minFreq =0;

    for (auto it: mapp) {
        int count =it.second;
        int element =it.first;

        if(count>maxFreq) {
            maxFreq = count;
            maxElement = element;
        }
        if(count<maxElement){
            minFreq = count;
            minElement = element;
        }
    }
    cout<<"\nElement "<<maxElement<<" with highest occurrence "<<maxFreq<<endl;
    cout<<"Element "<<minElement<<" with lowest occurrence "<<minFreq<<endl;



    // check high freq


//
//    //fetch
//    int q;
//    cout << "check number times :- ";
//    cin >> q;
//    while (q--) {
//        int num;
//        cout << "Enter character to check:-";
//        cin >> num;
//        cout << endl << mapp[num] << endl;
//    }


}

int main() {
//    numHashing();
//    charHashing();
//    characterHeap();
//    largeIntHash();
    highLowFreq();
    return 0;



}
