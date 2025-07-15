void __thiscall vostok::animation::mixing::n_ary_tree_converter::compute_buffer_size(
        vostok::animation::mixing::n_ary_tree_converter *this,
        survarium::single_game_effect **__comp)
{
  survarium::single_game_effect **v2; // ebx
  vostok::animation::mixing::binary_tree_weight_node *v3; // edi
  vostok::animation::mixing::binary_tree_weight_node *v4; // eax
  vostok::animation::mixing::binary_tree_weight_node *v5; // esi
  unsigned int m_reference_count; // eax
  unsigned int v7; // ecx
  float m_weight; // xmm0_4
  bool v9; // zf
  vostok::animation::mixing::binary_tree_base_node *i; // edi
  int v11; // esi
  int v12; // eax
  void *v13; // esp
  vostok::animation::mixing::binary_tree_weight_node *v14; // eax
  unsigned __int8 *v15; // edi
  survarium::single_game_effect **v16; // edx
  int v17; // esi
  int v18; // ecx
  int v19; // eax
  survarium::single_game_effect **v20; // esi
  unsigned __int8 *v21; // ecx
  unsigned int v22; // esi
  unsigned __int8 *v23; // edx
  unsigned __int8 *j; // eax
  unsigned __int8 *v25; // ecx
  unsigned __int8 *v26; // ecx
  unsigned __int8 *k; // eax
  unsigned __int8 *m; // eax
  int v29; // edi
  _BYTE v30[16]; // [esp+0h] [ebp-3Ch] BYREF
  _DWORD v31[3]; // [esp+10h] [ebp-2Ch] BYREF
  int v32; // [esp+1Ch] [ebp-20h]
  survarium::single_game_effect **__first; // [esp+20h] [ebp-1Ch] BYREF
  survarium::single_game_effect **__last; // [esp+24h] [ebp-18h]
  _BYTE *v35; // [esp+28h] [ebp-14h]
  vostok::animation::mixing::binary_tree_weight_node *v36; // [esp+2Ch] [ebp-10h] BYREF
  unsigned int m_next_unique_interpolator; // [esp+30h] [ebp-Ch] BYREF
  char v38; // [esp+37h] [ebp-5h]

  v2 = __comp;
  v3 = 0;
  m_next_unique_interpolator = 0;
  v4 = (vostok::animation::mixing::binary_tree_weight_node *)__comp[19];
  v5 = 0;
  v31[0] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
  v31[1] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  v31[2] = 0;
  v32 = 0;
  v36 = 0;
  if ( v4 )
  {
    ++v4->m_reference_count;
    v5 = v4;
    v36 = v4;
  }
  while ( v5 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v9 = v5->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v5->~vostok::animation::mixing::binary_tree_base_node)(
          v5,
          0);
      break;
    }
    if ( LOBYTE(v5[3].m_interpolator) )
    {
      __comp[26] = (survarium::single_game_effect *)((char *)__comp[26] - 1);
      goto LABEL_22;
    }
    fill_weights((vostok::animation::mixing::binary_tree_animation_node *)v5);
    v5->accept(v5, (vostok::animation::mixing::binary_tree_visitor *)v31);
    m_reference_count = v5[1].m_reference_count;
    m_next_unique_interpolator |= 1u;
    v7 = 0;
    if ( m_reference_count )
    {
      ++*(_DWORD *)(m_reference_count + 16);
      v7 = m_reference_count;
    }
    else
    {
      m_weight = v5[2].m_weight;
      v38 = 1;
      if ( m_weight != s_bm_current_air_resistance )
        goto LABEL_11;
    }
    v38 = 0;
LABEL_11:
    if ( (m_next_unique_interpolator & 1) != 0 )
    {
      m_next_unique_interpolator &= ~1u;
      if ( v7 )
      {
        v9 = (*(_DWORD *)(v7 + 16))-- == 1;
        if ( v9 )
          (**(void (__thiscall ***)(unsigned int, _DWORD))v7)(v7, 0);
      }
    }
    if ( v38 )
      __comp[29] = (survarium::single_game_effect *)((char *)__comp[29] + 24);
    for ( i = v5->m_next_weight; i; i = i->m_next_weight )
    {
      if ( !i->m_same_weight )
        i->accept(i, (vostok::animation::mixing::binary_tree_visitor *)v31);
    }
