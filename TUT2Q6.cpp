//6(a)
#include <iostream>
using namespace std;

struct Element { int i,j,x; };
struct Sparse {
    int m,n,num;
    Element *e;
};

Sparse* transpose(Sparse *s) {
    Sparse* t = new Sparse;
    t->m=s->n; t->n=s->m; t->num=s->num;
    t->e=new Element[s->num];
    int k=0;
    for(int col=0; col<s->n; col++){
        for(int i=0;i<s->num;i++){
            if(s->e[i].j==col){
                t->e[k].i=s->e[i].j;
                t->e[k].j=s->e[i].i;
                t->e[k++].x=s->e[i].x;
            }
        }
    }
    return t;
}

int main(){
    Sparse s;
    s.m=3; s.n=3; s.num=3;
    s.e=new Element[s.num];
    s.e[0]={0,0,5}; s.e[1]={1,2,8}; s.e[2]={2,1,6};
    Sparse* t=transpose(&s);
    for(int i=0;i<t->num;i++)
        cout<<t->e[i].i<<" "<<t->e[i].j<<" "<<t->e[i].x<<endl;
    return 0;
}

//6(b)
#include <iostream>
using namespace std;

struct Element { int i,j,x; };
struct Sparse {
    int m,n,num;
    Element *e;
};

Sparse* add(Sparse *s1,Sparse *s2){
    if(s1->m!=s2->m || s1->n!=s2->n) return nullptr;
    Sparse* sum=new Sparse;
    sum->m=s1->m; sum->n=s1->n;
    sum->e=new Element[s1->num+s2->num];
    int i=0,j=0,k=0;
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i<s2->e[j].i || (s1->e[i].i==s2->e[j].i && s1->e[i].j<s2->e[j].j))
            sum->e[k++]=s1->e[i++];
        else if(s2->e[j].i<s1->e[i].i || (s2->e[j].i==s1->e[i].i && s2->e[j].j<s1->e[i].j))
            sum->e[k++]=s2->e[j++];
        else {
            sum->e[k]=s1->e[i]; sum->e[k++].x=s1->e[i++].x+s2->e[j++].x;
        }
    }
    while(i<s1->num) sum->e[k++]=s1->e[i++];
    while(j<s2->num) sum->e[k++]=s2->e[j++];
    sum->num=k;
    return sum;
}

int main(){
    Sparse s1,s2;
    s1.m=s2.m=3; s1.n=s2.n=3;
    s1.num=2; s2.num=2;
    s1.e=new Element[s1.num]; s2.e=new Element[s2.num];
    s1.e[0]={0,0,5}; s1.e[1]={1,2,8};
    s2.e[0]={0,0,3}; s2.e[1]={2,1,6};
    Sparse* sum=add(&s1,&s2);
    for(int i=0;i<sum->num;i++)
        cout<<sum->e[i].i<<" "<<sum->e[i].j<<" "<<sum->e[i].x<<endl;
    return 0;
}

//6(c)
#include <iostream>
#include <vector>
using namespace std;

struct Element { int i,j,x; };
struct Sparse {
    int m,n,num;
    Element *e;
};

Sparse* multiply(Sparse *s1,Sparse *s2){
    if(s1->n!=s2->m) return nullptr;
    vector<Element> res;
    for(int i=0;i<s1->num;i++){
        for(int j=0;j<s2->num;j++){
            if(s1->e[i].j==s2->e[j].i){
                res.push_back({s1->e[i].i,s2->e[j].j,s1->e[i].x*s2->e[j].x});
            }
        }
    }
    Sparse* prod=new Sparse;
    prod->m=s1->m; prod->n=s2->n; prod->num=res.size();
    prod->e=new Element[res.size()];
    for(int i=0;i<res.size();i++) prod->e[i]=res[i];
    return prod;
}

int main(){
    Sparse s1,s2;
    s1.m=2; s1.n=2; s1.num=2;
    s2.m=2; s2.n=2; s2.num=2;
    s1.e=new Element[s1.num]; s2.e=new Element[s2.num];
    s1.e[0]={0,0,2}; s1.e[1]={1,1,3};
    s2.e[0]={0,0,4}; s2.e[1]={1,1,5};
    Sparse* prod=multiply(&s1,&s2);
    for(int i=0;i<prod->num;i++)
        cout<<prod->e[i].i<<" "<<prod->e[i].j<<" "<<prod->e[i].x<<endl;
    return 0;
}
