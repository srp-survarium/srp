void __userpurge vostok::render::culling::sector_double_query_preventer::render(
        vostok::render::culling::sector_double_query_preventer *this@<ecx>,
        int a2@<eax>,
        vostok::render::system_renderer *r)
{
  int v3; // esi
  int v4; // edi
  float v5; // edx
  float v6; // ecx
  float v7; // eax
  __int64 v8; // xmm0_8
  float v9; // ecx
  float v10; // edx
  __int64 v11; // xmm0_8
  float v12; // ecx
  float v13; // edx
  unsigned int v14; // eax
  __int64 v15; // xmm0_8
  float v16; // ecx
  __int64 v17; // xmm0_8
  unsigned __int16 frustrum_edges_indices[24]; // [esp+10h] [ebp-B0h] BYREF
  vostok::render::vertex_colored vertices[8]; // [esp+40h] [ebp-80h] BYREF
  _UNKNOWN *retaddr; // [esp+C0h] [ebp+0h] BYREF

  frustrum_edges_indices[0] = 0;
  frustrum_edges_indices[1] = 1;
  frustrum_edges_indices[2] = 1;
  frustrum_edges_indices[3] = 2;
  frustrum_edges_indices[4] = 2;
  frustrum_edges_indices[5] = 3;
  frustrum_edges_indices[6] = 3;
  frustrum_edges_indices[7] = 0;
  frustrum_edges_indices[8] = 4;
  frustrum_edges_indices[9] = 5;
  frustrum_edges_indices[10] = 5;
  frustrum_edges_indices[11] = 6;
  frustrum_edges_indices[12] = 6;
  frustrum_edges_indices[13] = 7;
  frustrum_edges_indices[14] = 7;
  frustrum_edges_indices[15] = 4;
  frustrum_edges_indices[16] = 0;
  frustrum_edges_indices[17] = 4;
  v3 = *(_DWORD *)(a2 + 16);
  frustrum_edges_indices[18] = 1;
  frustrum_edges_indices[19] = 5;
  v4 = *(_DWORD *)(a2 + 20);
  frustrum_edges_indices[20] = 2;
  frustrum_edges_indices[21] = 6;
  frustrum_edges_indices[22] = 3;
  for ( frustrum_edges_indices[23] = 7; v3 != v4; v3 += 100 )
  {
    v5 = *(float *)(v3 + 32);
    v6 = *(float *)(v3 + 20);
    v7 = *(float *)(v3 + 8);
    *(_QWORD *)&vertices[0].position.x = *(_QWORD *)v3;
    v8 = *(_QWORD *)(v3 + 12);
    vertices[1].position.z = v6;
    v9 = *(float *)(v3 + 44);
    vertices[2].position.z = v5;
    v10 = *(float *)(v3 + 56);
    *(_QWORD *)&vertices[1].position.x = v8;
    *(_QWORD *)&vertices[2].position.x = *(_QWORD *)(v3 + 24);
    v11 = *(_QWORD *)(v3 + 36);
    vertices[3].position.z = v9;
    v12 = *(float *)(v3 + 68);
    vertices[4].position.z = v10;
    v13 = *(float *)(v3 + 80);
    vertices[0].position.z = v7;
    v14 = *(_DWORD *)(v3 + 96);
    *(_QWORD *)&vertices[3].position.x = v11;
    v15 = *(_QWORD *)(v3 + 48);
    vertices[5].position.z = v12;
    v16 = *(float *)(v3 + 92);
    vertices[6].position.z = v13;
    vertices[0].color.m_value = v14;
    vertices[1].color.m_value = v14;
    vertices[2].color.m_value = v14;
    vertices[3].color.m_value = v14;
    vertices[4].color.m_value = v14;
    vertices[5].color.m_value = v14;
    vertices[6].color.m_value = v14;
    vertices[7].color.m_value = v14;
    *(_QWORD *)&vertices[4].position.x = v15;
    v17 = *(_QWORD *)(v3 + 60);
    vertices[7].position.z = v16;
    *(_QWORD *)&vertices[5].position.x = v17;
    *(_QWORD *)&vertices[6].position.x = *(_QWORD *)(v3 + 72);
    *(_QWORD *)&vertices[7].position.x = *(_QWORD *)(v3 + 84);
    vostok::render::system_renderer::draw_lines(
      r,
      vertices,
      (const vostok::render::vertex_colored *const)&retaddr,
      frustrum_edges_indices,
      (const unsigned __int16 *const)vertices,
      0);
  }
}
