# C++ Standard Template Library

## 1 vector

- 使用倍增思想进行存储的变长数组
- 是一种模板类型
- 在不知道数据元素有多少个的时候使用
- 支持按照下标访问
- 支持按照字典序进行比较运算

### 1.1 初始化

```cpp
#include<vector>
vector<int> v1; // 定义一个vector
vector<int> v2(300); // 定义一个初始大小为300的vector
```

### 1.2 基本操作

```cpp
vector<int> v;
// 使用 v.functon(); 调用自带的函数
// e.g. int k = v.size(); k里面就存储了当前现有的元素个数

size()  // 返回元素个数
empty()  // 返回是否为空
clear()  // 清空
front()/back() // 取最前/最后元素
push_back()/pop_back() // 在vector的最前位置/最后位置插入一个新元素
begin()/end() // vector的首迭代器和尾迭代器
```

## 2 pair

- `pair` 将一对值 (T1和T2) 组合成一个值
- `pair` 将2个数据组合成一组数据，当需要这样的需求时就可以使用 `pair`

### 2.1 初始化

- `pair` 包含两个数值，与容器一样，`pair`也是一种模板类型
- 在创建 `pair` 对象时，必须提供两个类型名，两个对应的类型名的类型不必相同

```cpp
pair<T1, T2> p1;            //创建一个空的pair对象（使用默认构造），它的两个元素分别是T1和T2类型，采用值初始化。
pair<T1, T2> p1(v1, v2);    //创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，second成员初始化为v2。
make_pair(v1, v2);          // 以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。

pair<string, string> anon;        // 创建一个空对象anon，两个元素类型都是string
pair<string, int> word_count;     // 创建一个空对象 word_count, 两个元素类型分别是string和int类型
pair<string, vector<int> > line;  // 创建一个空对象line，两个元素类型分别是string和vector类型
```

- 可以在定义时进行成员初始化

```cpp
pair<string, string> author("James","Joy");    // 创建一个author对象，两个元素类型分别为string类型，并默认初始值为James和Joy。
pair<string, int> name_age("Tom", 18);
pair<string, int> name_age2(name_age);    // 拷贝构造初始化
```

### 2.2 基本操作

```cpp
p1 < p2;                   // 两个pair对象间的小于运算，其定义遵循字典次序：如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回true。
p1 == p2;                 // 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
p1.first;                  // 返回对象p1中名为first的公有数据成员
p1.second;                 // 返回对象p1中名为second的公有数据成员
```

## 3 map

- 可以将 `map` 看作是由 `key` 标识元素的元素集合，这类容器也被称为“关联容器”，可以通过一个 `key` 值来快速决定一个元素，因此非常适合于需要按照 `key` 值查找元素的容器。
- STL 的容器 map 为我们处理有序 key-value 形式数据提供了非常大的便利，由于内部红黑树结构的存储，查找等操作的时间复杂度均为 $O(\log N)$。

### 3.1 初始化

```cpp
#include<map>
map<T1, T2> mp; //创建一个空的map,它的key为T1类型,value为T2类型
map<string, int> mp_cnt; //创建一个key为string类型,value为int类型的map
```

### 3.2 基本操作

#### 3.2.1 向 map 中插入元素

```cpp
mp[key] = value; 
```

[key] 操作是 map很有特色的操作,如果在map中存在键值为key的元素对, 则返回该元素对的值域部分,否则将会创建一个键值为key的元素对,值域为默认值。所以可以用该操作向map中插入元素对或修改已经存在的元素对的值域部分。

```cpp
m.insert(make_pair(key, value));  
```

也可以直接调用insert方法插入元素对，insert操作会返回一个pair，当map中没有与key相匹配的键值时，其first是指向插入元素对的迭代器，其second为true;若map中已经存在与key相等的键值时，其first是指向该元素对的迭代器，second为false。

#### 3.2.2 查找元素

```cpp
int i = m[key]; 
```

注意：当与该键值相匹配的元素对不存在时,会创建键值为key（当另一个元素是整形时，m[key]=0）的元素对。

```cpp
map<string, int>::iterator it = m.find(key);  
```

如果map中存在与key相匹配的键值时,find操作将返回指向该元素对的**迭代器**,否则,返回的迭代器等于map的end()

#### 3.3.3 删除元素

erase的参数可以是key或者迭代器

```cpp
m.erase(key);   
```

删除与指定key键值相匹配的元素对，**并返回**被删除的元素的个数。

```cpp
m.erase(it);   
```

删除由迭代器it所指定的元素对,**并返回**指向下一个元素对的迭代器。

#### 3.3.4 其他

```cpp
m.size();      //返回元素个数
m.empty();     //判断是否为空
m.clear();     //清空所有元素
m.begin();     //返回首迭代器
m.end();       //返回尾迭代器
```

### 3.3 实例

问题：用 map 统计字符串出现的次数

