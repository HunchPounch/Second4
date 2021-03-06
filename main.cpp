#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include "CComplexVector.h"
#include "CFactory.h"
#include "CFactoryHori.h"
#include "CFactoryVert.h"
#include "CComplexVectorVert.h"
#include "CComplexVectorHori.h"
#include "test.h"
#include <iterator>
using namespace std;
typedef map<string, CFactory*> factory;

int Size(stringstream &sss){
int count1 = 0;
string word;
while (sss >> word)
        count1++;
    return count1;
}

int input(const string name, vector<CComplexVector*> &v, map<string, CFactory*> &factory){

ifstream fin(name);
string str;
int dim;
string type;
string fname;
int Re;
int Im;
int i=0;
while(getline(fin,str)){
    stringstream ss(str);
    stringstream sss(str);
    dim = (Size(sss) - 2)/2;
    istream_iterator<string> it;
    it = ss;
    if(it!=istream_iterator<string>()){
        type = (*it);
        ++it;
        CComplexVector *w = factory[type]->Create(dim, *it);
        ++it;
        i = 0;
        while(i<dim && it!=istream_iterator<string>()){
            Re = stoi(*it);
            ++it;
            Im = stoi(*it);
            w->Set_Re_Im(Re, Im, i);
            i++;
            ++it;
        }
        v.push_back(w);
    }
}
return 0;
}

int main()
{
    if(main_test() == 1){
        cout << "tests not passed" << endl << endl;
        return 1;
    }
    else cout << "tests passed" << endl << endl;
    string file_name;
    cout << "Please enter file name" << endl;
    cin >> file_name;
    map<string, CFactory*> factory;
    factory["Hori"] = new CFactoryHori;
    factory["Vert"] = new CFactoryVert;
    vector<CComplexVector*> v;
    input(file_name, v, factory);

    for(vector<CComplexVector*>::iterator it = v.begin(); it!=v.end(); ++it){
        (*it)->output();
    }
    for(vector<CComplexVector*>::iterator it = v.begin(); it!=v.end(); ++it){
        delete *it;
    }

    return 0;
}



