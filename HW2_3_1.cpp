#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

void display_4x4(string tag, glm::mat4 m4)
{
    cout << tag << '\n';
    for (int col = 0; col < 4; ++col) {
        cout << "| ";
        for (int row = 0; row < 4; ++row) {
            cout << m4[row][col] << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}

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

void display_v4(string tag, glm::vec4 v4)
{
    cout
        << tag
        << "\n| "
        << v4.x << '\t'
        << v4.y << '\t'
        << v4.z << '\t'
        << v4.w
        << "\n"
        ;
}

int main()
{
    glm::vec4 v4{ 1, 2, 3, 1 };

    display_v4("점(1, 2, 3, (1))", v4);
    printf("\n\n");

    glm::mat4 m4{          //  1/√2 = 0.7071
        0.7, 0, -0.7, 0, 
        0, 1, 0, 0, 
        0.7, 0, 0.7, 0, 
        0, 0, 0, 1 
    };

    display_4x4("y축 회전(1/√2 = 0.7071)", m4);
    printf("-------------------------------------------------------------------------\n\n");

    display_v4("1번 y축으로 CCW로 45도 회전", m4 * v4);
    printf("\n\n");

    glm::vec4 B4 = m4 * v4;

    glm::mat4 Translate{          //  x축으로 -2, y축으로 3, z축으로 1 
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        -2, 3, 1, 1
    };

    display_v4("2번 x축 방향으로 -2, y축 방향으로 3, z축 방향으로 1만큼 translate", Translate*B4);
    printf("\n\n");

    glm::vec4 C4 = Translate * B4;

    glm::mat4 Scaling{        
        1.5, 0, 0, 0,
        0, -2, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    display_v4("3번 원점 기준으로 x축 방향으로 1.5배, y축 방향으로 -2배, z축 방향으로 1배 scaling", Scaling*C4);
    printf("\n\n");


    system("pause");
    return 0;
}
