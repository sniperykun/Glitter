#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 vColor;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	// vec3 color = vec3(1.0, 0.5, 0.0);
	// FragColor = vec4(color, 1.0f);
	
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
	FragColor = FragColor * vec4(vColor, 1.0);
}