#pragma once

#include <iostream>
using namespace std;

class Url {
public:
	Url();
	~Url();

	// url����
	string urlEncode(const string& str);

	// url����
	string urlDecode(const string& str);

private:
	unsigned char toHex(unsigned char x);
	unsigned char fromHex(unsigned char x);

};