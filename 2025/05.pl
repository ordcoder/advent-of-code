#!/usr/bin/perl
use v5.42;
my ($n, @r);
while (<>) {
	my ($f, $t) = split /-/;
	last unless defined $t;
	push @r, [$f, $t];
}
while (<>) {
	for my $ft (@r) {
		++$n, last if $ft->[0] <= $_ <= $ft->[1];
	}
}
say $n;
