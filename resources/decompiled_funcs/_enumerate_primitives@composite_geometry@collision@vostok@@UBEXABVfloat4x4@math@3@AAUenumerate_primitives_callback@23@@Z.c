void __thiscall vostok::collision::composite_geometry::enumerate_primitives(
        vostok::collision::composite_geometry *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **i; // edi

  m_begin = this->m_geometry_instances.m_begin;
  for ( i = this->m_geometry_instances.m_end; m_begin != i; ++m_begin )
    (*m_begin)->enumerate_primitives(*m_begin, transform, cb);
}
