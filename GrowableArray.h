#ifndef __G_ARRAY__
#define __G_ARRAY__
#include <iostream>
using namespace std;

//Array클래스를 상속받아 배열의 크기를 늘리는 추가구현이 필요한 함수만 재정의하여 사용.
//템플릿을 이용함으로써 배열의 원소의 자료형을 자유롭게 할 수 있다.
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
	
	//원래 배열의 크기보다 큰 인덱스 값을 전달받으면, 에러메세지를 출력하는 대신
	//새로운 배열을 전달받은 인덱스 값의 두배로 메모리를 할당하고 원래 함수의 값을 저장한다.
	//나머지는 0으로 초기화하고, 이 인스턴스의 data배열을 새 배열로 주소를 바꾼다.
	//원래 배열은 delete[]를 이용하여 메모리해제를 시켜준다.
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