#!/usr/bin/perl
use v5.42;
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
$_ = 0;
++$_ while not merge(@{$p[$_]});
say $xyz[$p[$_][0]][0] * $xyz[$p[$_][1]][0];

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
	return $sz[$j] == @xyz;
}

sub getpar {
	my ($i) = @_;
	$par[$i] = getpar($par[$i]) unless $par[$i] == $i;
	return $par[$i];
}
