#!/usr/bin/perl
use v5.42;
my ($ans, $maybe) = (0, 0);
while (<>) {
	next unless /x/;
	my ($w, $l, @c) = split /[x: ]+/;
	if (7*$c[0] + 7*$c[1] + 7*$c[2] + 7*$c[3] + 6*$c[4] + 5*$c[5] > $w * $l) {
	} elsif ($c[0] + $c[1] + $c[2] + $c[3] + $c[4] + $c[5] <= int($w/3) * int($l/3)) {
		++$ans;
	} else {
		++$maybe;
	}
}
say $ans;
say "+$maybe" if $maybe;
