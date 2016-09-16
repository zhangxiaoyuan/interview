#1.［SQL语句执行顺序](http://www.jellythink.com/archives/924)：

    (7)  SELECT 
    (8)  DISTINCT <select_list>
    (1)  FROM <left_table>
    (3)  <join_type> JOIN <right_table>
    (2)  ON <join_condition>
    (4)  WHERE <where_condition>
    (5)  GROUP BY <group_by_list>
    (6)  HAVING <having_condition>
    (9)  ORDER BY <order_by_condition>
    (10) LIMIT <limit_number>
    
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
