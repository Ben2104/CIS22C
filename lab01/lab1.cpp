/*
    Lab 1
    Hoang Khoi Do
    // Description: This assignment check if there are prime numbers in an array using Iteration and Recursion algorithm
*/
#include <iostream>
using namespace std;

// Global Integer
const int SORT_MAX_SIZE = 8;
/*

    Algorithm IsArrayPrimeIter(arr[], size)
    This algorithm check if there is prime number using Iteration
    Pre: arr - a non-empty array of integer numbers
    Post:
    Return: true or false
        i = 0
        loop(i < size)
            if(arr[i] == 1)
            return false
            end if
            j = 2
            loop(j <= arr[i] / 2)
                if (arr[i] % j == 0)
                return false
                end if
            end loop
        end loop
        return true
    end IsArrayPrimeIter
*/
bool IsArrayPrimeIter(int arr[], int size)
{
    cout << "Entering IsArrayPrimeIter" << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            cout << "Leaving IsArrayPrimeIter" << endl;
            return false;
        }
        for (int j = 2; j <= arr[i] / 2; j++)
        {
            if (arr[i] % j == 0)
            {
                cout << "Leaving IsArrayPrimeIter\n";
                return false;
            }
        }
    }
    cout << "Leaving IsArrayPrimeIter\n";
    return true;
}
/*
    Algorithm IsPrimeRecur(int dividend, divisor)
    This algorithm is the helper function for
    Pre: arr - a non-empty array of integer numbers
    Post:
    Return: true or false
        if (divend == 1)
            return false
        end if
        if (diviend == 2)
            return true
        end if
        if (dividend % divisor == 0)
        return false
        end if
        if (divisor*divisor > divend)
        return true
        end if
        return IsPrimeRecur(dividend, divisor + 1)
    end IsPrimeRecur
*/
bool IsPrimeRecur(int dividend, int divisor)
{
    cout << "Entering IsPrimeRecur" << endl;
    if (dividend == 1)
    {
        return false;
    }
    if (dividend == 2)
    {
        return true;
    }
    if (dividend % divisor == 0)
    {
        return false;
    }
    if (divisor * divisor > dividend)
    {
        return true;
    }
    cout << "Leaving IsPrimeRecur" << endl;
    return IsPrimeRecur(dividend, divisor + 1);
}
/*
    Algorithm IsArrayPrimeRecur(arr[], size)
    This algorithm check if there is prime number using Recursion
    Pre: arr - a non-empty array of integer numbers
    Post:
    Return: true or false
        if(size >= 1)
            return true
        end if
        if (!IsPrimeRecur(arr[size-1])
            return IsArrayPrimeRecur(arr, size-1)
        end if
        return false
    end IsArrayPrimeReCur
*/
bool IsArrayPrimeRecur(int arr[], int size)
{
    cout << "Entering IsArrayPrimeRecur" << endl;
    if (size == 0)
    {
        cout << "Leaving IsArrayPrimeRecur" << endl;
        return true;
    }
    if (IsPrimeRecur(arr[size - 1], 2))
    {
        cout << "Leaving IsArrayPrimeRecur" << endl;
        return IsArrayPrimeRecur(arr, size - 1);
    }
    cout << "Leaving IsArrayPrimeRecur" << endl;
    return false;
}
int main()
{
    cout << "Please enter your input data on one line only." << endl;
    int size;
    int index = 0;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    if (IsArrayPrimeIter(arr, size))
    {
        cout << "Array was found to be prime using iteration" << endl;
    }
    else
    {
        cout << "Not a Prime Array using iteration" << endl;
    }
    cout << endl;
    if (IsArrayPrimeRecur(arr, size))
    {
        cout << endl;
        cout << "Array was found to be prime using recursion" << endl;
    }
    else
    {
        cout << endl;
        cout << "Not a Prime Array using recursion" << endl;
    }
    return 0;
}