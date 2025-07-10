void __thiscall vostok::animation::mixing::n_ary_tree_converter::process_interpolators(
        vostok::animation::mixing::n_ary_tree_converter *this,
        vostok::animation::mixing::n_ary_tree_converter *interpolators_root,
        vostok::animation::mixing::binary_tree_base_node *interpolators_count,
        const vostok::animation::base_interpolator **buffer,
        vostok::mutable_buffer *buffera)
{
  vostok::animation::mixing::binary_tree_base_node *m_animations_root; // eax
  int v6; // edi
  vostok::animation::mixing::binary_tree_base_node *v7; // esi
  vostok::animation::mixing::binary_tree_base_node_vtbl *v8; // ecx
  vostok::animation::mixing::binary_tree_base_node *v9; // eax
  vostok::animation::mixing::binary_tree_base_node *v10; // ecx
  bool v11; // zf
  unsigned int v12; // eax
  void *v13; // esp
  vostok::animation::mixing::binary_tree_base_node *v14; // esi
  const vostok::animation::base_interpolator **i; // edi
  int v16; // eax
  vostok::animation::mixing::binary_tree_base_node *v17; // eax
  vostok::animation::mixing::binary_tree_base_node *v18; // esi
  const vostok::animation::base_interpolator *m_reference_count; // eax
  const vostok::animation::base_interpolator *v20; // eax
  vostok::animation::mixing::binary_tree_base_node_vtbl *v21; // ecx
  vostok::animation::mixing::binary_tree_base_node *v22; // eax
  vostok::animation::mixing::binary_tree_base_node *v23; // ecx
  int v24; // eax
  int j; // ecx
  const vostok::animation::base_interpolator **v26; // eax
  const vostok::animation::base_interpolator **v27; // edi
  unsigned int v28; // eax
  const vostok::animation::base_interpolator **v29; // esi
  const vostok::animation::base_interpolator *v30[3]; // [esp+0h] [ebp-18h] BYREF
  vostok::animation::interpolator_size_calculator size_calculator; // [esp+Ch] [ebp-Ch] BYREF

  m_animations_root = interpolators_root->m_animations_root;
  v6 = 0;
  v7 = 0;
  if ( m_animations_root )
  {
    ++m_animations_root->m_reference_count;
    v7 = m_animations_root;
  }
  while ( v7 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v11 = v7->m_reference_count-- == 1;
      if ( v11 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v7->~vostok::animation::mixing::binary_tree_base_node)(
          v7,
          0);
      break;
    }
    v8 = v7[3].__vftable;
    ++v6;
    v9 = 0;
    if ( v8 )
    {
      v9 = (vostok::animation::mixing::binary_tree_base_node *)v7[3].__vftable;
      ++v8[1].accept;
    }
    v10 = v7;
    v7 = v9;
    v11 = v10->m_reference_count-- == 1;
    if ( v11 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v10->~vostok::animation::mixing::binary_tree_base_node)(
        v10,
        0);
  }
  v12 = (unsigned int)buffer + 2 * v6;
  interpolators_root->m_interpolators_count = v12;
  v13 = alloca(4 * v12);
  v14 = interpolators_count;
  for ( i = v30; v14; v14 = v14->m_next_unique_interpolator )
  {
    v16 = (int)v14->cast_weight(v14);
    if ( v16 )
      *i++ = *(const vostok::animation::base_interpolator **)(v16 + 20);
  }
  v17 = interpolators_root->m_animations_root;
  v18 = 0;
  if ( v17 )
  {
    ++v17->m_reference_count;
    v18 = v17;
  }
  while ( v18 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v11 = v18->m_reference_count-- == 1;
      if ( v11 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v18->~vostok::animation::mixing::binary_tree_base_node)(
          v18,
          0);
      break;
    }
    m_reference_count = (const vostok::animation::base_interpolator *)v18[1].m_reference_count;
    if ( m_reference_count )
      *i++ = m_reference_count;
    v20 = (const vostok::animation::base_interpolator *)v18[2].__vftable;
    if ( v20 )
      *i++ = v20;
    v21 = v18[3].__vftable;
    v22 = 0;
    if ( v21 )
    {
      v22 = (vostok::animation::mixing::binary_tree_base_node *)v18[3].__vftable;
      ++v21[1].accept;
    }
    v23 = v18;
    v18 = v22;
    v11 = v23->m_reference_count-- == 1;
    if ( v11 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v23->~vostok::animation::mixing::binary_tree_base_node)(
        v23,
        0);
  }
  LOBYTE(buffer) = 0;
  if ( v30 != i )
  {
    v24 = i - v30;
    for ( j = 0; v24 != 1; ++j )
      v24 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::base_interpolator const * *,vostok::animation::base_interpolator const *,int,binary_tree_sort_interpolators_predicate>(
      (binary_tree_sort_interpolators_predicate)i,
      v30,
      i,
      0,
      2 * j,
      buffer);
    stlp_std::priv::__final_insertion_sort<vostok::animation::base_interpolator const * *,binary_tree_sort_interpolators_predicate>(
      v30,
      (binary_tree_sort_interpolators_predicate)v18,
      i,
      0);
  }
  v26 = stlp_std::adjacent_find<vostok::animation::base_interpolator const * *,vostok::animation::unique_interpolators_predicate>(
          v30,
          i);
  if ( v26 != i )
    v26 = stlp_std::priv::__unique_copy<vostok::animation::base_interpolator const * *,vostok::animation::base_interpolator const * *,vostok::animation::unique_interpolators_predicate>(
            v26,
            v26,
            i);
  v27 = v26;
  v28 = v26 - v30;
  interpolators_root->m_interpolators_count = v28;
  interpolators_root->m_binary_interpolators = (const vostok::animation::base_interpolator **)buffera->m_data;
  v28 *= 4;
  buffera->m_data += v28;
  buffera->m_size -= v28;
  v29 = v30;
  memcpy((unsigned __int8 *)interpolators_root->m_binary_interpolators, (unsigned __int8 *)v30, v28);
  size_calculator.__vftable = (vostok::animation::interpolator_size_calculator_vtbl *)&vostok::animation::interpolator_size_calculator::`vftable';
  size_calculator.m_comparer = 0;
  size_calculator.m_size = 0;
  if ( v30 != v27 )
  {
    do
    {
      (*v29)->accept(*v29, &size_calculator);
      ++v29;
    }
    while ( v29 != v27 );
  }
  interpolators_root->m_buffer_size += size_calculator.m_size + 4 * interpolators_root->m_interpolators_count;
}
