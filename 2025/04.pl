#!/usr/bin/perl
use v5.42;
my ($n, $h, $w, @m) = (0, 0, 0);
for (<>) {
	push @m, [split //];
	$w = -1 + length;
	++$h;
}
push @m, [split //, " " x ($w+1)];
for (my $i = 0; $i < $h; ++$i) {
	for (my $j = 0; $j < $w; ++$j) {
		my $c = 0;
		for (my $y = $i-1; $y <= $i+1; ++$y) {
			for (my $x = $j-1; $x <= $j+1; ++$x) {
				++$c if $m[$y][$x] eq "@";
			}
		}
		++$n if $m[$i][$j] eq "@" and $c <= 4;
	}
}
say $n;
