void __userpurge vostok::render::culling::portal_sector_system::draw_quads(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        int a2@<eax>,
        vostok::render::system_renderer *r)
{
  __int64 *v3; // ebp
  float *v4; // edi
  __int64 *v5; // esi
  float v6; // ecx
  float v7; // edx
  __int64 v8; // xmm0_8
  float v9; // eax
  __int64 v10; // xmm0_8
  __int64 v11; // xmm0_8
  unsigned __int16 quad_indices[8]; // [esp+10h] [ebp-50h] BYREF
  vostok::render::vertex_colored vertices[4]; // [esp+20h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h] BYREF

  quad_indices[0] = 0;
  quad_indices[1] = 1;
  v3 = *(__int64 **)(a2 + 272);
  quad_indices[2] = 1;
  quad_indices[3] = 2;
  v4 = *(float **)(a2 + 268);
  quad_indices[4] = 2;
  quad_indices[5] = 3;
  quad_indices[6] = 3;
  quad_indices[7] = 0;
  if ( v4 != (float *)v3 )
  {
    v5 = (__int64 *)(v4 + 6);
    do
    {
      v6 = *((float *)v5 - 1);
      v7 = *((float *)v5 + 2);
      v8 = *(_QWORD *)v4;
      vertices[0].position.z = v4[2];
      v9 = *((float *)v5 + 5);
      vertices[1].position.z = v6;
      *(_QWORD *)&vertices[0].position.x = v8;
      v10 = *(__int64 *)((char *)v5 - 12);
      vertices[2].position.z = v7;
      vertices[3].position.z = v9;
      *(_QWORD *)&vertices[1].position.x = v10;
      *(_QWORD *)&vertices[2].position.x = *v5;
      v11 = *(__int64 *)((char *)v5 + 12);
      vertices[0].color.m_value = -16711681;
      vertices[1].color.m_value = -16711681;
      vertices[2].color.m_value = -16711681;
      *(_QWORD *)&vertices[3].position.x = v11;
      vertices[3].color.m_value = -16711681;
      vostok::render::system_renderer::draw_lines(
        r,
        vertices,
        (const vostok::render::vertex_colored *const)&retaddr,
        quad_indices,
        (const unsigned __int16 *const)vertices,
        0);
      v4 += 12;
      v5 += 6;
    }
    while ( v4 != (float *)v3 );
  }
}
