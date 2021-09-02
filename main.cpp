#include "url.h"
#include <fstream>

int main() {

	Url* url = new Url();
	
	//进行URL编码 纯英文 对于不带中文的字符转的码ansi和utf8是一样的
	string str1 = "=;+/,";
	string str1_url = url->urlEncode(str1);
	cout << str1_url << endl;

	//对于带中文的ansi编码和解码 
	string str_ansi = "还魂草";
	string str_ansi_en = url->urlEncode(str_ansi);
	cout << str_ansi_en << endl;
	//ansi的中文解码后也是ansi格式的中文
	string str_ansi_de = url->urlDecode(str_ansi_en);
	cout << str_ansi_de << endl;

	//对于带中文的utf8的编码和解码
	string str_utf8 = u8"还魂草";
	string str_utf8_en = url->urlEncode(str_utf8);
	//可以看到相同的中文 utf8和ansi是不一样的
	cout << str_utf8_en << endl;
	//utf8的中文解码后也是utf8的
	string str_utf8_de = url->urlDecode(str_utf8_en);
	cout << str_utf8_de << endl;
	ofstream wtxt("log.txt");
	wtxt << str_utf8_de << endl;
	wtxt.close();

	delete url;
	system("pause");
	return 0;
}