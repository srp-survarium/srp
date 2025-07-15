void __usercall vostok::render::culling::portal_sector_structure::initialize_portals_geometry(
        vostok::render::culling::portal_sector_structure *this@<ecx>,
        int a2@<edi>)
{
  int v2; // esi
  void *v3; // esp
  int v4; // eax
  unsigned int v5; // ebx
  int v6; // esi
  void *v7; // esp
  const vostok::math::float3 *v8; // ecx
  const vostok::math::float3 *v9; // eax
  vostok::math::float3 *v10; // esi
  vostok::buffer_vector<unsigned int> *v11; // ecx
  vostok::buffer_vector<unsigned int> *v12; // ecx
  vostok::buffer_vector<unsigned int> *v13; // ecx
  vostok::buffer_vector<unsigned int> *v14; // ecx
  vostok::buffer_vector<unsigned int> *v15; // ecx
  vostok::buffer_vector<unsigned int> *v16; // ecx
  _BYTE v17[8]; // [esp+0h] [ebp-38h] BYREF
  vostok::buffer_vector<vostok::math::float3> v18; // [esp+8h] [ebp-30h] BYREF
  unsigned int *indices[3]; // [esp+14h] [ebp-24h] BYREF
  unsigned int vertex_count; // [esp+20h] [ebp-18h]
  const vostok::math::float3 *v21; // [esp+24h] [ebp-14h]
  vostok::math::float3 *end; // [esp+28h] [ebp-10h] BYREF
  vostok::math::float3 *where; // [esp+2Ch] [ebp-Ch] BYREF
  const vostok::math::float3 *v24; // [esp+30h] [ebp-8h]
  vostok::math::float3 *v25; // [esp+34h] [ebp-4h]

  v2 = 48 * ((*(_DWORD *)(a2 + 276) - *(_DWORD *)(a2 + 272)) / 76);
  vertex_count = 4 * ((*(_DWORD *)(a2 + 276) - *(_DWORD *)(a2 + 272)) / 76);
  v3 = alloca(v2);
  v18.m_begin = (vostok::math::float3 *)v17;
  v18.m_end = (vostok::math::float3 *)v17;
  v4 = (*(_DWORD *)(a2 + 276) - *(_DWORD *)(a2 + 272)) / 76;
  v18.m_max_end = (vostok::math::float3 *)&v17[v2];
  v5 = 6 * v4;
  v6 = 24 * v4;
  v7 = alloca(24 * v4);
  v8 = *(const vostok::math::float3 **)(a2 + 272);
  indices[0] = (unsigned int *)v17;
  indices[1] = (unsigned int *)v17;
  v9 = *(const vostok::math::float3 **)(a2 + 276);
  indices[2] = (unsigned int *)&v17[v6];
  v21 = v9;
  v24 = v8;
  if ( v8 != v9 )
  {
    while ( 1 )
    {
      v10 = (vostok::math::float3 *)(v18.m_end - v18.m_begin);
      end = (vostok::math::float3 *)&v8[6];
      where = v18.m_end;
      v25 = v10;
      vostok::buffer_vector<vostok::math::float3>::insert<vostok::math::float3 const *>(
        (const vostok::math::float3 *const *)&end,
        &v18,
        &where,
        v8 + 2);
      end = v10;
      vostok::buffer_vector<unsigned int>::push_back(v11, (int)indices, (const unsigned int *)&end);
      end = (vostok::math::float3 *)((char *)&v25->x + 1);
      vostok::buffer_vector<unsigned int>::push_back(v12, (int)indices, (const unsigned int *)&end);
      end = (vostok::math::float3 *)((char *)v25->elements + 2);
      vostok::buffer_vector<unsigned int>::push_back(v13, (int)indices, (const unsigned int *)&end);
      end = v25;
      vostok::buffer_vector<unsigned int>::push_back(v14, (int)indices, (const unsigned int *)&end);
      end = (vostok::math::float3 *)((char *)v25->elements + 2);
      vostok::buffer_vector<unsigned int>::push_back(v15, (int)indices, (const unsigned int *)&end);
      end = (vostok::math::float3 *)((char *)v25->elements + 3);
      vostok::buffer_vector<unsigned int>::push_back(v16, (int)indices, (const unsigned int *)&end);
      v24 = (const vostok::math::float3 *)((char *)v24 + 76);
      if ( v24 == v21 )
        break;
      v8 = v24;
    }
  }
  *(_DWORD *)(a2 + 312) = vostok::collision::new_triangle_mesh_geometry(
                            *(vostok::memory::base_allocator **)(a2 + 264),
                            v18.m_begin,
                            vertex_count,
                            indices[0],
                            v5);
}
