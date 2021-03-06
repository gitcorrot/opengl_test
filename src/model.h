#ifndef _MODEL_H_
#define _MODEL_H_

#include "shader.h"
#include "mathOpengl.h"

struct Model;

/**
 * Interface (virtual funcions) implementation 
 * using array of pointers to function 
 */
struct modelVTable 
{
    void (*modelLoad)(struct Model *self, char *path);
    void (*modelSetShader)(struct Model *self, Shader *shader);
    void (*modelTranslate)(struct Model *self, float x, float y, float z);
    void (*modelRotate)(struct Model *self, float x, float y, float z, float theta);
    void (*modelScale)(struct Model *self, float x, float y, float z);
    void (*modelRender)(struct Model *self, mat4f view, mat4f perspective, vec3f lightPosition);
    void (*modelPrint)(struct Model *self);
    void (*modelDestroy)(struct Model *self);
};

typedef struct Model
{
    struct modelVTable *vtable;

    int modelID;
    int textureID;

} Model;

Model *modelCreate();

void modelLoad(Model *self, char *path);
void modelSetShader(Model *self, Shader *shader);
void modelTranslate(Model *self, float x, float y, float z);
void modelRotate(Model *self, float x, float y, float z, float theta);
void modelScale(Model *self, float x, float y, float z);
void modelRender(Model *self, mat4f view, mat4f perspective, vec3f lightPosition);
void modelPrint(Model *self);
void modelDestroy(Model *self);

#endif
