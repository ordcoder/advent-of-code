#!/usr/bin/perl
use v5.42;
use List::Util qw(max);
my ($n, $l, @r) = (0, 0);
while (<>) {
	my ($f, $t) = split /-/;
	last unless defined $t;
	push @r, [$f, $t + 1];
}
@r = sort {$a->[0] <=> $b->[0] or $a->[1] <=> $b->[1]} @r;
for my $r (@r) {
	if ($r->[1] > $l) {
		$n += $r->[1] - max($r->[0], $l);
		$l = $r->[1];
	}
}
say $n;
