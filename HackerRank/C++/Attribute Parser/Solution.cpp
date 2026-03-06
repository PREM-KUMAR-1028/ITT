#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
int main()
{
    int N, Q;
    cin >> N >> Q;
    cin.ignore(); 
    map<string, string> hrml_map;
    vector<string> tag_stack;
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        if (line.substr(0, 2) == "</")
        {
            tag_stack.pop_back();
        } 
        else
        {
            line.erase(0, 1); 
            if (line.back() == '>') line.pop_back(); 
            stringstream ss(line);
            string tag_name, attr, eq, val;
            ss >> tag_name;
            string current_path = "";
            for (const string& t : tag_stack)
            {
                current_path += (current_path.empty() ? "" : ".") + t;
            }
            current_path += (current_path.empty() ? "" : ".") + tag_name;
            tag_stack.push_back(tag_name);
            while (ss >> attr >> eq >> val)
             {
                if (val.front() == '"') val.erase(0, 1);
                if (val.back() == '"') val.pop_back();
                hrml_map[current_path + "~" + attr] = val;
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        string query;
        getline(cin, query);
        if (hrml_map.count(query)) {
            cout << hrml_map[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
