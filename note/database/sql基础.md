#struct query language   
可以把SQL分作两个部分：`数据定义语言DDL` 和`数据操作语言DML`：   
* DDL：DDL 提供定义、删除、修改关系模式的命令
* DML：DML 提供从数据库中查询信息，以及在数据库中插入、删除、修改元组的能力

SQL 的 DML 部分包括删除、更新、插入、查询操作：

* SELECT - 从数据库表中获取数据
* UPDATE - 更新数据库表中的数据
* DELETE - 从数据库表中删除数据
* INSERT INTO - 向数据库表中插入数据

SQL 的数据定义语言 (DDL) 部分使我们有能力创建或删除表格。我们也可以定义索引（键），规定表之间的链接，以及施加表间的约束：

* CREATE DATABASE - 创建新数据库
* ALTER DATABASE - 修改数据库
* CREATE TABLE - 创建新表
* ALTER TABLE - 变更（改变）数据库表
* DROP TABLE - 删除表
* CREATE INDEX - 创建索引
* DROP INDEX - 删除索引

* 索引实际上就是数据结构，MySQL使用的主要是B－tree和B+tree进行索引的查询。

##1.SQL DML 增删改查：
###查询 select：
```sql
SELECT orderID, customer.custmer_id
FROM order, customer
WHERE order.customter_id = customer_customer_id;
```

###插入 insert into：
insert 语句中可以指定属性，也可以不指定，不指定属性时，插入值的排序和关系模式中属性排列的顺序一致。  
```sql
INSERT INTO course
VALUES('CS-437','Database System', 'Comp. Sci', 4);

INSERT INTO course(course_id, title, dept_name, credits)
VALUES('CS-437','Database System', 'Comp. Sci', 4);

INSERT INTO course(title, course_id, dept_name, credits)
VALUES('Database System', 'CS-437', 'Comp. Sci', 4);
```

###更新 update：
update 语句可以在不改变整个元组的情况下改变其部分属性的值:  
```sql
UPDATE instructor
SET salary = salary*1.5;
```
update语句可以嵌套select语句对满足查询条件的数据处理：
```sql
UPDATE instructor
SET salary = salary*1.05
WHERE salary < (SELECT avg(salary) FROM instructor);
```
SQL 语句提供case 语句，可以利用它在一条语句中执行多种更新
```sql
UPDATE instructor
SET salary = case
    WHEN salary < 7000 THEN salary = salary*1.5
    WHEN salary = 7000 THEN salary = salary*1.05
    ELSE salary = salary * 1.03
    END;
```

###删除 delete:
DELETE 语句用于删除表中的记录。只能删除整个元组，而不能只删除某些属性上的值。  
```sql
DELETE FROM instructor
WHERE salary < (SELECT avg(salary) FROM instrutor );
```

###where子句：
WHERE 子句用于提取那些满足指定标准的记录  
```sql
SELECT *
FROM website
WHERE country='CN';
```
以下运算符都可以运用于Where子句：   
=等于   <小于   >大于   <=小于等于    >=等于    <>(!=)不等于     between在某个范围     in多个可能值       
like搜索多种模式：%匹配任意字符串   下划线：匹配任意字符    

如下：查找 student表中所有电话号码(列名：telephone)的第一位为8或6，第三位为0的电话号码   
```sql
SELECT telephone
FROM student
WHERE telephone like '[8,6]_%';
```

###group by子句:
Group By 语句从英文的字面意义上理解就是根据(by)一定的规则进行分组(Group)  
统计 access_log 各个 site_id 的访问量：  
```sql
SELECT site_id SUM(access_log.count) AS num
FROM access_log 
GROUP BY site_id；
```
有订单表orders，包含字段用户信息userid，字段产品信息productid，以下语句能够返回至少被订购过两会的productid？：  
```sql
SELECT productid
FROM orders
GROUP BY productid 
HAVING count(productid) > 1;
```

###having子句：
在 SQL 中增加 HAVING 子句原因是，**WHERE 关键字无法与聚合函数一起使用**, HAVING 子句可以让我们筛选分组后的各组数据。  
查找网站访问信息中网站id大于等于3并且访问量大于200的网站的名字和url已经访问次数：
```sql
select website.name, website.url, sum(log.count) as nums 
from website inner join log on website.id = log.id where website.id >= 3
group by website.name having sum(log.count)>200
```

###order by子句：
ORDER BY 关键字用于对结果集按照一个列或者多个列进行排序，默认按照升序对记录进行排序。ASC：升序、DESC:降序
```sql
select website.name, website.url, sum(log.count) as nums 
from website inner join log on website.id = log.id where website.id >1
group by website.name having sum(log.count)>200
order by nums
```

###聚合函数：
SQL 拥有很多可用于计数和计算的内建函数，聚合函数计算从列中取得的值，返回一个单一的值，常用的聚合函数如下：

| 函数名称 |解释|
|---------|----|
|    AVG()    |   返回数值列的平均值       |
|    SUM()    |   返回数值列的总和         |
|   COUNT()   |   返回匹配指定条件的行数个数|
|   FIRST()   | 返回指定列中第一个记录的值  |
|   LAST()    | 返回指定列中最后一个记录的值|
|    MAX()    |   返回指定列的最大值       |
|    MIN()    |   返回指定列的最小值       |



