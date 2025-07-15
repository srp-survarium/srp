vostok::math::float3 *__cdecl vostok::physics::dimensions_from_bullet_shape(int a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // xmm0_4
  float v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]

  v2 = *(_DWORD *)(v1 + 4);
  if ( !v2 )
    goto LABEL_6;
  v3 = v2 - 8;
  if ( !v3 )
  {
    v7 = *(float *)(v1 + 32) * *(float *)(v1 + 16);
    v5 = 0;
    v8 = 0;
    goto LABEL_7;
  }
  if ( v3 != 2 )
  {
LABEL_6:
    v7 = *(float *)(v1 + 32);
    v8 = *(_DWORD *)(v1 + 36);
    v5 = *(_DWORD *)(v1 + 40) ^ _mask__NegFloat_;
    goto LABEL_7;
  }
  v4 = *(_DWORD *)(v1 + 64);
  v7 = *(float *)(v1 + 4 * v4 + 32);
  v8 = *(_DWORD *)(v1 + 4 * ((v4 + 2) % 3) + 32);
  v5 = 0;
LABEL_7:
  *(float *)a1 = v7;
  *(_DWORD *)(a1 + 4) = v8;
  *(_DWORD *)(a1 + 8) = v5;
  return (vostok::math::float3 *)a1;
}
