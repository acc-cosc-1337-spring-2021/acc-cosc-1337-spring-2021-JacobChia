#include "dna.h"
#include <string>
#include <iostream>
using namespace std;
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string& dna)
{
    int count = 0;
    int len = dna.length();
    for(int i=0;i<len;i++) {
        if(dna[i] == 'G')
            count++;
        else if (dna[i] == 'C')
            count++;
    }
    return count/len;
}



/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna)
{
    string result = "";
    int len = dna.length();
    for (int i=0;i<len;i++) {
        result = dna[i] + result;
    }
    return result;
}


/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
string get_dna_complement(string dna)
{
    string tmp = get_reverse_string(dna);
    int len = tmp.length();
    for (int i=0;i<len;i++) {
        switch(tmp[i]) {
            case 'T':
                tmp[i] = 'A';
                break;
            case 'A':
                tmp[i] = 'T';
                break;
            case 'C':
                tmp[i] = 'G';
                break;
            case 'G':
                tmp[i] = 'C';
                break;
            default:
                break;   
        }
    }
    return tmp;
}
