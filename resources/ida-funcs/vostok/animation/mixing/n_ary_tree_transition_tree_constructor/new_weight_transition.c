vostok::animation::mixing::n_ary_tree_base_node *__thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_base_node *from,
        vostok::animation::mixing::n_ary_tree_node_cloner *to,
        vostok::animation::mixing::n_ary_tree_node_cloner *a4)
{
  vostok::animation::mixing::n_ary_tree_addition_node *v5; // esi
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v7; // eax
  void (__thiscall *v8)(vostok::animation::mixing::n_ary_tree_base_node *); // edi
  vostok::animation::mixing::n_ary_tree_base_node *v9; // esi
  vostok::animation::mixing::n_ary_tree_node_cloner *v10; // ecx
  const vostok::animation::base_interpolator *v11; // eax
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v12; // ebx
  bool v13; // [esp+0h] [ebp-1Ch]
  void **v14; // [esp+10h] [ebp-Ch] BYREF
  const vostok::animation::base_interpolator *interpolator; // [esp+14h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_base_node *v16; // [esp+24h] [ebp+8h]

  v5 = (vostok::animation::mixing::n_ary_tree_addition_node *)&from[8];
  if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *))a4->m_result->is_weight)(a4->m_result) == 0.0 )
    return vostok::animation::mixing::n_ary_tree_node_cloner::clone(a4, v5);
  v7 = from[17].__vftable;
  v8 = v7->~vostok::animation::mixing::n_ary_tree_base_node;
  v7->~vostok::animation::mixing::n_ary_tree_base_node = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *))((char *)v7->~vostok::animation::mixing::n_ary_tree_base_node + 20);
  v7->accept = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *))((char *)v7->accept - 20);
  v16 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(to, v5);
  interpolator = 0;
  v9 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
         a4,
         (vostok::animation::mixing::n_ary_tree_addition_node *)&from[8]);
  v14 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  v9->accept(v9, (vostok::animation::mixing::n_ary_tree_visitor *)&v14);
  v11 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v10, (int)&from[8], interpolator, v13);
  if ( v8 )
  {
    v12 = from[33].__vftable;
    *(_DWORD *)v8 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
    *((_DWORD *)v8 + 1) = v16;
    *((_DWORD *)v8 + 2) = v9;
    *((_DWORD *)v8 + 3) = v11;
    *((_DWORD *)v8 + 4) = v12;
  }
  return (vostok::animation::mixing::n_ary_tree_base_node *)v8;
}


