#include "Solution.h"




class Solution {
public:

    string::size_type n;

    vector<size_t> positions;

    string defangIPaddr(string address) {
        n = address.find('.');
        while(n != std::string::npos){
            address.insert(n, 1, '[');
            address.insert(n+2, 1, ']');
            n = address.find('.', n+3);
        }
        return address;
    }
    vector<size_t> findDecimal(string address) {
        n = address.find('.');
        while(n != std::string::npos){
            positions.push_back(n);
            n = address.find('.', n+1);
        }
        return positions;
    }

    void printpositions(vector<size_t> positions){
        for(auto i = positions.cbegin(); i != positions.cend(); ++i){
            cout << *i << " ";
        }
    }

};


int main(){

    Solution solution_1; //need variable of type class to access class
    int a = 10, b = 22;
    string ip; //inputted ip address
    vector<size_t> positions;

    cout << "Input the IP address" << endl;
    cin >> ip;
    ip = solution_1.defangIPaddr(ip);
    positions = solution_1.findDecimal(ip);
    cout << "Your defanged IP address is: " << ip << endl;
    cout << "With Decimals located at ";
    solution_1.printpositions(positions);
}