#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int getdivisorsum(vector <int> &prime, int n) {

	int i=0;
	int k =0;
	int sum = 1;
    int d =n;
	while(n>1 && i<prime.size()) {
		if (n%prime[i]==0) {
			k++;
			n = n/prime[i];
			continue;
		}
		else {
			sum = sum * (pow(prime[i], k+1)-1) / (prime[i]-1);
			k=0;
			i++;
		}
	}
	if(k!=0) {
		sum = sum * (pow(prime[i], k+1)-1) / (prime[i]-1);
		k=0;
		i++;
	}
	return sum-d;
}
int main() {

	vector<int> prime;
	vector<int> sieve(1000, 0);

	for (int i=2; i<1000; i++) {
		if(sieve[i]==0) {
			prime.pb(i);
			for(int j = 2*i; j<1000; j+=i) {
				sieve[j]=1;
			}
		}
	}


	set <int> abundant;
	for (int i =3; i<100001; i++) {
		int k = getdivisorsum(prime, i);
		if(k>i) {
			abundant.insert(i);
		}
	}

	int t, n;
	cin>>t;

	while(t--) {
		cin>>n;
		int flag =0;

		set <int> :: iterator it = abundant.begin();
		for(; it!=abundant.end(); it++ ){
            int k = *it;
			if(abundant.find(n-k)!=abundant.end()) {
				cout<<"YES\n";
				flag =1;
				break;
			}
		}
		if (flag==0) {
			cout<<"NO\n";
		}
	}

	return 0;
}