给定 $n$ 个字符串，$m$ 个询问，每个问题询问一个字符串出现的次数。$n\le 2\times 10^4, m\le 2\times 10^4$，每个字符串的长度都不超过 $20$。

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    map<string, int> h;
    char str[50];
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        h[str]++;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%s", str);
        if (h.find(str) == h.end())
            puts("0");
        else printf("%d\n", h[str]);
    }
    return 0;
}
```

## 4 string

- 和字符型数组类似，是一个存储字符串的类型
- 不可使用 `scanf` 读入

### 4.1 初始化

```cpp
string s;
cin >> s; // 直接使用cin读入一个字符串
string s2 = {'1','2','3','4','5'}; // 像构造数组一样构造
```

### 4.2 基本操作

```cpp
string s;
// 使用 s.function(); 调用自带的函数

size()/length()  										//返回字符串长度
empty() 												//返回字符串是否为空
clear()													//清空字符串
substr(起始下标,(子串长度))  						  	   //返回子串
to_string() 											//把一个数值转化为字符串
c_str()  												//返回字符串所在字符数组的起始地址
find()													//用来找一个串是否包含一个子串
//(1) 如果找到了字串:返回第一个字串的起始下标
//(2) 如果没有找到(设字符串为s):返回s.
    
//以下函数只能在在只含有大小写英文字符的串中才能正常工作
transform(s.begin(), s.end(), s.begin(), ::toupper); 	//转换为大写
transform(s.begin(), s.end(), s.begin(), ::tolower); 	//转换为小写
s[i] = toupper(s[i]);									//把字符串的单个字符变大写
s[i] = tolower(s[i]);									//把字符串的单个字符变小写
```

## 5 stack

- 实现一个先近后出的数据结构
- 在弹出数据时需要判断栈是否为空
- 基础知识参考: [数据结构（C语言版） 第 三 章 栈与队列 知识梳理 + 作业习题详解](https://fanfansann.blog.csdn.net/article/details/105947123)

### 5.1 初始化

```cpp
#include<stack>
stack<int> sta; //初始化一个空栈
```

### 5.2 基本操作

```cpp
size()  //求栈的大小
empty() //判断栈是否为空
push()  //向栈顶插入一个元素
top()   //返回栈顶元素
pop()   //弹出栈顶元素
```

## 6 queue

- 实现一个先进先出的数据结构
- 在弹出数据时需要判断队列是否为空
- 基础知识参考: [数据结构（C语言版） 第 三 章 栈与队列 知识梳理 + 作业习题详解](https://fanfansann.blog.csdn.net/article/details/105947123)

### 6.1 初始化

```cpp
#include<queue>
queue<int> q; //初始化一个空队列
```

### 6.2 基本操作

```cpp
size()  //求队列的大小
empty() //判断队列是否为空
push()  //向队尾插入一个元素
front() //返回队头元素
back()  //返回队尾元素
pop()   //弹出队头元素
```

## 7 set

- 和数学上的集合定义一致
- 整个集合是有序的（数字从小到大、字符串按字典序）
- 每个操作的时间复杂度：$O(\log n)$

### 7.1 初始化

```cpp
#include<set>
set<int> s; //初始化一个空集合
```

### 7.2 基本操作

```cpp
size()         //求集合的大小
empty()		   //判断集合是否为空
clear()		   //清空集合
begin()/end()  //返回集合的开头元素和末尾元素
insert()       //插入一个数
find()         //查找一个数
count()        //返回某一个数的个数
erase()        //(1) 输入如果是一个数x,那么删除x 
               //(2) 输入一个迭代器，删除这个迭代器
```



## 数值和字符串转换

1. string 类

```
string和数值转换	 转换类型
to_string(val)	把val转换成string
stoi(s,p,b)		把字符串s从p开始转换成b进制的int
stol(s,p,b)		把字符串s从p开始转换成b进制的long
stoul(s,p,b)	把字符串s从p开始转换成b进制的unsigned long
stoll(s,p,b)	把字符串s从p开始转换成b进制的long long
stoull(s,p,b)	把字符串s从p开始转换成b进制的unsigned long long
stof(s,p)		把字符串s从p开始转换成float
stod(s,p)		把字符串s从p开始转换成double
stold(s,p)		把字符串s从p开始转换成long double
```

2. char 类

```
字符串和数值转换   	 作用
atof(s)				将字符串s[n]转换为双精度浮点型值。
atoi(s)				将字符串s[n]转换为整型值。
atol(s)				将字符串s[n]转换为长整型值。
strtod(s,*p,b)		将字符串s[n]转换为b进制双精度浮点型值，到p停止,并报告不能被转换的所有剩余数字。
strtol(s,*p,b)		将字符串s[n]转换为b进制长整值，到p停止,并报告不能被转换的所有剩余数字。
strtoul(s,*p,b)		将字符串s[n]转换为b进制无符号长整型值，到p停止,并报告不能被转换的所有剩余数字。
```

