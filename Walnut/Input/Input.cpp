#include "Input.h"

#include "Walnut/Application.h"

#include <GLFW/glfw3.h>

namespace Walnut {

	glm::vec2 Input::m_ScrollOffset = glm::vec2(0.0f);

	bool Input::IsKeyDown(KeyCode keycode)
	{
		GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
		int state = glfwGetKey(windowHandle, (int)keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonDown(MouseButton button)
	{
		GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
		int state = glfwGetMouseButton(windowHandle, (int)button);
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMouseScrollOffset()
	{
		GLFWwindow* windowHandle = Application::Get().GetWindowHandle();

		glfwSetScrollCallback(windowHandle, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			m_ScrollOffset.x = (float)xOffset;
			m_ScrollOffset.y = (float)yOffset;
		});

		return m_ScrollOffset;
	}

	glm::vec2 Input::GetMousePosition()
	{
		GLFWwindow* windowHandle = Application::Get().GetWindowHandle();

		double x, y;
		glfwGetCursorPos(windowHandle, &x, &y);
		return { (float)x, (float)y };
	}

	void Input::SetCursorMode(CursorMode mode)
	{
		GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
		glfwSetInputMode(windowHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)mode);
	}

}