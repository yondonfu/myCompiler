int global_a = 5;
int global_b = 9;

int main(void) {
	int a = 0;
	int b = 10;
	int c;
	int d = 5;

	read c;

	print c;

	while (b > 8 && a < 10) {
		print "WOO!";
		++a;
		--b;
	}

	print "DONE!";

	for (c = 0; c < 4; ++c) {
		print "YAY!";
	}

	print "DONE AGAIN!";

	do {
		print "WAHOO!";
		--d;
	} while (d >= 0);

	print "DONE YET AGAIN!";

	return 0;
}