//
//  main.cpp
//  CuttingSticks
//
//  Created by Zareek Galvan on 10/13/15.
//  Copyright © 2015 Trisquel Labs. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

int N = 52;
int matriz[52][52];
int arr[52];

void llenaMatriz(int n)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = INT_MAX;
        }
    }
    
    for (int i = 0; i <= n; i++)
    {
        matriz[i][i] = 0;
        matriz[i][i+1] = 0;
        matriz[i][i+2] = arr[i+2] - arr[i];
    }
}

void minimoCosto(int n)
{
    llenaMatriz(n);
    
    for (int k = 3; k<=n; k++)
    {
        for (int i = 0; i<=n; i++)
        {
            for (int j = i+1; j<=i+k-1; j++)
            {
                if ((matriz[i][j] + matriz[j][i+k] + arr[i+k] - arr[i]) < matriz[i][i+k])
                {
                    matriz[i][i+k] = matriz[i][j] + matriz[j][i+k] + arr[i+k] - arr[i];
                }
            }
        }
    }
}

int main()
{
    int length;
    int casos;
    
    while ((cin >> length) && (length != 0))
    {
        cin >> casos;
        
        for(int i = 0; i < casos; i++)
        {
            cin >> arr[i + 1];
        }
        arr[0] = 0;
        casos++;
        arr[casos] = length;
        minimoCosto(casos);
        cout << "The minimum cutting is "<< matriz[0][casos] << "." << endl;
        
    }
}
