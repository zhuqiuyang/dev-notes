#!/usr/bin/perl
 
# 方法定义
sub add_a_b{
   # 不使用 return
   $_[0]+$_[1];  
 
   # 使用 return
   # return $_[0]+$_[1];  
}
print add_a_b(1, 2)
