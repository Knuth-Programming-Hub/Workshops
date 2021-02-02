package com.company;
import java.io.*;
import java.util.*;

//Problem Statement:-
/*Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
 In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items
 respectively.
 Also given an integer W which represents knapsack capacity,
 find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
 You cannot break an item, either pick the complete item or don’t pick it (0-1 property).*/


public class Main {

    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int val[]=new int[n];
        int weight[]=new int[n];
        for(int i=0;i<n;i++){
            val[i] = input.nextInt();
        }
        for(int i=0;i<n;i++){
            weight[i] = input.nextInt();
        }
        int capacity=input.nextInt();

        int dp[][]=new int[n+1][capacity+1];
        for(int ar[]:dp){
            Arrays.fill(ar,-1);
        }
        System.out.println("Maximum value possible:"+knapsack(capacity,val,weight,n,dp));
    }
    //Iterative Approach
    static int knapsack2(int capacity,int []val,int weight[],int index,int dp[][]){
        for(int i=0;i<=val.length;i++){
            for(int j=0;j<=capacity;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if(j>=weight[i-1]){
                    dp[i][j]=Math.max(val[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[dp.length-1][dp[0].length-1];
    }
    //Recursive Approach
    static int knapsack(int capacity,int []val,int weight[],int index,int dp[][]){
        if(capacity==0){
            return 0;
        }
        if(index==0){
            return 0;
        }

        if(dp[index][capacity]!=-1){
            return dp[index][capacity];
        }
        if(weight[index-1]>capacity){
            dp[index][capacity]=knapsack(capacity,val,weight,index-1,dp);
            return dp[index][capacity];
        }
        else {
            dp[index][capacity] = Math.max(val[index - 1] + knapsack(capacity - weight[index - 1], val, weight, index -1 , dp),
                    knapsack(capacity, val, weight, index - 1, dp));
            return dp[index][capacity];
        }
    }
}