// Queue.h
#ifndef QUEUE
#define QUEUE
#include<list>
template<typename Queue_entry>
class Queue {
public:
	Queue( )=default;
	bool empty( )const{
		return data.empty();
	}
	Error_code append(const Queue_entry &x){
		try{
			data.push_back(x);
		}catch(const std::bad_alloc&){
			return overflow;
		}
		return success;
	}
	Error_code serve( ){
		if(data.empty())
			return underflow;
		data.pop_front();
		return success;
	}
	Error_code retrieve(Queue_entry &x)const{
		if(data.empty())
			return underflow;
		x=data.front();
		return success;
	}
protected:
	// front - front of queue
	// back  - rear  of queue
	std::list<Queue_entry> data;
};
template<typename Queue_entry>
class Extended_queue:public Queue<Queue_entry>{
public:
	bool full( )const{
		return false;
	}
	int size( )const{
		return Queue<Queue_entry>::data.size();
	}
	void clear( ){
		Queue<Queue_entry>::data.erase();
	}
	Error_code serve_and_retrieve(Queue_entry &item){
		if(Queue<Queue_entry>::data.empty())
			return underflow;
		item=Queue<Queue_entry>::data.front();
		Queue<Queue_entry>::data.pop_front();
	}
};
#endif