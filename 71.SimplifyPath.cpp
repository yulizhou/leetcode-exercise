class Solution {
public:
    string simplifyPath(string path) {
        string res, t;
        vector<string> temp;
        stringstream ss(path);
        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") continue;
            if (t == ".." && !temp.empty()) temp.pop_back();
            else if (t != "..") temp.push_back(t);
        }
        for (string s : temp) {
            res += "/" + s;
        }
        // if empty
        return res.empty() ? "/" : res;
    }
};