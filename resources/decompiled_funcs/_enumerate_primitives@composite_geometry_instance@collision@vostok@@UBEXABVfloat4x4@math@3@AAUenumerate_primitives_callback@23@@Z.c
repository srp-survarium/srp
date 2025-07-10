void __thiscall vostok::collision::composite_geometry_instance::enumerate_primitives(
        vostok::collision::composite_geometry_instance *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **i; // edi

  m_geometry = this->m_geometry;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  for ( i = m_geometry->m_geometry_instances.m_end; m_begin != i; ++m_begin )
    (*m_begin)->enumerate_primitives(*m_begin, transform, cb);
}
