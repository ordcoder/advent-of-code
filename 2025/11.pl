#!/usr/bin/perl
use v5.42;
my (%forw, %back);
while (<>) {
	my ($x, @ys) = split /[:\s]+/;
	for (@ys) {
		push @{$forw{$x}}, $_;
		$back{$_}{$x} = 1;
	}
}
my (@q, @top);
for (keys %forw) {
	push @q, $_ unless exists $back{$_};
}
while (@q) {
	my $x = shift @q;
	push @top, $x;
	for (@{$forw{$x}}) {
		delete $back{$_}{$x};
		push @q, $_ unless %{$back{$_}};
	}
}
my %cnt = (svr => 1);
for my $x (@top) {
	%cnt = ($x => $cnt{$x}) if $x =~ /^(dac|fft)$/;
	$cnt{$_} += $cnt{$x} // 0 for @{$forw{$x}};
}
say $cnt{out};
