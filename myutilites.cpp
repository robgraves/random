#include <iostream>

#include <cstdlib> //randint
#include <ctime> //randint
#include <vector>
#include <fstream> 
#include <sstream>
using namespace std;


class Utility{
        bool srand_has_exc;
    public:
    
        Utility(){
            srand_has_exc = false;
        }
        
    //random
        int randint(int start=0, int maxnum=0, int increment=0){
            /*generate a random int max at maxnum, starting from start, increment add value to both
             * 
             * maxnum = max number minus one
             * start = number no less than accepted
             * increment = add increment to 
             */
            if (!srand_has_exc){
                srand(time(0)); 
                srand_has_exc = true;
            }
            int num=0;
            while (true){
                num = (rand() % maxnum) + increment; 
                if (start == 0)
                    return num;
                else if (num < start)
                    continue;
                else
                    break;
            }
            return num;
        }
        
    //basic operations
        string reverse(string s){
            return string(s.rbegin(), s.rend());
        }
        
        //join vector into string separated by sep
        string join(vector<string> v, string sep){
            stringstream ss;
            for(size_t i = 0; i < v.size(); ++i){
                if(i != 0)
                    ss << sep;
                ss << v[i];
            }
            return ss.str();
        }

        //join str array into string separeted by sep
        string join(string array[], int size, string sep){
            stringstream ss;
            for(size_t i = 0; i < size; ++i){
                if(i != 0)
                    ss << sep;
                ss << array[i];
            }
            return ss.str();
        }
        
        //get max int from array
        int max(int a[], int size){
            int mx = a[0];
            for(int i=0; i<size; i++){
                if(mx < a[i]){
                    mx = a[i];
                }
            }
            return mx;
        }
        //get min int from array
        int min(int a[], int size){
            int mn = a[0];
            for(int i=0; i<size; i++){
                if(mn > a[i]){
                    mn = a[i];
                }
            }
            return mn;
        }
        //get sum of int array
        int sum(int a[], int size){
            int total = 0;
            for(int i=0; i<size; i++){
                total += a[i];
            }
            return total;
        }
        //get max int from vector
        int max(vector<int> v){
            int mx = v[0];
            for (vector<int>::size_type i = 0; i != v.size(); i++) {
                if(mx < v[i]){
                    mx = v[i];
                }
            }
            return mx;
        }
        //get min int from vector
        int min(vector<int> v){
            int mn = v[0];
            for (vector<int>::size_type i = 0; i != v.size(); i++) {
                if(mn > v[i]){
                    mn = v[i];
                }
            }
            return mn;
        }
        //get sum of int vector
        int sum(vector<int> v){
            int total = 0;
            for (vector<int>::size_type i = 0; i != v.size(); i++) {
                total += v[i];
            }
            return total;
        }
        
        
    //file i/o
        //write full str to file
        void write(string filename, string data){
            ofstream f;
            f.open(filename);
            f << data;
            f.close();
        }
        //write vector to file spaced by index, separated by sep
        void write(string filename, vector<string> v, string sep="\n"){
            ofstream f;
            f.open(filename);
            for (vector<int>::size_type i = 0; i != v.size(); i++) {
                f << v[i] << sep;
            }
            f.close();
        }
        //open file and read into vector str
        vector<string> open(string filename){ //get entire line
            string s = "";
            vector<string> v;
            ifstream f;
            f.open(filename);
            while(getline(f, s)){
                v.push_back(s);
            }
            f.close();
            return v;
        }
    
    
    //type conversion
        //convert from int to string
        string int2str(int inter){
            stringstream num_str;
            num_str << inter;
            return num_str.str();
        }
        
        //convert from string to int
        int str2int(string str){
            int i;
            stringstream ss(str);
            ss >> i;
            return i;
        }
        
        //convert from float to int
        int flo2int(float floater){
            int i = static_cast<int>(floater);
            return i;
        }
        
        //convert from double to int
        int dou2int(double d){
            int i = static_cast<int>(d);
            return i;
        }
        
        //ocnvert from cahr to string
        string cha2str(char ch){
            stringstream ss;
            string s;
            ss << ch;
            ss >> s;
            return s;
        }

        //convert from string to char
        char str2cha(string stringer){
            stringstream ss;
            char c;
            ss << stringer;
            ss >> c;
            return c;
        }

        //convert from character to ascii number
        int cha2asc(char ch){
            int i;
            i = (int)ch;
            return i;
        }

        //convert from ascii number to character
        char asc2cha(int num){
            char c;
            c = (char)num;
            return c;
        }
        
        string strip(const std::string& str,
                         const std::string& whitespace = " \t")
        {
            const auto strBegin = str.find_first_not_of(whitespace);
            if (strBegin == std::string::npos)
                return ""; // no content

            const auto strEnd = str.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;

            return str.substr(strBegin, strRange);
        }

        string reduce(const std::string& str,
                           const std::string& fill = " ",
                           const std::string& whitespace = " \t")
        {
            // trim first
            auto result = strip(str, whitespace);

            // replace sub ranges
            auto beginSpace = result.find_first_of(whitespace);
            while (beginSpace != std::string::npos)
            {
                const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
                const auto range = endSpace - beginSpace;

                result.replace(beginSpace, range, fill);

                const auto newStart = beginSpace + fill.length();
                beginSpace = result.find_first_of(whitespace, newStart);
            }

            return result;
        }
};


void test(){

    Utility util;
    
    
    for (int i=0; i<10; i++){
        cout << util.randint(5, 25) << ' ';
    }
    cout << endl;
    
    
    string gender[2] = {"Female", "Male"};
    for (int i=0; i<10; i++){
        cout << gender[util.randint(0,2)] << ' ';
    }
    cout << endl;
    
    
    cout << util.reverse("some random string") << endl;
    
    
    int a[10];
    for (int i=0; i<10; i++){
        a[i] = util.randint(0,25);
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << "max num: " << util.max(a, 10) << endl;
    cout << "max num: " << util.min(a, 10) << endl;
    cout << "sum: " << util.sum(a, 10) << endl;
    
    vector<int> v;
    for (int i=0; i<util.randint(3,10); i++){
        v.push_back(util.randint(0,100));
    }
    for (vector<int>::size_type i = 0; i != v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    cout << "max num: " << util.max(v) << endl;
    cout << "min num: " << util.min(v) << endl;
    cout << "sum: " << util.sum(v) << endl;
    
    string name = "test.html";
    util.write(name, "some\nrandom\ndata");
    util.open(name);
    vector<string> s = {"test", "this", "right\nnow"};
    util.write(name, s);
    util.open(name);
    
    cout << util.int2str(1024).substr(0,3) << endl;
    cout << util.str2int("24") + 1 << endl;
    cout << util.flo2int(10.1) - 5 << endl;
    cout << util.cha2str('c') + "h" << endl;
    cout << util.str2cha("s") + 'h' << endl;
    cout << util.cha2asc('c') << endl;
    cout << util.asc2cha(99) << endl;

    string foo = "    too much\t   \tspace\t\t\t  ";
    string bar = "one\ntwo";
    cout << "[" << util.strip(foo) << "]" << endl;
    cout << "[" << util.reduce(foo) << "]" << endl;
    cout << "[" << util.reduce(foo, "-") << "]" << endl;
    cout << "[" << util.strip(bar) << "]" << endl;
    
    string jointest[] = {"join", "random", "string", "array"};
    cout << util.join(jointest, 4, ",") << endl;
    vector<string> jointest2 = {"join", "random", "string", "vector"};
    cout << util.join(jointest2, ",");
}




int main (){
    test();
}
