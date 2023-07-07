/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:23:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/07 10:23:21 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MAX_HEIGHT 100
#define MAX_WIDTH 100

// Global variables for map dimensions
int height, width;

// Global array for visited positions
bool visited[MAX_HEIGHT][MAX_WIDTH];

// Global variable for the number of collectibles
int collectible_count = 0;

// Function to perform backtracking
bool backtrack(char map[MAX_HEIGHT][MAX_WIDTH], int row, int col)
{
    // Check if current position is out of bounds or already visited
    if (row < 0 || row >= height || col < 0 || col >= width || visited[row][col])
        return false;

    // Mark the current position as visited
    visited[row][col] = true;

    // Check if the current position is a wall
    if (map[row][col] == '1')
        return false;

    // Check if the current position is the exit
    if (map[row][col] == 'E')
        return true;

    // Check if the current position is a collectible
    if (map[row][col] == 'C')
        collectible_count--;

    // Define the possible movements (up, down, left, right)
    int movements[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Try all possible movements
    for (int i = 0; i < 4; i++)
    {
        int dx = movements[i][0];
        int dy = movements[i][1];
        if (backtrack(map, row + dx, col + dy))
            return true;
    }

    return false;
}

// Function to check if all collectibles and the exit are reachable
bool are_collectibles_reachable(const char *file_name)
{
    // Open the map file
    int fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open the file.\n");
        return false;
    }

    // Read the file contents
    char *line;
    int line_count = 0;
    int bytes_read;

    // Read lines until the end of the file
    while ((bytes_read = get_next_line(fd, &line)) > 0)
    {
        // Check if the line exceeds the maximum width
        if (ft_strlen(line) > MAX_WIDTH)
        {
            printf("Invalid map format: line %d exceeds the maximum width.\n", line_count);
            free(line);
            close(fd);
            return false;
        }

        // Copy the line to the map array
        ft_strlcpy(map[line_count], line, MAX_WIDTH + 1);

        // Count the number of collectibles
        for (int i = 0; i < width; i++)
        {
            if (map[line_count][i] == 'C')
                collectible_count++;
        }

        free(line);
        line_count++;

        // Check if the line count exceeds the maximum height
        if (line_count > MAX_HEIGHT)
        {
            printf("Invalid map format: the map exceeds the maximum height.\n");
            close(fd);
            return false;
        }
    }

    close(fd);

    // Check if any error occurred while reading the file
    if (bytes_read == -1)
    {
        printf("Failed to read the file.\n");
        return false;
    }

    // Set the map dimensions
    height = line_count;
    width = ft_strlen(map[0]);

    // Find the starting position
    int start_row, start_col;
    bool player_found = false;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == 'P')
            {
                start_row = i;
                start_col = j;
                player_found = true;
                break;
            }
        }

        if (player_found)
            break;
    }

    // Call the backtracking function from the starting position
    bool path_found = backtrack(map, start_row, start_col);

    // Check if all collectibles and the exit are reachable
    bool all_reachable = (collectible_count == 0) && path_found;

    return all_reachable;
}

int main()
{
    const char *file_name = "map.ber";

    bool reachable = are_collectibles_reachable(file_name);

    if (reachable)
        printf("All collectibles and the exit are reachable.\n");
    else
        printf("Not all collectibles and the exit are reachable.\n");

    return 0;
}

