#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

std::fstream inFile;//这样可能会快点
std::ofstream outFile;

int main(int argc, char* args[]) {

	//错误处理
	if (argc < 2) {
		std::cerr << "参数太少！too few arguments \n";
		return -1;
	}
	else if (argc > 2) {
		std::cerr << "参数太多！ too much arguments! \n";
		return -1;
	}

	//打开文件
	inFile.open(args[1], std::ios::in | std::ios::binary);
	std::cout << "文件名:" << args[1] << "\n";

	//新建输出文件
	std::string outName = args[1];
	outName += ".reverse";
	outFile.open(outName, std::ios::out | std::ios::binary | std::ios::trunc);

	//错误处理
	if (!inFile.is_open()) {
		std::cerr << "无法打开文件:" << args[1];
		return -1;
	}
	if (!outFile.is_open()) {
		std::cerr << "无法打开文件:" << outName;
		return -1;
	}

	//获取文件大小
	inFile.seekg(0, std::ios::end);
	int size = (int)inFile.tellg();
	std::cout << "文件大小:" << size << "\n";

	//建立缓冲区
	char* buffer = (char*)malloc(size);

	//读取数据到缓冲区
	inFile.seekg(0, std::ios::beg);
	inFile.read(buffer, size);

	//反转缓冲区
	std::vector<char> revBuffer(buffer, buffer + size);
	std::reverse(revBuffer.begin(), revBuffer.end());

	//输出保存
	outFile.write(revBuffer.data(), size);

	//结束
	inFile.close();
	outFile.close();
	return 0;
}


//fuck this shit, I love C more than C++

//no ,I love C++ again

//2025.07.21