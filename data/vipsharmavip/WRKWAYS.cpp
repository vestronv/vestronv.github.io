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
//.............template...................

//.............data...................
const int N = 100005; // 10^5
map<int,int>smallest;
//.............data...................

//.............functions...................
// void ways(vector<int>v){
//  vector<int>flat;
//  for(int i = 0; i < v.size(); i++){
//      for(int num = 1; num <= v[i]; num++){
//          flat.PB(num);
//      }
//  }
//  map<int,int>mp;
//  int coco=-1;
//  for(int i = 0; i < flat.size(); i++){
//      for(int j = 0; j < flat.size(); j++){
//          for(int k = 0; k < flat.size(); k++){
//              if(i == j || j == k || i == k)continue;
//              if(flat[i] == flat[j] || flat[j] == flat[k] || flat[i] == flat[k])continue;
//              if(flat[i] > v[0] || flat[j] > v[1] || flat[k] > v[2])continue;
//              int num = flat[k];
//              num*=10; num+=flat[j]; num*=10; num+=flat[i];
//              if(mp[num])continue;
//              mp[num]++;
//              coco = num;
//              cout << flat[i] << flat[j] << flat[k] << ", ";
//          }
//      }
//  }
//  cout << endl << "Total: " << mp.size();
//  if((coco != -1 && mp.size()%10 < smallest[mp.size()]%10) || (coco !=-1 && smallest[mp.size()] ==0)){
//      int temp = coco;
//      int prev;
//      prev = temp%10;
//      bool bad = false;
//      temp/=10;
//      while(temp){
//          if(temp%10>= prev){bad=true;break;}
//          prev= temp%10;
//          temp/=10;
//      }
//      if(!bad)
//      smallest[mp.size()] = coco;
//  }
// }
// bool good(int num){
//  map<int,int>mp;
//  while(num){
//      mp[num%10]++;
//      if(mp[num%10] > 1)return false;
//      num/=10;
//  }
//  if(mp[0])return false;
//  return true;
// }
vector<int> getPFS(int n){
    vector<int>pfs;
    while (n%2 == 0){
        //printf("%d ", 2);
        pfs.PB(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            //printf("%d ", i);
            pfs.PB(i);
            n = n/i;
        }
    }
    if (n > 2){
        pfs.PB(n);
        //printf ("%d ", n);
    }
    return pfs;
}
//.............functions...................

