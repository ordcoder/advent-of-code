#!/usr/bin/perl
use v5.42;
use List::Util qw(min max);
my $sum = 0;
local $/ = ",";
while (<>) {
	my ($fr, $to) = split /[-,]/;
	$sum += sumall($to) - sumall($fr-1);
}
say $sum;

sub sumall {
	my ($to) = @_;
	return sum2($to) + sum3($to) + sum5($to) + sum7($to);
}

sub sum2 {
	my ($to) = @_;
	my ($ten, $sum) = (1, 0);
	$sum += sumrange($to, $ten, 10*$ten+1), $ten*=10 while (10*$ten*$ten <= $to);
	return $sum;
}

sub sum3 {
	my ($to) = @_;
	my ($ten, $sum) = (1, 0);
	$sum += sumrange($to, $ten, 100*$ten*$ten+10*$ten+1), $ten*=10 while (100*$ten*$ten*$ten <= $to);
	$sum -= sumrange($to, 1, 111111);
	return $sum;
}

sub sum5 {
	my ($to) = @_;
	return sumrange($to,  1,      11111) +
	       sumrange($to, 10,  101010101) -
	       sumrange($to,  1, 1111111111);
}

sub sum7 {
	my ($to) = @_;
	return sumrange($to, 1, 1111111);
}

sub sumrange {
	my ($to, $fr, $mult) = @_;
	my $lim = max(min(int($to / $mult), 10*$fr-1), $fr-1);
	return ($lim + $fr) * ($lim+1 - $fr) / 2 * $mult;
}
