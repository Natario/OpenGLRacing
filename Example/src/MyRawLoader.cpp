#include "MyRawLoader.h"

namespace tutorial {
	
    MyRawLoader::MyRawLoader() { }
    MyRawLoader::~MyRawLoader() { }
	
	GLuint MyRawLoader::LoadRawImage(const char *filename, int width, int height)
	{
		GLuint texture;
		unsigned char *data;
		FILE *file;
 
		// open texture data
		file = fopen(filename, "rb");
		if (file == NULL) return 0;
	 
		// allocate buffer
		data = (unsigned char*) malloc(width * height * 4);

		// Just to suppress warning: ignoring return value of ‘size_t fread(void*, size_t, size_t, FILE*)’, declared with attribute warn_unused_result
		size_t creturn;
		// read texture data
		creturn = fread(data, width * height * 4, 1, file);
		fclose(file);
	 
		// allocate a texture name
		glGenTextures(1, &texture);
	 
		// select our current texture
		glBindTexture(GL_TEXTURE_2D, texture);
	 
		// select modulate to mix texture with color for shading
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_MODULATE);
	 
		// when texture area is small, bilinear filter the closest mipmap
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		// when texture area is large, bilinear filter the first mipmap
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	 
		// texture should tile
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 
		// build our texture mipmaps
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	 
		// free buffer
		free(data);
	 
		return texture;
	}
}
