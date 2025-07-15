int __thiscall vostok::math::aabb::intersect(
        vostok::math::aabb *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        vostok::math::float3 *result,
        vostok::math::float3 *a5)
{
  const vostok::math::float3 *v5; // eax
  int v6; // ecx
  char v7; // dl
  float v8; // xmm1_4
  float x; // xmm0_4
  vostok::math::float3 *v11; // ecx
  int v12; // esi
  int v13; // edx
  int v14; // ebx
  int v15; // eax
  int v16; // edx
  float v17; // xmm1_4
  const vostok::math::float3 *v18; // eax
  int v19; // esi
  int v20; // edx
  float v21; // xmm0_4
  _BYTE v22[12]; // [esp+Ch] [ebp-24h] BYREF
  float v23[3]; // [esp+18h] [ebp-18h] BYREF
  int v24; // [esp+24h] [ebp-Ch]
  int v25; // [esp+28h] [ebp-8h]
  _BYTE v26[4]; // [esp+2Ch] [ebp-4h]

  v5 = origin;
  v6 = 0;
  v7 = 1;
  v25 = (char *)direction - (char *)origin;
  v24 = v22 - (_BYTE *)origin;
  do
  {
    v8 = *(float *)((char *)&v5->x + (char *)direction - (char *)origin);
    x = v5->x;
    if ( v5->x > v8 )
    {
      v26[v6] = 1;
LABEL_6:
      *(float *)((char *)&v5->x + v22 - (_BYTE *)origin) = x;
      v7 = 0;
      goto LABEL_8;
    }
    x = v5[1].x;
    if ( v8 > x )
    {
      v26[v6] = 0;
      goto LABEL_6;
    }
    v26[v6] = 2;
LABEL_8:
    ++v6;
    v5 = (const vostok::math::float3 *)((char *)v5 + 4);
  }
  while ( v6 < 3 );
  if ( v7 )
  {
    *a5 = *direction;
    return 1;
  }
  else
  {
    v11 = result;
    v12 = 0;
    v13 = (char *)v23 - (char *)result;
    do
    {
      if ( v26[v12] == 2 || v11->x == 0.0 )
        *(float *)((char *)&v11->x + v13) = FLOAT_N1_0;
      else
        *(float *)((char *)&v11->x + v13) = (float)(*(float *)&v22[(char *)v11 - (char *)result]
                                                  - *(float *)((char *)&v11->x + (char *)direction - (char *)result))
                                          / v11->x;
      ++v12;
      v11 = (vostok::math::float3 *)((char *)v11 + 4);
    }
    while ( v12 < 3 );
    v14 = 0;
    v15 = 1;
    v16 = 0;
    do
    {
      if ( v23[v15] > v23[v16] )
      {
        v14 = v15;
        v16 = v15;
      }
      ++v15;
    }
    while ( v15 < 3 );
    v17 = v23[v14];
    if ( v17 >= 0.0 )
    {
      v18 = origin;
      v19 = 0;
      v20 = (char *)a5 - (char *)origin;
      do
      {
        if ( v14 == v19 )
        {
          *(float *)((char *)&v18->x + v20) = *(float *)((char *)&v18->x + v24);
        }
        else
        {
          v21 = (float)(*(float *)((char *)&v18->x + v25 + (char *)result - (char *)direction) * v17)
              + *(float *)((char *)&v18->x + v25);
          *(float *)((char *)&v18->x + v20) = v21;
          if ( v18->x > v21 || v21 > v18[1].x )
            return 0;
        }
        ++v19;
        v18 = (const vostok::math::float3 *)((char *)v18 + 4);
      }
      while ( v19 < 3 );
      return 2;
    }
    else
    {
      return 0;
    }
  }
}
