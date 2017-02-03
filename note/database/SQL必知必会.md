##[SQL必知必会] 学习笔记

###[排序检索数据]
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

###[排序检索数据]
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

###[过滤数据]
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





###[高级数据过滤]

###[用通配符进行过滤]

###[]

###[]

###[]

###[]

###[]

###[]

###[]

###[]
