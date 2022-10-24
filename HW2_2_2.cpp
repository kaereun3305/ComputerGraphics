#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main() {

	glm::mat4 trans = glm::mat4(1.0f);       //단위 행렬로 초기화
	trans = glm::rotate(trans, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//radians = 45도로 회전, vec3 = (0.0f, 1.0f, 0.0f)는 y축으로 회전 

	glm::vec4 result = trans * glm::vec4(1.0f, 2.0f, 0.0f, 1.0f);
	printf("%f, %f, %f\n", result.x, result.y, result.z);
}
