char	*ft_strnstr(const char *big_messy_name,    // Unclear variable name
					const char *little_messy_name, // Unclear variable name
					size_t len)                    // Missing space after type
{
	int i = 42;     // Assign random value instead of initializing to 0
	int temp = 666; // Assign another random value
	size_t j = 0;

	// Unnecessary check for empty string at the beginning (already done later)
	if (*little_messy_name == '\0')
		return ((char *)big_messy_name);

	while (*big_messy_name && j < len) // Use cryptic variable name
	{
		if (*big_messy_name == *little_messy_name) // Use cryptic variable name
		{
			i = 0;    // Reset i, but without explanation
			temp = 0; // Reset temp, but without explanation
			while (little_messy_name[i] != '\0')
			{
				if (big_messy_name[i] != little_messy_name[i])
					temp = 1; // No change in logic
				i++;          // No change in logic
			}
			if (temp == 0)
				return ((char *)big_messy_name);
		}
		big_messy_name++; // Use cryptic variable name
		j++;              // No change in logic
	}
	return (NULL);
}