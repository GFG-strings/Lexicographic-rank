#include<bits/stdc++.h>
using namespace std;

int LexRank(string str)
{
	int output=0;
	int n=str.length();
	
	//precomputing factorrial array first
	long fact[26];  //bcoz only 26 uniqie chars are present
	fact[0]=1;
	fact[1]=1;
	for(int i=2;i<26;i++)
	{
		fact[i]=fact[i-1]*i;
	}
	
	//instead of actually sorting the input string, I have put it in ASCII array initially 0
	int arr[256]={0};
	
	//ASCII array me only vahi characters mark karo jo input string me present ho bcoz we only need them
	for(int i=0;i<n;i++)
	{
		arr[str[i]]=1;
	}
	
	//ab actaully jaise jaise ek ek char ka kaam ho ra tha vaise vaise usko kahi store karna tha 
	//but actual me store karne se acha mark kar lo usko.
	int temp=0;
	
	//now traverse input string and har baar apne ko no of chars smaller than current char count karo
	for(int i=0;i<n;i++)
	{
		int n_of_chars_smaller=0;  //ye har str[i] ke liye hona isiliye yaha likha
		
		for(int j=0;j<256;j++)
		{
			//character tak pohoche to break karo
			if(str[i]==j)
			{
				break;
			}
			
			//konse konse marked hai and chote hai vo count karo
			//current character occur hone pe stop karo kyuki usse chote hona sab
			if(arr[j]==1)
			{
				n_of_chars_smaller++;
			}
		}
		//ab iska kaam ho gya to isko wapis unmark karo
		arr[str[i]]=0;
		temp++;
		output=output+(n_of_chars_smaller*fact[n-1-i]);
	}
	
	return output+1;
}

int main()
{
	string s="cba";
	int rank=LexRank(s);
	cout<<"\nRank => "<<rank;
	return 0;
}
