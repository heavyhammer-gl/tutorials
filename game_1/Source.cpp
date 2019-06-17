#include <GLFW/glfw3.h>
#include  <tweenData.hh>
#include  <tween.hh>

int main(void)
{
	Tween tween_;
	TweenData tweenData;
	tweenData.SetDuration(2.5);
	tweenData.SetDelay(0.0);
	tweenData.SetFrom(0.0);
	tweenData.SetTo(1.0);
	tweenData.SetIsLoop(true);
	tweenData.SetInterpolator(Easing::BounceEaseIn);
	tween_.SetTweenData(tweenData);
	tween_.Play();
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		tween_.Update();
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(.4,.4,.4,1);
		glRotatef (tween_.num, 0, 1, 1);
		glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.0);
			glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
			glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}