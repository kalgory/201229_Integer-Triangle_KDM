#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>>);
void print_vector(vector<vector<int>> triangle){
    for(int i=0; i<triangle.size(); i++){
        for(int j=0;j<i+1;j++){
            cout<<triangle[i][j]<<"  ";
        }cout<<endl;
    }
}


int main(){
    vector<vector<int>> input_case(5);
    for(int i=0; i<input_case.size();i++){
        input_case[i].resize(i+1);
        //for(int j=0;j<i+1;j++){
            //cin>>input_case[i][j];
        //}
    }
    input_case[0]={7};
    input_case[1]={3,8};
    input_case[2]={8,1,0};
    input_case[3]={2,7,4,4};
    input_case[4]={4,5,2,6,5};

    solution(input_case);
}

int solution(vector<vector<int>> triangle) {
    int case_triangle=0;
    
    //top bottom
    int answer=0;
    vector<vector<int>> temp (triangle.size());
    for(int i=0;i<triangle.size();i++) temp[i].resize(i+1);
     temp[0][0]=triangle[0][0];
    for(int i=0;i<triangle.size()-1;i++){
        for(int j=0;j<i+1;j++){
            temp[i+1][j]=max(triangle[i+1][j]+temp[i][j],temp[i+1][j]);
            temp[i+1][j+1]=max(triangle[i+1][j+1]+temp[i][j],temp[i+1][j+1]);
        }
    }
    for(int i=0;i<triangle.size();i++) answer=max(temp[triangle.size()-1][i],answer);
    if(case_triangle) return answer;

    //bottom top
    for(int i=triangle.size()-1;i>0;--i){
        for(int j=0;j<i;j++){
            triangle[i-1][j]+=max(triangle[i][j],triangle[i][j+1]);
        }
    }
    if(!case_triangle) return triangle[0][0] 
}