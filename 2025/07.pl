#!/usr/bin/perl
use v5.42;
my ($c, %t);
while (<>) {
	my $ind = index $_, "S";
	$t{$ind} = 1 if $ind >= 0;
	for my $t (keys %t) {
		next unless substr($_, $t, 1) eq "^";
		++$c;
		$t{$t-1} = $t{$t+1} = 1;
		delete $t{$t};
	}
}
say $c;
