/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:59:12 by laufarin          #+#    #+#             */
/*   Updated: 2023/11/27 19:08:43 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"


//Esta funcion calcula hasta donde llega la linea, y cuenta el len que necesito para guardar lo que sobre. entonces hago malloc a new storage del tamano que necesita, para luego copiar lo que sobra + \0
char *update_storage(char *storage)
{
	char *new_storage;

	free(storage);
	return (new_storage);











}
//Recibe un storage y calcula cuanto mide la linea a extraer, hacemos un malloc sobre line de ese tamano mas uno, y luego copiamos linea a linea en line, finalmente devolvemos line.
//
// storage -> "hola que tal\n muy bien"
// storage -> "y este cuento se acabo"
//
#include <stdio.h>
#include <stdlib.h>

char *extract_line(char *storage)
{
	char *line;
	int	i;

	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc(sizeof (char) * i + 1);	
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] !='\n' && storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i] = storage[i];
	line[++i] = '\0';
	return (line);
}
/*
int	main (void)
{
	char	*storage;
	char	*ret;

	storage = "abcdef";
	ret = extract_line(storage);
s                                          	printf("%s", ret);
	return(0);
}
*/


//Esta funcion recibe un storage, y va leyendo del arxivo e insertando en el hasta que haya suficiente informacion como para mas tarde extraer una linea. Cuando hay suficiente informacion, en el momento que hay un \n, o el resultado del read es 0 que significa que hemos llegado al final del archivo
//

char *fill_storage(int fd, char *storage)
{
	char *buffer;
	int num_bits;
	
	//malloc a buffer de tamano BUFFER_SIZE + 1
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);

	//while en storage no hayamos puesto aun un \n o no hayamos llegado al final del arxivo
	//hacemos un read al buffer
	// y storage = ft_strjoin(storage, buffer)
	//
	num_bits = 1; //Le pongo 1 porque si le pongo 0 no entro en el while la primera vez
	while(num_bits != 0 && !ft_strchr(buffer, '\n'))
	{
		num_bits = read(fd, buffer, BUFFER_SIZE);
		//caso 1: num_bits == -1 -> ha ocurrido un error y salgo con NULL
		if (num_bits == -1)
			return (NULL);
		//case 2: num_bits > 0   -> hemos escrito num_bits caracteres en buffer
		//caso 3: num_bits == 0  -> Ya hemos llegado al final del archivo
		buffer[num_bits] = '\0';
		storage = ft_strjoin(storage, buffer);
		//buffer[BUFFER_SIZE] = '\0';   <- MAL
	}
	
	return (storage);
}

char *get_next_line(int fd)
{
	char *line;
	static char *storage = NULL;

	//proteger los parametros
	if(fd < 0)
		return (NULL);
	storage = fill_storage(fd, storage);
	if(storage == NULL)
		return (NULL);
	line = extract_line(storage);
	storage = update_storage(storage);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main() 
{
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) 
	{
        perror("Error al abrir el archivo");
        return 1;
    }

	printf("line = %s\n", get_next_line(fd));
    // Puedes utilizar otras funciones de entrada/salida como printf, scanf, etc.

    close(fd);

    return 0;
}
*/
