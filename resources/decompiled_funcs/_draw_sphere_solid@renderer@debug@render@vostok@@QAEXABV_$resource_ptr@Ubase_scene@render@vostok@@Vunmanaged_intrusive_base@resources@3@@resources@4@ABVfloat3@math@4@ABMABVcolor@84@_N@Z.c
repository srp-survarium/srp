void __userpurge vostok::render::debug::renderer::draw_sphere_solid(
        vostok::render::debug::renderer *this@<edi>,
        const vostok::math::float3 *center@<esi>,
        float *radius@<ecx>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::color *color,
        bool use_depth)
{
  __int64 v6; // xmm0_8
  float v7; // xmm7_4
  const vostok::math::float4x4 *v8; // eax
  vostok::math::sphere sphere; // [esp+0h] [ebp-50h] BYREF
  vostok::math::float4x4 result; // [esp+10h] [ebp-40h] BYREF

  v6 = *(_QWORD *)&center->x;
  v7 = *radius;
  sphere.vector.z = center->z;
  *(_QWORD *)&sphere.vector.x = v6;
  sphere.vector.w = v7;
  if ( vostok::math::cuboid::test(&this->frustum, &sphere) != 2 )
  {
    sphere.vector.x = v7;
    sphere.vector.y = v7;
    sphere.vector.z = v7;
    v8 = vostok::math::create_translation(&result, center);
    vostok::render::debug::renderer::draw_primitive_solid(
      (const vostok::math::float3 *)&sphere,
      92,
      this,
      scene,
      v8,
      vostok::geometry_utils::ellipsoid_solid::vertices,
      vostok::geometry_utils::ellipsoid_solid::faces,
      0x21Cu,
      color,
      use_depth);
  }
}
