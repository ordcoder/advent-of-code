#!/usr/bin/perl
use v5.42;
use List::Util qw(product);
my (@xyz, @p, @par, @sz);
push @xyz, [split /,/] while (<>);
for (my $i = 0; $i < @xyz; ++$i) {
	for (my $j = 0; $j < $i; ++$j) {
		push @p, [$j, $i, dist2($j, $i)];
	}
	push @par, $i;
	push @sz, 1;
}
@p = sort {$a->[2] <=> $b->[2]} @p;
my $lim = @xyz == 20 ? 10 : 1000;
for (my $i = 0; $i < $lim; ++$i) {
	merge(@{$p[$i]});
}
@sz = sort {$b <=> $a} @sz;
say product(@sz[0 .. 2]);

sub dist2 {
	my ($i, $j) = @_;
	return ($xyz[$i][0] - $xyz[$j][0])**2 + ($xyz[$i][1] - $xyz[$j][1])**2 + ($xyz[$i][2] - $xyz[$j][2])**2;
}

sub merge {
	my ($i, $j) = @_;
	($i, $j) = rand(2) < 1 ? (getpar($i), getpar($j)) : (getpar($j), getpar($i));
	return if $i == $j;
	$par[$i] = $j;
	$sz[$j] += $sz[$i];
	$sz[$i] = 1;
}

sub getpar {
	my ($i) = @_;
	$par[$i] = getpar($par[$i]) unless $par[$i] == $i;
	return $par[$i];
}
