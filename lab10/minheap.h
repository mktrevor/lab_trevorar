#ifndef MINHEAP_H
#define MINHEAP_H

template <typename T>
class MinHeap
{ public:
   virtual void push(const T& item) = 0;
   virtual T& top() = 0;
   virtual void pop() = 0;
   virtual int size() const = 0;
   virtual bool empty() const = 0;
   virtual bool decreaseKey(const T& val, const T& newVal) = 0;
};

#endif
