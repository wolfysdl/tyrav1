/*
# ______       ____   ___
#   |     \/   ____| |___|
#   |     |   |   \  |   |
#-----------------------------------------------------------------------
# Copyright 2022, tyra - https://github.com/h4570/tyra
# Licenced under Apache License 2.0
# Sandro Sobczyński <sandro.sobczynski@gmail.com>
*/

#pragma once

#include <renderer/3d/mesh/dynamic/dynamic_mesh.hpp>
#include <renderer/3d/pipeline/dynamic/dynpip_options.hpp>
#include "states/game/renderer/renderer_dynamic_pair.hpp"
#include <renderer/renderer.hpp>

using Tyra::DynamicMesh;
using Tyra::DynPipOptions;
using Tyra::Renderer;
using Tyra::TextureRepository;
using Tyra::Vec4;

namespace Demo {

class Enemy {
 public:
  Enemy(TextureRepository* repo);
  ~Enemy();

  DynamicMesh* bodyMesh;
  DynamicMesh* gunMesh;
  DynPipOptions* options;
  std::vector<RendererDynamicPair*> pairs;

  void update(const Vec4& playerPosition);

 private:
  void allocateOptions();
};

}  // namespace Demo