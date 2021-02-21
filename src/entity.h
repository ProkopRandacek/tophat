#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>
#include "rect.h"

typedef struct {
	rect r;
	int c;
	uint32_t *image;
	uint32_t color;
	int id;
} entity;

typedef struct entnode {
	entity *val;
	struct entnode *next;
} entnode_t;

entity entityfromrect(rect r, uint32_t color);
entity entityfromimage(char path[]);
void draw(entity o, rect cam);

#endif
