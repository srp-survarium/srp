void __usercall vostok::math::curve_line_points<float,0>::recalculate_ranges(
        vostok::math::curve_line_points<float,0> *this@<ecx>,
        int a2@<eax>)
{
  unsigned int v2; // edx
  float *v3; // ecx
  unsigned int v4; // esi
  float *v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4

  v2 = *(_DWORD *)(a2 + 24);
  if ( v2 )
  {
    v3 = *(float **)(a2 + 16);
    *(float *)a2 = v3[4];
    v4 = 1;
    *(float *)(a2 + 4) = v3[4];
    *(float *)(a2 + 8) = v3[1];
    *(float *)(a2 + 12) = *v3;
    if ( v2 > 1 )
    {
      v5 = v3 + 6;
      do
      {
        v6 = v5[4];
        if ( *(float *)a2 > v6 )
          *(float *)a2 = v6;
        v7 = v5[4];
        if ( v7 > *(float *)(a2 + 4) )
          *(float *)(a2 + 4) = v7;
        v8 = v5[1];
        if ( *(float *)(a2 + 8) > v8 )
          *(float *)(a2 + 8) = v8;
        if ( *v5 > *(float *)(a2 + 12) )
          *(float *)(a2 + 12) = *v5;
        ++v4;
        v5 += 6;
      }
      while ( v4 < v2 );
    }
  }
}


void __usercall vostok::math::curve_line_points<vostok::math::float3_pod,0>::recalculate_ranges(
        vostok::math::curve_line_points<vostok::math::float3_pod,0> *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx
  float *v3; // edx
  float *v4; // ebx
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm0_4
  unsigned int v8; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)(a2 + 40) )
  {
    v2 = *(_DWORD *)(a2 + 32);
    *(float *)a2 = *(float *)(v2 + 48);
    *(float *)(a2 + 4) = *(float *)(v2 + 48);
    v3 = (float *)(a2 + 8);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(v2 + 12);
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(v2 + 16);
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(v2 + 20);
    v4 = (float *)(a2 + 20);
    *(_DWORD *)(a2 + 20) = *(_DWORD *)v2;
    *(_DWORD *)(a2 + 24) = *(_DWORD *)(v2 + 4);
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(v2 + 8);
    v8 = 1;
    if ( *(_DWORD *)(a2 + 40) > 1u )
    {
      v5 = v2 + 56;
      do
      {
        v6 = *(float *)(v5 + 48);
        if ( *(float *)a2 > v6 )
          *(float *)a2 = v6;
        v7 = *(float *)(v5 + 48);
        if ( v7 > *(float *)(a2 + 4) )
          *(float *)(a2 + 4) = v7;
        if ( *v3 > *(float *)(v5 + 12)
          && *(float *)(a2 + 12) > *(float *)(v5 + 16)
          && *(float *)(a2 + 16) > *(float *)(v5 + 20) )
        {
          *v3 = *(float *)(v5 + 12);
          *(_DWORD *)(a2 + 12) = *(_DWORD *)(v5 + 16);
          *(_DWORD *)(a2 + 16) = *(_DWORD *)(v5 + 20);
        }
        if ( *(float *)v5 > *v4 && *(float *)(v5 + 4) > *(float *)(a2 + 24) && *(float *)(v5 + 8) > *(float *)(a2 + 28) )
        {
          *v4 = *(float *)v5;
          *(_DWORD *)(a2 + 24) = *(_DWORD *)(v5 + 4);
          *(_DWORD *)(a2 + 28) = *(_DWORD *)(v5 + 8);
        }
        ++v8;
        v5 += 56;
      }
      while ( v8 < *(_DWORD *)(a2 + 40) );
    }
  }
}


void __usercall vostok::math::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx
  float *v3; // edx
  float *v4; // ebx
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm0_4
  unsigned int v8; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)(a2 + 48) )
  {
    v2 = *(_DWORD *)(a2 + 40);
    *(float *)a2 = *(float *)(v2 + 64);
    *(float *)(a2 + 4) = *(float *)(v2 + 64);
    v3 = (float *)(a2 + 8);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(v2 + 16);
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(v2 + 20);
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(v2 + 24);
    *(_DWORD *)(a2 + 20) = *(_DWORD *)(v2 + 28);
    v4 = (float *)(a2 + 24);
    *(_DWORD *)(a2 + 24) = *(_DWORD *)v2;
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(v2 + 4);
    *(_DWORD *)(a2 + 32) = *(_DWORD *)(v2 + 8);
    *(_DWORD *)(a2 + 36) = *(_DWORD *)(v2 + 12);
    v8 = 1;
    if ( *(_DWORD *)(a2 + 48) > 1u )
    {
      v5 = v2 + 72;
      do
      {
        v6 = *(float *)(v5 + 64);
        if ( *(float *)a2 > v6 )
          *(float *)a2 = v6;
        v7 = *(float *)(v5 + 64);
        if ( v7 > *(float *)(a2 + 4) )
          *(float *)(a2 + 4) = v7;
        if ( *v3 > *(float *)(v5 + 16)
          && *(float *)(a2 + 12) > *(float *)(v5 + 20)
          && *(float *)(a2 + 16) > *(float *)(v5 + 24)
          && *(float *)(a2 + 20) > *(float *)(v5 + 28) )
        {
          *v3 = *(float *)(v5 + 16);
          *(_DWORD *)(a2 + 12) = *(_DWORD *)(v5 + 20);
          *(_DWORD *)(a2 + 16) = *(_DWORD *)(v5 + 24);
          *(_DWORD *)(a2 + 20) = *(_DWORD *)(v5 + 28);
        }
        if ( *(float *)v5 > *v4
          && *(float *)(v5 + 4) > *(float *)(a2 + 28)
          && *(float *)(v5 + 8) > *(float *)(a2 + 32)
          && *(float *)(v5 + 12) > *(float *)(a2 + 36) )
        {
          *v4 = *(float *)v5;
          *(_DWORD *)(a2 + 28) = *(_DWORD *)(v5 + 4);
          *(_DWORD *)(a2 + 32) = *(_DWORD *)(v5 + 8);
          *(_DWORD *)(a2 + 36) = *(_DWORD *)(v5 + 12);
        }
        ++v8;
        v5 += 72;
      }
      while ( v8 < *(_DWORD *)(a2 + 48) );
    }
  }
}
