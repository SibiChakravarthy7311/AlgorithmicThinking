// AlgorithmicThinking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
/*
class Node {
public:
    int data;
    Node* left, * right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL) {
        return root;
    }
    if (left == NULL && right == NULL) {
        return NULL;
    }
    if (left != NULL) {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}
*/

int main()
{
    /*
    Peak Finder problem
    Find a peak if it exists in a given array
    1D array, arr = [a,b,c,d,e,f,g,h,i]
	position 2 is a peak if b>=a && b>=c
	position 9 is a peak if i>h
    */

    vector<int> v = {4,7,2,3,8,9,0,1,5};
    
    //vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
    bool peak = false;
    int h = v.size(), l=0, ci, i=0, s;
    s = h;

    //1D-peak Straight forward approach
    
    for (i = 0; i < h; i++) {
        if (i == 0) {
            if (v[i] > v[i + 1]) {
                peak = true;
                break;
            }
        }
        else if (i == h-1) {
            if (v[i] > v[i - 1]) {
                peak = true;
                break;
            }
        }
        else {
            if (v[i]>=v[i - 1] && v[i]>=v[i+1]) {
                peak = true;
                break;
            }
        }
    }
    if (peak) {
        cout << "StraightForward Algorithm 1D-Peak: " << v[i] << endl;
        peak = false;
    }

    //1D-peak binary search approach

    while (true) {
        ci = (h + l) / 2;
        if (ci == 0 || ci == s - 1) {
            peak = true;
            break;
        }
        if (v[ci] < v[ci - 1]) {
            h = ci;
        }
        else if (v[ci] < v[ci + 1]) {
            l = ci;
        }
        else {
            peak = true;
            break;
        }
    }
    if (peak) {
        cout << "Binary Search 1D-Peak: " << v[ci] << endl;
        peak = false;
    }
    
    //vector<vector<int>> v2 = { {1,2,3,4}, {14,13,12,5}, {15,9,11,17}, {16,17,19,20} };
    //vector<vector<int>> v2 = { {1,2,3,4}, {13,12,14,5}, {15,9,11,17}, {16,12,13,20} };
    vector<vector<int>> v2 = { {1,2,3,4}, {13,14,12,5}, {15,9,11,17}, {16,17,19,20} };
    int ch = v2[0].size(), cc, cl=0, r=v2.size(), j=0, cmax, imax=0, var;
    int cs = ch, check=0;

    //2D-peak Straight forward approach

    for (i = 0; i < r; i++) {
        if (peak) {
            break;
        }
        for (j = 0; j < cs; j++) {
            check = 0;
            var = v2[i][j];
            if (j == 0) {
                check++;
            }
            else {
                if (var >= v2[i][j - 1]) {
                    check++;
                }
            }
            if(j==r-1) {
                check++;
            }
            else {
                if (var >= v2[i][j + 1]) {
                    check++;
                }
            }
            if (i == 0) {
                check++;
            }
            else {
                if (var >= v2[i-1][j]) {
                    check++;
                }
            }
            if (i == cs - 1) {
                check++;
            }
            else {
                if (var >= v2[i+1][j]) {
                    check++;
                }
            }
            if (check == 4) {
                peak = true;
                break;
            }
        }
    }
    
    if (peak) {
        peak = false;
        cout << "2D-peak StraightForward algorithm: " << v2[i-1][j] << endl;
    }

    //2D-peak binary search approach

    while (true) {
        cc = (ch + cl) / 2;
        cmax = v2[0][cc];
        for (i = 0; i < r; i++) {
            if (cmax < v2[i][cc]) {
                cmax = v2[i][cc];
                imax = i;
            }
        }
        if (cc == 0 || cc == cs - 1) {
            peak = true;
            break;
        }
        if (v2[imax][cc] < v2[imax][cc - 1]) {
            ch = cc;
        }
        else if (v2[imax][cc] < v2[imax][cc + 1]) {
            cl = cc;
        }
        else {
            peak = true;
            break;
        }
    }

    if (peak) {
        cout << "2D-peak Binary algorithm: " << v2[imax][cc];
        peak = false;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
