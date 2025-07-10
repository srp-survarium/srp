vostok::animation::mixing::n_ary_tree_visitor_vtbl *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_visitor *a2@<eax>,
        const vostok::animation::base_interpolator *from_animation_interpolator,
        vostok::animation::mixing::n_ary_tree_base_node *from,
        float to)
{
  vostok::animation::mixing::n_ary_tree_cloner *v6; // ecx
  const vostok::animation::base_interpolator *v7; // eax
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v8; // edi
  void (__thiscall *visit)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *); // ecx
  const vostok::math::float4x4 *v10; // xmm0_4
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *result; // eax
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  vostok::animation::mixing::n_ary_tree_visitor *v13; // edi
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v14; // eax
  void (__thiscall *v15)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *); // ebx
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v16; // ebp
  const vostok::animation::base_interpolator *v17; // eax
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v18; // ecx
  void (__thiscall *v19)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *); // edx
  const vostok::math::float4x4 *v20; // xmm0_4
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v21; // edi
  bool v22; // [esp+0h] [ebp-2Ch]
  void **v23; // [esp+14h] [ebp-18h] BYREF
  int v24; // [esp+18h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_weight_node weight; // [esp+1Ch] [ebp-10h] BYREF

  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))from_animation_interpolator->transition_time)(from_animation_interpolator) == 0.0 )
  {
    v7 = vostok::animation::mixing::n_ary_tree_cloner::clone(v6, (int)&a2[8], from_animation_interpolator, v22);
    v8 = a2[17].__vftable;
    visit = v8->visit;
    v8->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v8->visit + 12);
    v8->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v8->visit - 12);
    if ( visit )
    {
      v10 = clear_value;
      *(_DWORD *)visit = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      *((_DWORD *)visit + 1) = v7;
      *((_DWORD *)visit + 2) = v10;
    }
    return (vostok::animation::mixing::n_ary_tree_visitor_vtbl *)visit;
  }
  else
  {
    accept = from->accept;
    weight.m_interpolator = from_animation_interpolator;
    weight.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    LODWORD(weight.m_weight) = clear_value;
    v23 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v24 = 0;
    accept(from, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v23, &weight);
    if ( v24 )
    {
      v14 = a2[17].__vftable;
      v15 = v14->visit;
      v14->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v14->visit + 20);
      v14->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v14->visit - 20);
      a2[9].__vftable = 0;
      a2[11].__vftable = 0;
      from->accept(from, &a2[8]);
      v16 = a2[9].__vftable;
      a2[11].__vftable = 0;
      v17 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_cloner *)from_animation_interpolator,
              (int)&a2[8],
              from_animation_interpolator,
              v22);
      v18 = a2[17].__vftable;
      v19 = v18->visit;
      v18->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v18->visit + 12);
      v18->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v18->visit - 12);
      if ( v19 )
      {
        v20 = clear_value;
        *(_DWORD *)v19 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
        *((_DWORD *)v19 + 1) = v17;
        *((_DWORD *)v19 + 2) = v20;
      }
      if ( v15 )
      {
        v21 = a2[33].__vftable;
        *(_DWORD *)v15 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
        *((_DWORD *)v15 + 1) = v16;
        *((_DWORD *)v15 + 2) = v19;
        *((_DWORD *)v15 + 3) = v17;
        *((_DWORD *)v15 + 4) = v21;
      }
      return (vostok::animation::mixing::n_ary_tree_visitor_vtbl *)v15;
    }
    else
    {
      v13 = a2 + 8;
      v13[1].__vftable = 0;
      v13[3].__vftable = 0;
      from->accept(from, v13);
      result = v13[1].__vftable;
      v13[3].__vftable = 0;
    }
  }
  return result;
}
