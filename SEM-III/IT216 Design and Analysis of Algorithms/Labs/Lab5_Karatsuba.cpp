#include<bits/stdc++.h>
using namespace std;

int make_equal_length(string &x, string &y) {
    
    int x_len = x.length();
    int y_len = y.length();
    
    if(x_len < y_len) {
        
        for(int i = 0 ; i < y_len - x_len ; ++i)
            x = '0' + x;
            
        return y_len;
        
    }else if(y_len < x_len) {
        
        for(int i = 0 ; i < x_len - y_len ; ++i)
            y = '0' + y;
            
        return x_len;
        
    }
    
    return x_len;
    
}

string binary_addition(string x, string y) {
    
    string result;
    int len = make_equal_length(x, y);
    int carry = 0;
    
    for(int i = len-1 ; i >= 0 ; --i) {
        
        int bit1 = x.at(i) - '0';
        int bit2 = y.at(i) - '0';
        
        int sum = (bit1 ^ bit2 ^ carry) + '0';
        
        result = (char)sum + result;
        
        carry = (bit1&bit2) || (bit1&carry) || (bit2&carry);
    }
    
    if(carry) result = '1' + result;
    
    return result;
}

long long int Karatsuba(string x, string y) {
    
    int n = make_equal_length(x, y);
    
    // Base case
    if(n == 0) {return 0;}
    if(n == 1) {return (x[0] - '0') * (y[0] - '0');}
    
    int fh = n/2;
    int sh = n - fh;
    string x_left = x.substr(0, fh);
    string x_right = x.substr(fh, sh);
    
    string y_left = y.substr(0, fh);
    string y_right = y.substr(fh, sh);
    
    long long int p1 = Karatsuba(x_left, y_left);
    long long int p2 = Karatsuba(x_right, y_right);
    long long int p3 = Karatsuba(binary_addition(x_left, x_right), binary_addition(y_left, y_right));
    
    // result = p1*pow(2, n) + (p3 - p1 - p2)*pow(2, n/2) + p2;
    return p1*(1 << 2*sh) + (p3 - p1 - p2)*(1<<sh) + p2;
}

string to_binary(long long int num) {
    
    string result;
    while(num != 0) {
        
        int last_bit = num % 2 + '0';
        result = (char)last_bit + result;
        num = num >> 1;
    }
    return result;
}

int main() {
    
    string x, y;
    
    cout << "Enter the first binary number : ";
    cin >> x;
    
    cout << "Enter the second binary number : ";
    cin >> y;
    
    long long int result = Karatsuba(x, y);
    string bin = to_binary(result);
    cout << "Multipnication of two binary numbers is " << bin << " in binary form.\n";
    cout << "Multipnication of two binary numbers is " << result << " in decimal form.\n";

}


