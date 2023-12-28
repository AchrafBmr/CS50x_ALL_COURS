#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// Change all black pixels to dark red
			BYTE rgb_red = image[i][j].rgbtRed;
			BYTE rgb_green = image[i][j].rgbtGreen;
			BYTE rgb_blue = image[i][j].rgbtBlue;
			if (rgb_red == 0x00 && rgb_green == 0x00 && rgb_blue == 0x00)
			{
				image[i][j].rgbtRed = 0x76;
			}
		}
	}
}
