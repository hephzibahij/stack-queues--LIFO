#include <stdlib.h>

/**
 * _realloc - allocate the malloc
 *@ptr: from the point
 *@old_size: from the old size
 *@new_size: from the new size
 *
 * Return: 0 is success
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int copy_size = (old_size < new_size) ? old_size : new_size;
	char *new_ptr = malloc(new_size);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	for (unsigned int i = 0; i < copy_size; i++)
	{
		new_ptr[i] = ptr[i];
	}
	free(ptr);
	return (new_ptr);
}
