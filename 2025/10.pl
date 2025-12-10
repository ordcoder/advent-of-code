#!/usr/bin/perl
use v5.42;
use List::Util qw(min);
my $sum;
while (<>) {
	my @parts = split;
	my ($tgt, $tgtstr, $jolts) = (0, shift @parts, pop @parts);
	for (my $i = 0; $i + 2 < length $tgtstr; ++$i) {
		$tgt |= 1 << $i if substr($tgtstr, $i + 1, 1) eq "#";
	}
	my @btn;
	for my $btnstr (@parts) {
		my $btn = 0;
		for my $i (split /,/, substr($btnstr, 1, -1)) {
			$btn |= 1 << $i;
		}
		push @btn, $btn;
	}
	$sum += rec($tgt, \@btn, 0, 0);
}
say $sum;

sub rec {
	my ($tgt, $btn, $i, $s) = @_;
	if ($i == @$btn) {
		return $tgt == 0 ? $s : @$btn + 1;
	}
	return min(rec($tgt, $btn, $i + 1, $s), rec($tgt ^ $btn->[$i], $btn, $i + 1, $s + 1));
}
