#ifndef __G_ARRAY__
#define __G_ARRAY__
#include <iostream>
using namespace std;

//ArrayŬ������ ��ӹ޾� �迭�� ũ�⸦ �ø��� �߰������� �ʿ��� �Լ��� �������Ͽ� ���.
//���ø��� �̿������ν� �迭�� ������ �ڷ����� �����Ӱ� �� �� �ִ�.
template <typename T>
class GrowableArray :public Array<T> {
public:
	GrowableArray<T>(int size) {
		if (size <= 0) {
			cout << "Array size error!\n";
		}
		else {
			this->data = new T[size];
			this->len = size;
		}
	}
	
	//���� �迭�� ũ�⺸�� ū �ε��� ���� ���޹�����, �����޼����� ����ϴ� ���
	//���ο� �迭�� ���޹��� �ε��� ���� �ι�� �޸𸮸� �Ҵ��ϰ� ���� �Լ��� ���� �����Ѵ�.
	//�������� 0���� �ʱ�ȭ�ϰ�, �� �ν��Ͻ��� data�迭�� �� �迭�� �ּҸ� �ٲ۴�.
	//���� �迭�� delete[]�� �̿��Ͽ� �޸������� �����ش�.
	virtual T & operator [](int i) {
		if (i < this->len && i >= 0) {
			return this->data[i];
		}
		else {
			int j;
			T *ndata;
			ndata = new T[i * 2];
			for (j = 0; j < this->len; j++) {
				ndata[j] = this->data[j];
			}
			this->len = i * 2;
			for (j; j < this->len; j++) {
				ndata[j] = 0;
			}
			delete[] this->data;
			this->data = ndata;

			return this->data[i];
		}
	}
};


#endif