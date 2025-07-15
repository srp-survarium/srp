void __thiscall vostok::render::culling::portal_sector_structure::initialize_portals_geometry(
        vostok::render::culling::portal_sector_structure *this,
        vostok::render::culling::portal_sector_structure *thisa)
{
  vostok::render::culling::portal_sector_structure *v2; // esi
  int v3; // ecx
  unsigned int v4; // ebx
  void *v5; // esp
  void *v6; // esp
  const vostok::render::culling::portal *m_end; // eax
  const vostok::render::culling::portal *m_begin; // ecx
  unsigned int *v9; // edi
  int v10; // esi
  _DWORD *v11; // edi
  _DWORD *v12; // edi
  int *v13; // edi
  _DWORD *v14; // edi
  _DWORD *v15; // edi
  vostok::collision::triangle_mesh_buffer *v16; // eax
  vostok::collision::geometry *v17; // eax
  const unsigned int *v18[4]; // [esp+0h] [ebp-34h] BYREF
  vostok::buffer_vector<vostok::math::float3> vertices; // [esp+10h] [ebp-24h] BYREF
  unsigned int indices_count; // [esp+18h] [ebp-1Ch]
  const unsigned int **v21; // [esp+1Ch] [ebp-18h]
  const vostok::render::culling::portal *portals_end; // [esp+20h] [ebp-14h]
  vostok::math::float3 *end; // [esp+24h] [ebp-10h] BYREF
  vostok::math::float3 *where; // [esp+28h] [ebp-Ch] BYREF
  const vostok::render::culling::portal *it; // [esp+2Ch] [ebp-8h]
  vostok::memory::base_allocator *thisb; // [esp+3Ch] [ebp+8h]

  v2 = thisa;
  v3 = (char *)thisa->m_portals.m_end - (char *)thisa->m_portals.m_begin;
  v4 = 4 * (v3 / 76);
  v5 = alloca(48 * (v3 / 76));
  vertices.m_begin = (vostok::math::float3 *)v18;
  vertices.m_end = (vostok::math::float3 *)v18;
  indices_count = 6 * (v3 / 76);
  v6 = alloca(24 * (v3 / 76));
  m_end = thisa->m_portals.m_end;
  m_begin = thisa->m_portals.m_begin;
  v9 = (unsigned int *)v18;
  v21 = v18;
  portals_end = m_end;
  it = m_begin;
  if ( m_begin != m_end )
  {
    while ( 1 )
    {
      v10 = vertices.m_end - vertices.m_begin;
      end = (vostok::math::float3 *)&m_begin->m_visible;
      where = vertices.m_end;
      vostok::buffer_vector<vostok::math::float3>::insert<vostok::math::float3 const *>(
        m_begin->m_points,
        (const vostok::math::float3 *const *)&end,
        &vertices,
        &where);
      if ( v9 )
        *v9 = v10;
      v11 = v9 + 1;
      if ( v11 )
        *v11 = v10 + 1;
      v12 = v11 + 1;
      if ( v12 )
        *v12 = v10 + 2;
      v13 = v12 + 1;
      if ( v13 )
        *v13 = v10;
      v14 = v13 + 1;
      if ( v14 )
        *v14 = v10 + 2;
      v15 = v14 + 1;
      if ( v15 )
        *v15 = v10 + 3;
      v9 = v15 + 1;
      if ( ++it == portals_end )
        break;
      m_begin = it;
    }
    v9 = (unsigned int *)v21;
    v2 = thisa;
  }
  thisb = v2->m_allocator;
  v16 = (vostok::collision::triangle_mesh_buffer *)((int (__stdcall *)(int))thisb->call_malloc)(352);
  if ( v16 )
  {
    vostok::collision::triangle_mesh_buffer::triangle_mesh_buffer(
      v16,
      thisb,
      vertices.m_begin,
      v4,
      v9,
      indices_count,
      v18[0],
      (unsigned int)v18[1]);
    v2->m_portals_geometry = v17;
  }
  else
  {
    v2->m_portals_geometry = 0;
  }
}
