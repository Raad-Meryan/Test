#include "ft_printf.h"

void	test_char(void)
{
	int	n;

	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a char " Y "[%c]" RST "\n", 'A'));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a char " G "[%c]" RST "\n", 'A'));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a char " Y "[%10c]" RST "\n", 'A'));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a char " G "[%10c]" RST "\n", 'A'));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a char " Y "[%-10c]" RST "\n", 'A'));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a char " G "[%-10c]" RST "\n", 'A'));
	printf("/////////////////////////\n");
	n = 10;
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a char " Y "[%-*c]" RST "\n", n, 'A'));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a char " G "[%-*c]" RST "\n", n, 'A'));
}

void	test_precent(void)
{
	int	n;

	n = 10;
	// Test without color formatting first
	printf("\tmine_CHARS = %d\n",
			ft_printf("This is a percent sign: [%%]\n"));
				// Use '%%' to print '%'
	printf("\treal_CHARS=%d\n\n",
			printf("This is a percent sign: [%%]\n")); // Same fix here
	printf("/////////////////////////\n");
	printf("\tmine_CHARS = %d\n",
		ft_printf("This is a char with percent and dynamic width [%-*%]\n", n));
		// Use '%%' to print '%'
	printf("\treal_CHARS=%d\n\n",
		printf("This is a char with percent and dynamic width [%%]\n"));
}

void	test_str(void)
{
	char	*s;

	s = "Raad Samer Meryan";
	printf("\tmine_CHARS = %d\n", ft_printf("This is a str [%%s]: [%s]\n", s));
	printf("\treal_CHARS = %d\n\n", printf("This is a str [%%s]: [%s]\n", s));
	printf("\tmine_CHARS = %d\n", ft_printf("This is a str [%%10s]: [%10s]\n",
			s));
	printf("\treal_CHARS = %d\n\n", printf("This is a str [%%10s]: [%10s]\n",
			s));
	printf("\tmine_CHARS = %d\n",
		ft_printf("This is a str [%%10.3s]: [%10.3s]\n", s));
	printf("\treal_CHARS = %d\n\n",
		printf("This is a str [%%10.3s]: [%10.3s]\n", s));
	printf("\tmine_CHARS = %d\n",
		ft_printf("This is a str [%%-10.3s]: [%-10.3s]\n", s));
	printf("\treal_CHARS = %d\n\n",
		printf("This is a str [%%-10.3s]: [%-10.3s]\n", s));
	printf("\tmine_CHARS = %d\n", ft_printf("This is a str [%%*.*s]: [%*.*s]\n",
			3, 6, s));
	printf("\treal_CHARS = %d\n\n", printf("This is a str [%%*.*s]: [%*.*s]\n",
			3, 6, s));
}

void	test_numbers(void)
{
	int				num;
	unsigned int	u;

	num = -12345;
	unsigned int unum = 4294967295; // Max value for 32-bit unsigned integer
	u = 8374;
	// Signed integers (%d and %i)
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a signed number [%d]\n", num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a signed number [%d]\n", num));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a signed number with width [%10d]\n", num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a signed number with width [%10d]\n", num));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a signed number with precision [%.10d]\n", num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a signed number with precision [%.10d]\n", num));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a signed number left-justified [%-10d]\n", num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a signed number left-justified [%-10d]\n", num));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a signed number with width and precision [%10.5d]\n",
			num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a signed number with width and precision [%10.5d]\n",
			num));
	// Unsigned integers (%u)
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is an unsigned number [%u]\n", u));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is an unsigned number [%u]\n", u));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is an unsigned number with width [%10u]\n", u));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is an unsigned number with width [%10u]\n", u));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is an unsigned number with precision [%.10u]\n", u));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is an unsigned number with precision [%.10u]\n", u));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is an unsigned number left-justified [%-10u]\n", u));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is an unsigned number left-justified [%-10u]\n", u));
	// Hexadecimal (%x and %X)
	unsigned int hex_num = 0x2A3F; // Example hexadecimal number
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a hex number (lowercase) [%x]\n", hex_num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a hex number (lowercase) [%x]\n", hex_num));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a hex number (uppercase) [%X]\n", hex_num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a hex number (uppercase) [%X]\n", hex_num));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a hex number with # flag [%#x]\n", hex_num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a hex number with # flag [%#x]\n", hex_num));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a hex number with width [%10x]\n", hex_num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a hex number with width [%10x]\n", hex_num));
	printf("/////////////////////////\n");
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("This is a hex number with precision [%.10x]\n", hex_num));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("This is a hex number with precision [%.10x]\n", hex_num));
}

