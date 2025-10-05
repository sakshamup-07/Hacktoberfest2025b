#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    vector<vector<int>> m;
public:
    Matrix(int r, int c) : m(r, vector<int>(c,0)) {}
    void set(int i,int j,int val){m[i][j]=val;}
    int get(int i,int j) const {return m[i][j];}
    int rows() const {return m.size();}
    int cols() const {return m[0].size();}
    Matrix operator+(const Matrix& o) {
        Matrix res(rows(), cols());
        for(int i=0;i<rows();i++)
            for(int j=0;j<cols();j++)
                res.set(i,j,m[i][j]+o.get(i,j));
        return res;
    }
    Matrix operator*(const Matrix& o) {
        Matrix res(rows(), o.cols());
        for(int i=0;i<rows();i++)
            for(int j=0;j<o.cols();j++)
                for(int k=0;k<cols();k++)
                    res.set(i,j, res.get(i,j)+m[i][k]*o.get(k,j));
        return res;
    }
    void print() {
        for(auto &r:m){for(auto v:r) cout<<v<<" "; cout<<"\n";}
    }
};

int main() {
    Matrix A(2,2), B(2,2);
    A.set(0,0,1); A.set(0,1,2);
    A.set(1,0,3); A.set(1,1,4);
    B.set(0,0,5); B.set(0,1,6);
    B.set(1,0,7); B.set(1,1,8);
    cout<<"A+B:\n"; (A+B).print();
    cout<<"A*B:\n"; (A*B).print();
}
