void __userpurge vostok::render::debug::renderer::draw_cone(
        const vostok::math::float4x4 *matrix@<edi>,
        const vostok::math::float3 *size@<eax>,
        vostok::render::debug::renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::color *color,
        bool use_depth)
{
  float x; // xmm0_4
  __int64 v8; // xmm1_8
  vostok::math::sphere sphere; // [esp+8h] [ebp-10h] BYREF

  x = size->x;
  if ( size->x <= size->y )
    x = size->y;
  v8 = *(_QWORD *)&matrix->lines[3].x;
  sphere.vector.z = matrix->c.z;
  *(_QWORD *)&sphere.vector.x = v8;
  sphere.vector.w = x;
  if ( vostok::math::cuboid::test(&this->frustum, &sphere) != 2 )
    vostok::render::debug::renderer::draw_lines(
      size,
      this,
      scene,
      matrix,
      vostok::geometry_utils::cone::vertices,
      (vostok::buffer_vector<vostok::render::vertex_colored> *)0x11,
      vostok::geometry_utils::cone::pairs,
      0x20u,
      color,
      1);
}
