#!/usr/bin/perl
use warnings;
use strict;

my $str = 'new york city';

$str =~ s/new york/New York/;

print $str, "\n";

print "--- \n";
$str = "I'm fine. Thank you.";
my $count = ($str =~ tr/././);
print $count, "\n";

my $str2 = "welcome to my world.";

$str2 =~ m/my/;

print "matched before: $` \n";
print "matched: $& \n";
print "matched after: $' \n";


