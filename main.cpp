#include "url.h"
#include <fstream>

int main() {

	Url* url = new Url();
	
	//����URL���� ��Ӣ�� ���ڲ������ĵ��ַ�ת����ansi��utf8��һ����
	string str1 = "=;+/,";
	string str1_url = url->urlEncode(str1);
	cout << str1_url << endl;

	//���ڴ����ĵ�ansi����ͽ��� 
	string str_ansi = "�����";
	string str_ansi_en = url->urlEncode(str_ansi);
	cout << str_ansi_en << endl;
	//ansi�����Ľ����Ҳ��ansi��ʽ������
	string str_ansi_de = url->urlDecode(str_ansi_en);
	cout << str_ansi_de << endl;

	//���ڴ����ĵ�utf8�ı���ͽ���
	string str_utf8 = u8"�����";
	string str_utf8_en = url->urlEncode(str_utf8);
	//���Կ�����ͬ������ utf8��ansi�ǲ�һ����
	cout << str_utf8_en << endl;
	//utf8�����Ľ����Ҳ��utf8��
	string str_utf8_de = url->urlDecode(str_utf8_en);
	cout << str_utf8_de << endl;
	ofstream wtxt("log.txt");
	wtxt << str_utf8_de << endl;
	wtxt.close();

	delete url;
	system("pause");
	return 0;
}