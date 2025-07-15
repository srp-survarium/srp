char __thiscall vostok::collision::composite_geometry::ray_test(
        vostok::collision::composite_geometry *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **e; // [esp+18h] [ebp-4h]

  m_begin = this->m_geometry_instances.m_begin;
  e = this->m_geometry_instances.m_end;
  if ( m_begin == e )
    return 0;
  while ( !((unsigned __int8 (__stdcall *)(const vostok::math::float3 *, const vostok::math::float3 *, _DWORD, float *))(*m_begin)->ray_test)(
             origin,
             direction,
             LODWORD(max_distance),
             distance) )
  {
    if ( ++m_begin == e )
      return 0;
  }
  return 1;
}
