#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

using namespace std;


void display_4x4(string tag, glm::mat4 m4)
{
	cout << tag << '\n';
	for (int row = 0; row < 4; ++row) {
		cout << "| ";
		for (int col = 0; col < 4; ++col) {
			cout << m4[col][row] << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}

void display_v4(string tag, glm::vec4 v4)
{
	cout
		<< tag
		<< "\n| " << v4.x
		<< "\n| " << v4.y
		<< "\n| " << v4.z
		<< "\n| " << v4.w
		<< "\n"
		;
}

int main()
{

	glm::vec4 v{ 1, 2, 3, 1 };

	display_v4("v", v);

	glm::mat4 I{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	display_4x4("I", I);

	display_v4("I * v", I * v);
}
