Code to split a sentence into words.
```
vector<string> vec;
stringstream str(s);
string tmp;
while (getline(str, tmp, ' '))
vec.push_back(tmp);
```