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
