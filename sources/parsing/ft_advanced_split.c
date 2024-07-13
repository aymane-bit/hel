/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:36:23 by aymane            #+#    #+#             */
/*   Updated: 2024/07/09 19:12:36 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

int count_segments(const char *str) {
    int count = 0;
    while (*str) {
        // Skip leading spaces
        if (*str == ' ') {
            count++;
            while (*str == ' ') {
                str++;
            }
        } else if (*str == '$') {
            count++;
            str++;
            while (*str && *str != ' ') {
                str++;
            }
        } else {
            count++;
            while (*str && *str != ' ' && *str != '$') {
                str++;
            }
        }
    }
    return count;
}

// Function to split the string
char **ft_advanced_split(const char *str) {
    int segments = count_segments(str);
    char **result = malloc((segments + 1) * sizeof(char *));
    int segment_index = 0;

    while (*str) {
        // Handle spaces
        if (*str == ' ') {
            const char *start = str;
            while (*str == ' ') {
                str++;
            }
            int length = str - start;
            result[segment_index] = malloc((length + 1) * sizeof(char));
            strncpy(result[segment_index], start, length);
            result[segment_index][length] = '\0';
            segment_index++;
        } else if (*str == '$') {
            // Handle $ sign
            const char *start = str;
            str++;
            while (*str && *str != ' ') {
                str++;
            }
            int length = str - start;
            result[segment_index] = malloc((length + 1) * sizeof(char));
            strncpy(result[segment_index], start, length);
            result[segment_index][length] = '\0';
            segment_index++;
        } else {
            // Handle regular words
            const char *start = str;
            while (*str && *str != ' ' && *str != '$') {
                str++;
            }
            int length = str - start;
            result[segment_index] = malloc((length + 1) * sizeof(char));
            strncpy(result[segment_index], start, length);
            result[segment_index][length] = '\0';
            segment_index++;
        }
    }

    result[segment_index] = NULL;
    return result;
}
