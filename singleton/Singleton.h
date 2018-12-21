#pragma once

template<typename T>
class Singleton
{
public:
	Singleton() {};
	virtual ~Singleton() {};

	static T* GetSingleton() {
		if (_Singleton == nullptr) {
			_Singleton = new T;
		}
		return _Singleton;
	}

private:
	static T* _Singleton;
};

template<typename T> T* Singleton<T>::_Singleton = nullptr;

