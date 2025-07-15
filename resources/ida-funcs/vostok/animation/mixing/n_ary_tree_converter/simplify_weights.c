void __usercall vostok::animation::mixing::n_ary_tree_converter::simplify_weights(
        vostok::animation::mixing::n_ary_tree_converter *this@<ecx>,
        int a2@<eax>)
{
  vostok::animation::mixing::binary_tree_weight_node *v2; // eax
  vostok::animation::mixing::binary_tree_weight_node *v3; // esi
  vostok::animation::mixing::binary_tree_base_node *m_next_weight; // edi
  const vostok::animation::base_interpolator *m_interpolator; // eax
  const vostok::animation::base_interpolator *v6; // edi
  const vostok::animation::base_interpolator *v7; // eax
  const vostok::animation::base_interpolator *v8; // ecx
  vostok::animation::mixing::binary_tree_base_node *v9; // eax
  bool v10; // zf
  _DWORD v11[2]; // [esp+10h] [ebp-28h] BYREF
  char v12; // [esp+18h] [ebp-20h]
  void **v13; // [esp+1Ch] [ebp-1Ch] BYREF
  char v14; // [esp+20h] [ebp-18h]
  vostok::animation::mixing::binary_tree_base_node *v15; // [esp+24h] [ebp-14h]
  vostok::animation::mixing::binary_tree_weight_node *v16; // [esp+28h] [ebp-10h] BYREF
  const vostok::animation::base_interpolator *v17; // [esp+2Ch] [ebp-Ch]
  vostok::animation::mixing::binary_tree_weight_node_vtbl *v18; // [esp+30h] [ebp-8h]
  int v19; // [esp+34h] [ebp-4h]

  v2 = *(vostok::animation::mixing::binary_tree_weight_node **)(a2 + 76);
  v3 = 0;
  v19 = 0;
  v16 = 0;
  if ( v2 )
  {
    ++v2->m_reference_count;
    v3 = v2;
    v16 = v2;
  }
  while ( v3 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v10 = v3->m_reference_count-- == 1;
      if ( v10 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v3->~vostok::animation::mixing::binary_tree_base_node)(
          v3,
          0);
      return;
    }
    fill_weights((vostok::animation::mixing::binary_tree_animation_node *)v3);
    v13 = &vostok::animation::mixing::binary_tree_null_weight_searcher::`vftable';
    v14 = 0;
    m_next_weight = v3->m_next_weight;
    v15 = 0;
    v18 = 0;
    if ( m_next_weight )
    {
      do
      {
        if ( !m_next_weight->m_same_weight )
        {
          m_next_weight->accept(m_next_weight, (vostok::animation::mixing::binary_tree_visitor *)&v13);
          v18 = (vostok::animation::mixing::binary_tree_weight_node_vtbl *)((char *)v18 + 1);
          v15 = m_next_weight;
        }
        m_next_weight = m_next_weight->m_next_weight;
      }
      while ( m_next_weight );
      if ( v18 == (vostok::animation::mixing::binary_tree_weight_node_vtbl *)1 )
      {
        m_interpolator = v3[1].m_interpolator;
        v6 = 0;
        if ( m_interpolator )
        {
          ++m_interpolator[4].__vftable;
          v19 |= 1u;
          v6 = m_interpolator;
          v7 = v3[1].m_interpolator;
          v8 = 0;
          v17 = 0;
          if ( v7 )
          {
            ++v7[4].__vftable;
            v17 = v7;
            v8 = v7;
          }
          v9 = (vostok::animation::mixing::binary_tree_base_node *)v8[9].__vftable;
        }
        else
        {
          v9 = v3[1].m_next_weight;
          v8 = v17;
        }
        v11[0] = &vostok::animation::mixing::n_ary_tree_redundant_multiplicands_detector::`vftable';
        v11[1] = v9;
        v12 = 0;
        if ( (v19 & 1) != 0 )
        {
          v19 &= ~1u;
          if ( v8 )
          {
            v10 = v8[4].__vftable-- == (vostok::animation::base_interpolator_vtbl *)1;
            if ( v10 )
              ((void (__thiscall *)(const vostok::animation::base_interpolator *, _DWORD))v8->interpolated_value)(v8, 0);
          }
        }
        if ( v6 )
        {
          v10 = v6[4].__vftable-- == (vostok::animation::base_interpolator_vtbl *)1;
          if ( v10 )
            ((void (__thiscall *)(const vostok::animation::base_interpolator *, _DWORD))v6->interpolated_value)(v6, 0);
        }
        v15->accept(v15, (vostok::animation::mixing::binary_tree_visitor *)v11);
        if ( v12 )
          v18 = 0;
      }
    }
    v3[2].__vftable = v18;
    LOBYTE(v3[3].m_interpolator) = v14;
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v3[1].m_simplified_weight,
      &v16);
    v3 = v16;
  }
}
