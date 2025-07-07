#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

#include"mystring.h"

void test_string1()
{
	lcz::string s1("hello world");
	cout << s1.c_str() << endl;

	lcz::string s2;
	cout << s2.c_str() << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	const lcz::string s3("hello world");
	s3[0];

	//bit::string::const_iterator cit = s3.begin();
	auto cit = s3.begin();
	while (cit != s3.end())
	{
		//*cit += 1;

		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	lcz::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it += 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void test_string2()
{

	lcz::string s1("hello world");
	cout << s1.c_str() << endl;

	s1.push_back(' ');
	s1.push_back('#');
	s1.append("hello bit");
	cout << s1.c_str() << endl;

	lcz::string s2("hello world");
	cout << s2.c_str() << endl;

	s2 += ' ';
	s2 += '#';
	s2 += "hello bit";
	cout << s2.c_str() << endl;
}

void test_string3()
{
	lcz::string s1("helloworld");
	cout << s1.c_str() << endl;

	s1.insert(5, 3, '#');
	cout << s1.c_str() << endl;

	s1.insert(0, 3, '#');
	cout << s1.c_str() << endl;


	lcz::string s2("helloworld");
	s2.insert(5, "%%%%%");
	cout << s2.c_str() << endl;
}

void test_string4()
{
	lcz::string s1("helloworld");
	cout << s1.c_str() << endl;

	s1.erase(5, 3);
	cout << s1.c_str() << endl;

	s1.erase(5, 30);
	cout << s1.c_str() << endl;

	s1.erase(2);
	cout << s1.c_str() << endl;
}

void test_string5()
{
	// 21：18继续
	lcz::string url = "ftp://www.baidu.com/?tn=65081411_1_oem_dg";

	size_t pos1 = url.find("://");
	if (pos1 != lcz::string::npos)
	{
		lcz::string protocol = url.substr(0, pos1);
		cout << protocol.c_str() << endl;
	}

	size_t pos2 = url.find('/', pos1 + 3);
	if (pos2 != lcz::string::npos)
	{
		lcz::string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
		lcz::string uri = url.substr(pos2 + 1);

		cout << domain.c_str() << endl;
		cout << uri.c_str() << endl;
	}
}

void test_string6()
{
	lcz::string s("hello world");
	s.resize(8);
	cout << s.c_str() << endl;
	cout << s << endl;

	s.resize(13, 'x');
	cout << s.c_str() << endl;
	cout << s << endl;

	s.resize(20, 'y');
	cout << s.c_str() << endl;
	cout << s << endl;

	// c的字符数组，以\0为终止算长度
	// string不看\0，以size为终止算长度

	lcz::string ss("hello world");
	ss += '\0';
	ss += "!!!!!!!!!!";
	cout << ss.c_str() << endl;
	cout << ss << endl;

	lcz::string copy(ss);
	cout << ss << endl;
	cout << copy << endl;

	ss += "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	cout << ss << endl;
}

void test_string7()
{
	lcz::string s;
	cin >> s;
	cout << s << endl;

	cin >> s;
	cout << s << endl;

	//char buff[128];
	//for (size_t i = 0; i < 5; i++)
	//{
	//	cin >> buff[i];
	//}

	//for (size_t i = 0; i < 5; i++)
	//{
	//	cout << buff[i] << endl;
	//}
}

void test_string8()
{
	//string s1("bb");
	//string s2("aaa");
	//cout << (s1 < s2) << endl;

	lcz::string s1("hello");
	lcz::string s2("hello");
	cout << (s1 < s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 == s2) << endl << endl;


	lcz::string s3("hello");
	lcz::string s4("helloxxx");
	cout << (s3 < s4) << endl;
	cout << (s3 > s4) << endl;
	cout << (s3 == s4) << endl << endl;


	lcz::string s5("helloxxx");
	lcz::string s6("hello");
	cout << (s5 < s6) << endl;
	cout << (s5 > s6) << endl;
	cout << (s5 == s6) << endl << endl;
}

void test_string9()
{
	lcz::string s1("hello");
	lcz::string s2(s1);

	cout << s1 << endl;
	cout << s2 << endl;

	lcz::string s3("xxxxxxxxxxxxx");
	s1 = s3;

	cout << s1 << endl;
	cout << s3 << endl;
}

int main()
{
	test_string5();

	return 0;
}