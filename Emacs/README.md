#### 启动/关闭

- `SPC q R`: restart emacs.
- `SPC f e R`: reload 配置
- `SPC f s`: 保存 dotfile 更改
- `SPC q q`: 退出

#### Window

- `SPC w /`: 右侧分屏
- `SPC 0..9`: 切换
- `SPC w d`: 关闭当前 window

#### Buffer

- `SPC b h`: 回到首页
- `SPC TAB`: 切换

#### Edit

- `gd`: 跳转到定义
- `C-o`: evil jump back
- `g c c`: line 注释
- `u`: undo
- `C-r`: redo
- `SPC j =`: buffer 个代码 indent
- `dired mode`?

#### Dired mode

Dired Mode 是一个强大的模式它能让我们完成和文件管理相关的所有操作。

- `+` 创建目录
- `g` 刷新目录
- `C` 拷贝
- `D` 删除
- `R` 重命名
- `d` 标记删除
- `u` 取消标记
- `x` 执行所有的标记

#### Theme

- `all-the-icons`: 安装后`SPC SPC` 执行`install`
  ```el
   (setq neo-theme 'icons)
  ```
- `dotspacemacs-additional-packages '(doom-themes all-the-icons)`

### Home 跳转

- `TAB` or `J` to move to next button.

- `Shift-TAB` or `K` to move to previous button.

- `w` to jump to warning list.

- `r` to jump to recent file list if it is enabled.

- `p` to jump to project list if it is enabled.

- `b` to jump to bookmark list if it is enabled.

- `c` to jump to org-agenda list if it is enabled.

- `d` to jump to org-todo list if it is enabled.

- `o` to jump to any link or button.

- `m` to jump to the top menu.

- `SPC` (in Vim editing style) or `Alt-m` (in Emacs editing style) to access

- `SPC f e d` 访问`.spacemacs` file.

- `SPC h SPC` to access a list of documentation and supported layers. You can type anything to narrow to a specific feature i.e. "python" for Python layer. There are multiple lists and you can press `Ctrl-o` to switch between them.

- When reading a document, you can use `SPC s j` to jump to a heading.

- Please consult Spacemacs documentation from `SPC h SPC` for more details.
