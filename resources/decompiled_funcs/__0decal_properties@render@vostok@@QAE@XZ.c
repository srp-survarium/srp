void __thiscall vostok::render::decal_properties::decal_properties(
        vostok::render::decal_properties *this,
        vostok::render::decal_properties *thisa)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  __int64 v3; // [esp+Ch] [ebp-4Ch]
  vostok::math::float4x4 v4; // [esp+18h] [ebp-40h] BYREF

  thisa->material.m_object = 0;
  qmemcpy(thisa, vostok::math::float4x4::identity(&v4), 0x40u);
  m_object = thisa->material.m_object;
  thisa->material.m_object = 0;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  *(float *)&v3 = FLOAT_0_5;
  *((float *)&v3 + 1) = FLOAT_0_5;
  *(_QWORD *)&thisa->width_height_far_distance.x = v3;
  thisa->width_height_far_distance.z = FLOAT_0_5;
  thisa->projection_on_terrain_geometry = 1;
  thisa->projection_on_static_geometry = 1;
  thisa->projection_on_speedtree_geometry = 1;
  thisa->projection_on_skeleton_geometry = 1;
  thisa->projection_on_particle_geometry = 1;
  thisa->alpha_angle = -1.0;
  thisa->clip_angle = -1.0;
}
