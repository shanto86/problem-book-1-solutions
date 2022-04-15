// Author: Jony Bepary <sohelahmedjony@gmail.com>
//  2022
//  @jbeary
//  http://jony-blog.github.io/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
queue<int> q;

// প্রতিবার স্ট্রিং থেকে লেক্সোগ্রাফিক্যালি ছোট বর্নের ইন্ডেক্স গুলা
// Queue তে পুশ করে
void the_smallest(string &str)
{
    q = {};
    int small = 0;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[small] > str[i])
        {
            small = i;
        }
    }
    for (int i = 0; i < str.size(); i++)
    {

        if (str[small] == str[i])
        {
            q.push(i);
        }
    }
    // cout << small << endl;
}

// the_smallest() ফাংশন থেকে জেনারেট করা একই রকম smallest letter এর ইন্ডেক্স গুলার queue
// থেকে যেই কয়টা ইন্ডেক্স আছে তার প্রতিটি সাবসিকুয়েন্ট স্ট্রিং গুলা চেক ও এলিমিনেট করে লেক্সোগ্রাফিক্যালি
// সবচেয়ে ছোট সাবসিকুয়েন্ট স্ট্রিং এর স্টার্টিং ইন্ডেক্স রিটার্ন করে

int picking_worthy(string &str)
{

    int s = q.front(), sz = str.size(), sx, qx;
    q.pop();
    int i = 1;

    // if all the subsequence string are same return S/0
    // eg: AAAA, BBBB, A, B
    if ((q.size() + 1) == str.size())
    {
        return s;
    }
    // if not তাহলে খোজাখুজি শুরু
    while (!q.empty())
    {
        // নিচের sx qx আসলে ফরমুলা দিয়ে ইন্ডেক্স নাম্বার জেনারেট করতেসে
        // কারন array এর মাথা আর পাছা কানেক্টেড
        sx = (s + i) - floor((s + i) / sz) * sz;
        qx = (q.front() + i) - floor((q.front() + i) / sz) * sz;

        if (str[sx] == str[qx]) // যদি সমান তাহলে পরের letter চেক করবে
        {
            i++;
        }
        else if (str[sx] < str[qx]) // যদি বড় হয় তাহলে স্ট্রিং টা বাদ দিয়া দেবে
        {
            q.pop();
            i = 0;
        }
        // যদি ছোট হয় তাহলে চেকিং "সাবসিকুয়েন্ট স্ট্রিং এর স্টার্টিং ইন্ডেক্স" তাহলে
        // current smallest "সাবসিকুয়েন্ট স্ট্রিং এর স্টার্টিং ইন্ডেক্স" টার সাথে swap করবে
        // ও কিউ থেকে নেক্সট "সাবসিকুয়েন্ট স্ট্রিং এর স্টার্টিং ইন্ডেক্স" pick করবে
        else if (str[sx] > str[qx])
        {
            s = q.front(); //swap
            q.pop(); //pick
            i = 0;
        }
    }
    return s;
}
int main()
{
    string str;
    ll re, t;
    cin >> t;
    while (t--)
    {
        cin >> str;
        //লেক্সোগ্রাফিক্যালি ছোট বর্নের ইন্ডেক্স গুলা বাছাই করে নিচ্ছে
        the_smallest(str);
        //বাছাই করা ইন্ডেক্সগুলো একটা আরেক্টার সাথে কম্পেয়ার
        //তুলোনামুলক লেক্সোগ্রাফিক্যালি ছোট "সাবসিকুয়েন্ট স্ট্রিং এর স্টার্টিং ইন্ডেক্স" এর ইন্ডেক্স গ্রিডিলি সিলেক্ট করে রিটার্ন করবে
        re = picking_worthy(str);
        // cout << re << " : ";
        if (re == 0)
        {
            cout << str << endl;
            continue;
        }

        //  রিটার্নকৃত সবচেয়ে ছোট সাবসিকুয়েন্ট স্ট্রিং এর স্টার্টিং ইন্ডেক্স
        //  ধরে পুরো স্ট্রিং ওই অর্ডার এ প্রিন্ট করতাসে
        for (int i = re; 1; i++)
        {
            if (i == re - 1)
            {
                cout << str[i];
                break;
            }
            else if (i == str.size())
            {
                i = -1;
                continue;
            }
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}
