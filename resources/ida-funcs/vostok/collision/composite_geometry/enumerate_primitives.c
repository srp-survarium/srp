void __thiscall vostok::collision::composite_geometry::enumerate_primitives(
        vostok::collision::composite_geometry *this,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::geometry_instance **m_begin; // edi
  vostok::collision::geometry_instance *v3; // ebx
  void (__thiscall **p_enumerate_primitives)(vostok::collision::geometry_instance *, const vostok::math::float4x4 *, vostok::collision::enumerate_primitives_callback *); // esi
  vostok::math::float4x4 *v5; // eax
  vostok::collision::geometry_instance **e; // [esp+Ch] [ebp-44h]
  vostok::math::float4x4 v7; // [esp+10h] [ebp-40h] BYREF

  m_begin = this->m_geometry_instances.m_begin;
  for ( e = this->m_geometry_instances.m_end; m_begin != e; ++m_begin )
  {
    v3 = *m_begin;
    p_enumerate_primitives = &(*m_begin)->enumerate_primitives;
    v5 = vostok::math::float4x4::identity(&v7);
    (*p_enumerate_primitives)(v3, v5, cb);
  }
}


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
