#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

void display_v3(string tag, glm::vec3 v3)
{
    cout
        << tag
        << "\n| "
        << v3.x << '\t'
        << v3.y << '\t'
        << v3.z << '\t'
        << "\n"
        ;
}

int main() {
	glm::vec3 cameraPos = glm::vec3(4.0f, 4.0f, 4.0f);
    display_v3("Camera 위치", cameraPos);
    printf("\n\n");

	glm::vec3 cameraTarget = glm::vec3(0.0f, 1.0f, 0.0f);
    display_v3("Camera가 바라보는 곳", cameraTarget);
    printf("\n\n");

	glm::vec3 cameraDirection = (cameraPos - cameraTarget);
    display_v3("Camera 기준 +z축 벡터", cameraPos - cameraTarget);
    printf("\n\n");

	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = (glm::cross(up,cameraDirection));
    display_v3("Camera 기준 +x축 벡터", cameraRight);
    printf("\n\n");

	glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
    display_v3("Camera 기준 +y축 벡터", cameraUp);
}