LABEL_22:
    __comp[26] = (survarium::single_game_effect *)((char *)__comp[26] + 1);
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v5[1].m_simplified_weight,
      &v36);
    v5 = v36;
    v3 = 0;
  }
  v11 = (int)__comp[26];
  v12 = 176 * v11;
  v11 *= 4;
  __comp[29] = (survarium::single_game_effect *)((char *)__comp[29] + v32 + v11 + v12);
  v13 = alloca(v11);
  __first = (survarium::single_game_effect **)v30;
  __last = (survarium::single_game_effect **)v30;
  v14 = (vostok::animation::mixing::binary_tree_weight_node *)__comp[19];
  v35 = &v30[v11];
  v36 = 0;
  if ( v14 )
  {
    ++v14->m_reference_count;
    v3 = v14;
    v36 = v14;
  }
  while ( v3 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v9 = v3->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v3->~vostok::animation::mixing::binary_tree_base_node)(
          v3,
          0);
      break;
    }
    if ( !LOBYTE(v3[3].m_interpolator) )
    {
      m_next_unique_interpolator = (unsigned int)v3[1].m_next_unique_interpolator;
      vostok::buffer_vector<void const *>::push_back(
        (vostok::buffer_vector<void const *> *)this,
        (int)&__first,
        (const void **)&m_next_unique_interpolator);
    }
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v3[1].m_simplified_weight,
      &v36);
    v3 = v36;
  }
  v15 = (unsigned __int8 *)__last;
  v16 = __first;
  if ( __first != __last )
  {
    v17 = __last - __first;
    v18 = v17;
    v19 = 0;
    while ( v18 != 1 )
    {
      ++v19;
      v18 >>= 1;
    }
    stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
      (stlp_std::less<survarium::single_game_effect *>)__last,
      __first,
      __last,
      0,
      2 * v19,
      __comp);
    if ( v17 <= 16 )
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        (unsigned __int8 *)__first,
        v15);
    }
    else
    {
      v20 = __first + 16;
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        (unsigned __int8 *)__first,
        (unsigned __int8 *)__first + 64);
      v21 = (unsigned __int8 *)v20;
      if ( v20 != (survarium::single_game_effect **)v15 )
      {
        do
        {
          v22 = *(_DWORD *)v21;
          v23 = v21;
          for ( j = v21 - 4; v22 < *(_DWORD *)j; j -= 4 )
          {
            *(_DWORD *)v23 = *(_DWORD *)j;
            v23 = j;
          }
          v21 += 4;
          *(_DWORD *)v23 = v22;
        }
        while ( v21 != v15 );
        v2 = __comp;
      }
    }
    v16 = __first;
  }
  v25 = (unsigned __int8 *)v16;
  if ( v16 == (survarium::single_game_effect **)v15 )
  {
    v26 = v15;
    goto LABEL_61;
  }
  for ( k = (unsigned __int8 *)(v16 + 1); k != v15; k += 4 )
  {
    if ( *(_DWORD *)v25 == *(_DWORD *)k )
      goto LABEL_54;
    v25 = k;
  }
  v25 = v15;
LABEL_54:
  if ( v25 != v15 )
  {
    for ( m = v25 + 4; m != v15; m += 4 )
    {
      if ( *(_DWORD *)v25 != *(_DWORD *)m )
      {
        v25 += 4;
        *(_DWORD *)v25 = *(_DWORD *)m;
      }
    }
    v26 = v25 + 4;
LABEL_61:
    if ( v26 != v15 )
      v15 = (unsigned __int8 *)&v16[((v15 - (unsigned __int8 *)v16) >> 2) - ((v15 - v26) >> 2)];
  }
  v29 = (v15 - (unsigned __int8 *)v16) >> 2;
  v2[27] = (survarium::single_game_effect *)v29;
  v2[29] = (survarium::single_game_effect *)((char *)v2[29] + 136 * v29 + 60);
}
