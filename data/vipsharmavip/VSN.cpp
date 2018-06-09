// copy From Here
// need for speed...
#include <bits/stdc++.h>
using namespace std;
// bad times...

//.............template...................
#define vimal
#ifdef vimal

#endif
#define boost ios::sync_with_stdio(0);cin.tie(0);
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
//.............template...................

//.............data...................
const int N = 100005; // 10^5
ld px, py, pz, qx, qy, qz, dx, dy, dz, cx, cy, cz, r;
//.............data...................

//.............functions...................
ld square(ld num){
    return num*num;
}
//.............functions...................

//.............main...................
int main(){
    boost;
    int t;
    cin >> t;
    while(t--){
        cin >> px >> py >> pz >> qx >> qy >> qz >> dx >> dy >> dz >> cx >> cy >> cz >> r;
        ld QPX = qx - px, QPY = qy - py, QPZ = qz - pz;
        ld PCX = px - cx, PCY = py - cy, PCZ = pz - cz;
        ld len = square(PCX) + square(PCY) + square(PCZ) - square(r);
        ld   a = square(dx)*(square(PCX) - len) + square(dy)*(square(PCY) - len) + square(dz)*(square(PCZ) - len) + (2.0*PCX*PCY*dx*dy) + (2.0*PCY*PCZ*dy*dz) + (2.0*PCX*PCZ*dx*dz);
        ld   b = 2.0*QPX*dx*(square(PCX) - len) + 2.0*QPY*dy*(square(PCY) - len) + 2.0*QPZ*dz*(square(PCZ) - len) + (2.0*PCX*PCY*(QPX*dy + QPY*dx)) + (2.0*PCY*PCZ*(QPY*dz + QPZ*dy)) + (2.0*PCX*PCZ*(QPX*dz + QPZ*dx));
        ld   c = square(QPX)*(square(PCX) - len) + square(QPY)*(square(PCY) - len) + square(QPZ)*(square(PCZ) - len) + (2.0*PCX*PCY*QPX*QPY) + (2.0*PCY*PCZ*QPY*QPZ) + (2.0*PCX*PCZ*QPX*QPZ);
        ld ans, root1, root2;
        if(a == 0){
            ans = -(b/c);
        }
        else{
            root1 = (-b + sqrt(square(b) - 4*a*c)) / (2*a);
            root2 = (-b - sqrt(square(b) - 4*a*c)) / (2*a);
            if(root1 > 0 && root2 > 0)
                ans = min(root1,root2);
            else
                ans = max(root1,root2);
        }
        cout << fixed << setprecision(12) << 1.0*ans << endl;
        //printf("%.10lf\n", ans);
    }
    return 0;
}
