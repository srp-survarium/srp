void __thiscall vostok::collision::composite_geometry_instance::enumerate_primitives(
        vostok::collision::composite_geometry_instance *this,
        vostok::collision::enumerate_primitives_callback *cb)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_begin; // edi
  vostok::collision::geometry_instance *v4; // ebx
  void (__thiscall **p_enumerate_primitives)(vostok::collision::geometry_instance *, const vostok::math::float4x4 *, vostok::collision::enumerate_primitives_callback *); // esi
  vostok::math::float4x4 *v6; // eax
  const vostok::collision::geometry_instance *const *e; // [esp+Ch] [ebp-44h]
  vostok::math::float4x4 v8; // [esp+10h] [ebp-40h] BYREF

  m_geometry = this->m_geometry;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  for ( e = (const vostok::collision::geometry_instance *const *)m_geometry->m_geometry_instances.m_end;
        m_begin != (vostok::collision::geometry_instance **)e;
        ++m_begin )
  {
    v4 = *m_begin;
    p_enumerate_primitives = &(*m_begin)->enumerate_primitives;
    v6 = vostok::math::float4x4::identity(&v8);
    (*p_enumerate_primitives)(v4, v6, cb);
  }
}


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
