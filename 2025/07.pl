#!/usr/bin/perl
use v5.42;
use List::Util qw(sum0);
my %t;
while (<>) {
	$t{index $_, "S"} = 1 if $. == 1;
	for my $t (keys %t) {
		next unless substr($_, $t, 1) eq "^";
		$t{$t-1} += $t{$t};
		$t{$t+1} += $t{$t};
		delete $t{$t};
	}
}
say sum0 values %t;
