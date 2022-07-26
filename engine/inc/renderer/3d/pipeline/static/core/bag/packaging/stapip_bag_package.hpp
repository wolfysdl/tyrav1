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

#include "../stapip_bag.hpp"
#include "renderer/core/3d/bbox/core_bbox_frustum.hpp"

namespace Tyra {

class StaPipBagPackage {
 public:
  StaPipBagPackage();
  ~StaPipBagPackage();

  StaPipBag* bag;

  Vec4* vertices;
  Vec4* sts;
  Vec4* normals;
  Vec4* colors;
  /** maxVertCount is max value, because we decided to put max maxVertCount
   * verts to single quad buffer in VU1 */
  u16 size;
  CoreBBoxFrustum isInFrustum;

  /**
   * We are creating StaPipBagPackagesBBox which checks CoreBBoxBBox for every
   * maxVertCount / 3. So this variable is index of starting
   * StaPipBagPackagesBBox's CoreBBoxBBox. If package have <= maxVertCount / 3
   * verts, we will need only single (starting) bbox. if package have
   * maxVertCount verts, we will calculate CoreBBoxBBox from 3
   * StaPipBagPackagesBBox's bboxes.
   */
  u32 indexOf1By3BBox;

  void print() const;
  void print(const char* name) const;
  void print(const std::string& name) const { print(name.c_str()); }
  std::string getPrint(const char* name = nullptr) const;
};

}  // namespace Tyra