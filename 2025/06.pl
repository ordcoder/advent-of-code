#!/usr/bin/perl
use v5.42;
my ($sum, @parts);
push @parts, [split] while (<>);
for (my $i = 0; $i < @{$parts[-1]}; ++$i) {
	my $r = $parts[0][$i];
	if ($parts[-1][$i] eq "+") {
		for (my $j = 1; $j < @parts - 1; ++$j) {
			$r += $parts[$j][$i];
		}
	} elsif ($parts[-1][$i] eq "*") {
		for (my $j = 1; $j < @parts - 1; ++$j) {
			$r *= $parts[$j][$i];
		}
	}
	$sum += $r;
}
say $sum;
