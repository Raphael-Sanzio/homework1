#include<iostream>  
#include <stdio.h>  
using namespace std;  
double hypothose(double w[],int feature_num,double* training_set){  
    double sum=0;  
    for(int i=0;i<feature_num;i++){  
        sum+=w[i]*training_set[i];  
    }  
    if (sum>0) return 1;  
    else return 0;  
}  
void perception(int feature_num,int training_num,double a,int times,double** training_set,double w[]){  
     int dimentions=feature_num+1;  
     while(times--){  
            double* delta_w=new double[feature_num];  
            for(int i=0;i<feature_num;i++){  
                delta_w[i]=0;  
            }  
            for(int i=0;i<training_num;i++){  
                for(int j=0;j<feature_num;j++){  
                    delta_w[j]+=(training_set[i][feature_num]-hypothose(w,feature_num,training_set[i]))*training_set[i][j]*a;  
                }  
            }  
            for(int i=0;i<feature_num;i++){  
                w[i]+=delta_w[i];  
            }  
            delete[] delta_w;  
        }  
}  
int main(){  
    int feature_num,training_num,times;  
    double a;  
    freopen("in.txt","r",stdin);  
    while(cin>>feature_num>>training_num>>a>>times){  
        double** training_set=new double*[ training_num];  
        for(int i=0;i<training_num;i++){  
            training_set[i]=new double[training_num+2];  
        }  
        double* w=new double[feature_num+1];  
        for(int i=0;i<training_num;i++){  
            training_set[i][0]=1;  
        }  
        for(int i=0;i<training_num;i++){  
            for(int j=1;j<=feature_num+1;j++){  
                cin>>training_set[i][j];  
            }  
        }  
        for(int i=0;i<=feature_num;i++){  
            cin>>w[i];  
        }  
        perception(feature_num+1,training_num,a,times,training_set,w);  
        for(int i=0;i<feature_num;i++){  
            cout<<w[i]<<' ';  
        }  
        cout<<w[feature_num]<<endl;  
        delete[] w;  
        for(int i=0;i<training_num;i++){  
            delete[] training_set[i];  
        }  
        delete[] training_set;  
    }  
    return 0;  
}  
