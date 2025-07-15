void __thiscall vostok::animation::mixing::n_ary_tree_converter::compute_buffer_size(
        vostok::animation::mixing::n_ary_tree_converter *this,
        vostok::animation::mixing::n_ary_tree_converter *thisa)
{
  vostok::animation::mixing::binary_tree_animation_node *v2; // esi
  vostok::animation::mixing::n_ary_tree_converter *v3; // edi
  vostok::animation::mixing::binary_tree_animation_node *m_animations_root; // eax
  vostok::animation::mixing::binary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v6; // ecx
  char v7; // bl
  bool v8; // zf
  vostok::animation::mixing::binary_tree_base_node *i; // edi
  vostok::animation::mixing::binary_tree_animation_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v11; // eax
  vostok::animation::mixing::binary_tree_animation_node *v12; // ecx
  unsigned int m_animations_count; // esi
  void *v14; // esp
  vostok::animation::mixing::binary_tree_animation_node *v15; // eax
  vostok::animation::mixing::binary_tree_animation_node *v16; // esi
  vostok::animation::mixing::binary_tree_animation_node *v17; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v18; // eax
  vostok::animation::mixing::binary_tree_animation_node *v19; // ecx
  const void **m_begin; // edx
  const void **m_end; // esi
  void **v22; // eax
  const void **v23; // eax
  const void **v24; // eax
  int v25; // eax
  const void *v26; // [esp+0h] [ebp-34h] BYREF
  vostok::animation::mixing::n_ary_tree_size_calculator calculator; // [esp+10h] [ebp-24h] BYREF
  vostok::buffer_vector<void const *> animated_objects; // [esp+20h] [ebp-14h] BYREF
  void **end; // [esp+28h] [ebp-Ch] BYREF
  void *value[2]; // [esp+2Ch] [ebp-8h] BYREF

  v2 = 0;
  value[0] = 0;
  v3 = thisa;
  m_animations_root = thisa->m_animations_root;
  calculator.vostok::animation::mixing::binary_tree_visitor::__vftable = (vostok::animation::mixing::n_ary_tree_size_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
  calculator.vostok::animation::mixing::n_ary_tree_visitor::__vftable = (vostok::animation::mixing::n_ary_tree_visitor_vtbl *)&vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  calculator.m_comparer = 0;
  calculator.m_size = 0;
  if ( m_animations_root )
  {
    ++m_animations_root->m_reference_count;
    v2 = m_animations_root;
  }
  while ( v2 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v8 = v2->m_reference_count-- == 1;
      if ( v8 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v2->~vostok::animation::mixing::binary_tree_base_node)(
          v2,
          0);
      break;
    }
    if ( v2->m_null_weight_found )
    {
      --v3->m_animations_count;
      goto LABEL_21;
    }
    fill_weights(v2);
    v2->accept(v2, &calculator);
    m_time_driving_animation = v2->m_time_driving_animation;
    value[0] = (void *)((int)value[0] | 1);
    v6 = 0;
    if ( m_time_driving_animation )
    {
      ++m_time_driving_animation->m_reference_count;
      v6 = m_time_driving_animation;
LABEL_9:
      v7 = 0;
      goto LABEL_10;
    }
    if ( v2->m_time_scale == *(float *)&clear_value )
      goto LABEL_9;
    v7 = 1;
LABEL_10:
    if ( ((int)value[0] & 1) != 0 )
    {
      value[0] = (void *)((int)value[0] & ~1u);
      if ( v6 )
      {
        v8 = v6->m_reference_count-- == 1;
        if ( v8 )
          ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v6->~vostok::animation::mixing::binary_tree_base_node)(
            v6,
            0);
      }
    }
    if ( v7 )
      v3->m_buffer_size += 24;
    for ( i = v2->m_next_weight; i; i = i->m_next_weight )
    {
      if ( !i->m_same_weight )
        i->accept(i, &calculator);
    }
    v3 = thisa;
LABEL_21:
    ++v3->m_animations_count;
    m_object = v2->m_next_weight_animation.m_object;
    v11 = 0;
    if ( m_object )
    {
      v11 = v2->m_next_weight_animation.m_object;
      ++m_object->m_reference_count;
    }
    v12 = v2;
    v2 = v11;
    v8 = v12->m_reference_count-- == 1;
    if ( v8 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v12->~vostok::animation::mixing::binary_tree_base_node)(
        v12,
        0);
  }
  m_animations_count = v3->m_animations_count;
  v3->m_buffer_size += calculator.m_size + 184 * m_animations_count;
  v14 = alloca(136 * m_animations_count);
  vostok::buffer_vector<void const *>::buffer_vector<void const *>(&animated_objects, &v26, m_animations_count, 0);
  v15 = v3->m_animations_root;
  v16 = 0;
  if ( v15 )
  {
    ++v15->m_reference_count;
    v16 = v15;
  }
  while ( v16 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v8 = v16->m_reference_count-- == 1;
      if ( v8 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v16->~vostok::animation::mixing::binary_tree_base_node)(
          v16,
          0);
      break;
    }
    if ( !v16->m_null_weight_found )
    {
      value[0] = (void *)v16->m_animated_object;
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        &animated_objects,
        (const void **)value);
    }
    v17 = v16->m_next_weight_animation.m_object;
    v18 = 0;
    if ( v17 )
    {
      v18 = v16->m_next_weight_animation.m_object;
      ++v17->m_reference_count;
    }
    v19 = v16;
    v16 = v18;
    v8 = v19->m_reference_count-- == 1;
    if ( v8 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v19->~vostok::animation::mixing::binary_tree_base_node)(
        v19,
        0);
  }
  stlp_std::sort<void const * *>(animated_objects.m_begin, animated_objects.m_end);
  m_begin = animated_objects.m_begin;
  value[0] = animated_objects.m_end;
  m_end = animated_objects.m_end;
  if ( animated_objects.m_begin == animated_objects.m_end
    || (v23 = animated_objects.m_begin + 1, animated_objects.m_begin + 1 == animated_objects.m_end) )
  {
    v22 = (void **)animated_objects.m_end;
  }
  else
  {
    while ( *m_begin != *v23 )
    {
      m_begin = v23++;
      if ( v23 == animated_objects.m_end )
      {
        v22 = (void **)animated_objects.m_end;
        goto LABEL_55;
      }
    }
    v22 = (void **)m_begin;
    if ( m_begin != animated_objects.m_end )
    {
      v24 = m_begin + 1;
      if ( m_begin + 1 != animated_objects.m_end )
      {
        do
        {
          if ( *m_begin != *v24 )
            *++m_begin = *v24;
          ++v24;
        }
        while ( v24 != m_end );
      }
      v22 = (void **)(m_begin + 1);
    }
  }
LABEL_55:
  end = v22;
  vostok::buffer_vector<void const *>::erase(
    &animated_objects,
    &animated_objects,
    (const void ***)&end,
    (const void **const *)value);
  v25 = vostok::buffer_vector<void const *>::size(&animated_objects);
  thisa->m_animated_objects_count = v25;
  thisa->m_buffer_size += 136 * v25;
  vostok::buffer_vector<char const *>::~buffer_vector<char const *>(&animated_objects);
}
