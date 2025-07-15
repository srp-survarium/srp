void __thiscall vostok::render::culling::portal_sector_system::initialize_portals_occlusion_bounds_and_results(
        vostok::render::culling::portal_sector_system *this,
        int a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  int v5; // eax
  float *v6; // ebx
  vostok::math::float3 *v7; // eax
  vostok::buffer_vector<vostok::math::float4> *v8; // ecx
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  vostok::math::float3 v13; // [esp-10h] [ebp-50h]
  float v14; // [esp+Ch] [ebp-34h]
  int v15; // [esp+10h] [ebp-30h]
  int v16; // [esp+14h] [ebp-2Ch]
  vostok::math::float3 __last; // [esp+24h] [ebp-1Ch] BYREF
  float v18[4]; // [esp+30h] [ebp-10h] BYREF

  v2 = a2;
  v3 = *(_DWORD *)(a2 + 264);
  v4 = *(_DWORD *)(v3 + 276);
  v5 = *(_DWORD *)(v3 + 272);
  v16 = v4;
  v15 = v5;
  if ( v5 != v4 )
  {
    v6 = (float *)(v5 + 68);
    do
    {
      *(_QWORD *)&v13.elements[1] = 0;
      LODWORD(v13.x) = v6 + 1;
      v7 = stlp_std::accumulate<vostok::math::float3 const *,vostok::math::float3>(
             (const vostok::math::float3 *)(v6 - 11),
             &__last,
             v13,
             0.0);
      v9 = v7->z * 0.25;
      v10 = v7->y * 0.25;
      v11 = v7->x * 0.25;
      if ( (float)((float)((float)((float)(*(v6 - 3) - v9) * (float)(*(v6 - 3) - v9))
                         + (float)((float)(*(v6 - 4) - v10) * (float)(*(v6 - 4) - v10)))
                 + (float)((float)(*(v6 - 5) - v11) * (float)(*(v6 - 5) - v11))) <= (float)((float)((float)((float)(*v6 - v9) * (float)(*v6 - v9))
                                                                                                  + (float)((float)(*(v6 - 1) - v10) * (float)(*(v6 - 1) - v10)))
                                                                                          + (float)((float)(*(v6 - 2) - v11)
                                                                                                  * (float)(*(v6 - 2) - v11))) )
        v14 = (float)((float)((float)(*v6 - v9) * (float)(*v6 - v9))
                    + (float)((float)(*(v6 - 1) - v10) * (float)(*(v6 - 1) - v10)))
            + (float)((float)(*(v6 - 2) - v11) * (float)(*(v6 - 2) - v11));
      else
        v14 = (float)((float)((float)(*(v6 - 3) - v9) * (float)(*(v6 - 3) - v9))
                    + (float)((float)(*(v6 - 4) - v10) * (float)(*(v6 - 4) - v10)))
            + (float)((float)(*(v6 - 5) - v11) * (float)(*(v6 - 5) - v11));
      v12 = (float)((float)((float)(*(v6 - 6) - v9) * (float)(*(v6 - 6) - v9))
                  + (float)((float)(*(v6 - 7) - v10) * (float)(*(v6 - 7) - v10)))
          + (float)((float)(*(v6 - 8) - v11) * (float)(*(v6 - 8) - v11));
      if ( (float)((float)((float)((float)(*(v6 - 9) - v9) * (float)(*(v6 - 9) - v9))
                         + (float)((float)(*(v6 - 10) - v10) * (float)(*(v6 - 10) - v10)))
                 + (float)((float)(*(v6 - 11) - v11) * (float)(*(v6 - 11) - v11))) > v12 )
        v12 = (float)((float)((float)(*(v6 - 9) - v9) * (float)(*(v6 - 9) - v9))
                    + (float)((float)(*(v6 - 10) - v10) * (float)(*(v6 - 10) - v10)))
            + (float)((float)(*(v6 - 11) - v11) * (float)(*(v6 - 11) - v11));
      if ( v12 <= v14 )
        v12 = v14;
      v18[0] = v7->x * 0.25;
      v18[1] = v10;
      v18[2] = v9;
      v18[3] = fsqrt(v12);
      vostok::buffer_vector<vostok::math::float4>::push_back(v8, (const vostok::math::float4 *)(a2 + 49444), v18);
      v15 += 76;
      v6 += 19;
    }
    while ( v15 != v16 );
    v2 = a2;
  }
  memset(*(_DWORD *)(v2 + 49460), 255, *(_DWORD *)(v2 + 49464) - *(_DWORD *)(v2 + 49460));
}
