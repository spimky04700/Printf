#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			ch;
	char			*str;
	char			*null_str = NULL;
	int				n;
	int				zero = 0;
	unsigned int	un;
	unsigned int	large = 4294967295U; // UINT_MAX
	void			*ptr;
	void			*null_ptr = NULL;
	int				ret1;
	int				ret2;

	ch = 'Z';
	str = "Hello 42";
	n = -12345;
	un = 4242;
	ptr = str;

    ft_putstr("--- %c ---\n");
	ret1 = ft_printf("ft_printf : |%c|\n", ch);
	ret2 = printf("printf    : |%c|\n", ch);
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

    ft_putstr("--- %s ---\n");
	ret1 = ft_printf("ft_printf : |%s|\n", str);
	ret2 = printf("printf    : |%s|\n", str);
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

    ft_putstr("--- %s_NULL ---\n");
	ret1 = ft_printf("ft_printf : |%s|\n", null_str);
	ret2 = printf("printf    : |%s|\n", null_str);
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

	ft_putstr("--- %p ---\n");
	ret1 = ft_printf("ft_printf : |%p|\n", ptr);
	ret2 = printf("printf    : |%p|\n", ptr);
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

    ft_putstr("--- %p_NULL ---\n");
	ret1 = ft_printf("ft_printf : |%p|\n", null_ptr);
	ret2 = printf("printf    : |%p|\n", null_ptr);
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

	// --- %d et %i ---
    ft_putstr("--- %d & %d ---\n");
	ret1 = ft_printf("ft_printf : |%d| |%i| |%d|\n", n, n, zero);
	ret2 = printf("printf    : |%d| |%i| |%d|\n", n, n, zero);
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

	// --- %u ---
    ft_putstr("--- %u ---\n");
	ret1 = ft_printf("ft_printf : |%u| |%u|\n", un, large);
	ret2 = printf("printf    : |%u| |%u|\n", un, large);
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

	// --- %x et %X ---
    ft_putstr("--- %x & %X ---\n");
	ret1 = ft_printf("ft_printf : |%x| |%X| |%x|\n", 0, 3735928559U, large);
	ret2 = printf("printf    : |%x| |%X| |%x|\n", 0, 3735928559U, large);
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

	// --- %% ---
    ft_putstr("--- %% ---\n");
	ret1 = ft_printf("ft_printf : 100%% OK !\n");
	ret2 = printf("printf    : 100%% OK !\n");
	printf("retours -> ft_printf:%d | printf:%d\n\n", ret1, ret2);

	return (0);
}
