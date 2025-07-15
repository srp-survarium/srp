void __thiscall vostok::render::texture_streaming_async_worker::update_wanted_mips(
        vostok::render::texture_streaming_async_worker *this,
        int a2)
{
  int v2; // edi
  int *v3; // eax
  int v4; // ebx
  int v5; // eax
  unsigned int v6; // esi
  double v7; // st7
  int v8; // eax
  double v9; // st7
  unsigned int v10; // eax
  vostok::buffer_vector<vostok::render::potential_request> *v11; // ecx
  unsigned int v12; // edx
  int v13; // eax
  int v14; // ecx
  float v15; // xmm0_4
  unsigned int v16; // ecx
  int v17; // ecx
  float v18; // xmm0_4
  double v19; // st7
  int v20; // [esp+20h] [ebp-C4h]
  char v21; // [esp+20h] [ebp-C4h]
  unsigned int v22; // [esp+24h] [ebp-C0h]
  float screen_size_y; // [esp+28h] [ebp-BCh]
  float v24; // [esp+2Ch] [ebp-B8h]
  vostok::render::potential_request *v25; // [esp+30h] [ebp-B4h]
  float out_wanted_mip_level_decimals; // [esp+34h] [ebp-B0h] BYREF
  int v27; // [esp+38h] [ebp-ACh]
  float v28; // [esp+3Ch] [ebp-A8h]
  float v29; // [esp+40h] [ebp-A4h]
  float tiling; // [esp+44h] [ebp-A0h] BYREF
  float out_distance; // [esp+48h] [ebp-9Ch] BYREF
  float w; // [esp+4Ch] [ebp-98h]
  int i; // [esp+50h] [ebp-94h]
  unsigned int v34; // [esp+54h] [ebp-90h]
  vostok::math::float2 max_texture_size_calculated_for; // [esp+5Ch] [ebp-88h] BYREF
  vostok::math::sphere object_sphere; // [esp+64h] [ebp-80h] BYREF
  unsigned __int8 dst[112]; // [esp+74h] [ebp-70h] BYREF

  v27 = 0;
  v2 = a2;
  *(_DWORD *)(*(_DWORD *)(a2 + 160) + 4) = **(_DWORD **)(a2 + 160);
  v3 = *(int **)(a2 + 164);
  v4 = *v3;
  for ( i = v3[1]; v4 != i; ++v27 )
  {
    v25 = 0;
    v34 = *(_DWORD *)(v4 + 320);
    v5 = *(_DWORD *)(v4 + 272);
    v6 = 1;
    v22 = 1;
    v24 = 0.0;
    out_wanted_mip_level_decimals = FLOAT_10000_0;
    w = 0.0;
    v29 = FLOAT_10000_0;
    v28 = 0.0;
    v20 = v5;
    if ( v5 )
    {
      while ( 1 )
      {
        screen_size_y = *(float *)(v5 + 32);
        v7 = (double)*(unsigned int *)(v4 + 284);
        object_sphere = *(vostok::math::sphere *)(v5 + 12);
        tiling = 0.0;
        out_distance = 0.0;
        v8 = *(_DWORD *)(v4 + 288);
        max_texture_size_calculated_for.x = v7;
        v9 = (double)*(int *)(v4 + 288);
        if ( v8 < 0 )
          v9 = v9 + 4294967300.0;
        max_texture_size_calculated_for.y = v9;
        v10 = vostok::render::calculate_wanted_texture_mip_levels(
                (const vostok::math::float3 *)(a2 + 176),
                &max_texture_size_calculated_for,
                &object_sphere,
                *(const vostok::math::float4x4 **)(a2 + 188),
                *(_DWORD *)(a2 + 192),
                screen_size_y,
                *(float *)(v4 + 280),
                &tiling,
                &out_distance,
                &out_wanted_mip_level_decimals);
        v22 -= v22 < v10 ? v22 - v10 : 0;
        if ( tiling <= v29 )
          v29 = tiling;
        if ( w <= object_sphere.vector.w )
          w = object_sphere.vector.w;
        if ( out_wanted_mip_level_decimals <= 0.0 )
          out_wanted_mip_level_decimals = 0.0;
        if ( v24 <= out_distance )
          v24 = out_distance;
        if ( v28 <= screen_size_y )
          v28 = screen_size_y;
        v25 = (vostok::render::potential_request *)((char *)v25 + 1);
        v20 = *(_DWORD *)(v20 + 4);
        if ( !v20 )
          break;
        v5 = v20;
      }
      v6 = v22;
      v2 = a2;
    }
    memset((int)dst, 0, sizeof(dst));
    vostok::buffer_vector<vostok::render::potential_request>::push_back(
      v11,
      *(const vostok::render::potential_request **)(v2 + 160),
      dst);
    v12 = v34;
    v13 = *(_DWORD *)(*(_DWORD *)(v2 + 160) + 4) - 112;
    *(_DWORD *)(v13 + 4) = v27;
    *(_DWORD *)(v13 + 12) = v6;
    *(_DWORD *)(v13 + 24) = v6;
    if ( !v12 )
      v12 = *(_DWORD *)(v4 + 292);
    *(_DWORD *)(v13 + 8) = v12;
    *(_DWORD *)(v13 + 52) = *(_DWORD *)(v4 + 296);
    if ( v6 <= v12 )
      v14 = 0;
    else
      v14 = v6 - v12;
    v15 = v29;
    *(_DWORD *)(v13 + 32) = v14;
    *(float *)(v13 + 56) = v15;
    *(_DWORD *)(v13 + 68) = 0;
    *(_DWORD *)(v13 + 28) = *(_DWORD *)(v4 + 300);
    v16 = *(_DWORD *)(v4 + 296);
    if ( v16 < v6 )
      v21 = 0;
    else
      v21 = v16 - v6;
    *(_DWORD *)(v13 + 36) = *(_DWORD *)(v4 + 284) >> v21;
    *(_DWORD *)(v13 + 40) = *(_DWORD *)(v4 + 288) >> v21;
    *(_DWORD *)(v13 + 44) = *(_DWORD *)(v4 + 304);
    v17 = *(_DWORD *)(v4 + 308);
    *(_DWORD *)(v13 + 72) = 0;
    *(_DWORD *)(v13 + 48) = v17;
    *(_DWORD *)(v13 + 20) = *(_DWORD *)(v4 + 312);
    *(float *)(v13 + 64) = v24;
    v18 = v28;
    *(_BYTE *)(v13 + 106) = v6 > v12;
    *(_DWORD *)(v13 + 60) = 0;
    *(_BYTE *)(v13 + 104) = 0;
    *(_BYTE *)(v13 + 105) = 0;
    *(_BYTE *)(v13 + 108) = 0;
    *(_BYTE *)(v13 + 107) = 1;
    v19 = *(float *)(v4 + 280);
    *(_DWORD *)(v13 + 80) = 0;
    *(float *)(v13 + 100) = v19;
    *(_DWORD *)(v13 + 16) = 0;
    *(float *)(v13 + 96) = v18;
    *(_DWORD *)(v13 + 76) = v25;
    vostok::render::potential_request::calc_priority(v25, v13);
    v4 += 328;
  }
}
