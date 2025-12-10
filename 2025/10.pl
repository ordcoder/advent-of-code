#!/usr/bin/perl
use v5.42;
use List::Util qw(any min max);
my $sum = 0;
my (@btn, @jlt, @ord);
while (<>) {
	my @parts = split;
	my ($lgh, $jlt) = (shift @parts, pop @parts);
	@btn = @jlt = @ord = ();
	push @btn, [split /,/, substr($_, 1, -1)] for @parts;
	push @jlt, {i => scalar @jlt, v => 0|$_, b => [], o => 0} for split /,/, substr($jlt, 1, -1);
	for my ($i, $b) (indexed @btn) {
		push @{$jlt[$_]{b}}, $i for @$b;
	}
	while (@ord < @jlt) {
		my $mi = -1;
		for my ($i, $j) (indexed @jlt) {
			next if $j->{o};
			next unless $mi < 0 or $j->{v} == 0 or @{$j->{b}} < @{$jlt[$mi]{b}};
			$mi = $i;
		}
		my $j = $jlt[$mi];
		$j->{o} = 1;
		push @ord, $mi;
		for my $b (@{$j->{b}}) {
			for my $k (@{$btn[$b]}) {
				next if $k == $mi;
				@{$jlt[$k]{b}} = grep {$_ != $b} @{$jlt[$k]{b}};
			}
		}
	}

	$sum += rec(0, 0, 0);
}
say $sum;

sub rec {
	my ($i, $ii, $s) = @_;
	return $s if $i == @ord;
	my $j = $jlt[$ord[$i]];
	return rec($i + 1, 0, $s) if $j->{v} == 0;
	my $r = 123456789;
	return $r if $ii == @{$j->{b}};
	my ($v, $b) = ($j->{v}, $btn[$j->{b}[$ii]]);
	if ($ii == @{$j->{b}} - 1) {
		for (@$b) {
			return $r if $jlt[$_]->{v} < $v;
		}
		$jlt[$_]->{v} -= $v for @$b;
		$r = rec($i + 1, 0, $s + $v);
		$jlt[$_]->{v} += $v for @$b;
		return $r;
	}
	my $d;
	D: for ($d = 0; ; ++$d) {
		$r = min($r, rec($i, $ii + 1, $s + $d));
		for (@$b) {
			last D if $jlt[$_]->{v} <= 0;
		}
		--$jlt[$_]->{v} for @$b;
	}
	$jlt[$_]->{v} += $d for @$b;
	return $r;
}
