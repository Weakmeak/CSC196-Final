#pragma once
#include "Input/InputSystem.h"

#include "Math/MathUtils.h"
#include "Math/Vector2.h"
#include "Math/Random.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include "Framework/Scene.h"

#include "Audio/AudioSystem.h"

#include <memory>

namespace digi {
	extern InputSystem g_Innie;
	extern Renderer g_Ren;
	extern Time g_Time;
	extern AudioSystem g_Miku;
}