##1.插入模式
`o`: 行后插入
`O`: 行前插入
`i`: 光标前插入
`a`: 光标后插入(after)

##2.光标移动
`0`或`|`: 到行首
`$`或`g_`: 到行尾
`/string`: 搜索字符串,n跳到下一字符

##3.拷贝/粘贴
`P/p`: 粘贴
`yy`: 拷贝当前行

##4.undo/redo
`u`: undo
`<C-r>`: redo

##5.打开/保存/退出/改变文件
`:e <path/to/file>`: 打开一个文件
`:w`: 保存(write)
`:saveas </path/to/file>`: 另存为<path/to/file>
`:x`or`ZZ`or`:wq`: 保存并退出(:x仅在需要时保存)
`:q!`: 退出不保存    `:qa!`: 强制退出所有正在编辑的文件
`:bp` or `:bn`: buffer中多个文件的跳转
`:so %`: source 当前文件
