##[SQL必知必会] 学习笔记

###**[检索数据]**
####1.检索单个列:
```sql
SELECT prod_name
FROM Products;
```

####2.检索多个列：
```sql
SELECT prod_name, prod_id, prod_price
FROM Products;
```

####3.检索所有列：
```sql
SELECT * 
FROM Products;
```

###[**排序检索数据**]
####1.排序数据：
```sql
SELECT prod_name 
FROM Products
ORDER BY prod_name;
```
> ORDER BY子句中使用的列可以是显示所选择的列，也可以是非检索的列，即可以用别的非检索列做排序,ORDER BY子句放在最后位置

####2.按多个列排序：
```sql
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY prod_price, prod_name;
```
> 多个列排序时，仅在第一个拍序列中有重复数据时，才会再按照第二个列排序，否则就都按照第一个列排序

####3.按照位置排序：
```sql
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY 2, 3
```
> 2表示SELECT列表中的prod_price，3表示SELECT列表中的prod_name，可以减少重复输入名称

####4.指定排序方向：
```sql
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY prod_price DESC;
```
 > 默认采用升序排列，DESC表示降序排列，如果有多个列排序，DESC关键字应用到直接位于其前面的列名称
 
```sql
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY prod_price DESC, prod_name;
```

###[**过滤数据**]
####1.使用where子句：
```sql
SELECT prod_name, prod_price
FROM Products
WHERE prod_price = 3.49;
```

####2.检查单个值：
```sql
SELECT prod_name, prod_price
FROM Products
WHERE prod_price < 10;
```

####3.不匹配检查：
```sql
SELECT vend_id, prod_name
FROM Products
WHERE vend_id <> 'DLL01'; 
或者 WHERE vend_id != 'DLL01';
```
> 单引号用于限定字符串类型的数据，数字类型数据不需要

####4.范围值检查
```sql
SELECT prod_name, prod_price 
FROM Products
WHERE prod_price BETWEEN 5 AND 10;
```

####5.空值检查
```sql
SELECT prod_name
FROM Products
WHERE prod_price IS NULL;
```
> NULL表示空值，与0、空字符、空格不一样


###[**高级数据过滤**]
> 逻辑操作符：用来联结或改变WHERE子句中的子句的关键字 

####1.AND操作符
```sql
SELECT prod_id, prod_price, prod_name
FROM Products
WHERE vend_id = 'DLL01' AND prod_price <= 4;
```

####2.OR操作符：
```sql
SELECT prod_id, prod_name, prod_price
FROM Products
WHERE vend_id = 'DLL01' OR vend_id = 'BRS01';
```
> 如果第一个条件满足，则后面的条件不再计算，提高查询效率

####3.计算次序：
```sql
SELECT prod_id, prod_name, prod_price
FROM Products
WHERE (vend_id = 'DLL01' OR vend_id = 'BSR01') AND proc_price >= 10;
```
> AND和OR的计算次序，AND优先级更高，因此要注意计算顺序，尽量使用圆括号保证

####4.IN操作符：
```sql
SELECT prod_id, prod_name, prod_price
FROM Products
WHERE vend_id IN ('DLL01', 'BSR01')
ORDER BY prod_name;
```
>  IN操作符也表示取值范围，但是是单点的不连续的条件集合，但是BETWEEN是连续条件的集合.IN操作符更类似于OR操作符，多个条件中某一个满足即可。

####5.NOT操作符：
```sql
SELECT prod_id, prod_price, prod_name
FROM Products
WHERE NOT vend_id = 'DLL01' 或 WHERE vend_id <> 'DLL01'
ORDER BY prod_name;
```
> NOT操作符只有一个功能，否定其后的任何条件，因为NOT从不自己单独使用，


###[**用通配符进行过滤**]
> 使用通配符，必须使用LIKE操作符，通配符只能用于文本字段，不能用于非文本数据类型

####1.%通配符：表示
```sql
SELECT prod_id, prod_name, prod_price
FROM Products
WHERE prod_name LIKE 'Fish%' 或 WHERE prod_name LIKE '%bean bag%' 或 WHERE prod_name LIKE 'F%Y';
```
> %表示任意字符出现任何次数，包括可以匹配0个字符。

####2.*_*下划线通配符：
```sql
SELECT prod_id, prod_name, prod_price
FROM Products
WHERE prod_name LIKE '_ inch teddy bear';
```
> 下划线*_*通配符和%通配符的不同：下划线*_*通配符总是匹配一个字符，而%通配符可以匹配0个到n个字符。

####3.方括号[]通配符：
```sql
SELECT cust_contact 
FROM Customers
WHERE cust_contact LIKE '[JM]%'
ORDER BY cust_contact;
```
> 方括号[]通配符用来指定一个字符集，必须匹配[]内的一个字符才可以，支持的DBMS不多。

####4.*通配符使用技巧*：
* 1.不要过分使用通配符，尽量选择其他操作符，减少通配符的使用；
* 2.在使用通配符时，不要放在搜索模式的开始处，开始处的通配符搜索起来是最慢的

###**[创建计算字段]**
####1.拼接字段：
```sql
SELECT vend_name || '(' || vend_country || ')' 
AS vend_title
FROM Vendors
ORDER BY vend_name;
```
```sql
SELECT vend_name + '(' + vend_country + ')'
AS vend_title
FROM Vendors
ORDER BY vend_name;
```
```mysql
SELECT CONCAT(vend_name, '(', vend_country, ')') 
FROM Vendors
ORDER BY vend_name;
```
> oracle使用||拼接，有的DBMS使用+拼接，MySQL不支持这两种，使用函函数CONCAT()实现
> RTRIM()函数去掉串右边空格，LTRIM()函数去掉串左边空格，TRIM()函数去掉串左右两边空格

####2.算术计算：
```sql
SELECT prod_id, quality, item_price, 
       quality * item_price AS  expanded_price
FROM OrderItems
WHERE order_num = 20008;
```
> 支持 + - * / 四则运算，可以使用圆括号区分优先级

###[使用数据处理函数]
####1.使用函数的问题：
* SQL是不可移植的，因为不同的DBMS实现同一功能可能使用了不同的实现方式。
* 为了实现可移植性，必须减少函数的使用，但是这样又不利于应用程序的性能，且不使用函数，编写某些应用程序代码会很复杂。

####2.使用函数：
大多数SQL实现支持以下函数：
* 用于处理文本串(如删除或填充值，转换值为大写或小写）的文本函数；
* 用于在数值数据上进行算数操作(如返回绝对值，进行代数运算)的数值函数；
* 用于处理日期和时间值并从这些值中提取特定成分(如返回两个日期之差，检查日期有效性)的日期和时间函数；
* 返回DBMS正使用的特殊信息(如返回用户登录信息)的系统函数；
 
####3.文本处理函数：
```sql
SELECT vend_name, UPPER(vend_name) AS vend_name_upper
FROM Vendors
ORDER BY vend_name;
```

常用文本处理函数： 

|   函数    |           解释                        |
|:----------|:--------------------------------------|
|  LFET()   |   返回串左边的字符                     |
|  RIGHT()  |   返回串右边的字符                     |
| LENGTH()  |   返回串的长度                         |
|  LOWER()  |   将串转换为小写                       |
|  UPPER()  |   将串转换为大写                       |
|  LTRIM()  |   去掉串左边的空格                     |
|  RTRIM()  |   去掉串右边的空格                     |
| SOUNDEX() |   返回与给定词发音类似的所有词          |
| 
