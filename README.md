这是博主学习几个月后做的第一个项目 qt版本是6.7.2 之前没有开发经验 所以可能bug会比较多 代码也比较杂乱 好在注释加的比较多
大家有需要的可以重构一下 大家把login和mainwindow的tcpConnect函数的地址和端口号改为自己需要的就可以使用了
因为qt6没有自带mysql的驱动 所以数据库直接使用的sqlite 数据库代码也可以在文件中找到

2024.10.18
修改清空聊天记录后再次发送消息 如果消息和上条间隔不到三分钟 则不会加载时间戳的bug
原理是在菜单选择清空聊天记录后重新设置 list->setObjectName("notime");

2024.10.19
睡不着改了几个突然想到的bug 稍微优化了一下
修改连接池建立消息表时 缺失两列属性的bug 分别是filename和status
给服务器处理器 处理文件消息时加了互斥锁 变量名为mutex
确定了上传文件大小最大是500mb
加快了文件保存速度
给保存文件加了几个弹窗 用户体验更好
