#### zshrc

```shell
# Path to your oh-my-zsh installation.
export ZSH=/Users/Ace/.oh-my-zsh
DEFAULT_USER="$USER"


ZSH_THEME="agnoster"

plugins=(git z osx brew node npm svn rsync go)

source ~/.bash_profile

source $ZSH/oh-my-zsh.sh

export GOPATH=$HOME/Documents/go/
# export GOPATH=$HOME/Documents/goTemp/
start_proxy() {
  export http_proxy=http://127.0.0.1:1087
  export https_proxy=http://127.0.0.1:1087
}
stop_proxy() {
  unset http_proxy
  unset https_proxy
}

alias saber="ssh power@saber.xin"
alias la="ls -a"
alias ll="ls -l"
alias vi="vim"
alias vim="mvim -v"
alias ga="git add ."
alias gc="git commit -m"
alias gps="git push"
# alias pc="proxychains4"
alias mv_go="mv $GOPATH/src/github.com/golang/* $GOPATH/src/golang.org/x/"
alias emacs="/Applications/Emacs.app/Contents/MacOS/Emacs --insecure"
alias ngrok="./ngrok"
```

#### vscode

```json
{
  // 将设置放入此文件中以覆盖默认设置
  "editor.fontSize": 14,
  "editor.tabSize": 2,
  "files.autoSave": "on",
  "files.associations": {
    "*.vue": "vue"
  },
  "workbench.iconTheme": "vscode-icons",
  "window.zoomLevel": 0,
  "javascript.format.enable": false,
  "prettier.singleQuote": true,
  "prettier.eslintIntegration": true,
  "C_Cpp.clang_format_style": "google",
  "eslint.validate": ["javascript", "javascriptreact", "vue"],
  "extensions.ignoreRecommendations": false,
  "[markdown]": {},
  "workbench.colorTheme": "One Dark Pro",
  "[go]": {}
}
```

#### vimrc

```shell
syntax enable
set background=dark
colorscheme solarized
#auto indent
set ai
set showmatch
set cursorline
set autoread                "文件在vim之外修改过,自动重新载入.
set foldmethod=syntax
```
