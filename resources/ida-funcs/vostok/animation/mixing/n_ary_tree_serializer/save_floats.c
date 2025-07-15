void __thiscall vostok::animation::mixing::n_ary_tree_serializer::save_floats(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        int a2)
{
  unsigned int v2; // ebx
  void *v3; // esp
  unsigned __int8 *v4; // ecx
  int v5; // eax
  float *v6; // esi
  unsigned __int8 *v7; // edi
  float *v8; // ecx
  float *v9; // edx
  float *v10; // eax
  float *i; // ecx
  float *v12; // edx
  float *j; // ecx
  unsigned int power_of_two; // eax
  unsigned int v15; // eax
  unsigned int v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v19; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v21; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v22; // ecx
  unsigned int *v23; // esi
  unsigned int *v24; // ebx
  unsigned int v25; // ebx
  vostok::animation::mixing::n_ary_tree_serializer *v26; // ecx
  unsigned __int8 *v27; // esi
  unsigned __int8 *v28; // ebx
  float *v29; // esi
  int v30; // edx
  unsigned __int8 *v31; // ecx
  float v32; // xmm0_4
  unsigned __int8 v33[12]; // [esp+0h] [ebp-1Ch] BYREF
  unsigned int v34; // [esp+Ch] [ebp-10h]
  unsigned int v35; // [esp+10h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+14h] [ebp-8h]
  bool v37; // [esp+1Bh] [ebp-1h]
  int k; // [esp+24h] [ebp+8h]

  v2 = (*(_DWORD *)(a2 + 4120) - *(_DWORD *)(a2 + 4116)) >> 2;
  v3 = alloca(4 * v2);
  v4 = *(unsigned __int8 **)(a2 + 4116);
  v5 = (*(_DWORD *)(a2 + 4120) - (int)v4) >> 2;
  dst = v33;
  memcpy(v33, v4, 4 * v5);
  v6 = (float *)&dst[4 * v2];
  v7 = dst;
  stlp_std::sort<float *>((float *)dst, v6, v8);
  v9 = (float *)v7;
  if ( v7 == (unsigned __int8 *)v6 )
  {
    v10 = v6;
  }
  else
  {
    for ( i = (float *)(v7 + 4); ; ++i )
    {
      if ( i == v6 )
      {
        v10 = v6;
        goto LABEL_8;
      }
      if ( *v9 == *i )
        break;
      v9 = i;
    }
    v10 = v9;
LABEL_8:
    if ( v10 != v6 )
    {
      v12 = v10;
      for ( j = v10 + 1; j != v6; ++j )
      {
        if ( *v12 != *j )
          *++v12 = *j;
      }
      v10 = v12 + 1;
    }
  }
  v35 = ((char *)v10 - (char *)v7) >> 2;
  power_of_two = vostok::round_up_to_the_next_power_of_two((void *)(v2 + 1));
  v15 = vostok::bit_index(power_of_two);
  v16 = v15 > 1 ? 1 - v15 - 1 : -1;
  v17 = vostok::round_up_to_the_next_power_of_two((void *)(v35 + 1));
  v18 = vostok::bit_index(v17);
  v34 = v18 > 1 ? 1 - v18 - 1 : -1;
  v19 = (vostok::animation::mixing::n_ary_tree_serializer *)(32 * v2 + 11);
  v37 = (unsigned int)v19 > 32 * v35 + v16 + v2 * v34 + 11;
  vostok::animation::mixing::n_ary_tree_serializer::append(v19, a2, v37, 1u);
  vostok::animation::mixing::n_ary_tree_serializer::append(v21, a2, v2, 0xAu);
  if ( !v37 )
  {
    v23 = *(unsigned int **)(a2 + 4116);
    v24 = *(unsigned int **)(a2 + 4120);
    while ( v23 != v24 )
      vostok::animation::mixing::n_ary_tree_serializer::append(v22, a2, *v23++, 0x20u);
    return;
  }
  v25 = v35;
  vostok::animation::mixing::n_ary_tree_serializer::append(v22, a2, v35, v16);
  v27 = dst;
  v28 = &dst[4 * v25];
  while ( v27 != v28 )
  {
    vostok::animation::mixing::n_ary_tree_serializer::append(v26, a2, *(_DWORD *)v27, 0x20u);
    v27 += 4;
  }
  v29 = *(float **)(a2 + 4116);
  v35 = *(_DWORD *)(a2 + 4120);
  if ( v29 != (float *)v35 )
  {
    v30 = (v28 - dst) >> 4;
    for ( k = v30; ; v30 = k )
    {
      v31 = dst;
      if ( v30 <= 0 )
        break;
      v32 = *v29;
      while ( *(float *)v31 != v32 )
      {
        v31 += 4;
        if ( *(float *)v31 == v32 )
          break;
        v31 += 4;
        if ( *(float *)v31 == v32 )
          break;
        v31 += 4;
        if ( *(float *)v31 == v32 )
          break;
        v31 += 4;
        if ( --v30 <= 0 )
          goto LABEL_34;
      }
LABEL_43:
      vostok::animation::mixing::n_ary_tree_serializer::append(
        (vostok::animation::mixing::n_ary_tree_serializer *)((v31 - dst) >> 2),
        a2,
        (v31 - dst) >> 2,
        v34);
      if ( ++v29 == (float *)v35 )
        return;
    }
LABEL_34:
    if ( (v28 - v31) >> 2 != 1 )
    {
      if ( (v28 - v31) >> 2 != 2 )
      {
        if ( (v28 - v31) >> 2 != 3 )
        {
LABEL_42:
          v31 = v28;
          goto LABEL_43;
        }
        if ( *(float *)v31 == *v29 )
          goto LABEL_43;
        v31 += 4;
      }
      if ( *(float *)v31 == *v29 )
        goto LABEL_43;
      v31 += 4;
    }
    if ( *(float *)v31 == *v29 )
      goto LABEL_43;
    goto LABEL_42;
  }
}
