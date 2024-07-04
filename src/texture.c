#include "../headers/header.h"

static const char *textureFileNames[NUM_TEXTURES] = {
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/graystone.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/eagle.png",
};

/**
 * WallTexturesready - load textures in the respective position
 *
*/
void WallTexturesready(void)
{
	int k;

	for (k = 0; k < NUM_TEXTURES; k++)
	{
		upng_t *upng;

		upng = upng_new_from_file(textureFileNames[k]);

		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				wallTextures[k].upngTexture = upng;
				wallTextures[k].width = upng_get_width(upng);
				wallTextures[k].height = upng_get_height(upng);
				wallTextures[k].texture_buffer = (color_t *)upng_get_buffer(upng);
			}
		}
	}

}

/**
 * freeWallTextures - free wall textures
 *
*/

void freeWallTextures(void)
{
	int k;

	for (k = 0; k < NUM_TEXTURES; k++)
		upng_free(wallTextures[k].upngTexture);
}
