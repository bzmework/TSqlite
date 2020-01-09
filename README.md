# TSqlite
 TSqlite是采用ATL封装的sqlite3数据库COM DLL，简单易用，如果你习惯用ADO，正好满足你所需，如下例所示：
   
```
Do While Not rs.EOF   
    For i = 0 To rs.ColumnCount - 1   
        Debug.Print rs.ColumnValue(rs.ColumnName(i))    
    Next   
    rs.MoveNext   
Loop   
```
   
测试效果如下：   
![image](https://github.com/bzmework/TSqlite/blob/master/test.jpg)      
   
编译环境：   
Windows 10   
Visual Studio 2019   
说明：支持vs6-vs2019所有版本编译，如果你要支持在xp上使用，请采用TSqlite.dsw，若有必要则进行升级，   
升级路线一般是：vs6升级到vs2005进行过渡然后升级到更高版本的vs编译环境，   
如果你嫌繁琐则自己手工构造工程文件。   
   
sqlite版本：3.30.1   
QQ群：948127686   
   