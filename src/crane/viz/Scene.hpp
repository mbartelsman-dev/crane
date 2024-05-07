
#pragma once
#define CRANE_HEADER_CONTENTS
#include <typeindex>
#include <unordered_map>
#include <vector>

#include <crane.hpp>

namespace crane::viz
{

struct SceneNode
{

};

struct Scene
{
    std::vector<SceneNode> nodes_;
    std::unordered_map<DrawInfo> nodes_;
};

}

#undef CRANE_HEADER_CONTENTS