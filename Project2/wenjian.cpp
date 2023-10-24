# include<iostream>
using namespace std;
# include<fstream>
# include<string>

//文本文件
//写文件
void test61()
{
	//1 包含头文件<fstream>
	
	//2 创建流对象
	ofstream ofs;   //写
	//3 指定打开方式
	ofs.open("test.txt", ios::out);  //打开方式 写 ios::out
	//4 写内容
	ofs << "姓名：张三" << endl;
	ofs << "姓名：李四" << endl;
	ofs << "姓名：王五" << endl;
	//5 关闭
	ofs.close();
}

//读文件
void test62()
{
	//1 包含头文件<fstream>

	//2 创建流对象
	ifstream ifs;   //读
	//3 打开文件 并且判断是否成功打开
	ifs.open("test.txt", ios::in);    //打开方式  读ios::in
	
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4 读数据
	//方式一
	//char b[1024] = { 0 };  
	//while (ifs >> b)
	//{
	//	cout << b << endl;
	//}
	
	//方式二
	//char b[1024] = { 0 };
	//while (ifs.getline(b,sizeof(b)))
	//{
	//	cout << b << endl;
	//}

	//方式三
	string b;
	while ( getline(ifs,b))
	{
		cout << b << endl;
	}

	//方式四
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;
	//}

	//5 关闭
	ifs.close();

}

//二进制文件
//写文件
class base5
{
public:
	char name[64];
	int age;
};

void test63()
{
	//1 包含头文件<fstream>

	//2 创建流对象
	ofstream ofs;   //写
	//3 指定打开方式
	ofs.open("person.txt", ios::out|ios::binary);  //打开方式 写 ios::out   二进制 ios::binary
	//4 写内容
	base5 b = { "张三",18 };
	ofs.write((const char*)&b, sizeof(b));
	//5 关闭
	ofs.close();
}

//读文件
void test64()
{
	//1 包含头文件<fstream>

	//2 创建流对象
	ifstream ifs;   //读
	//3 打开文件 判断是否打开成功
	ifs.open("person.txt", ios::in | ios::binary);  //打开方式 读 ios::in   二进制 ios::binary
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4 读内容
	base5 b;
	ifs.read((char *)&b,sizeof(b));
	cout << "姓名："<< b.name << endl;
	cout << "年龄："<< b.age << endl;
	//5 关闭
	ifs.close();
}

//int main()
//{
//	//test61();
//	//test62();
//	//test63();
//	test64();
//
//	system("pause");
//	return 0;
//}