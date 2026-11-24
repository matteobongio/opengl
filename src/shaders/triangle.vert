#version 460 core

layout (location = 0) in vec4 aPos;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

out vec2 texCoords;

void main()
{
    gl_Position = projection * view * model * vec4(aPos.x, aPos.y, 0.0, 1.0);
    texCoords = aPos.zw;
}
