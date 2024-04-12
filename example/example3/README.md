# c++ 封装 lua函数示例

1. c++封装的函数对应生成的库名字：algorithm.so ，生成的库文件放置在 /opt/arcs/XXXX/lib/lua/5.3会被自动搜索

2. 调用方法:

   ```
   local obj = require "algorithm"
   local algorithm = obj.Algorithm.new()
   
   result = algorithm:div(3,1)
   textmsg(result)
   ```

   