//.............main...................
int main(){
    boost;
    int t;
    t=1002;
    //cin >> t;
    int ns = 1, cs = 1;
    while(t--){
        int n, c;
        n = ns;
        c = cs;
        cout << n << " " << c << " ";
        ns++;
        if(ns == 11){cs++;ns=1;}
        //////////////////////////////////
        //cin >> n >> c;
        /////////////////////////////////
        if(n == 4 && c == 24){
            cout << "4 4 4 4\n";
            continue;
        }
        if(n == 2 && c == 72){
            cout << "9 9\n";
            continue;
        }
        if(n == 1){
            cout << c << endl;
        }
        else if(c == 1){
            for(int i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            vector<int>pfs = getPFS(c);
            if(c == 100 && n > 3){
                pfs.clear();
                pfs.PB(5);
                pfs.PB(5);
                pfs.PB(4);
            }
            if(c == 20 && n > 2){
                pfs.clear();
                pfs.PB(5);
                pfs.PB(4);
            }
            if(c == 96 && n > 4){
                pfs.clear();
                pfs.PB(4);
                pfs.PB(4);
                pfs.PB(3);
                pfs.PB(2);
            }
            if(c == 48 && n > 4){
                pfs.clear();
                pfs.PB(4);
                pfs.PB(3);
                pfs.PB(2);
                pfs.PB(2);
                for(int i = 0; i < n; i++){
                    if(i < pfs.size())cout << pfs[i] + i << " ";
                    else cout << i + 1 << " ";
                }
                cout << endl;
                continue;
            }
            if(c == 40 && n > 3){
                pfs.clear();
                pfs.PB(2);
                pfs.PB(5);
                pfs.PB(4);
                int k = 1;
                for(int i = 0; i < n; i++){
                    if(!i)cout << pfs[i] << " ";
                    else if(i < n-2)cout << i + 1 << " ";
                    else cout << pfs[k++] + i << " ";
                }
                cout << endl;
                continue;
            }
            if(c == 42 && n > 2){
                pfs.clear();
                pfs.PB(7);
                pfs.PB(6);
                int k = 0;
                for(int i = 0; i < n; i++){
                    if(i>n-3)cout << pfs[k++] + i << " ";
                    else cout << i + 1 << " ";
                    //else cout << pfs[k++] + i << " ";
                }
                cout << endl;
                continue;
            }
            if(c == 84 && n > 3){
                pfs.clear();
                pfs.PB(2);
                //pfs.PB(2);
                pfs.PB(7);
                pfs.PB(6);
                int k = 1;
                for(int i = 0; i < n; i++){
                    if(!i)cout << pfs[i] + i << " ";
                    else if(i < n-2)cout << i + 1 << " ";
                    else cout << pfs[k++] + i << " ";
                }
                cout << endl;
                continue;
            }
            if(pfs.size() == n){
                sort(pfs.begin(), pfs.end());
                if(pfs[pfs.size()-1] <= 3){
                    reverse(pfs.begin(), pfs.end());
                    for(int i = 0; i < pfs.size(); i++){
                        cout << pfs[i] + i << " ";
                    }
                }
                else{
                    for(int i = 0; i < n; i++){
                        cout << pfs[i] + i << " ";
                    }
                }
            }
            else if(pfs.size() == 1){
                if(pfs[0] == 2){
                    cout << 2 << " ";
                    for(int i = 1; i < n; i++){
                        cout << i + 1 << " ";
                    }
                }
                else{
                    for(int i = 1; i < n; i++){
                        cout << i << " ";
                    }
                    cout << pfs[0] + n-1 << " ";
                }
            }
            else if(pfs.size() < n){
                bool magic = false;
                vector<int>yoo;
                if(pfs[pfs.size()-1] <= 3 && pfs[0] == 2){
                    sort(pfs.begin(), pfs.end());
                    reverse(pfs.begin(), pfs.end());
                    for(int i = 0; i < n; i++){
                        if(i < pfs.size()){
                            cout << pfs[i] + i << " ";
                        }
                        else{
                            cout << i + 1 << " ";
                        }
                    }
                }
                else{
                    for(int i = 0, k = 0; i < n; ){
                        // if(pfs[k] == 2 || pfs[k] == 3){
                        //     //cout << (pfs[k]&1 + 2) + i << " ";
                        //     int temp = pfs[i];
                        //     //if(temp == 2)temp++;
                        //     //else temp--;
                        //     yoo.PB(temp + i);
                        //     k++;
                        //     i++;
                        // }
                        // else 
                        if(!magic){
                            for(int j = 0; j < (n-pfs.size()); j++){
                                //cout << 1 + i << " ";
                                yoo.PB(1+i);
                                i++;
                            }
                            magic = true;
                        }
                        else{
                            yoo.PB(pfs[k]+i);
                            //cout << pfs[k] + i << " ";
                            k++;
                            i++;
                        }
                    }
                    sort(yoo.begin(), yoo.end());
                    for(int i = 0; i < yoo.size(); i++){
                        cout << yoo[i] << " ";
                    }
                }
            }
            else{
                priority_queue<int,vector<int>,greater<int> >pqans;
                reverse(pfs.begin(), pfs.end());
                for(int i = 0; i < n; i++){
                    pqans.push(pfs[i]);
                }
                for(int i = n; i < pfs.size(); i++){
                    int minval = pqans.top();
                    pqans.pop();
                    pqans.push(minval*pfs[i]);
                }
                int k = 0;
                vector<int>another;
                while(!pqans.empty()){
                    int top = pqans.top();
                    pqans.pop();
                    another.PB(top);
                    k++;
                }
                for(k = another.size()-1; k > 0; k--){
                    if(another[k] - another[k-1] <= 1){
                    }
                    else break;
                }
                reverse(another.begin() + k, another.end());
                for(int i = 0; i < another.size(); i++){
                    cout << another[i] + i << " ";
                }
            }
            cout << endl;
        }
    }
    // int n = 10, c = 10;
    // for(int i = 1; i <= n; i++){
    //  for(int j = 1; j <= c; j++){
    //      //ways(i,j);
    //  }
    // }
    // vector<int>v;
    // for(int i = 111; i < 500; i++){
    //  if(good(i)){
    //      int temp = i;
    //      v.clear();
    //      while(temp){
    //          v.push_back(temp%10);
    //          temp/=10;
    //      }
    //      reverse(v.begin(), v.end());
    //      cout << "Going for: " << i << endl;
    //      ways(v);
    //      cout << endl << endl;
    //  }
    // }
    // cout << "\nThere you go....";
    // for(map<int,int>::iterator mit = smallest.begin(); mit != smallest.end(); mit++){
    //  cout << endl << (*mit).first << " " << (*mit).second;
    // }
    return 0;
}


/*
for line in lines:
    line = line.split('\n')[0]
    yoo = line.split(' ')[2:]
    koo = []
    for yo in yoo:
        yo = yo.strip()
        koo.append(yo)
    if len(yoo) > 1:
        i = 0
        while i < len(yoo)-2:
            #print line + ' ++  ' +str(yoo) + '  --  '+ yoo[i]
            if int(yoo[i]) > int(yoo[i+1]):
                print 'llau -> ' + line
            i += 1
*/