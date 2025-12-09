#!/usr/bin/perl
use v5.42;
my ($area, @red) = (0);
push @red, [split /,/] while (<>);
for (my $i = 0; $i < @red; ++$i) {
	for (my $j = 0; $j < $i; ++$j) {
		my $s = (1 + abs($red[$i][0] - $red[$j][0])) * (1 + abs($red[$i][1] - $red[$j][1]));
		$area = $s if $s > $area;
	}
}
say $area;
