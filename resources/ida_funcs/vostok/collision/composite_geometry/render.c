void __thiscall vostok::collision::composite_geometry::render(
        vostok::collision::composite_geometry *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer,
        const vostok::math::float4x4 *matrix)
{
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **i; // edi
  const vostok::math::float4x4 *v6; // eax
  vostok::math::float4x4 result; // [esp+10h] [ebp-40h] BYREF

  m_begin = this->m_geometry_instances.m_begin;
  for ( i = this->m_geometry_instances.m_end; m_begin != i; ++m_begin )
  {
    v6 = (*m_begin)->get_matrix(*m_begin);
    vostok::math::mul4x3(&result, v6, matrix);
    (*m_begin)->render(*m_begin, scene, renderer, &result);
  }
}
