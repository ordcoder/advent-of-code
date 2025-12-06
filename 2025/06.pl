#!/usr/bin/perl
use v5.42;
use List::Util qw(sum0 product);
my ($sum, $op, @args, @parts);
push @parts, [split //] while (<>);
my @ops = @{pop @parts};
for (my $i = 0; $i < @ops; ++$i) {
	local $_ = join "", map $_->[$i], @parts;
	if (/^\s+$/) {
		$sum += $op->(@args);
		@args = ();
	} else {
		push @args, $_;
	}
	if ($ops[$i] eq "+") {
		$op = \&sum0;
	} elsif ($ops[$i] eq "*") {
		$op = \&product;
	}
}
say $sum;
