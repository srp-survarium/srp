void __thiscall vostok::animation::mixing::n_ary_tree_serializer::save_times_in_ms(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        int a2)
{
  void *v4; // esp
  unsigned __int8 *v5; // ecx
  unsigned int *v6; // esi
  unsigned int *v7; // ecx
  unsigned int *v8; // eax
  int v9; // edi
  int v10; // edi
  unsigned int power_of_two; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  int v15; // edi
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v20; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v21; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v22; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v23; // ecx
  _DWORD *v24; // esi
  vostok::animation::mixing::n_ary_tree_serializer *v25; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v26; // ecx
  char *i; // esi
  int *v28; // esi
  char *v29; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v30; // [esp-8h] [ebp-34h]
  unsigned int v31; // [esp-4h] [ebp-30h]
  unsigned int v32; // [esp-4h] [ebp-30h]
  unsigned int v33[3]; // [esp+0h] [ebp-2Ch] BYREF
  int v34; // [esp+Ch] [ebp-20h]
  unsigned int *v35; // [esp+10h] [ebp-1Ch]
  unsigned int v36; // [esp+14h] [ebp-18h]
  unsigned int v37; // [esp+18h] [ebp-14h]
  unsigned int v38; // [esp+1Ch] [ebp-10h]
  unsigned int v39; // [esp+20h] [ebp-Ch]
  unsigned int v40; // [esp+24h] [ebp-8h]
  char *v41; // [esp+28h] [ebp-4h]
  unsigned int v42; // [esp+34h] [ebp+8h]
  _DWORD *j; // [esp+34h] [ebp+8h]
  char *v44; // [esp+34h] [ebp+8h]
  bool v45; // [esp+37h] [ebp+Bh]

  v42 = (*(_DWORD *)(a2 + 12) - *(_DWORD *)(a2 + 8)) >> 2;
  vostok::animation::mixing::n_ary_tree_serializer::append(this, a2, v42, 0xAu);
  v4 = alloca(4 * v42);
  v5 = *(unsigned __int8 **)(a2 + 8);
  v31 = 4 * ((*(_DWORD *)(a2 + 12) - (int)v5) >> 2);
  v41 = (char *)v33;
  memcpy((unsigned __int8 *)v33, v5, v31);
  v6 = &v33[v42];
  stlp_std::sort<unsigned int *>(v33, v6, v7);
  v38 = v33[0];
  v8 = stlp_std::unique<unsigned int *>(v33, v6);
  v9 = *(v8 - 1);
  v35 = v8;
  v10 = v9 - *(_DWORD *)v41;
  v40 = v8 - v33;
  power_of_two = vostok::round_up_to_the_next_power_of_two((void *)(v10 + 2));
  v12 = vostok::bit_index(power_of_two);
  v39 = v12 > 1 ? 1 - v12 - 1 : -1;
  v13 = vostok::round_up_to_the_next_power_of_two((void *)(v10 + 1));
  v14 = vostok::bit_index(v13);
  v15 = v14 > 1 ? 1 - v14 - 1 : -1;
  v36 = v15;
  v16 = vostok::round_up_to_the_next_power_of_two((void *)(v42 + 1));
  v17 = vostok::bit_index(v16);
  v37 = v17 > 1 ? 1 - v17 - 1 : -1;
  v18 = vostok::round_up_to_the_next_power_of_two((void *)(v40 + 1));
  v19 = vostok::bit_index(v18);
  v34 = v19 > 1 ? 1 - v19 - 1 : -1;
  v20 = (vostok::animation::mixing::n_ary_tree_serializer *)((v42 * v39 + 4)
                                                           * ((unsigned int)((*(_DWORD *)(a2 + 12) - *(_DWORD *)(a2 + 8)) >> 2) > 1)
                                                           + 43);
  v45 = (unsigned int)v20 > ((unsigned int)((*(_DWORD *)(a2 + 12) - *(_DWORD *)(a2 + 8)) >> 2) > 1)
                          * (v42 * v34 + v37 + v15 * (v40 - 1) + 4)
                          + 43;
  vostok::animation::mixing::n_ary_tree_serializer::append(v20, a2, v45, 1u);
  vostok::animation::mixing::n_ary_tree_serializer::append(v21, a2, v38, 0x20u);
  if ( ((*(_DWORD *)(a2 + 12) - *(_DWORD *)(a2 + 8)) & 0xFFFFFFFC) != 4 )
  {
    if ( v45 )
    {
      vostok::animation::mixing::n_ary_tree_serializer::append(v22, a2, v36, 5u);
      vostok::animation::mixing::n_ary_tree_serializer::append(v25, a2, v40, v37);
      for ( i = v41;
            ;
            vostok::animation::mixing::n_ary_tree_serializer::append(
              v26,
              a2,
              *(_DWORD *)i - *((_DWORD *)i - 1) - 1,
              v36) )
      {
        i += 4;
        if ( i == (char *)v35 )
          break;
      }
      v28 = *(int **)(a2 + 8);
      v35 = *(unsigned int **)(a2 + 12);
      if ( v28 != (int *)v35 )
      {
        v44 = &v41[4 * v40];
        do
        {
          v32 = v34;
          v29 = stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
                  v41,
                  v28,
                  v44);
          vostok::animation::mixing::n_ary_tree_serializer::append(v30, a2, (v29 - v41) >> 2, v32);
          ++v28;
        }
        while ( v28 != (int *)v35 );
      }
    }
    else
    {
      vostok::animation::mixing::n_ary_tree_serializer::append(v22, a2, v39, 5u);
      v24 = *(_DWORD **)(a2 + 8);
      for ( j = *(_DWORD **)(a2 + 12); v24 != j; ++v24 )
        vostok::animation::mixing::n_ary_tree_serializer::append(v23, a2, *v24 - v38, v39);
    }
  }
}
