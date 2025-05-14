#include <stdio.h>
#include <math.h>
#include <glm/glm.hpp>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static int gNumVertices = 0;
static int gNumTriangles = 0;
static int* gIndexBuffer = NULL;
static float* gVertexBuffer = NULL;
static float* gNormalBuffer = NULL;

static void create_scene() {
    int stacks = 128;  // latitude
    int slices = 128;  // longitude

    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<int> indices;

    // vertices
    for (int i = 0; i <= stacks; ++i) {
        float v = (float)i / stacks;
        float phi = v * M_PI;
        for (int j = 0; j <= slices; ++j) {
            float u = (float)j / slices;
            float theta = u * M_PI * 2;

            float x = sinf(phi) * cosf(theta);
            float y = cosf(phi);
            float z = -sinf(phi) * sinf(theta);

            glm::vec3 pos(x, y, z);
            positions.push_back(pos);
            normals.push_back(glm::normalize(pos));  // smooth normal
        }
    }

    // indices
    for (int i = 0; i < stacks; ++i) {
        for (int j = 0; j < slices; ++j) {
            int first = i * (slices + 1) + j;
            int second = first + slices + 1;

            // triangle 1
            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            // triangle 2
            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }

    // copy to global buffers
    gNumVertices = (int)positions.size();
    gNumTriangles = (int)(indices.size() / 3);
    gVertexBuffer = new float[3 * gNumVertices];
    gNormalBuffer = new float[3 * gNumVertices];
    gIndexBuffer = new int[indices.size()];

    for (int i = 0; i < gNumVertices; ++i) {
        gVertexBuffer[3 * i + 0] = positions[i].x;
        gVertexBuffer[3 * i + 1] = positions[i].y;
        gVertexBuffer[3 * i + 2] = positions[i].z;

        gNormalBuffer[3 * i + 0] = normals[i].x;
        gNormalBuffer[3 * i + 1] = normals[i].y;
        gNormalBuffer[3 * i + 2] = normals[i].z;
    }

    for (size_t i = 0; i < indices.size(); ++i) {
        gIndexBuffer[i] = indices[i];
    }
}
