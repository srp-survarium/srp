void __userpurge vostok::render::debug::renderer::draw_sphere(
        vostok::render::debug::renderer *this@<edi>,
        const vostok::math::float4x4 *m@<eax>,
        float *radius@<ecx>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::color *color,
        bool use_depth)
{
  float v6; // xmm7_4
  __int64 v8; // xmm0_8
  vostok::math::sphere sphere; // [esp+4h] [ebp-14h] BYREF

  v6 = *radius;
  v8 = *(_QWORD *)&m->lines[3].x;
  sphere.vector.z = m->c.z;
  *(_QWORD *)&sphere.vector.x = v8;
  sphere.vector.w = v6;
  if ( vostok::math::cuboid::test(&this->frustum, &sphere) != 2 )
  {
    sphere.vector.x = v6;
    sphere.vector.y = v6;
    sphere.vector.z = v6;
    vostok::render::debug::renderer::draw_lines(
      (const vostok::math::float3 *)&sphere,
      this,
      scene,
      m,
      vostok::geometry_utils::ellipsoid::vertices,
      (vostok::buffer_vector<vostok::render::vertex_colored> *)0x72,
      vostok::geometry_utils::ellipsoid::pairs,
      0x150u,
      color,
      1);
  }
}
