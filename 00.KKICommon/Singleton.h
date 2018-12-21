#pragma once

template<typename T>
class Singleton
{
public:
	Singleton();
	virtual ~Singleton();

	static T* GetSingleton();

private:
	static T* _singleton;
};

template<typename T> 
T* Singleton<T>::_singleton = nullptr;

template<typename T>
Singleton<T>::Singleton()
{
}

template<typename T>
Singleton<T>::~Singleton()
{
}

template<typename T>
T* Singleton<T>::GetSingleton()
{
	if (_singleton == nullptr) {
		_singleton = new T;
	}

	return _singleton;
}
