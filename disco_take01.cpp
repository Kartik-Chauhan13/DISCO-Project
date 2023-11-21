
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
  freopen("a.txt", "r", stdin);
  // freopen("b.txt", "w", stdout);
#else

#endif
  string s;
  int flag = 1;
  string str;
  map<string, vector<vector<string>>> m;
  while (flag)
  {
    vector<vector<string>> v;
    for (int i = 0; i < 6; i++)
    {

      cin >> s;
      if (i == 0)
      {
        str = s;
      }
      else if (i == 1)
      {
        vector<string> v1;
        v1.push_back(s);
        // cout<<v1[0]<<endl;
        v.push_back(v1);
        // cout<<v[0][0]<<endl;
      }
      else
      {
        vector<string> v2;
        if (s == "-")
        {
          v2.push_back(s);
          v.push_back(v2);
        }
        else
        {
          vector<int> comma;
          for (int i = 0; i < s.size(); i++)
          {
            if (s[i] == ',')
            {
              comma.push_back(i);
            }
          }
          if (comma.size() != 0)
          {
            string s1 = s.substr(0, comma[0]);
            v2.push_back(s1);
            for (int i = 0; i < comma.size(); i++)
            {
              string s1 = s.substr(comma[i] + 1, comma[i]);
              v2.push_back(s1);
            }
          }
          else
          {
            v2.push_back(s);
          }
          v.push_back(v2);
        }
        m[str] = v;
      }
      if (s == "END")
      {
        flag = 0;
        break;
      }
    }
  }

  map<string, vector<string>> ctp;
  map<string, double> profx;
  for (const auto &i : m)
  {

    for (const auto &innerVec : i.second)
    {
      for (const auto &str : innerVec)
      {
        if (str == "-" || str == "1.5" || str == "0.5" || str == "1")
        {
          if (str != "-")
          {
            profx[i.first] = stod(str);
          }
        }
        else
        {
          if (ctp.count(str) > 0)
          {
            vector<string> v = ctp[str];
            v.push_back(i.first);
            ctp[str] = v;
          }
          else
          {
            vector<string> v;
            v.push_back(i.first);
            ctp[str] = v;
          }
        }
      }
    }
  }
  int max = 0;
  map<string, vector<string>> allot;
  map<string, vector<string>> cdc;

  for (auto i : ctp)
  {
    string s = (i.first).substr(0, 5);
    if ((s == "ugcdc" || s == "hdcdc"))
    {
      cdc[i.first] = i.second;
      if ((i.second).size() > max)
      {
        max = (i.second).size();
      }
    }
  }
  cout << max << endl;
  int n = max;
  for (int i = 1; i <= n; i++)
  {
    for (auto j : cdc)
    {
      if ((j.second).size() == i)
      {
        cout <<i<<" "<< j.first << " ";
        double sum = 0;
        for (auto str : j.second)
        {
          sum = sum + profx[str];
        }
        cout << sum << endl;
      }
    }
  }
  
  return 0;
}