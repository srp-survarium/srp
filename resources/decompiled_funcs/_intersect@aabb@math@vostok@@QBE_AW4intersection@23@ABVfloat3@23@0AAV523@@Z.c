int __thiscall vostok::math::aabb::intersect(
        vostok::math::aabb *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        int result,
        vostok::math::float3 *resulta)
{
  const vostok::math::float3 *v5; // ebp
  const vostok::math::float3 *v6; // edi
  int v7; // esi
  int v8; // eax
  char v9; // dl
  const vostok::math::float3 *v10; // ecx
  int v11; // ebx
  float v12; // xmm0_4
  float x; // xmm1_4
  float v14; // xmm1_4
  float v16; // xmm0_4
  vostok::math::float3 *v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  int v22; // esi
  float v23; // xmm1_4
  int v24; // edi
  float *p_x; // eax
  char *v26; // edx
  float v27; // xmm0_4
  int v28; // [esp+10h] [ebp-1Ch]
  float maxT[3]; // [esp+14h] [ebp-18h]
  float candidatePlane[3]; // [esp+20h] [ebp-Ch] BYREF

  v5 = origin;
  v6 = direction;
  v7 = (char *)direction - (char *)origin;
  v8 = 0;
  v9 = 1;
  v10 = origin;
  v28 = (char *)direction - (char *)origin;
  v11 = (char *)candidatePlane - (char *)origin;
  do
  {
    v12 = *(float *)((char *)&v10->x + v7);
    x = v10->x;
    if ( v10->x <= v12 )
    {
      v14 = v10[1].x;
      if ( v12 <= v14 )
      {
        *((_BYTE *)&origin + v8) = 2;
      }
      else
      {
        *((_BYTE *)&origin + v8) = 0;
        *(float *)((char *)&v10->x + v11) = v14;
        v9 = 0;
      }
    }
    else
    {
      *((_BYTE *)&origin + v8) = 1;
      *(float *)((char *)&v10->x + v11) = x;
      v9 = 0;
    }
    ++v8;
    v10 = (const vostok::math::float3 *)((char *)v10 + 4);
  }
  while ( v8 < 3 );
  if ( v9 )
  {
    *resulta = *v6;
    return 1;
  }
  else
  {
    v16 = -1.0;
    v17 = (vostok::math::float3 *)result;
    if ( (_BYTE)origin == 2 || *(float *)result == 0.0 )
      v18 = -1.0;
    else
      v18 = (float)(candidatePlane[0] - v6->x) / *(float *)result;
    maxT[0] = v18;
    if ( BYTE1(origin) == 2 || (v19 = *(float *)(result + 4), v19 == 0.0) )
      v20 = -1.0;
    else
      v20 = (float)(candidatePlane[1] - v6->y) / v19;
    maxT[1] = v20;
    if ( BYTE2(origin) != 2 )
    {
      v21 = *(float *)(result + 8);
      if ( v21 != 0.0 )
        v16 = (float)(candidatePlane[2] - v6->z) / v21;
    }
    v22 = 0;
    maxT[2] = v16;
    result = v20 > v18;
    if ( v16 > maxT[result] )
      result = 2;
    v23 = maxT[result];
    if ( v23 >= 0.0 )
    {
      v24 = (char *)v17 - (char *)direction;
      p_x = &v5->x;
      v26 = (char *)((char *)resulta - (char *)v5);
      do
      {
        if ( result == v22 )
        {
          *(float *)((char *)p_x + (_DWORD)v26) = *(float *)((char *)p_x + v11);
        }
        else
        {
          v27 = (float)(*(float *)((char *)p_x + v28 + v24) * v23) + *(float *)((char *)p_x + v28);
          *(float *)((char *)p_x + (_DWORD)v26) = v27;
          if ( *p_x > v27 || v27 > p_x[3] )
            return 0;
        }
        ++v22;
        ++p_x;
      }
      while ( v22 < 3 );
      return 2;
    }
    else
    {
      return 0;
    }
  }
}
