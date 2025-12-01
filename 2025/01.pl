#!/usr/bin/perl
use v5.42;
my ($d, $n) = (50, 0);
while (<>) {
	tr/LR/-+/;
	$d += $_;
	$n += int abs $d/100;
	++$n if $d <= 0 and $d != $_;
	$d %= 100;
}
say $n;
