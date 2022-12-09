#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

void stv(vector<int> parties, int seats) {

  int sum = 0, avail = seats;

  for (int i = 0; i < parties.size(); ++i) {
    sum += parties[i]; // sum votes
  }

  vector<int> nseats;
  vector<ld> nparty;
  for (int i = 0; i < parties.size(); ++i) {
    nseats.push_back((int)floor((ld)parties[i] * seats / sum));
    nparty.push_back((ld)parties[i] / sum -
                     floor((ld)parties[i] * seats / sum) / seats);
    avail -= (int)floor((ld)parties[i] * seats / sum);
  }

  while (avail > 0) {
    ld currmax = 0;
    int maxind = 0;
    for (int i = 0; i < parties.size(); ++i) {
      if (nparty[i] > currmax) {
        currmax = nparty[i];
        maxind = i;
      }
    }
    --avail;
    ++nseats[maxind];
    nparty[maxind] = 0; // max 1 extra seat
  }

  for (int i = 0; i < nseats.size(); ++i) {
    cout << i << ' ' << nseats[i] << endl;
  }
}

int main() {

  vector<int> parties;
  int seats;

  cin >> seats;
  int temp = -1;
  while (true) {
    cin >> temp;
    if (temp == 0)
      break;
    parties.push_back(temp);
  }

  stv(parties, seats);
}
