#!/usr/bin/perl
use v5.42;
my ($area, @red) = (0);
push @red, [split /,/] while (<>);
for (my $i = 0; $i < @red; ++$i) {
	for (my $j = 0; $j < $i; ++$j) {
		my ($x1, $y1, $x2, $y2) = (@{$red[$i]}, @{$red[$j]});
		($x1, $x2) = ($x2, $x1) if $x1 > $x2;
		($y1, $y2) = ($y2, $y1) if $y1 > $y2;
		my ($ok, $s) = (1, (1 + $x2 - $x1) * (1 + $y2 - $y1));
		for (my $k = 0; $k < @red; ++$k) {
			my ($xa, $ya, $xb, $yb) = (@{$red[$k-1]}, @{$red[$k]});
			if ($xa == $xb and $x1 < $xa < $x2) {
				$ok = 0, last unless ($ya <= $y1 and $yb <= $y1) or ($ya >= $y2 and $yb >= $y2);
			} elsif ($ya == $yb and $y1 < $ya < $y2) {
				$ok = 0, last unless ($xa <= $x1 and $xb <= $x1) or ($xa >= $x2 and $xb >= $x2);
			}
		}
		$area = $s if $ok and $s > $area;
	}
}
say $area;
