#!/usr/bin/perl
use v5.42;
my ($d, $n) = (50, 0);
while (<>) {
	tr/LR/-+/;
	$d += $_;
	$d %= 100;
	++$n unless $d;
}
say $n;
