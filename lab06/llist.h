#ifndef LLIST_H
#define LLIST_H

template <typename T>
struct Item {
  T val;
  Item<T> *next;
};

template <typename T>
class LList {
 public:
  LList();
  ~LList();
  bool empty() const;
  int size() const;
  void push_back(const T& new_val);
  void pop_front();
  T& peek_front() const;
  //T& at(int loc) const;
  //bool remove(const T& val);
  void clear();
 private:
  Item<T> *getNodeAt(int loc) const;

 private:
  Item<T> *head_;
};

// Write the constructor here
template <typename T>
LList<T>::LList()
{

}




// Write the destructor here
template <typename T>
LList<T>::~LList()
{
  clear();
}





template <typename T>
bool LList<T>::empty() const
{


}

template <typename T>
int LList<T>::size() const
{



}

template <typename T>
Item<T>* LList<T>::getNodeAt(int loc) const
{


}

template <typename T>
void LList<T>::push_back(T new_val)
{




} 

template <typename T>
T LList<T>::pop_front()
{


}

template <typename T>
T& LList<T>::peek_front() const
{


}

//template <typename T>
//bool LList<T>::remove(const T& val)
//{
//
//}

//template <typename T>
//T& LList<T>::at(int loc) const
//{
//}


template <typename T>
void LList<T>::clear()
{
  while(head_ != NULL){
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
}


#endif
