#!/usr/bin/perl
use warnings;
use strict;

my $x = 10;

my $xr = \$x;

$$xr = $$xr * 2;


print("\$x = $x \n");

print("\$\$xr= $$xr \n");


print("\$xr = $xr \n");
