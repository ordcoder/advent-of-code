#!/usr/bin/perl
use v5.42;
use List::Util qw(maxstr);
my $sum = 0;
for (<>) {
	my ($jolt, $o) = ("", 0);
	for (my $i = 0; $i < 12; ++$i) {
		my $m = maxstr split //, substr($_, $o, $i-12);
		$jolt .= $m;
		$o = 1 + index $_, $m, $o;
	}
	$sum += $jolt;
}
say $sum;
