#struct query language
可以把SQL分作两个部分：数据定义语言DDL 和数据操作语言DML：

DDL：DDL 提供定义、删除、修改关系模式的命令
DML：DML 提供从数据库中查询信息，以及在数据库中插入、删除、修改元组的能力

SQL 的 DML 部分包括删除、更新、插入、查询操作：
SELECT - 从数据库表中获取数据
UPDATE - 更新数据库表中的数据
DELETE - 从数据库表中删除数据
INSERT INTO - 向数据库表中插入数据

SQL 的数据定义语言 (DDL) 部分使我们有能力创建或删除表格。我们也可以定义索引（键），规定表之间的链接，以及施加表间的约束：
CREATE DATABASE - 创建新数据库
ALTER DATABASE - 修改数据库
CREATE TABLE - 创建新表
ALTER TABLE - 变更（改变）数据库表
DROP TABLE - 删除表
CREATE INDEX - 创建索引
DROP INDEX - 删除索引

索引实际上就是数据结构，MySQL使用的主要是B－tree和B+tree进行索引的查询。SQL语言对大小写不敏感

##1.SQL DML 增删改查：
###查询 select：
```sql
SELECT orderID, customer.custmer_id
FROM order, customer
WHERE order.customter_id = customer_customer_id
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
SET salary = salary*1.5
```
update语句可以嵌套select语句对满足查询条件的数据处理：
```sql
UPDATE instructor
SET salary = salary*1.05
WHERE salary < (SELECT avg(salary) FROM instructor)
```
SQL 语句提供case 语句，可以利用它在一条语句中执行多种更新
```sql
UPDATE instructor
SET salary = case
    WHEN salary < 7000 THEN salary = salary*1.5
    WHEN salary = 7000 THEN salary = salary*1.05
    ELSE salary = salary * 1.03
    END
```
