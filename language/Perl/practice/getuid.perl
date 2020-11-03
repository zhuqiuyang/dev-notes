#!/usr/bin/perl
#by www.gitbook.net


   ($name, $passwd, $uid, $gid, $quota,
      $comment, $gcos, $dir, $shell) = getpwuid(0);
   print "Name = $name\n";
   print "Password = $passwd\n";
   print "UID = $uid\n";
   print "GID = $gid\n";
   print "Quota = $quota\n";
   print "Comment = $comment\n";
   print "Gcos = $gcos\n";
   print "HOME DIR = $dir\n";
   print "Shell = $shell\n";

