//
// Created by Gaurav Kesh Roushan on 04/01/24.

#include <iostream>
using namespace std;

void pattern1(int n) {
    for (int i = 0; i < n; i++) {
        cout << "****\n";
    }
}
void pattern2(int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << "*";
        cout << "\n";
    }
}
void pattern3(int n) {
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j < i; j++)
            cout << j;
//            cout<<j;
        cout << "\n";
    }

}
void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << i;
        }
        cout << "\n";
    }

}
void pattern5(int n) {
    for (int i = 5; i--;) {
        for (int j = i + 1; j--;) {
            cout << "*";
        }
        cout << "\n";
    }
}
void pattern6(int n) {
    for (int i = n + 1; i--;) {
        for (int j = i; j--;)
            cout << j + 1;
//            cout<<j;
        cout << "\n";
    }

}
void pattern7(int n) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        };
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        };
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        };
        cout << "\n";
    };

};
void pattern8(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
            cout << "*";
        }
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "\n";
    }
}
void pattern9(int n) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        };
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        };
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        };
        cout << "\n";
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
            cout << "*";
        }
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "\n";
    }
}
void pattern10(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
void pattern11(int n) {
    int start = 1;
    for (int i = 0; i <=n; i++) {
        if(i%2==0) start = 1;
        else start = 0;
        for (int j = 0; j <i;j++) {
            cout<<start;
            start = 1-start;
        }
        cout<<endl;

    };
}
void pattern12(int n){
    int space = 2*(n-1);
    for (int i = 1; i <= n; i++) {
        //number
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        //space
        for(int l =1;l<=space;l++){
            cout<<" ";
        }
        for (int k = i; k >=1;k--) {
            cout<<k;
        }
        cout<<endl;
        space -=2;
    }
}
void pattern13(int n){
    int num  =1;
    for (int i = 0; i <n ;i++) {
        for (int j = 0; j <=i ; ++j) {
            cout<<num<<" ";
            num = num +1;
        }
        cout<<endl;
    }
}
void pattern14(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << char(65 + j); // to get character alphabets
        }
        cout << "\n";
    }

}
void pattern15(int n) {
    int l = n;
    for (int i = 0; i < l; i++) {
        int f = n;
        for (int j = 0; j < f; j++) {
            cout << char(65 + j); // to get character alphabets
        }
        f = n--;
        cout << "\n";
    }
}
void pattern16(int n){
    int l = n;
    for (int i = 0; i<=l; i++){
        char ch = 'A'+i;
        for (int j = 0; j <= i; j++) {
            cout<<ch<<" ";; // to get character alphabets
        }
        cout << "\n";
    }
}
void pattern17(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        };
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for (int j = 1; j <= 2 * i + 1; j++) {
            cout<<ch;
            if(j<=breakpoint) ch++;
            else ch--;
        };
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        };
        cout << "\n";
    };

};
void pattern18(int n){
    char ch = 'E';
    for (int i = 0; i <n; i++) {
        for (int j =i; j>=0;j--) {
            char k = ch-j;
            cout<<k<<" ";
        }
        cout<<endl;
    }
}

//main function

int main() {
    int a;
    cout << "Enter the limit:- ";
    cin >> a;
    pattern18(a);
    return 0;
}

