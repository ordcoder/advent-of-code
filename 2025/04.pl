#!/usr/bin/perl
use v5.42;
my ($n, $r, $h, $w, @m) = (-1, 1, 0, 0);
for (<>) {
	push @m, [split //];
	$w = -1 + length;
	++$h;
}
push @m, [split //, " " x ($w+1)];
while ($r) {
	$n += $r;
	$r = 0;
	for (my $i = 0; $i < $h; ++$i) {
		for (my $j = 0; $j < $w; ++$j) {
			next unless $m[$i][$j] eq "@";
			my $c = 0;
			for (my $y = $i-1; $y <= $i+1; ++$y) {
				for (my $x = $j-1; $x <= $j+1; ++$x) {
					++$c if $m[$y][$x] eq "@";
				}
			}
			if ($c <= 4) {
				$m[$i][$j] = ".";
				++$r;
			}
		}
	}
}
say $n;
