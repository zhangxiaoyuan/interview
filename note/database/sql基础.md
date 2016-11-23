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

###[DML语句执行顺序](http://www.jellythink.com/archives/924)：
```sql
    (7)  SELECT    //要查询的数据列
    (8)  DISTINCT <select_list>   //DISTINCT表示排除重复项
    (1)  FROM <left_table>   //要查询的数据来源
    (3)  <join_type> JOIN <right_table>     //left jion：表示要将左表中的所有数据添加到新生表中，right join：表示将右表
    (2)  ON <join_condition>         //表示join条件
    (4)  WHERE <where_condition>    //从整个结果集中过滤数据
    (5)  GROUP BY <group_by_list>   //按照指定的列分组即按照指定列的值进行去重, **这里还会执行聚合函数** 
    (6)  HAVING <having_condition>   //在GROUP BY分组之后过滤组内的数据
    (9)  ORDER BY <order_by_condition>   //按照指定的列排序
    (10) LIMIT <limit_number>   //从第一个数字的当前行取出第二个数字个行书，如：LIMIT 10,20表示从第10行开始取出20行数据
```   
> 前面序号为执行顺序

SQL语句执行顺序总共分为10步，第一步是FROM，最后一步是LIMIT，中间的每一步操作都会生成一个虚表，但是这个虚表是对用户不可见的
每一步虚表都生成一个结果，做下一步执行的输入，如果某一步不存在，那么就跳过这一步的操作。只有最后一个虚表的结果会返回给用户

例子：

    SELECT a.customer_id, COUNT(b.order_id) as total_orders
    FROM table1 AS a
    LEFT JOIN table2 AS b
    ON a.customer_id = b.customer_id
    WHERE a.city = 'hangzhou'
    GROUP BY a.customer_id
    HAVING count(b.order_id) < 2
    ORDER BY total_orders DESC;

> 
  1、FORM: 对FROM左边的表和右边的表计算笛卡尔积，产生虚表VT1。  
  2、ON: 对虚表VT1进行ON过滤，只有那些符合<join-condition>的行才会被记录在虚表VT2中。  
  3、JOIN： 如果指定了OUTER JOIN（比如left join、 right   join），那么保留表中未匹配的行就会作为外部行添加到虚拟表VT2中，产生虚拟表VT3。  
  4、WHERE： 对虚拟表VT3进行WHERE条件过滤。只有符合<where-condition>的记录才会被插入到虚拟表VT4中。  
  5、GROUP BY: 根据group by子句中的列，对VT4中的记录进行分组操作，产生VT5。  
  6、HAVING： 对虚拟表VT5应用having过滤，只有符合<having-condition>的记录才会被 插入到虚拟表VT6中。  
  7、SELECT： 执行select操作，选择指定的列，插入到虚拟表VT7中。  
  8、DISTINCT： 对VT7中的记录进行去重。产生虚拟表VT8.  
  9、ORDER BY: 将虚拟表VT8中的记录按照<order_by_list>进行排序操作，产生虚拟表VT9.  
  10、LIMIT：取出指定行的记录，产生虚拟表VT10, 并将结果返回。   


##2.DDL 创建删除：

`CREATE DATABASE` 语句用于创建数据库，DROP DATABASE 语句用于删除数据库。下面的 SQL 语句创建一个名为 "my_db" 的数据库：


```SQL
CREATE DATABASE my_db;
```

`CREATE TABLE` 语句用于创建数据库中的表，表由行和列组成，每个表都必须有个表名。使用 DROP TABLE 语句来删除表。假设想要创建一个名为 "Persons" 的表，包含五列：PersonID、LastName、FirstName、Address 和 City。

```SQL
CREATE TABLE Persons
(
    PersonID int,
    LastName varchar(255),
    FirstName varchar(255),
    Address varchar(255),
    City varchar(255)
);
```

`ALTER TABLE` 语句用于在已有的表中添加、删除或修改列。

```SQL
ALTER TABLE table_name
---
ADD column_name datatype
DROP COLUMN column_name
MODIFY COLUMN column_name datatype // ALTER COLUMN column_name datatype
```

假设想要想要删除 "Person" 表中的 "DateOfBirth" 列，可以使用下面的 SQL 语句：

    ALTER TABLE Persons
    DROP COLUMN DateOfBirth
CREATE INDEX 语句用于在表中创建索引，在不读取整个表的情况下，索引使数据库应用程序可以更快地查找数据。CREATE UNIQUE INDEX 在表上创建一个唯一的索引，不允许使用重复的值。DROP INDEX 语句用于删除表中的索引。

假设在 "Persons" 表的 "LastName" 列上创建一个名为 "PIndex" 的索引：

```SQL
CREATE INDEX PIndex
ON Persons (LastName)
```


##扩展阅读：
[十步完全理解 SQL](http://blog.jobbole.com/55086/)
