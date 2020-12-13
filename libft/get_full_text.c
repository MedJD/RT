
#include "libft.h"

char	*get_full_text(const int fd)
{
	char	*text;
	char	*tmp;
	int		ret;
	int		sum;

	sum = 0;
	text = (char*)malloc(BUFF_SIZE + 1);
	while ((ret = read(fd, &text[sum], BUFF_SIZE)))
	{
		sum += ret;
		text[sum] = '\0';
		tmp = ft_strdup(text);
		free(text);
		text = (char*)malloc(sum + BUFF_SIZE + 1);
		ft_strcpy(text, tmp);
		free(tmp);
	}
	text[sum] = '\0';
	return (text);
}
