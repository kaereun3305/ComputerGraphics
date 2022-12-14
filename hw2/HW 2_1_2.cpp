#include<iostream>
#include<glm/glm.hpp>
#include <string>

using namespace::std;

void display_v3(string tag, glm::vec3 v3) {
	cout << tag
		<< "\n | "
		<< v3.x << '\t'
		<< v3.y << '\t'
		<< v3.z << '\t'
		<< "\n"
		;
}
int main() {
	glm::vec3 vCross = glm::cross(
		glm::vec3(2.0f, -1.0f, 3.0f), // unit-size vector along the x axis
		glm::vec3(0.0f, 1.0f, 0.0f) // unit- size vector along the y axis
	);
	display_v3("cross( x, y )", vCross);
	glm::vec3 vA(2.0f, -1.0f, 3.0f);
	glm::vec3 vB(0.0f, 1.0f, 0.0f);
	float dot_product = glm::dot(vA, vB);
	cout << "dot- product: " << dot_product << "\n\n";
}
