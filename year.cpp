#include<iostream>
#include<string>

using namespace std;

int main()
{
	const string str[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int T;
	cin>>T;
	string str_temp;
	getline(cin,str_temp);
	int t=0;
	while(t<T)
	{
		string str1,str2;
		getline(cin,str1);
		getline(cin,str2);
		string str1_temp(str1.begin(),str1.begin()+str1.find(" ")),str2_temp(str2.begin(),str2.begin()+str2.find(" "));
		int year1(0),year2(0);
		string str1_year(str1.begin()+str1.find(",")+1,str1.end()),str2_year(str2.begin()+str2.find(",")+1,str2.end());
		for(size_t i=0;i<str1_year.size();++i)
			year1=year1*10+str1_year[i]-'0';
		
		for(size_t i=0;i<str2_year.size();++i)
			year2=year2*10+str2_year[i]-'0';

		int pos1,pos2;
		for(pos1=0;pos1<12;++pos1)
		{
			if(str[pos1]==str1_temp)break;
		}

		if(pos1>=2)year1++;

		for(pos2=0;pos2<12;++pos2)
		{
			if(str[pos2]==str2_temp)break;
		}
		if(pos2<1)year2--;

		int sum(0);
		for(int i=year1;i<=year2;++i)
			if((i%4==0 && i%100!=0)  || i%400==0)sum++;
        
		++t;
		cout<<"Case #"<<t<<":"<<sum<<endl;
	}
	return 0;
}
