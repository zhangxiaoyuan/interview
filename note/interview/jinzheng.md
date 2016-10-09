1.哈希表原理

2.数据库操作：
```SQL
mysql -u root -p 
lulu1030

show databases;
create database test;
drop database test;

use course_select_sys;

create table cust(
    Studentno int(5) not null primary key auto_increment,
    Name char(10) not null,
    Address char(30),
    Telno char(15) not null
);

show tables;
show table cust;
insert into cust values(00001,"zxy","shenzhenshi","18681551304");
insert into cust values(00002,"zxy2","changsha","18681551304");
insert into cust values(00003,"zxy3","guangzhou","18681551304");
insert into cust values(00004,"zxy4","xianggang","18681551304");
insert into cust values(00005,"zxy5","shijiazhuang","18681551304");
insert into cust values(00006,"zxy6,"xi'an","18681551304");
insert into cust values(11,"zxy11","shenzhen","11");
insert into cust values(22,"zxy22","changsha","22");
insert into cust values(33,"zxy33","hunan","33");
insert into cust values(44,"zxy44","guangdong","44");
insert into cust values(55,"zxy55","xi'an","55");


create table mark(
    studentno int(5) not null primary key auto_increment,
    english double(3,1) not null,
    math double(3,1) not null,
    computer double(3,1)
);

select * from mark;
insert into mark values(00001,99.0,34.0,56.2);
insert into mark values(00002,0.0,34.0,56.2);
insert into mark values(00003,1.0,34.0,56.2);
insert into mark values(00004,10.0,34.0,56.2);
insert into mark values(00005,20.2,34.0,56.2);
insert into mark values(00006,30.0,34.0,56.2);
insert into mark values(00007,40.0,34.0,56.2);
insert into mark values(00008,50.0,34.0,56.2);
insert into mark values(00009,60.0,34.0,56.2);
insert into mark values(00010,70.0,34.0,56.2);
insert into mark values(11,10.0,10.0,10.0);
insert into mark values(22,20.0,20.0,20.0);
insert into mark values(33,30.0,30.0,30.0);
insert into mark values(44,40.0,40.0,40.0);
insert into mark values(55,50.0,50.0,50.0);

/*查询所有学生的英语平均成绩*/


/*查询学号为11,22,33,44,55的学生的数学成绩，姓名，学生地址，电话号码*/
select * from cust as t1 left join mark as t2 on t1.Studentno=t2.studentno where t1.Studentno in (11,22,33,44,55);

select t2.math as math, t1.Name as name, t1.Address as addr, t1.Telno as no from cust as t1 left join mark as t2 on t1.Studentno=t2.studentno where t1.Studentno in (11,22,33,44,55);

```
