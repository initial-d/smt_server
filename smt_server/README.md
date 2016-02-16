simple_server
=============
此组件是为了使用c++方便快速的构建http server,编写基于http协议json格式的接口,和nginx等传统服务器相比,更加重视开发的便捷性,项目参考[restbed](https://bitbucket.org/Corvusoft/restbed/overview) 实现
## 特点
* linux 2.6 +
* 单进程 + 单线程 + epoll
* g++3.4 +
* 强调简洁实用

## 性能
 * qps 12000+ (短连接 ab -c 10 -n 10000 localhost:3490/hello)
 * qps 16000+ (长连接 ab -c 10 -n 10000 -k localhost:3490/hello)

## 构建 && 测试
```
 make && make test && ./bin/http_server_test 3490
 curl "localhost:3490/hello"
```

## 功能列表
  * http 1.0/1.1(keep-alive 支持) GET请求
  * 便捷的开发形式
  * Json格式的数据返回
  * ~~支持JSON数据返回~~
  * 支持Path parameter
  * ~~增加一个proxy来处理高并发~~ 使用epoll来实现,2014-11-6
  * ~~解决CPU导致的瓶颈,提高qps~~ 

