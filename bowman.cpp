#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits.h>
#include <errno.h>
#include <math.h>

using namespace std;

//Blaise Bowman, CIS 4930 Bioinformatics Assignment #3

vector<char> build(int k, int n, int t, int p, vector<char> &deBruijnseq, vector<char> &graph) {
    if (t > n + 1) {
        if (n % p == 0) {
            for (int i = 1; i < p + 1; i++) {
                deBruijnseq.push_back(graph[i]);
            }
        }
    } else {
        graph[t] = graph[t - p];
        build(k, n, t + 1, p, deBruijnseq, graph);
        for (int j = graph[t - p] + 1; j < k; j++) {
            graph[t] = j;
            build(k, n, t + 1, t, deBruijnseq, graph);
        }
    }
    return deBruijnseq;
}

std::string deBruijn(int k, int n) {
    vector<char> graph((k * n), 0); //initialize char vector
    vector<char> deBruijnseq;
    string buf;

    deBruijnseq = build(k, n, 1, 1, deBruijnseq, graph);
    for (char i : deBruijnseq) {
        buf.push_back('0' + i);
    }
    //return buf + buf.substr(0, n - n);
    string ret = buf.substr(0, n);
    //reverse(ret.begin(), ret.end());
    //return buf;
    //string buf2 = buf;
    return buf.substr(0, k) + buf.substr(k);
}

int main(int argc, char *argv[]) {
    //ACCEPTS: Value of k
    //OUTPUTS: k-Universal String, find a circular string containing each binary k-mer exactly once
    long k_long;
    char *p;
    errno = 0;
    //int k;
    //k = 3; for testing within CLion
    k_long = strtol(argv[1], &p, 10); //---->>> k, for testing via Linux
    if (*p != '\0' || errno != 0 || k_long > INT_MAX) {
        return 0;
    }
    if (k_long < 1) {
        cout << "Invalid k-value provided." << endl;
        return 0;
    }
    int k = k_long;

/*
    auto db = deBruijn2(2,3);
    cout << " in-order " << db << endl;
    auto dbs = db;
    reverse(dbs.begin(), dbs.end());
    cout << " reversed " << dbs << endl;*/

    //BEGIN PART A
    ofstream out;
    ofstream ofile("assignment3_partA.txt");
    if (ofile.is_open()) {
        if (k >= 1) {
            ofile << deBruijn(2, k) << endl;
        } else {
            ofile << "The provided k-value " << k << " is invalid." << endl;
        }
    }
    ofile.close();
    ofile.clear();
    //END PART A

    //BEGIN PART B
    ofile.open("assignment3_partB.txt");
    if (ofile.is_open()) {
        //ofile << "With k = 4, a k-universal circular binary string is: ";
        ofile << deBruijn(2, 4) << endl;
        //ofile << "With k = 5, a k-universal circular binary string is: ";
        ofile << deBruijn(2, 5) << endl;
    }
    ofile.close();
    ofile.clear();
    //END PART B

    //BEGIN PART C
    ofile.open("assignment3_partC.txt");
    if (ofile.is_open()) {
        if (k > 2) {
            ofile << "Yes." << endl << endl;
            /*ofile << "The number of possible different k-universal strings for a given k-value is: " << "(2)^((2^(k-1))-k)" << endl;
            ofile << "With k = " << k << ", there are multiple k-universal strings." << endl;
            int val = (pow(2,(pow(2,k-1)) - k));
            ofile << "There are " << val << " k-universal strings for k = " << k << "." << endl;*/
        } else if (k <= 2) {
            ofile << "No." << endl << endl;
            /*ofile << "The number of possible different k-universal strings for a given k-value is: " << "(2)^((2^(k-1))-k)" << endl;
            ofile << "Since k = " << k << ", there are not multiple k-universal strings." << endl;
            int val = (pow(2,(pow(2,k-1)) - k));
            ofile << "There is " << val << " k-universal string for k = " << k << "." << endl;*/
        } else {
            ofile << "Invalid k-value entered." << endl;
        }
    }
    ofile.close();
    ofile.clear();
    //END PART C

    //PART D:
    //DONE IN WORD
    return 0;
}


