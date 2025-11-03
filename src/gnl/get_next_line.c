#include "survival_lib.h"

/**
 * @file get_next_line.c
 * @brief Implementation of line reading functionality from file descriptors
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 *
 * @note This implementation supports reading from multiple file descriptors
 * concurrently by maintaining separate buffers for each descriptor.
 */

/**
 * @brief Extracts and returns the next complete line from the buffer
 *
 * @details This function processes the internal buffer to extract a complete
 * line terminated by a newline character or the end of the buffer. It updates
 * the buffer pointer to remove the extracted line, leaving any remaining data
 * for subsequent reads. The newline character is included in the returned line
 * if present.
 *
 * @ingroup get_next_line
 *
 * @param[in,out] buffer Pointer to the buffer containing the data to process
 *
 * @return Pointer to the extracted line (must be freed by caller)
 * @retval NULL If the buffer is empty or NULL
 *
 * @note The returned string must be freed by the caller to prevent memory leaks.
 * @warning The buffer pointer is modified and reallocated during this operation.
 */
static char	*extract_line(char **buffer)
{
    char	*line;
    char	*new_buffer;
    size_t	i;

    if (!*buffer || **buffer == '\0')
        return (NULL);
    i = 0;
    while ((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    if ((*buffer)[i] == '\n')
        i++;
    line = str_substring(*buffer, 0, i);
    new_buffer = str_duplicate(*buffer + i);
    free(*buffer);
    *buffer = new_buffer;
    return (line);
}

/**
 * @brief Checks if a newline character exists in the buffer
 *
 * @details This function scans the provided buffer string to determine if it
 * contains a newline character ('\n'). It is used to decide whether the buffer
 * contains a complete line ready for extraction or if more data needs to be
 * read from the file descriptor.
 *
 * @ingroup get_next_line
 *
 * @param[in] buffer The buffer string to scan for newline characters
 *
 * @return Newline presence indicator
 * @retval 1 If a newline character is found in the buffer
 * @retval 0 If no newline is found or buffer is NULL
 */
static int	has_newline(char *buffer)
{
    if (!buffer)
        return (0);
    while (*buffer)
    {
        if (*buffer == '\n')
            return (1);
        buffer++;
    }
    return (0);
}

/**
 * @brief Reads data from file descriptor and appends it to the buffer
 *
 * @details This function performs a single read operation from the specified
 * file descriptor using a temporary buffer of size BUFFER_SIZE. The read data
 * is then appended to the existing buffer content. If the buffer is initially
 * NULL, it is initialized as an empty string before appending. This function
 * handles memory allocation and deallocation internally.
 *
 * @ingroup get_next_line
 *
 * @param[in] fd The file descriptor to read from
 * @param[in,out] buffer Pointer to the buffer where data will be appended
 *
 * @return Number of bytes read from the file descriptor
 * @retval >0 Number of bytes successfully read
 * @retval 0 End of file reached
 * @retval -1 Read error occurred
 *
 * @note The buffer is dynamically reallocated to accommodate new data.
 * @warning The buffer pointer may be modified during this operation.
 */
static ssize_t	read_into_buffer(int fd, char **buffer)
{
    char	temp[BUFFER_SIZE + 1];
    ssize_t	bytes_read;
    char	*new_buffer;

    bytes_read = read(fd, temp, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (bytes_read);
    temp[bytes_read] = '\0';
    if (*buffer == NULL)
        *buffer = str_duplicate("");
    new_buffer = str_join(*buffer, temp);
    free(*buffer);
    *buffer = new_buffer;
    return (bytes_read);
}

/**
 * @brief Reads and returns the next line from a file descriptor
 *
 * @details This function reads from the specified file descriptor and returns
 * one complete line at a time, including the terminating newline character if
 * present. It maintains internal state for each file descriptor (up to 1024
 * concurrent descriptors) to handle partial reads across multiple calls. The
 * function continues reading until a complete line is available or EOF/error
 * is encountered. Memory is managed automatically for buffering, and the caller
 * is responsible for freeing the returned line.
 *
 * @ingroup get_next_line
 *
 * @param[in] fd The file descriptor to read from (must be non-negative)
 *
 * @return Pointer to the next line read from the file descriptor
 * @retval NULL If EOF is reached, an error occurs, or invalid parameters
 *
 * @note The returned string must be freed by the caller to prevent memory leaks.
 * @note The function supports reading from up to 1024 different file descriptors
 * concurrently.
 * @warning BUFFER_SIZE must be greater than 0 for proper functionality.
 * @warning File descriptor must be valid and open for reading.
 */
char    *get_next_line(int fd)
{
    static char	*buffers[1024];
    char		*line;
    ssize_t		bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_read = 1;
    while (!has_newline(buffers[fd]) && bytes_read > 0)
    {
        bytes_read = read_into_buffer(fd, &buffers[fd]);
        if (bytes_read == -1)
        {
            free(buffers[fd]);
            buffers[fd] = NULL;
            return (NULL);
        }
    }
    line = extract_line(&buffers[fd]);
    return (line);
}
