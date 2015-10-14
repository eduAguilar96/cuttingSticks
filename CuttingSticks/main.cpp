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

int main()
{
    int length;
    int casos;
    int matriz[52][52];
    int arr[52];
    int N = 50;
    
    cin >> length;
    
    while (length != 0)
    {
        cin >> casos;
        
        arr[0] = 0;
        for(int i = 0; i < casos; i++)
        {
            cin >> arr[i + 1];
        }
        casos++;
        arr[casos] = length;
        
        for (int i = 0; i <= N + 1; i++)
        {
            for (int j = 0; j <= N + 1; j++)
            {
                matriz[i][j] = INT_MAX;
            }
        }
        
        for (int i = 0; i <= casos; i++)
        {
            matriz[i][i] = 0;
            matriz[i][i+1] = 0;
            matriz[i][i+2] = arr[i+2] - arr[i];
        }
        
        for (int k = 3; k<=casos; k++)
        {
            for (int i = 0; i<=casos-k; i++)
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
        
        cout << "The minimum cutting is "<< matriz[0][casos] << "." << endl;
        cin >> length;
    }
}
