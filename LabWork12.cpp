#include <iterator>
#include <array>
#include <list>
#include <cstddef>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
template <typename T>
struct RevIterator 
{
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;

    RevIterator(pointer ptr) : m_ptr(ptr) {}

    reference operator*() const { return *m_ptr; }
    RevIterator& operator++() { m_ptr--; return *this; }  
    RevIterator& operator--() { m_ptr++; return *this; }  
    RevIterator operator++(int) { RevIterator tmp = *this; --(*this); return tmp; }
    RevIterator operator--(int) { RevIterator tmp = *this; ++(*this); return tmp; }
    RevIterator& operator+(int offset) { m_ptr-=offset; return *this; }
    RevIterator& operator-(int offset) { m_ptr+=offset; return *this; }
    friend bool operator== (const RevIterator& a, const RevIterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const RevIterator& a, const RevIterator& b) { return a.m_ptr != b.m_ptr; };  

private:
  pointer m_ptr;

};

template <typename T>
class vector_iter
{
public:
    vector_iter(std::vector<T> &m_data): m_data(m_data) {}
    RevIterator<T> begin() { return RevIterator<T>(&m_data[m_data.size()-1]); }
    RevIterator<T> end()   { return RevIterator<T>(&m_data[0]-1); }
private:
    std::vector<T> &m_data;
};

template <typename T>
class list_iter
{
public:
    list_iter(std::list<T> &m_data): m_data(m_data) {}
    RevIterator<T> begin() { return RevIterator<T>(&(m_data.back())-1); }
    RevIterator<T> end()   { return RevIterator<T>(&(m_data.front())-1); }
private:
    std::list<T> &m_data;
};

template <typename T>
class array_iter
{
public:
    array_iter(std::array<T, 5> &m_data): m_data(m_data) {}
    RevIterator<T> begin() { return RevIterator<T>(&m_data[m_data.size()]-1); }
    RevIterator<T> end()   { return RevIterator<T>(&m_data[0]-1); }
private:
    std::array<T, 5> &m_data;
};

template <typename T>
class deque_iter
{
public:
    deque_iter(std::deque<T> &m_data): m_data(m_data) {}
    RevIterator<T> begin() { return RevIterator<T>(&m_data[m_data.size()]-1); }
    RevIterator<T> end()   { return RevIterator<T>(&m_data[0]-1); }
private:
    std::deque<T> &m_data;
};
int main()
{
  std::vector<int> data={1,2,3,4,5};
  std::vector<double> data1={1.5,2.1,33.12312,4.211,5.75};
  std::vector<char> data2={'a','h','t','r','i'};
  std::vector<std::string> data3={"alexey","ivan","murad","alihan","joe"};
  vector_iter vdouble(data1);
  vector_iter vchar(data2);
  vector_iter vstring(data3);
  vector_iter vint(data);
  data.erase(data.begin()+1);
  for (auto it = vint.begin(), end=vint.end(); it != end; ++it) { 
    const auto i = *it; 
    std::cout << i << " ";
  }
  std::cout <<"\n";
  for (auto it = vdouble.begin(), end=vdouble.end(); it != end; ++it) { 
    const auto i = *it; 
    std::cout << i << " ";
  }
  std::cout <<"\n";
  for (auto it = vchar.begin(), end=vchar.end(); it != end; ++it) { 
    const auto i = *it; 
    std::cout << i << " ";
  }
  std::cout <<"\n";
  for (auto it = vstring.begin(), end=vstring.end(); it != end; ++it) { 
    const auto i = *it; 
    std::cout << i << " ";
  }
  std::cout <<"\n";
  std::cout <<"------------------------------------------\n";
  std::deque<int> ddata{1,2,3,4,5};
  std::deque<double> ddata1={1.51,52.1,33.12312,94.2121,5.75};
  std::deque<char> ddata2={'z','o','v','s','s'};
  std::deque<std::string> ddata3={"john","max","alexey","andrey","masha"};
  deque_iter ddouble(ddata1);
  deque_iter dchar(ddata2);
  deque_iter dstring(ddata3);
  deque_iter dint(ddata);
  ddata.erase(ddata.begin()+3);
  for (auto it = dint.begin(), end=dint.end(); it != end; ++it) { 
    const auto i = *it; 
    std::cout << i << " ";
  }
  std::cout <<"\n";
  for (auto it = ddouble.begin(), end=ddouble.end(); it != end; ++it) { 
    const auto i = *it; 
    std::cout << i << " ";
  }
  std::cout <<"\n";
  for (auto it = dchar.begin(), end=dchar.end(); it != end; ++it) { 
    const auto i = *it; 
    std::cout << i << " ";
  }
  std::cout <<"\n";
  for (auto it = dstring.begin(), end=dstring.end(); it != end; ++it) { 
    const auto i = *it; 
    std::cout << i << " ";
  }
  std::cout <<"\n";
}

