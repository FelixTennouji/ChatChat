

# ChatChat简介 
这是一套C/S模型的安全聊天软件，也是我第三个大型个人项目。

初步计划支持Windows，Linux，Android,以C++与Qt框架完成桌面客户端，C++实现服务端，未来会用c++/python/java写服务端【锻炼用】，同时增加安卓（Java）与桌面（Java，python）端程序。会设计一套应用层通信协议。

预计支持功能有：基于RSA等加密算法的聊天模式，支持视频通信，Ftp文件传输（针对局域网会有优化），内网穿透，通过内网穿透实现直连聊天（同时实现视频功能）

***

## ChatChatV0.1β
### cilent（客户端）：

图示：

![example1](http://m.qpic.cn/psc?/V51VgQiX2vBqqf4EuF560KuLpK26zMDd/45NBuzDIW489QBoVep5mcdkMj2xrwioLSM*3Sum8YnT.oG7Vi.kpf2fY7VhPcx1fXxjr0Ak8Yg1WxideiHQ0yBr6GmbRyW*9qP1xtHuipt4!/b&bo=SQUzAwAAAAABF0w!&rf=viewer_4)

目前客户端采用Qt/C++实现第一版，启用多线程技术完成等待用户输入同时完成网络事件

以下功能为第一版内容后续会逐渐追加
实现日志系统

1. File：支持聊天记录的保存，与服务端链接，进行注册，选择加密协议（下一个版本支持），选择服务器端口与IP，提供默认的私人Ip与端口，下一个版本会支持内网穿透，聊天直连模式与文件传输FTP
2. Edit：支持剪切复制粘贴撤销功能，并且提供html代码进行美观操作，实例：
```
<center>居中文本<\center>
<font size="5">大小为5的文本</font>
<font color="red">红色文本</font>
or
<font color="FF0000">红色文本</font>
```
3. View：目前只支持mini模式（就是这个版本），full模式未来会开发
4. Member：显示当前聊天室成员，下一个版本引入私聊
5. History：默认查找本地聊天记录，并通过MD5和时间戳来判断服务器端是否为最新，并且通过下面加载最新选项来下载聊天记录
6. Help:帮助栏
7. 主窗口
8. 输入栏：通过左边标签与主窗口提示完成注册，登录，左标签显示当前用户名（白字黑底）或者当前操作状态（白字蓝底），右按钮提示提交命令，（紫底黑字），存在错误命令通过（红底灰字）提示，通过 / 命令直接完成一些操作，实例：

| 命令 | 参数解释 | 
| :-----:| :----: | 
|/help|显示帮助（所有命令）| 
|/help 命令单词|显示该命令的帮助文档，例如/help history显示history的详细用法与参数提示|
|/ban_id|房主命令。后面加冒号，然后添加用户UID，多人用英文逗号隔开，表示此人禁止进入该聊天室，房主不能禁止自己加入|
|/clear|清屏|
|/create_room|创建一个房间 （一个用户最多创建三个房间）|
|/exit|退出程序|
|/find 用户名|可以根据用户名查找所对应的用户的UID 也可以根据用户UID查询|
|/history|载入本地聊天室记录，末尾参数 -a 会请求服务器获得此聊天室记录|
|/member|列出当前聊天室成员|
|/quit|处于聊天室会退出当前聊天室，处于服务器大厅会退出大厅|
|/register| 注册，登录界面无法输入用户名时可以通过这个命令注册，也可以通过文件->注册实现 | 
|/room|显示房间信息，房主UID为0代表是房主是服务器管理员，如果用户为房主，通过-s:参数修改房间信息，示例：/room -s:chat_room_property=public,chat_room_status=open,chat_room_password_exist=no   意思是聊天室公开（允许任何人进来），允许任何人讨论话题（关闭就是仅允许房主发话）；公开聊天室不允许设置密码，私人聊天室设置密码则允许任何人凭借密码进入，不设置密码则为申请式进入|
|/room_applicant|用户为房主可用命令：显示当前申请者UID，名称，申理由，-y允许所有申请者,-n拒绝所有申请者，-p:申请者ID表示允许通过的人|
|/room_list|处于服务器大厅可通过此命令列出聊天室|
|/room_transfer|房主命令；加冒号，后面跟着接受转让者UID，表示将房主权限转让给对方|
|/save|保存聊天记录到本地|
9. 状态栏:显示登录IP，端口，其他一些进度信息，文本框输入字数
10. 

### server（服务端）：
目前以Java NIO完成，功能设计：
实现日志系统
1. 注册方面，最多允许同一IP在1天注册6个用户，未来会加入邮箱自动验证功能
2. 通过公开第三方库 Miracl 实现RSA不对称加密，未来会自己手动实现这个要求
3. 使用AIO技术来满足不同人在不同聊天室的需求
4. and so on