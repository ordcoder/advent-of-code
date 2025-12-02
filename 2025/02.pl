#!/usr/bin/perl
use v5.42;
my $sum = 0;
local $/ = ",";
while (<>) {
	my ($fr, $to) = split /[-,]/;
	$sum += sumupto($to) - sumupto($fr-1);
}
say $sum;

sub sumupto {
	my ($to) = @_;
	my ($ten, $sum) = (10, 0);
	$sum += sumrange($ten/10, $ten-1, $ten), $ten*=10 while ($ten*$ten <= $to);
	my $lim = int($to / ($ten+1));
	$sum += sumrange($ten/10, $lim, $ten) if ($lim >= $ten/10);
	return $sum;
}

sub sumrange {
	my ($fr, $to, $ten) = @_;
	return ($to + $fr) * ($to+1 - $fr) / 2 * ($ten+1);
}
