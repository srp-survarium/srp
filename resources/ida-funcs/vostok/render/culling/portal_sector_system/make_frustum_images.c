void __userpurge vostok::render::culling::portal_sector_system::make_frustum_images(
        const vostok::math::float3 *view_dir@<eax>,
        unsigned int a2@<edi>,
        vostok::render::culling::portal_sector_system *this)
{
  vostok::render::culling::portal_sector_structure *m_object; // esi
  void *v5; // esp
  int v6; // ecx
  vostok::render::culling::spatial_sector *m_end; // edi
  vostok::math::aabb *p_m_aabb; // esi
  vostok::render::culling::sector_double_query_preventer *v9; // ecx
  vostok::math::float3 *v10; // eax
  vostok::buffer_vector<vostok::math::float3> *v11; // ecx
  unsigned int v12[3]; // [esp-Ch] [ebp-24h] BYREF
  vostok::math::float3 v13; // [esp+0h] [ebp-18h] BYREF
  vostok::math::float3 value; // [esp+Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp+8h]

  v12[0] = a2;
  value = *view_dir;
  if ( value.x < 0.0 )
  {
    if ( value.y < 0.0 )
    {
      v15 = value.z >= 0.0;
    }
    else if ( value.z < 0.0 )
    {
      v15 = 3;
    }
    else
    {
      v15 = 2;
    }
  }
  else if ( value.y < 0.0 )
  {
    if ( value.z < 0.0 )
      v15 = 4;
    else
      v15 = 5;
  }
  else if ( value.z < 0.0 )
  {
    v15 = 6;
  }
  else
  {
    v15 = 7;
  }
  m_object = this->m_structure.m_object;
  v5 = alloca(12 * (m_object->m_sectors.m_end - m_object->m_sectors.m_begin));
  v6 = (char *)m_object->m_sectors.m_end - (char *)m_object->m_sectors.m_begin;
  m_end = m_object->m_sectors.m_end;
  p_m_aabb = &m_object->m_sectors.m_begin->m_aabb;
  v9 = (vostok::render::culling::sector_double_query_preventer *)&v12[3 * (v6 >> 5)];
  LODWORD(value.x) = v12;
  LODWORD(value.y) = v12;
  LODWORD(value.z) = v9;
  while ( p_m_aabb != (vostok::math::aabb *)m_end )
  {
    v10 = vostok::math::aabb::vertex(p_m_aabb, &v13, (vostok::math::float3 *)v15, v12[0]);
    vostok::buffer_vector<vostok::math::float3>::push_back(v11, &value, v10);
    p_m_aabb = (vostok::math::aabb *)((char *)p_m_aabb + 32);
  }
  vostok::render::culling::sector_double_query_preventer::make_frustum_images(
    v9,
    (const vostok::math::float3 *)this->m_preventer,
    SLODWORD(value.x));
}
