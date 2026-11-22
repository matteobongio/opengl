#version 460 core

layout (location = 0) in vec4 aPos;

out vec2 texCoords;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
    texCoords = vec2(aPos.z, aPos.w);
}
