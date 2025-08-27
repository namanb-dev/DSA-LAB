//5(a)
#include <iostream>
using namespace std;

class Diagonal {
    int *A, n;
public:
    Diagonal(int n) { this->n=n; A=new int[n]; }
    void set(int i,int j,int x){ if(i==j) A[i-1]=x; }
    int get(int i,int j){ return (i==j)?A[i-1]:0; }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Diagonal d(3);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9);
    d.display();
    return 0;
}


//5(b)
#include <iostream>
using namespace std;

class TriDiagonal {
    int *A, n;
public:
    TriDiagonal(int n){ this->n=n; A=new int[3*n-2]; }
    void set(int i,int j,int x){
        if(i-j==0) A[n-1+i-1]=x;
        else if(i-j==1) A[i-2]=x;
        else if(j-i==1) A[2*n-1+i-1]=x;
    }
};

int main(){
    TriDiagonal t(4);
    t.set(1,1,5);
    t.set(2,1,2); t.set(2,2,6); t.set(2,3,7);
    return 0;
}

//5(c)
#include <iostream>
using namespace std;

class LowerTri {
    int *A, n;
public:
    LowerTri(int n){ this->n=n; A=new int[n*(n+1)/2]; }
    void set(int i,int j,int x){ if(i>=j) A[i*(i-1)/2+j-1]=x; }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j) cout<<A[i*(i-1)/2+j-1]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main(){
    LowerTri l(3);
    l.set(1,1,5); l.set(2,1,3); l.set(2,2,8);
    l.set(3,1,4); l.set(3,2,6); l.set(3,3,9);
    l.display();
    return 0;
}

//5(d)
#include <iostream>
using namespace std;

class UpperTri {
    int *A, n;
public:
    UpperTri(int n){ this->n=n; A=new int[n*(n+1)/2]; }
    void set(int i,int j,int x){ if(i<=j) A[j*(j-1)/2+i-1]=x; }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j) cout<<A[j*(j-1)/2+i-1]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main(){
    UpperTri u(3);
    u.set(1,1,5); u.set(1,2,3); u.set(1,3,4);
    u.set(2,2,8); u.set(2,3,6);
    u.set(3,3,9);
    u.display();
    return 0;
}

//5(e)
#include <iostream>
using namespace std;

class Symmetric {
    int *A, n;
public:
    Symmetric(int n){ this->n=n; A=new int[n*(n+1)/2]; }
    void set(int i,int j,int x){ if(i>=j) A[i*(i-1)/2+j-1]=x; }
    int get(int i,int j){ return (i>=j)?A[i*(i-1)/2+j-1]:A[j*(j-1)/2+i-1]; }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Symmetric s(3);
    s.set(1,1,5); s.set(2,1,3); s.set(2,2,8);
    s.set(3,1,4); s.set(3,2,6); s.set(3,3,9);
    s.display();
    return 0;
}
