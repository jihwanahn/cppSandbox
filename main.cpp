#include <iostream>
#include <d3dx9math.h>


using namespace std;

typedef long long ll;

ll binpow(ll a, ll b) {
    ll res{ 1 };

    while (b > 0) {
        if (b & 1) res *= a;

        a = a * a;
        cout << "Before : " << b << endl;
        b >>= 1;
        cout << "After : " << b << endl;
    }

    return res;
}


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    
    // ll i = 2;
    // ll j = 8;
    //
    // cout << binpow(i, j) << endl;    
    // int a{ 1 };
    // int b{ 1 };
    // int bb{ 2 };
    // auto c = a & b;
    // auto d = a | bb;
    // cout << c << " " << d;

    D3DXVECTOR3 u{ 1.f, 0.f, 1.f };
    D3DXVECTOR3 v{ 0.f, 1.f, 0.f };

    // u == v ? cout << "Same Vector!!!" << endl : cout << "Diff Vector!!" << endl;
    
    // cout << D3DXVec3Length(&u) << endl;
    // D3DXVec3Normalize(&v, &u);

    // cout << v.x << " " << v.y << " " << v.z << endl;
    // cout << D3DXVec3Length(&v) << endl;

    D3DXVECTOR3 newU = u * 3;


	return 0;
}