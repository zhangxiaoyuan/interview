#1.SQL定义：
struct query language   
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

#2.[SQL语句执行顺序：](http://www.jellythink.com/archives/924)

    (7)  SELECT    //要查询的数据列
    (8)  DISTINCT <select_list>   //DISTINCT表示排除重复项
    (1)  FROM <left_table>   //要查询的数据来源
    (3)  <join_type> JOIN <right_table>     //left jion：表示要将左表中的所有数据添加到新生表中，right join：表示将右表
    (2)  ON <join_condition>         //表示join条件
    (4)  WHERE <where_condition>    //从整个结果集中过滤数据
    (5)  GROUP BY <group_by_list>   //按照指定的列分组，即按照指定列的值进行去重
    (6)  HAVING <having_condition>   //在GROUP BY分组之后过滤组内的数据
    (9)  ORDER BY <order_by_condition>   //按照指定的列排序
    (10) LIMIT <limit_number>   //从第一个数字的当前行取出第二个数字个行书，如：LIMIT 10,20表示从第10行开始取出20行数据
    
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

#3.[MySql常用命令](http://www.cnblogs.com/zhangzhu/archive/2013/07/04/3172486.html)

###4.储存过程：
存储过程（Stored Procedure）是一组为了完成特定功能的SQL语句集，经编译后存储在数据库。中用户通过指定存储过程的名字并给出参数（如果该存储过程带有参数）来执行它。存储过程用于实现频繁使用的查询、业务规则、被其他过程使用的公共例行程序。存储过程在创建时即在服务器上进行编译，所以执行起来比单个 SQL 语句快

###5.触发器怎么工作的?
答：触发器主要是通过事件进行触发而被执行的，当对某一表进行诸如UPDATE、 INSERT、 DELETE 这些操作时，数据库就会自动执行触发器所定义的SQL 语句，从而确保对数据的处理必须符合由这些SQL 语句所定义的规则
