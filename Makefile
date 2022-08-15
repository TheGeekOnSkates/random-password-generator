all:
	clear && gcc ./*.c -orandom-password || exit 1
	./random-password && echo "" && ./random-password 15 && echo "" && ./random-password 160 && echo ""

