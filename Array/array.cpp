#include <iostream>
using namespace std;

class Array
{
private:
  int size;
  int length;
  int * items;
public:
  Array(int size){
    this->size = size;
    length = 0;
    items = new int[size];
  }
  void fill(){
    length = 0;
    int no_of_items;
    cout<<"How many items you want to fill? ";
    cin >> no_of_items;
    if(no_of_items > size){
      cout<<"You can't exceed the array size.\n";
      return;
    }else{
      for (int i = 0; i < no_of_items; i++){
        cout<< "element no. "<<i+1<<": ";
        cin>>items[i];
        length++;
      }
    }
  }
  int getSize(){
    return size;
  }
  int getLength(){
    return length;
  }
  int Search(int key){
    int index = -1;
    for (int i = 0; i < length; i++){
      if (items[i] == key){
        index = i;
        break;
      }
    }
    return index;
  }
  void Append(int newItem){
    if (length == size){
      cout<<"Array is full.\n";
    }else{
      items[length] = newItem;
      length++;
    }
  }
  void Insert(int idx, int item){
    if (idx < size){
      if (length == size){
        cout<<"Array is full.\n";
      }else{
        if (idx<length){
          for(int i=length;i>idx;i--){
            items[i] = items[i-1];
          }
          items[idx] = item;
          length ++;
        }else{
          cout<<"Try to append cuz you exceed length.\n";
        }
      }
    }else{
      cout<< "you can't exceed array size.\n";
    }
  }
  void Delete(int idx){
    if (idx >=0 && idx < length){
      for (int i = idx; i < length-1; i++)
      {
        items[i] = items[i+1];
      }
      length--;
      cout<<"Deleted successfully.\n";
    }else{
      cout<<"Index out of range.\n";
    }
  }
  void Enlarge(int newSize){
    if(newSize <= size){
      cout<<"New size must be larger than old size.\n";
    }else{
      size = newSize;
      int * old = items;
      items = new int[newSize];
      for (int i = 0; i < length; i++){
        items[i] = old[i];
      }
      delete[] old;
    }
  }
  void Merge(Array other){
    int * old = items;
    size += other.getSize();
    items = new int[size];
    int i;
    for (i = 0; i < length; i++){
      items[i] = old[i];
    }
    delete[] old;
    // int j=i;
    // for (int i = 0; i < other.getLength(); i++){
    //   items[j++] = other.items[i];
    //   length++;
    // }
    for (int i = length; i < length+other.getLength(); i++){
      items[i] = other.items[i-length];
    }
    length += other.getLength();
  }
  void display(){
    if(length == 0){
      cout<<"Array is empty.\n";
    }else{
      cout<<"Array items: ";
      for (int i = 0; i < length; i++)
      {
        cout<<items[i]<<"   ";
      }
      cout<<"\n";
    }
  }
};
int main(){
  int arrSize, key, newItem, item, idx, idx_delete, newSize;
  char c;
  Array arr(3);
  arr.fill();
  arr.display();
  Array other(3);
  other.fill();
  other.display();
  arr.Merge(other);
  arr.display();
  // do{
  //   cout<<"Enter array size: ";
  //   cin>>arrSize;
  //   Array a(arrSize);
  //   a.fill();
  //   a.display();
  //   a.Merge(other);
  //   cout<<"Array size: "<<a.getSize()<<"\n";
  //   cout<<"Array length: "<<a.getLength()<<"\n";
  //   a.display();
  //   cout<< "Enter key you want to search for: ";
  //   cin>>key;
  //   if(a.Search(key) != -1)
  //     cout<<"Key found at index: "<<a.Search(key)<<"\n";
  //   else
  //     cout<<"Key not found in array\n";
  //   cout<<"Enter number you wanna append it to array: ";
  //   cin>>newItem;
  //   a.Append(newItem);
  //   a.display();
  //   cout<<"Enter number you wanna insert it to array: ";
  //   cin>>item;
  //   cout<<"want it at index no: ";
  //   cin>>idx;
  //   a.Insert(idx, item);
  //   a.display();
  //   cout<<"Enter index for element you wanna delete it: ";
  //   cin>>idx_delete;
  //   a.Delete(idx_delete);
  //   a.display();
  //   cout<<"Array size: "<<a.getSize()<<"\n";
  //   cout<<"Array length: "<<a.getLength()<<"\n";
  //   cout<<"Enter new size to enlarge the array: ";
  //   cin>>newSize;
  //   a.Enlarge(newSize);
  //   cout<<"Array size: "<<a.getSize()<<"\n";
  //   cout<<"Enter number you wanna append it to array: ";
  //   cin>>newItem;
  //   a.Append(newItem);
  //   a.display();
  //   cout<< "want to repeat operation? y or n \nyour choice: ";
  //   cin >> c;
  // }while(c == 'y');
  return 0;
}