void	test_pointers(void)
{
	int		a;
	char	*str;
	void	*null_ptr;
	int		*ptr_to_a;

	a = 42;
	str = "Hello, World!";
	null_ptr = NULL;
	ptr_to_a = &a;
	// when pointer is null, it will print (nil)
	// Test printing a pointer with null value
	printf(Y "\tmine_CHARS=%d" RST "\n", ft_printf("Null pointer: [%p]\n",
			null_ptr));
	printf(Y "\treal_CHARS=%d" RST "\n", printf("Null pointer: [%p]\n",
			null_ptr));
	printf("/////////////////////////\n");
	// Test printing a pointer to an integer variable
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("Pointer to int variable [a]: [%p]\n", &a));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("Pointer to int variable [a]: [%p]\n", &a));
	printf("/////////////////////////\n");
	// Test printing a pointer to a string literal
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("Pointer to string literal [str]: [%p]\n", str));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("Pointer to string literal [str]: [%p]\n", str));
	printf("/////////////////////////\n");
	// Test printing a null pointer
	printf(Y "\tmine_CHARS=%d" RST "\n", ft_printf("Null pointer: [%p]\n",
			null_ptr));
	printf(Y "\treal_CHARS=%d" RST "\n", printf("Null pointer: [%p]\n",
			null_ptr));
	printf("/////////////////////////\n");
	// Test printing a pointer to a pointer
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("Pointer to pointer [ptr_to_a]: [%p]\n", ptr_to_a));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("Pointer to pointer [ptr_to_a]: [%p]\n", ptr_to_a));
	printf("/////////////////////////\n");
	// Test printing a pointer with width and flags
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("Pointer with width and flags: [%20p]\n", &a));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("Pointer with width and flags: [%20p]\n", &a));
	printf("/////////////////////////\n");
	// Test printing a left-justified pointer with width
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("Left-justified pointer: [%-20p]\n", &a));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("Left-justified pointer: [%-20p]\n", &a));
	printf("/////////////////////////\n");
	// Test printing a pointer with precision (should be ignored for %p)
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("Pointer with precision: [%.5p]\n", &a));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("Pointer with precision: [%.5p]\n", &a));
	printf("/////////////////////////\n");
	// Test printing a pointer with zero flag (should be ignored for %p)
	printf(Y "\tmine_CHARS=%d" RST "\n",
		ft_printf("Pointer with zero flag: [%020p]\n", &a));
	printf(Y "\treal_CHARS=%d" RST "\n",
		printf("Pointer with zero flag: [%020p]\n", &a));
}

int	main(void)
{
	test_char();
	printf("\n/////\n");
	test_precent();
	printf("\n/////\n");
	test_str();
	printf("\n/////\n");
	test_numbers();
	printf("\n/////\n");
	test_pointers();
	return (0);
}

/*
This is a signed number [-12345]
	mine_CHARS=33
This is a signed number [-12345]
	real_CHARS=33
/////////////////////////
This is a signed number with width [    -12345]
	mine_CHARS=48
This is a signed number with width [    -12345]
	real_CHARS=48
/////////////////////////
This is a signed number with precision [-12345]
	mine_CHARS=48
This is a signed number with precision [-0000012345]
	real_CHARS=53
/////////////////////////
This is a signed number left-justified [-12345    ]
	mine_CHARS=52
This is a signed number left-justified [-12345    ]
	real_CHARS=52
/////////////////////////
This is a signed number with width and precision [    -12345]
	mine_CHARS=62
This is a signed number with width and precision [    -12345]
	real_CHARS=62
/////////////////////////
This is an unsigned number [8374]
	mine_CHARS=34
This is an unsigned number [8374]
	real_CHARS=34
/////////////////////////
This is an unsigned number with width [      8374]
	mine_CHARS=51
This is an unsigned number with width [      8374]
	real_CHARS=51
/////////////////////////
This is an unsigned number with precision [8374]
	mine_CHARS=49
This is an unsigned number with precision [0000008374]
	real_CHARS=55
/////////////////////////
This is an unsigned number left-justified [8374      ]
	mine_CHARS=55
This is an unsigned number left-justified [8374      ]
	real_CHARS=55
/////////////////////////
This is a hex number (lowercase) [2a3f]
	mine_CHARS=40
This is a hex number (lowercase) [2a3f]
	real_CHARS=40
/////////////////////////
This is a hex number (uppercase) [2A3F]
	mine_CHARS=40
This is a hex number (uppercase) [2A3F]
	real_CHARS=40
/////////////////////////
This is a hex number with # flag [0x2a3f]
	mine_CHARS=42
This is a hex number with # flag [0x2a3f]
	real_CHARS=42
/////////////////////////
This is a hex number with width [      2a3f]
	mine_CHARS=45
This is a hex number with width [      2a3f]
	real_CHARS=45
/////////////////////////
This is a hex number with precision [2a3f]
	mine_CHARS=43
This is a hex number with precision [0000002a3f]
	real_CHARS=49

*/
