// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	// Border the image with black pixels
	int bi_height = height + 2;
	int bi_width = width + 2;
	// Border the image with black pixels
	RGBTRIPLE bordered_image[bi_height][bi_width];
	border_image(height, width, image, bordered_image);

@@ -98,6 +98,20 @@ void blur(int height, int width, RGBTRIPLE image[height][width])
// Detect edges
void edges (int height, int width, RGBTRIPLE image[height][width])
{
	// Border the image with black pixels
	int bi_height = height + 2;
	int bi_width = width + 2;
	RGBTRIPLE bordered_image[bi_height][bi_width];
	border_image(height, width, image, bordered_image);

	// Detect edges for each pixel in image[][]
	for (int i = 1; i < bi_height - 1; i++)
	{
		for (int j = 1; j < bi_width - 1; j++)
		{
			image[i - 1][j - 1] = calc_edge(i, j, bi_height, bi_width, bordered_image);
		}
	}
	return;
}

@@ -144,3 +158,53 @@ RGBTRIPLE calc_blur_rgb(int index_i, int index_j, int height, int width, RGBTRIP
	blur_triple.rgbtBlue = round(blur_blue);
	return blur_triple;
}

// Calculate edge rgb values for pixel image[i][j]
RGBTRIPLE calc_edge (int index_i, int index_j, int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE triple, Gx_triple, Gy_triple, result_triple;
	short Gx[3][3] = {
		{ -1, 0, 1 },
		{ -2, 0, 2 },
		{ -1, 0, 1 }
	};
	short Gy[3][3] = {
		{ -1, -2, -1 },
		{ 0, 0, 0 },
		{ 1, 2, 1 }
	};
	int Gx_red = 0, Gx_green = 0, Gx_blue = 0;
	int Gy_red = 0, Gy_green = 0, Gy_blue = 0;
	float result_red = 0.0, result_green = 0.0, result_blue = 0.0;
	int i = index_i - 1, i_GxGy = 0;
	int j = index_j - 1, j_GxGy = 0;

	// Calculate rgb values for Gx and Gy
	while (i <= index_i + 1)
	{
		while (j <= index_j + 1)
		{
			triple = image[i][j];
			Gx_red += triple.rgbtRed * Gx[i_GxGy][j_GxGy];
			Gy_red += triple.rgbtRed * Gy[i_GxGy][j_GxGy];
			Gx_green += triple.rgbtGreen * Gx[i_GxGy][j_GxGy];
			Gy_green += triple.rgbtGreen * Gy[i_GxGy][j_GxGy];
			Gx_blue += triple.rgbtBlue * Gx[i_GxGy][j_GxGy];
			Gy_blue += triple.rgbtBlue * Gy[i_GxGy][j_GxGy];
			j++, j_GxGy++;
		}
		i++, i_GxGy++;
	}

	// Calculate the result triple rgb values
	// result = round( square_root(Gx * Gx + Gy * Gy) ) % 255 for each rgb
	result_red = (int)round( sqrt( Gx_red * Gx_red + Gy_red * Gy_red ) ) % 0xff;
	result_green = (int)round( sqrt( Gx_green * Gx_green + Gy_green * Gy_green ) ) % 0xff;
	result_blue = (int)round( sqrt( Gx_blue * Gx_blue + Gy_blue * Gy_blue ) ) % 0xff;

	// Assign rgb vals to result triple and return
	result_triple.rgbtRed = result_red;
	result_triple.rgbtGreen = result_green;
	result_triple.rgbtBlue = result_blue;
	return result_triple;
}