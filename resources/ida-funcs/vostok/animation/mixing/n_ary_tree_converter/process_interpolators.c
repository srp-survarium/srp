void __thiscall vostok::animation::mixing::n_ary_tree_converter::process_interpolators(
        vostok::animation::mixing::n_ary_tree_converter *this,
        const vostok::animation::base_interpolator **interpolators_root,
        _DWORD *interpolators_count,
        const vostok::animation::base_interpolator **buffer,
        const vostok::animation::base_interpolator **a5)
{
  const vostok::animation::base_interpolator **v5; // ebx
  vostok::animation::mixing::binary_tree_base_node *v6; // eax
  const vostok::animation::base_interpolator **v7; // ecx
  int v8; // edi
  bool v9; // zf
  const vostok::animation::base_interpolator *v10; // eax
  void *v11; // esp
  _DWORD *v12; // esi
  int v13; // eax
  const vostok::animation::base_interpolator **v14; // ecx
  const vostok::animation::base_interpolator *v15; // eax
  vostok::animation::mixing::binary_tree_base_node *v16; // eax
  const vostok::animation::base_interpolator **v17; // ecx
  const vostok::animation::base_interpolator *v18; // eax
  const vostok::animation::base_interpolator **v19; // edx
  const vostok::animation::base_interpolator *v20; // eax
  const vostok::animation::base_interpolator **v21; // edx
  int v22; // eax
  const vostok::animation::base_interpolator **v23; // edi
  int v24; // esi
  int i; // ecx
  const vostok::animation::base_interpolator **v26; // esi
  const vostok::animation::base_interpolator **v27; // esi
  const vostok::animation::base_interpolator **v28; // edi
  const vostok::animation::base_interpolator **v29; // esi
  const vostok::animation::base_interpolator **v30; // edi
  unsigned __int8 *v31; // edi
  const vostok::animation::base_interpolator **v32; // ecx
  unsigned int v33; // eax
  _BYTE v34[12]; // [esp+0h] [ebp-1Ch] BYREF
  _DWORD v35[2]; // [esp+Ch] [ebp-10h] BYREF
  int v36; // [esp+14h] [ebp-8h]
  const vostok::animation::base_interpolator **__first; // [esp+18h] [ebp-4h]

  v5 = interpolators_root;
  v6 = (vostok::animation::mixing::binary_tree_base_node *)interpolators_root[19];
  v7 = 0;
  v8 = 0;
  interpolators_root = 0;
  if ( v6 )
  {
    ++v6->m_reference_count;
    v7 = (const vostok::animation::base_interpolator **)v6;
    interpolators_root = (const vostok::animation::base_interpolator **)v6;
  }
  while ( v7 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v9 = v7[4] == (const vostok::animation::base_interpolator *)1;
      v7[4] = (const vostok::animation::base_interpolator *)((char *)v7[4] - 1);
      if ( v9 )
        ((void (__thiscall *)(const vostok::animation::base_interpolator **, _DWORD))(*v7)->__vftable)(v7, 0);
      break;
    }
    ++v8;
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v7
    + 15,
      (vostok::animation::mixing::binary_tree_weight_node **)&interpolators_root);
    v7 = interpolators_root;
  }
  v10 = (const vostok::animation::base_interpolator *)((char *)buffer + 2 * v8);
  v5[28] = v10;
  v11 = alloca(4 * (_DWORD)v10);
  v12 = interpolators_count;
  __first = (const vostok::animation::base_interpolator **)v34;
  buffer = (const vostok::animation::base_interpolator **)v34;
  while ( v12 )
  {
    v13 = (*(int (__thiscall **)(_DWORD *))(*v12 + 8))(v12);
    if ( v13 )
    {
      v14 = buffer;
      v15 = *(const vostok::animation::base_interpolator **)(v13 + 20);
      ++buffer;
      *v14 = v15;
    }
    v12 = (_DWORD *)v12[3];
  }
  v16 = (vostok::animation::mixing::binary_tree_base_node *)v5[19];
  v17 = 0;
  interpolators_root = 0;
  if ( v16 )
  {
    ++v16->m_reference_count;
    v17 = (const vostok::animation::base_interpolator **)v16;
    interpolators_root = (const vostok::animation::base_interpolator **)v16;
  }
  while ( v17 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v9 = v17[4] == (const vostok::animation::base_interpolator *)1;
      v17[4] = (const vostok::animation::base_interpolator *)((char *)v17[4] - 1);
      if ( v9 )
        ((void (__thiscall *)(const vostok::animation::base_interpolator **, _DWORD))(*v17)->__vftable)(v17, 0);
      break;
    }
    v18 = v17[9];
    if ( v18 )
    {
      v19 = buffer++;
      *v19 = v18;
    }
    v20 = v17[10];
    if ( v20 )
    {
      v21 = buffer++;
      *v21 = v20;
    }
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v17
    + 15,
      (vostok::animation::mixing::binary_tree_weight_node **)&interpolators_root);
    v17 = interpolators_root;
  }
  v22 = 0;
  LOBYTE(interpolators_root) = 0;
  if ( __first != buffer )
  {
    v23 = __first;
    v24 = buffer - __first;
    for ( i = v24; i != 1; i >>= 1 )
      ++v22;
    stlp_std::priv::__introsort_loop<vostok::animation::base_interpolator const * *,vostok::animation::base_interpolator const *,int,binary_tree_sort_interpolators_predicate>(
      (binary_tree_sort_interpolators_predicate)__first,
      __first,
      buffer,
      0,
      2 * v22,
      interpolators_root);
    if ( v24 <= 16 )
    {
      stlp_std::priv::__insertion_sort<vostok::animation::base_interpolator const * *,vostok::animation::base_interpolator const *,binary_tree_sort_interpolators_predicate>(
        v23,
        buffer,
        (binary_tree_sort_interpolators_predicate *)&interpolators_root);
    }
    else
    {
      v26 = v23 + 16;
      stlp_std::priv::__insertion_sort<vostok::animation::base_interpolator const * *,vostok::animation::base_interpolator const *,binary_tree_sort_interpolators_predicate>(
        v23,
        v23 + 16,
        (binary_tree_sort_interpolators_predicate *)&interpolators_root);
      while ( v26 != buffer )
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::animation::base_interpolator const * *,vostok::animation::base_interpolator const *,binary_tree_sort_interpolators_predicate>(
          v26,
          *v26);
        ++v26;
      }
    }
  }
  v27 = __first;
  v28 = __first;
  if ( __first == buffer )
  {
    v29 = buffer;
  }
  else
  {
    while ( 1 )
    {
      if ( ++v27 == buffer )
      {
        v29 = buffer;
        goto LABEL_40;
      }
      if ( !vostok::animation::compare(*v27) )
        break;
      v28 = v27;
    }
    v29 = v28;
LABEL_40:
    if ( v29 != buffer )
    {
      v30 = v29;
      while ( ++v29 != buffer )
      {
        if ( vostok::animation::compare(*v29) )
          *++v30 = *v29;
      }
      v29 = v30 + 1;
    }
  }
  v31 = (unsigned __int8 *)__first;
  v32 = a5;
  v33 = v29 - __first;
  v5[28] = (const vostok::animation::base_interpolator *)v33;
  v33 *= 4;
  v5[20] = *v32;
  *v32 = (const vostok::animation::base_interpolator *)((char *)*v32 + v33);
  v32[1] = (const vostok::animation::base_interpolator *)((char *)v32[1] - v33);
  memcpy((unsigned __int8 *)v5[20], v31, v33);
  v35[1] = 0;
  v36 = 0;
  for ( v35[0] = &vostok::animation::interpolator_size_calculator::`vftable'; v31 != (unsigned __int8 *)v29; v31 += 4 )
    (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)v31 + 24))(*(_DWORD *)v31, v35);
  v5[29] = (const vostok::animation::base_interpolator *)((char *)v5[29] + 4 * (_DWORD)v5[28] + v36);
}
