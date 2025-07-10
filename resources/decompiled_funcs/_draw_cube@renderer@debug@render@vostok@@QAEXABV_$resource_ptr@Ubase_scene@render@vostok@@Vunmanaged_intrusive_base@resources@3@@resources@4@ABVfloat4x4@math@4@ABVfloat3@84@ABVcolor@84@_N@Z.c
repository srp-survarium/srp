void __userpurge vostok::render::debug::renderer::draw_cube(
        vostok::math::aabb *matrix@<edi>,
        const vostok::math::float3 *size@<eax>,
        vostok::render::debug::renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::color *color,
        bool use_depth)
{
  float z; // ecx
  __int64 v8; // xmm0_8
  vostok::math::cuboid *v9; // ecx
  vostok::math::aabb bb; // [esp+0h] [ebp-30h] BYREF
  vostok::math::aabb v11; // [esp+18h] [ebp-18h] BYREF

  z = size->z;
  bb.min.x = -size->x;
  bb.min.y = -size->y;
  bb.min.z = -size->z;
  *(_QWORD *)&v11.min.x = *(_QWORD *)&bb.min.x;
  v8 = *(_QWORD *)&size->x;
  v11.min.z = bb.min.z;
  v11.max.z = z;
  *(_QWORD *)&v11.max.x = v8;
  bb = *vostok::math::aabb::modify(matrix, &v11);
  if ( vostok::math::cuboid::test_inexact(v9, this->frustum.m_planes, &bb) != 2 )
    vostok::render::debug::renderer::draw_lines(
      size,
      this,
      scene,
      (const vostok::math::float4x4 *)matrix,
      vostok::geometry_utils::obb::vertices,
      (vostok::buffer_vector<vostok::render::vertex_colored> *)8,
      vostok::geometry_utils::obb::pairs,
      0xCu,
      color,
      1);
}
