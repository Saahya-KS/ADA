/*You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 void dfs(int** image, int imageSize, int* imageColSize, int r, int c, int originalColor, int newColor) {
    if (r < 0 || r >= imageSize || c < 0 || c >= imageColSize[r]) return;
    if (image[r][c] != originalColor || image[r][c] == newColor) return;

    image[r][c] = newColor;

    dfs(image, imageSize, imageColSize, r + 1, c, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r - 1, c, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r, c + 1, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r, c - 1, originalColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int originalColor = image[sr][sc];

    if (originalColor != color) {
        dfs(image, imageSize, imageColSize, sr, sc, originalColor, color);
    }

    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    return image;
}