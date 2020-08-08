#include <bits/stdc++.h>

using namespace std;


vector<string> split_string(string);
// the funtion is responsible to know if the current block is a corner case or not
// if current block is corner just add all the area on the corner side 
int legal_address(int i, int j,vector<vector<int>> A){
    if(i==-1)
        return 0;
    if(j==-1)
        return 0;
    if(i>=A.size())
        return 0;
    if(j>=A[0].size())
        return 0;

    return 1;
}
// the program divides all the A[i][j] as seperate blocks
// and then calculate the exposed area per block basis
// this is the function which does the same for a single block
int block_area(int i, int j,vector<vector<int>> A){
    int area=0;
    // A[i-1][j]
    if(legal_address(i-1,j,A)){
        if(A[i][j]>A[i-1][j])
            area=area+A[i][j]-A[i-1][j];
    }
    else{
        area=area+A[i][j];
    }
    // A[i][j+1]
    if(legal_address(i,j+1,A)){
        if(A[i][j]>A[i][j+1])
            area=area+A[i][j]-A[i][j+1];
    }
    else{
        area=area+A[i][j];
    }
    // A[i+1][j]
    if(legal_address(i+1,j,A)){
        if(A[i][j]>A[i+1][j])
            area=area+A[i][j]-A[i+1][j];
    }
    else{
        area=area+A[i][j];
    }
    // A[i][j-1]
    if(legal_address(i,j+1,A)){
        if(A[i][j]>A[i][j+1])
            area=area+A[i][j]-A[i][j+1];
    }
    else{
        area=area+A[i][j];
    }    // A[i][j]
    
    if (A[i][j]!=0)
        area=area+2;
    return area;
}
// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
        int total_area=0;
        for(int i=0;i<(int)A.size();i++){
            for(int j=0;j<(int)A[0].size();j++)
                total_area=total_area+block_area(i,j, A);

        }
    return total_area;
}
// driver code below pretty much pointless 
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