vostok::animation::mixing::n_ary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *a2@<eax>,
        const vostok::animation::base_interpolator *from_animation_interpolator,
        vostok::animation::mixing::n_ary_tree_node_cloner *from,
        float to)
{
  vostok::animation::mixing::n_ary_tree_node_cloner *v6; // ecx
  const vostok::animation::base_interpolator *v7; // eax
  unsigned int m_operands_count; // edi
  float *v9; // ecx
  float v10; // xmm0_4
  vostok::animation::mixing::n_ary_tree_addition_node_vtbl *v12; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner_vtbl *v13; // eax
  vostok::animation::mixing::n_ary_tree_addition_node *v14; // esi
  unsigned int v15; // eax
  _DWORD *v16; // ebx
  vostok::animation::mixing::n_ary_tree_node_cloner *v17; // ecx
  const vostok::animation::base_interpolator *v18; // eax
  unsigned int v19; // ecx
  float *v20; // edx
  float v21; // xmm0_4
  unsigned int v22; // edi
  bool v23; // [esp+0h] [ebp-28h]
  _DWORD v24[2]; // [esp+Ch] [ebp-1Ch] BYREF
  int v25; // [esp+14h] [ebp-14h]
  char v26; // [esp+18h] [ebp-10h]
  _DWORD v27[3]; // [esp+1Ch] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_base_node *v28; // [esp+34h] [ebp+Ch]

  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))from_animation_interpolator->transition_time)(from_animation_interpolator) == 0.0 )
  {
    v7 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v6, (int)&a2[4], from_animation_interpolator, v23);
    m_operands_count = a2[8].m_operands_count;
    v9 = *(float **)m_operands_count;
    *(_DWORD *)m_operands_count += 12;
    *(_DWORD *)(m_operands_count + 4) -= 12;
    if ( v9 )
    {
      v10 = s_bm_current_air_resistance;
      *(_DWORD *)v9 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      *((_DWORD *)v9 + 1) = v7;
      v9[2] = v10;
    }
    return (vostok::animation::mixing::n_ary_tree_base_node *)v9;
  }
  else
  {
    v12 = a2[10].__vftable;
    v25 = 0;
    v24[1] = v12;
    v13 = from->__vftable;
    v27[0] = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    v27[1] = from_animation_interpolator;
    *(float *)&v27[2] = s_bm_current_air_resistance;
    v24[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v26 = 0;
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_cloner *, _DWORD *, _DWORD *))v13->visit)(
      from,
      v24,
      v27);
    v14 = a2 + 4;
    if ( v25 )
    {
      v15 = a2[8].m_operands_count;
      v16 = *(_DWORD **)v15;
      *(_DWORD *)v15 += 20;
      *(_DWORD *)(v15 + 4) -= 20;
      v28 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(from, v14);
      v18 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v17, (int)&a2[4], from_animation_interpolator, v23);
      v19 = a2[8].m_operands_count;
      v20 = *(float **)v19;
      *(_DWORD *)v19 += 12;
      *(_DWORD *)(v19 + 4) -= 12;
      if ( v20 )
      {
        v21 = s_bm_current_air_resistance;
        *(_DWORD *)v20 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
        *((_DWORD *)v20 + 1) = v18;
        v20[2] = v21;
      }
      if ( v16 )
      {
        v22 = a2[16].m_operands_count;
        *v16 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
        v16[1] = v28;
        v16[2] = v20;
        v16[3] = v18;
        v16[4] = v22;
      }
      return (vostok::animation::mixing::n_ary_tree_base_node *)v16;
    }
    else
    {
      return vostok::animation::mixing::n_ary_tree_node_cloner::clone(from, v14);
    }
  }
}


vostok::animation::mixing::n_ary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *a2@<eax>,
        const vostok::animation::base_interpolator *to_animation_interpolator,
        vostok::animation::mixing::n_ary_tree_base_node *from,
        vostok::animation::mixing::n_ary_tree_base_node *to)
{
  vostok::animation::mixing::n_ary_tree_addition_node *v6; // esi
  unsigned int m_operands_count; // eax
  _DWORD *v9; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *v10; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v11; // esi
  vostok::animation::mixing::n_ary_tree_node_cloner *v12; // ecx
  const vostok::animation::base_interpolator *v13; // eax
  unsigned int v14; // ecx
  float *v15; // edx
  float v16; // xmm0_4
  unsigned int v17; // edi
  bool v18; // [esp+0h] [ebp-30h]
  vostok::animation::mixing::n_ary_tree_double_dispatcher dispatcher; // [esp+Ch] [ebp-24h] BYREF
  vostok::animation::mixing::n_ary_tree_addition_node_vtbl *v20; // [esp+10h] [ebp-20h]
  int v21; // [esp+14h] [ebp-1Ch]
  char v22; // [esp+18h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_weight_node v23; // [esp+1Ch] [ebp-14h] BYREF
  void **v24; // [esp+28h] [ebp-8h] BYREF
  const vostok::animation::base_interpolator *interpolator; // [esp+2Ch] [ebp-4h]

  if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)from[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                       + 4))(from[1].__vftable) == 0.0 )
  {
    v6 = a2 + 4;
    return vostok::animation::mixing::n_ary_tree_node_cloner::clone(
             (vostok::animation::mixing::n_ary_tree_node_cloner *)from,
             v6);
  }
  v21 = 0;
  v23.m_interpolator = to_animation_interpolator;
  v20 = a2[10].__vftable;
  v23.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  v23.m_weight = s_bm_current_air_resistance;
  dispatcher.__vftable = (vostok::animation::mixing::n_ary_tree_double_dispatcher_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v22 = 0;
  vostok::animation::mixing::n_ary_tree_weight_node::accept(&v23, &dispatcher, from);
  v6 = a2 + 4;
  if ( !v21 )
    return vostok::animation::mixing::n_ary_tree_node_cloner::clone(
             (vostok::animation::mixing::n_ary_tree_node_cloner *)from,
             v6);
  m_operands_count = a2[8].m_operands_count;
  v9 = *(_DWORD **)m_operands_count;
  *(_DWORD *)m_operands_count += 20;
  *(_DWORD *)(m_operands_count + 4) -= 20;
  v10 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
          (vostok::animation::mixing::n_ary_tree_node_cloner *)from,
          v6);
  interpolator = 0;
  v11 = v10;
  v24 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  v10->accept(v10, (vostok::animation::mixing::n_ary_tree_visitor *)&v24);
  v13 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v12, (int)&a2[4], interpolator, v18);
  v14 = a2[8].m_operands_count;
  v15 = *(float **)v14;
  *(_DWORD *)v14 += 12;
  *(_DWORD *)(v14 + 4) -= 12;
  if ( v15 )
  {
    v16 = s_bm_current_air_resistance;
    *(_DWORD *)v15 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    *((_DWORD *)v15 + 1) = v13;
    v15[2] = v16;
  }
  if ( v9 )
  {
    v17 = a2[16].m_operands_count;
    *v9 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
    v9[1] = v15;
    v9[2] = v11;
    v9[3] = v13;
    v9[4] = v17;
  }
  return (vostok::animation::mixing::n_ary_tree_base_node *)v9;
}


