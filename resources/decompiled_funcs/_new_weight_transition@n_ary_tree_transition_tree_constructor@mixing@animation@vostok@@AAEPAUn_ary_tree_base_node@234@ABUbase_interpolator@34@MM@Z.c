vostok::animation::mixing::n_ary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        bool a2@<bl>,
        int a3@<esi>,
        const vostok::animation::base_interpolator *interpolator,
        float from,
        float to)
{
  vostok::animation::mixing::n_ary_tree_cloner *v6; // ecx
  double v7; // st6
  int v8; // eax
  _DWORD *v9; // edi
  const vostok::animation::base_interpolator *v10; // eax
  const vostok::math::float4x4 *v11; // xmm0_4
  int v13; // eax
  _DWORD *v14; // ebx
  const vostok::animation::base_interpolator *v15; // eax
  int v16; // eax
  _DWORD *v17; // ebp
  const vostok::animation::base_interpolator *v18; // eax
  const vostok::math::float4x4 *v19; // xmm0_4
  bool v20; // [esp-4h] [ebp-10h]
  bool v21; // [esp+0h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_cloner *v22; // [esp+8h] [ebp-4h]

  v7 = ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator);
  v8 = *(_DWORD *)(a3 + 68);
  v9 = *(_DWORD **)v8;
  if ( v7 == 0.0 )
  {
    *(_DWORD *)v8 += 12;
    *(_DWORD *)(v8 + 4) -= 12;
    if ( v9 )
    {
      v10 = vostok::animation::mixing::n_ary_tree_cloner::clone(v6, a3 + 32, interpolator, v21);
      v11 = clear_value;
      v9[1] = v10;
      *v9 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v9[2] = v11;
      return (vostok::animation::mixing::n_ary_tree_base_node *)v9;
    }
  }
  else
  {
    *(_DWORD *)v8 += 20;
    *(_DWORD *)(v8 + 4) -= 20;
    v13 = *(_DWORD *)(a3 + 68);
    v20 = a2;
    v14 = *(_DWORD **)v13;
    *(_DWORD *)v13 += 12;
    *(_DWORD *)(v13 + 4) -= 12;
    if ( v14 )
    {
      v15 = vostok::animation::mixing::n_ary_tree_cloner::clone(v6, a3 + 32, interpolator, v20);
      *v14 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v14[1] = v15;
      v14[2] = 0;
    }
    v16 = *(_DWORD *)(a3 + 68);
    v17 = *(_DWORD **)v16;
    *(_DWORD *)v16 += 12;
    *(_DWORD *)(v16 + 4) -= 12;
    if ( v17 )
    {
      v18 = vostok::animation::mixing::n_ary_tree_cloner::clone(v6, a3 + 32, interpolator, v20);
      v19 = clear_value;
      *v17 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v17[1] = v18;
      v17[2] = v19;
    }
    if ( v9 )
    {
      v22 = *(vostok::animation::mixing::n_ary_tree_cloner **)(a3 + 132);
      v9[3] = vostok::animation::mixing::n_ary_tree_cloner::clone(v22, a3 + 32, interpolator, v20);
      *v9 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      v9[1] = v14;
      v9[2] = v17;
      v9[4] = v22;
    }
  }
  return (vostok::animation::mixing::n_ary_tree_base_node *)v9;
}
