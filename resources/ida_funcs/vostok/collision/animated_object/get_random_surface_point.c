vostok::math::float3 *__thiscall vostok::collision::animated_object::get_random_surface_point(
        vostok::collision::animated_object *this,
        vostok::math::float3 *result,
        vostok::math::float3 *current_time,
        unsigned int current_timea)
{
  vostok::math::float3 *v5; // eax
  float x; // esi
  void *v7; // esp
  _BYTE *v8; // ecx
  float *v9; // edi
  int v10; // ecx
  float v11; // xmm0_4
  float y; // ecx
  double v13; // st7
  int v14; // edi
  _BYTE *v15; // eax
  int v16; // edx
  int v17; // esi
  _DWORD *v18; // edi
  float *v19; // eax
  int *v20; // ecx
  int v21; // edx
  float v22; // xmm4_4
  float v23; // xmm0_4
  int (__thiscall *v24)(int *); // eax
  float *v25; // eax
  float v26; // xmm1_4
  float z; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm4_4
  int v30; // [esp-4h] [ebp-3Ch] BYREF
  _BYTE v31[12]; // [esp+0h] [ebp-38h] BYREF
  vostok::math::float3 bone_coords; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::math::float3 collision_coords; // [esp+18h] [ebp-20h]
  _BYTE *v34; // [esp+24h] [ebp-14h]
  float surface_area; // [esp+28h] [ebp-10h]
  vostok::math::random32 random_number; // [esp+2Ch] [ebp-Ch] BYREF
  float *v37; // [esp+30h] [ebp-8h]
  int v38; // [esp+34h] [ebp-4h]
  unsigned int i; // [esp+40h] [ebp+8h]
  float ia; // [esp+40h] [ebp+8h]

  if ( LODWORD(result[2].z) )
  {
    x = result->x;
    random_number.m_seed = (LODWORD(result->y) - LODWORD(result->x)) / 112;
    v7 = alloca(4 * random_number.m_seed);
    v8 = v31;
    v34 = v31;
    v9 = (float *)v31;
    i = 0;
    if ( random_number.m_seed )
    {
      v38 = 0;
      v37 = (float *)&v30;
      do
      {
        v10 = *(_DWORD *)(*(_DWORD *)(v38 + LODWORD(x) + 108) + 136);
        surface_area = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v10 + 100))(v10);
        if ( i )
          v11 = *v37;
        else
          v11 = 0.0;
        if ( v9 )
          *v9 = v11 + surface_area;
        x = result->x;
        y = result->y;
        ++i;
        v38 += 112;
        ++v37;
        ++v9;
      }
      while ( i < (LODWORD(y) - LODWORD(x)) / 112 );
      v8 = v34;
    }
    random_number.m_seed = current_timea;
    v13 = *(v9 - 1);
    random_number.m_seed = 134775813 * current_timea + 1;
    v14 = ((char *)v9 - v8) >> 2;
    v15 = v8;
    while ( v14 > 0 )
    {
      v16 = v14 >> 1;
      ia = v13 * ((double)((unsigned __int64)random_number.m_seed >> 12) * 0.00000095367432);
      if ( ia <= *(float *)&v15[4 * (v14 >> 1)] )
      {
        v14 >>= 1;
      }
      else
      {
        v15 += 4 * v16 + 4;
        v14 += -1 - v16;
      }
    }
    v17 = 112 * ((v15 - v8) >> 2);
    v18 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(v17 + LODWORD(result->x) + 108) + 136) + 264);
    (*(void (__thiscall **)(_DWORD, vostok::math::float3 *, vostok::math::random32 *))(*(_DWORD *)*v18 + 120))(
      *v18,
      &bone_coords,
      &random_number);
    v19 = (float *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v18 + 8))(*v18);
    v20 = *(int **)(v17 + LODWORD(result->x) + 108);
    v21 = *v20;
    v22 = v19[1];
    collision_coords.x = (float)((float)((float)(v19[8] * bone_coords.z) + (float)(v19[4] * bone_coords.y))
                               + (float)(*v19 * bone_coords.x))
                       + v19[12];
    collision_coords.y = (float)((float)((float)(v19[9] * bone_coords.z) + (float)(v22 * bone_coords.x))
                               + (float)(v19[5] * bone_coords.y))
                       + v19[13];
    v23 = (float)((float)((float)(v19[10] * bone_coords.z) + (float)(v19[2] * bone_coords.x))
                + (float)(v19[6] * bone_coords.y))
        + v19[14];
    v24 = *(int (__thiscall **)(int *))(v21 + 8);
    collision_coords.z = v23;
    v25 = (float *)v24(v20);
    v26 = collision_coords.y;
    z = collision_coords.z;
    v28 = collision_coords.x;
    v29 = v25[1];
    current_time->x = (float)((float)((float)(v25[4] * collision_coords.y) + (float)(v25[8] * collision_coords.z))
                            + (float)(*v25 * collision_coords.x))
                    + v25[12];
    current_time->y = (float)((float)((float)(v25[5] * v26) + (float)(v29 * v28)) + (float)(v25[9] * z)) + v25[13];
    current_time->z = (float)((float)((float)(v25[6] * v26) + (float)(v25[2] * v28)) + (float)(v25[10] * z)) + v25[14];
    return current_time;
  }
  else
  {
    v5 = current_time;
    current_time->x = 0.0;
    current_time->y = 0.0;
    current_time->z = 0.0;
  }
  return v5;
}
