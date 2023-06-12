#include <bits/stdc++.h>
using namespace std;

unordered_map<char,vector<string>> collector;
unordered_map<char,set<char>> first;
unordered_map<char,set<char>> follow;
vector<char> NT;
bool hsh[26];
bool hsh_follow[26];

void find_first(char nt,int n);
void null_exp(vector<string> &v,int i,int n,char &nt);
void find_follow(char ch);
void first_in_follow(vector<string> &v,int j,int k,int n,char ch,char cur_production);

void find_first(char nt,int n)
{ if(!hsh[nt-'A'])
  {
  vector<string> &v = collector[nt];
  for(int i=0;i<v.size();i++)
  { if( v[i][0] <65 || v[i][0] > 90)
    { first[nt].insert(v[i][0]);
    }
    else
    { null_exp(v,i,n,nt);
    }
  }
  hsh[nt - 'A'] = true;
  }
}

void null_exp(vector<string> &v,int i,int n,char &nt)
{ // find first of non_terminal
      find_first(v[i][n],n);
      // copy first of non terminal to this production
      set<char> temp = first[v[i][n]];
      for(auto str : temp)
      { if(str != '@')
        { first[nt].insert(str); }
        else
        { if(n+1<v[i].length())
            { null_exp(v,i,n+1,nt);
            }
          else
          { first[nt].insert('@');
          }
        }
      }
}

void find_follow(char ch)
{ for(auto i=collector.begin();i!=collector.end();i++)
  { vector<string> &v = i->second;
    for(int j=0;j<v.size();j++)
    { for(int k=0;k<v[j].length();k++)
      { if(v[j][k] == ch)
        { first_in_follow(v,j,k,0,ch,i->first);
        }
      }
    }
  }
}

void first_in_follow(vector<string> &v,int j,int k,int n,char ch,char cur_production)
{ if(k+1+n < v[j].length())
  { if(v[j][k+1+n] < 65 || v[j][k+1+n] > 90)
    { follow[ch].insert(v[j][k+1+n]);}
    else
    { for(auto str : first[v[j][k+1+n]])
      { if(str != '@') { follow[ch].insert(str); }
        else { first_in_follow(v,j,k,n+1,ch,cur_production); }
      }
    }
  }
  else
  { if(ch != cur_production)
    {if(!hsh_follow[cur_production-'A'])
     { find_follow(cur_production);
       hsh_follow[cur_production-'A'] = true;
     }
    for(auto str : follow[cur_production])
     { follow[ch].insert(str);
     }
    }
  }
}

int main()
{ int n;
  cin >> n;
  char main_char;
  for(int j=0;j<n;j++)
  { string s;
    cin >> s;
    if(j==0) {main_char = s[0];}
    NT.push_back(s[0]);
    int start =3;
    for(int i=3;i<s.size();i++)
    { if(s[i] == '|')
      { collector[s[0]].push_back(s.substr(start,i-start));
        start = i+1;
      }
    }
    collector[s[0]].push_back(s.substr(start,s.size()-start));
  }
  for(auto i = collector.begin();i != collector.end(); i++)
  { find_first(i->first,0);
  }
  for(auto i = first.begin();i != first.end(); i++)
  { set<char> temp = i->second;
    cout << "FIRST(" << i->first << ") :  ";
    for(auto str : temp)
    { cout << str << " ";
    }
    cout << endl;
  }
  cout << endl;
  follow[main_char].insert('$');
  for(int i=0;i<NT.size();i++)
  { find_follow(NT[i]);
  }
  for(auto i = follow.begin();i != follow.end(); i++)
  { set<char> temp = i->second;
    cout << "FOLLOW(" << i->first << ") :  ";
    for(auto str : temp)
    { cout << str << " ";
    }
    cout << endl;
  }
  return 0;
}