#include <string>

std::string	getFileName(char *file)
{
	std::string fileName;

	int i = 0;
	while (file[i])
	{
		if (file[i] == '.')
			break ;
		i++;
	}
	fileName.assign(file);
	fileName.erase(i, fileName.npos);
	return (fileName);
}

std::string	getFileExtension(char *file)
{
	std::string extension;
	extension.assign(file);
	int i = 0;
	while (file[i])
	{
		if (file[i] == '.')
			break ;
		i++;
	}
	extension.erase(0, i);
	return (extension);
}

std::string	getOutfile(char *file)
{
	return getFileName(file) + ".replace" + getFileExtension(file);
}