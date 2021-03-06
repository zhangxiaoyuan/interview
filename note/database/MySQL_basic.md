##1.Mysql数据类型：
###1、数字类型：
MySQL使用标准的 ANSI SQL 数字类型，支持整型和浮点数。

* __整数__: tinyint、smallint、mediumint、int、bigint

| 类型 | 范围 |
|------| -----|
| tinyint |  1个字节 范围(-128~127) |
| smallint | 2个字节 范围(-32768~32767) |
| mediumint | 3个字节 范围(-8388608~8388607)|
| int | 4个字节 范围(-2147483648~2147483647) |
| bigint | 8个字节 范围(+-9.22*10的18次方)  |

* __浮点型__：float、double、real、decimal

| 类型 | 范围 |
|------|-----|
| float(m,d) | 单精度浮点型，8位精度(4字节)，m总个数，d小数位 |
| double(m,d) | 双精度浮点型，16位精度(8字节)，m总个数，d小数位 |
| decimal(m,d) | decimal是存储为字符串的浮点数 |

> 设一个字段定义为float(5,3)，如果插入一个数123.45678,实际数据库里存的是123.457，总个数以实际为准，即6位。

###2、字符串类型：
* __字符串__: char、varchar
* __文本__: tinytext、text、mediumtext、longtext
* __二进制(可用来存储图片、音乐等)__: tinyblob、blob、mediumblob、longblob

| 类型 | 含义 |
|------|------|
| char(n) | 固定长度，最多255个字符 |
| varchar(n) | 可变长度，最多65535个字符 |
| tinytext | 可变长度，最多255个字符 |
| text | 可变长度，最多65535个字符 |
| mediumtext | 可变长度，最多2的24次方-1个字符 |
| longtext | 可变长度，最多2的32次方-1个字符 |

> char（n）和varchar（n）中括号中n代表字符的个数，并不代表字节个数，所以当使用了中文的时候(UTF8)意味着可以插入m个中文，但是实际会占用m*3个字节。

* char和varchar相比：
 + char(n) 若存入字符数小于n，则以空格补于其后，查询之时再将空格去掉。所以char类型存储的字符串末尾不能有空格，varchar不限于此。
 + char(n) 固定长度，char(4)不管是存入几个字符，都将占用4个字节，varchar是存入的实际字符数+1个字节（n<=255）或2个字节(n>255)，所以varchar(4)，存入3个字符将占用4个字节。
 + char类型的字符串检索速度要比varchar类型的快。
 
* varchar和text相比：
 + varchar可指定n，text不能指定，内部存储varchar是存入的实际字符数+1个字节（n<=255）或2个字节(n>255)，text是实际字符数+2个字节。
 + text类型不能有默认值。
 + varchar可直接创建索引，text创建索引要指定前多少个字符。varchar查询速度快于text。

###3、时间与日期：

| 类型 | 含义 |
|------|------|
| date | 日期'2016-11-24' |
| time | 时间'16:32:30'   |
| datetime | 日期时间'2016-11-24 16:33:00' |
| timestamp | 时间戳，自动存储记录修改时间 |

> 若定义一个字段为timestamp，这个字段里的时间数据会随其他字段修改的时候自动刷新，所以这个数据类型的字段可以存放这条记录最后被修改的时间。


##2.数据类型属性：
* **`auto_increment`** ：
 为新插入的行赋一个唯一的整数标识符，为列赋此属性将为每个新插入的行赋值为上一次插入的ID+1。MySQL要求将auto_increment属性用于作为主键的列。
 ```sql
 id smallint not null auto_increment primary key
 ```
 
* **`default`**:
 确保在没有任何值可用的情况下，赋予某个常量值，这个值必须是常量，因为MySQL不允许插入函数或表达式值.此外，此属性无法用于BLOB或TEXT列。如果已经为此列指定了NULL属性，没有指定默认值时默认值将为NULL，否则默认值将依赖于字段的数据类型。
 ```sql
 subscribed enum('0', '1') not null default '0'
 ```
* __`index`__:
 如果所有其他因素都相同，要加速数据库查询，使用索引通常是最重要的一个步骤。索引一个列会为该列创建一个有序的键数组，每个键指向其相应的表行。以后针对输入条件可以搜索这个有序的键数组，与搜索整个未索引的表相比，这将在性能方面得到极大的提升。
 
 ```sql
  create table employees
  (
      id varchar(9) not null,
      firstname varchar(15) not null,
      lastname varchar(25) not null,
      email varchar(45) not null,
      phone varchar(10) not null,
      index lastname(lastname),
      primary key(id)
  );
 ```
 
 或者使用创建索引的方式：
 
 ```sql
 create index lastname on employees (lastname(7));
 ```
 
 > 这一次只索引了名字的前7个字符，因为可能不需要其它字母来区分不同的名字。因为使用较小的索引时性能更好，所以应当在实践中尽量使用小的索引。

* __`not null`__:
如果将一个列定义为not null，将不允许向该列插入null值。建议在重要情况下始终使用not null属性，因为它提供了一个基本验证，确保已经向查询传递了所有必要的值

* __`null`__:
为列指定null属性时，该列可以保持为空，而不论行中其它列是否已经被填充。记住，null精确的说法是“无”，而不是空字符串或0。

* __`primary key`__:
属性用于确保指定行的唯一性，指定为主键的列中，值不能重复，也不能为空。为指定为主键的列赋予auto_increment属性是很常见的，因为此列不必与行数据有任何关系，而只是作为一个唯一标识符。主键有两种：
 * 单字段主键：如果输入到数据库中的每行都已经有不可修改的唯一标识符，一般会使用单字段主键。注意，此主键一旦设置就不能再修改。
 * 多字段主键：如果记录中任何一个字段都不可能保证唯一性，就可以使用多字段主键。这时，多个字段联合起来确保唯一性。如果出现这种情况，指定一个auto_increment整数作为主键是更好的办法。

* __`unique`__:
被赋予unique属性的列将确保所有值都有不同的值，只是null值可以重复。一般会指定一个列为unique，以确保该列的所有值都不同。
```sql
email varchar(45) unique
```

##3.扩展阅读：
[[MySQL处理数据库和表的常用命令](http://www.jellythink.com/archives/646)]
[[MySQL数据类型和属性](http://www.jellythink.com/archives/642)]
