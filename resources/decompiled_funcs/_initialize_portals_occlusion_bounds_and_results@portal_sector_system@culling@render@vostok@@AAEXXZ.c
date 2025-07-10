void __usercall vostok::render::culling::portal_sector_system::initialize_portals_occlusion_bounds_and_results(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        _DWORD *a2@<edi>)
{
  int v2; // eax
  const vostok::render::culling::portal *v3; // ecx
  const vostok::render::culling::portal *v4; // eax
  float *p_z; // esi
  float *v6; // ebx
  vostok::math::float3 *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  _QWORD *v12; // eax
  vostok::math::float3 v13; // [esp-Ch] [ebp-50h]
  float v14; // [esp+Ch] [ebp-38h]
  float sqr_radius; // [esp+10h] [ebp-34h]
  const vostok::render::culling::portal *it; // [esp+14h] [ebp-30h]
  const vostok::render::culling::portal *portals_end; // [esp+18h] [ebp-2Ch]
  vostok::math::float3 _Init; // [esp+28h] [ebp-1Ch] BYREF
  __int64 v19; // [esp+34h] [ebp-10h]
  __int64 v20; // [esp+3Ch] [ebp-8h]

  v2 = a2[66];
  v3 = *(const vostok::render::culling::portal **)(v2 + 276);
  v4 = *(const vostok::render::culling::portal **)(v2 + 272);
  portals_end = v3;
  it = v4;
  if ( v4 != v3 )
  {
    p_z = &v4->m_points[3].z;
    do
    {
      *(_QWORD *)&v13.elements[1] = 0;
      LODWORD(v13.x) = &_Init;
      v7 = stlp_std::accumulate<vostok::math::float3 const *,vostok::math::float3>(
             (const vostok::math::float3 *)(p_z - 11),
             (const vostok::math::float3 *)(p_z + 1),
             v13,
             0.0);
      v8 = v7->x * 0.25;
      v9 = v7->y * 0.25;
      v10 = v7->z * 0.25;
      if ( (float)((float)((float)((float)(*(p_z - 3) - v10) * (float)(*(p_z - 3) - v10))
                         + (float)((float)(*(p_z - 4) - v9) * (float)(*(p_z - 4) - v9)))
                 + (float)((float)(*(p_z - 5) - v8) * (float)(*(p_z - 5) - v8))) <= (float)((float)((float)((float)(*p_z - v10) * (float)(*p_z - v10))
                                                                                                  + (float)((float)(*(p_z - 1) - v9) * (float)(*(p_z - 1) - v9)))
                                                                                          + (float)((float)(*(p_z - 2) - v8)
                                                                                                  * (float)(*(p_z - 2) - v8))) )
        v14 = (float)((float)((float)(*p_z - v10) * (float)(*p_z - v10))
                    + (float)((float)(*(p_z - 1) - v9) * (float)(*(p_z - 1) - v9)))
            + (float)((float)(*(p_z - 2) - v8) * (float)(*(p_z - 2) - v8));
      else
        v14 = (float)((float)((float)(*(p_z - 3) - v10) * (float)(*(p_z - 3) - v10))
                    + (float)((float)(*(p_z - 4) - v9) * (float)(*(p_z - 4) - v9)))
            + (float)((float)(*(p_z - 5) - v8) * (float)(*(p_z - 5) - v8));
      v11 = (float)((float)((float)(*(p_z - 6) - v10) * (float)(*(p_z - 6) - v10))
                  + (float)((float)(*(p_z - 7) - v9) * (float)(*(p_z - 7) - v9)))
          + (float)((float)(*(p_z - 8) - v8) * (float)(*(p_z - 8) - v8));
      v6 = p_z - 11;
      if ( (float)((float)((float)((float)(*(p_z - 9) - v10) * (float)(*(p_z - 9) - v10))
                         + (float)((float)(*(p_z - 10) - v9) * (float)(*(p_z - 10) - v9)))
                 + (float)((float)(*v6 - v8) * (float)(*v6 - v8))) > v11 )
        v11 = (float)((float)((float)(*(p_z - 9) - v10) * (float)(*(p_z - 9) - v10))
                    + (float)((float)(*(p_z - 10) - v9) * (float)(*(p_z - 10) - v9)))
            + (float)((float)(*v6 - v8) * (float)(*v6 - v8));
      if ( v11 <= v14 )
        sqr_radius = v14;
      else
        sqr_radius = v11;
      *(float *)&v19 = v7->x * 0.25;
      *((float *)&v19 + 1) = v9;
      *(float *)&v20 = v10;
      *((float *)&v20 + 1) = sqrtf(sqr_radius);
      v12 = (_QWORD *)a2[74];
      if ( v12 )
      {
        *v12 = v19;
        v12[1] = v20;
      }
      a2[74] += 16;
      p_z += 19;
      ++it;
    }
    while ( it != portals_end );
  }
  memset(a2[76], (unsigned __int8 *)0xFF, a2[77] - a2[76]);
}
