//Ϊ��ʵ�ּ������������һ������ջ���������󷵻ع��ܣ���ʵ�����κ��ַ�����ջ
template<typename T>
class miniStack
{
public:
	bool empty();
	bool full();
	T get_top();
	void push(T data);
	void pop();


private:
	int size = 100;
	T num_stack[100] = { '\0' };
	int tick = 0;





};


template<typename T>
bool miniStack<T>::empty()
{
	if (tick == 0)
		return 1;
	else
		return 0;
}
template<typename T>

bool miniStack<T>::full()
{
	if (size == tick)
		return 1;
	else
		return 0;
}
template<typename T>

T miniStack<T>::get_top()
{
	if (!empty())
		return num_stack[tick - 1];

}
template<typename T>

void miniStack<T>::push(T data)
{
	if (!full())
	{
		num_stack[tick] = data;
		tick++;
	}
}
template<typename T>

void miniStack<T>::pop()
{
	if (!empty())
	{
		num_stack[tick - 1] = '\0';
		tick--;
	}



}




