#include "Key.h"

char Key::h2d(char hex)
  {
    if(hex > 0x39) hex -= 7; // adjust for hex letters upper or lower case
    return(hex & 0xf);
  }

Key::Key (char *importVal, uint8_t importSize) {
	size = importSize/2;
	for (int i = 0;i < (importSize/2); i++) {
		high = h2d(importVal[i*2]);
		low = h2d(importVal[i*2+1]);
		key[i] = (high<<4)|low;		
	}
}


Key::Key (uint8_t generationSize) {
	size = generationSize;
	for (uint8_t i = 0; (i < generationSize) && (i < 64); i++) {
		key[i] = (uint8_t) random(0xFF);
	}
}


Key::Key (): Key(64) {}


size_t Key::getSize () {
	return size;
}


void Key::exportToArray (uint8_t *expArray) {
	for (uint8_t i = 0; i < size; i++) {
		expArray[i] = key[i];
	}
}