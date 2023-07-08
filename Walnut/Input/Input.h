#pragma once

#include "KeyCodes.h"

#include <glm/glm.hpp>

namespace Walnut {

	class Input
	{
	public:
		static bool IsKeyDown(KeyCode keycode);
		static bool IsMouseButtonDown(MouseButton button);
		static float GetMouseScrollOffset();

		static glm::vec2 GetMousePosition();

		static void SetCursorMode(CursorMode mode);
	private:
		static float s_ScrollOffset;
	};

}
