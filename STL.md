# C++ Standard Template Library

## 1 vector

- 使用倍增思想进行存储的变长数组
- 是一种模板类型
- 在不知道数据元素有多少个的时候使用
- 支持按照下标访问
- 支持按照字典序进行比较运算

### 1.1 初始化

```cpp
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

也可以直接调用insert方法插入元素对,insert操作会返回一个pair,当map中没有与key相匹配的键值时,其first是指向插入元素对的迭代器,其second为true;若map中已经存在与key相等的键值时,其first是指向该元素对的迭代器,second为false。

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



