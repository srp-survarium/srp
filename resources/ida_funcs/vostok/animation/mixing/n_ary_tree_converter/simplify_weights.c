void __usercall vostok::animation::mixing::n_ary_tree_converter::simplify_weights(
        vostok::animation::mixing::n_ary_tree_converter *this@<ecx>,
        int a2@<eax>)
{
  vostok::animation::mixing::binary_tree_animation_node *v2; // eax
  vostok::animation::mixing::binary_tree_animation_node *v3; // edi
  vostok::animation::mixing::binary_tree_base_node *m_next_weight; // esi
  vostok::animation::mixing::binary_tree_base_node *v5; // ebx
  unsigned int v6; // ebp
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v8; // eax
  vostok::animation::mixing::binary_tree_animation_node *v9; // ecx
  const vostok::animation::base_interpolator *m_weight_interpolator; // eax
  bool v11; // zf
  vostok::animation::mixing::binary_tree_animation_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v13; // eax
  vostok::animation::mixing::binary_tree_animation_node *v14; // ecx
  int v15; // [esp+14h] [ebp-20h]
  vostok::animation::mixing::binary_tree_animation_node *v16; // [esp+18h] [ebp-1Ch]
  vostok::animation::mixing::binary_tree_null_weight_searcher searcher; // [esp+1Ch] [ebp-18h] BYREF
  vostok::animation::mixing::n_ary_tree_redundant_multiplicands_detector detector; // [esp+24h] [ebp-10h] BYREF

  v2 = *(vostok::animation::mixing::binary_tree_animation_node **)(a2 + 4);
  v3 = 0;
  v15 = 0;
  if ( v2 )
  {
    ++v2->m_reference_count;
    v3 = v2;
  }
  while ( v3 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v11 = v3->m_reference_count-- == 1;
      if ( v11 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v3->~vostok::animation::mixing::binary_tree_base_node)(
          v3,
          0);
      return;
    }
    fill_weights(v3);
    m_next_weight = v3->m_next_weight;
    v5 = 0;
    v6 = 0;
    searcher.__vftable = (vostok::animation::mixing::binary_tree_null_weight_searcher_vtbl *)&vostok::animation::mixing::binary_tree_null_weight_searcher::`vftable';
    searcher.m_result = 0;
    if ( m_next_weight )
    {
      do
      {
        if ( !m_next_weight->m_same_weight )
        {
          m_next_weight->accept(m_next_weight, &searcher);
          v5 = m_next_weight;
          ++v6;
        }
        m_next_weight = m_next_weight->m_next_weight;
      }
      while ( m_next_weight );
      if ( v6 == 1 )
      {
        m_weight_driving_animation = v3->m_weight_driving_animation;
        if ( m_weight_driving_animation )
        {
          ++m_weight_driving_animation->m_reference_count;
          v15 |= 1u;
          m_next_weight = m_weight_driving_animation;
          v8 = v3->m_weight_driving_animation;
          v9 = 0;
          v16 = 0;
          if ( v8 )
          {
            ++v8->m_reference_count;
            v16 = v8;
            v9 = v8;
          }
          m_weight_interpolator = v9->m_weight_interpolator;
        }
        else
        {
          m_weight_interpolator = v3->m_weight_interpolator;
          v9 = v16;
        }
        detector.__vftable = (vostok::animation::mixing::n_ary_tree_redundant_multiplicands_detector_vtbl *)&vostok::animation::mixing::n_ary_tree_redundant_multiplicands_detector::`vftable';
        detector.m_interpolator = m_weight_interpolator;
        detector.m_result = 0;
        if ( (v15 & 1) != 0 )
        {
          v15 &= ~1u;
          if ( v9 )
          {
            v11 = v9->m_reference_count-- == 1;
            if ( v11 )
              ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v9->~vostok::animation::mixing::binary_tree_base_node)(
                v9,
                0);
          }
        }
        if ( m_next_weight )
        {
          v11 = m_next_weight->m_reference_count-- == 1;
          if ( v11 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_next_weight->~vostok::animation::mixing::binary_tree_base_node)(
              m_next_weight,
              0);
        }
        v5->accept(v5, &detector);
        if ( detector.m_result )
          v6 = 0;
      }
    }
    v3->m_null_weight_found = searcher.m_result;
    v3->m_unique_weights_count = v6;
    m_object = v3->m_next_weight_animation.m_object;
    v13 = 0;
    if ( m_object )
    {
      v13 = v3->m_next_weight_animation.m_object;
      ++m_object->m_reference_count;
    }
    v14 = v3;
    v3 = v13;
    v11 = v14->m_reference_count-- == 1;
    if ( v11 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v14->~vostok::animation::mixing::binary_tree_base_node)(
        v14,
        0);
  }
}
