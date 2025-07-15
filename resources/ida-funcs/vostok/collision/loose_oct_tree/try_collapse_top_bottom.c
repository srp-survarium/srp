void __usercall vostok::collision::loose_oct_tree::try_collapse_top_bottom(
        vostok::collision::loose_oct_tree *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  int v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // edi
  vostok::math::float3 *v8; // eax
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  vostok::math::float3 v14; // [esp+8h] [ebp-Ch] BYREF

  v2 = *(_DWORD **)(a2 + 4);
  do
  {
    v3 = v2;
    v4 = -1;
    v5 = 0;
    do
    {
      if ( *v3 )
      {
        if ( v4 != -1 )
          return;
        v4 = v5 >> 2;
      }
      ++v3;
      v5 += 4;
    }
    while ( v3 != v2 + 8 );
    v6 = v2[v4];
    v7 = *(_DWORD *)(a2 + 12);
    --*(_DWORD *)(a2 + 44);
    v2[8] = v7;
    *(_DWORD *)(a2 + 12) = v2;
    *(_DWORD *)(a2 + 4) = v6;
    *(_DWORD *)(v6 + 32) = 0;
    *(float *)(a2 + 28) = *(float *)(a2 + 28) * 0.5;
    v8 = vostok::collision::octant_vector(&v14, (vostok::math::float3 *)v4);
    v9 = *(float *)(a2 + 28);
    v10 = v8->y * v9;
    v11 = v8->z * v9;
    v12 = *(float *)(a2 + 16) + (float)(v8->x * v9);
    *(float *)(a2 + 20) = *(float *)(a2 + 20) + v10;
    v13 = *(float *)(a2 + 24);
    *(float *)(a2 + 16) = v12;
    *(float *)(a2 + 24) = v13 + v11;
    v2 = *(_DWORD **)(a2 + 4);
  }
  while ( !v2[9] );
}