vostok::animation::mixing::n_ary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        int a2@<esi>,
        const vostok::animation::base_interpolator *interpolator,
        float from,
        float to)
{
  vostok::animation::mixing::n_ary_tree_node_cloner *v5; // ecx
  double v6; // st6
  int v7; // eax
  float *v8; // edi
  const vostok::animation::base_interpolator *v9; // eax
  float v10; // xmm0_4
  int v11; // eax
  _DWORD *v12; // ebx
  const vostok::animation::base_interpolator *v13; // eax
  int v14; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner *v15; // ecx
  const vostok::animation::base_interpolator *v16; // eax
  float v17; // xmm0_4
  bool v19; // [esp+0h] [ebp-10h]
  int v20; // [esp+8h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_node_cloner *v21; // [esp+Ch] [ebp-4h]

  v6 = ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator);
  v7 = *(_DWORD *)(a2 + 68);
  v8 = *(float **)v7;
  if ( v6 == 0.0 )
  {
    *(_DWORD *)v7 += 12;
    *(_DWORD *)(v7 + 4) -= 12;
    if ( v8 )
    {
      v9 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v5, a2 + 32, interpolator, v19);
      v10 = s_bm_current_air_resistance;
      *(_DWORD *)v8 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      *((_DWORD *)v8 + 1) = v9;
      v8[2] = v10;
    }
  }
  else
  {
    *(_DWORD *)v7 += 20;
    *(_DWORD *)(v7 + 4) -= 20;
    v11 = *(_DWORD *)(a2 + 68);
    v12 = *(_DWORD **)v11;
    *(_DWORD *)v11 += 12;
    *(_DWORD *)(v11 + 4) -= 12;
    if ( v12 )
    {
      v13 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v5, a2 + 32, interpolator, v19);
      *v12 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v12[1] = v13;
      v12[2] = 0;
    }
    v14 = *(_DWORD *)(a2 + 68);
    v15 = *(vostok::animation::mixing::n_ary_tree_node_cloner **)v14;
    *(_DWORD *)v14 += 12;
    *(_DWORD *)(v14 + 4) -= 12;
    v21 = v15;
    if ( v15 )
    {
      v16 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v15, a2 + 32, interpolator, v19);
      v15 = v21;
      v17 = s_bm_current_air_resistance;
      v21->__vftable = (vostok::animation::mixing::n_ary_tree_node_cloner_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v21->m_result = (vostok::animation::mixing::n_ary_tree_base_node *)v16;
      *(float *)&v21->m_constructor = v17;
    }
    if ( v8 )
    {
      v20 = *(_DWORD *)(a2 + 132);
      *((_DWORD *)v8 + 3) = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v15, a2 + 32, interpolator, v19);
      *(_DWORD *)v8 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      *((_DWORD *)v8 + 1) = v12;
      *((_DWORD *)v8 + 2) = v21;
      *((_DWORD *)v8 + 4) = v20;
    }
  }
  return (vostok::animation::mixing::n_ary_tree_base_node *)v8;
}
