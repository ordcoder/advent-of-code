#!/usr/bin/perl
use v5.42;
use List::Util qw(maxstr);
my $sum = 0;
for (<>) {
	my $m = maxstr split //, substr($_, 0, -2);
	my $i = index $_, $m;
	my $n = maxstr split //, substr($_, $i+1, -1);
	$sum += $m . $n;
}
say $sum;
