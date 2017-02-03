##[SQL必知必会] 学习笔记

###[排序检索数据]
####    1.检索单个列:
```sql
SELECT prod_name
FROM Products;
```

####    2.检索多个列：
```sql
SELECT prod_name, prod_id, prod_price
FROM Products;
```

####    3.检索所有列：
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
> ORDER BY子句中使用的列可以是显示所选择的列，也可以是非检索的列，即可以用别的非检索列做排序

####2.按多个列排序：
```sql
SELECT prod_name, prod_id, prod_price
FROM Products
ORDER BY prod_price, prod_name;
```
> 多个列排序时，仅在第一个拍序列中有重复数据时，才会再按照第二个列排序，否则就都按照第一个列排序
