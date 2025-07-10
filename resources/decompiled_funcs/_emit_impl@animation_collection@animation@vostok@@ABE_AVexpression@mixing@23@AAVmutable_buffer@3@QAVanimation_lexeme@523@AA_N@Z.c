vostok::animation::mixing::expression *__userpurge vostok::animation::animation_collection::emit_impl@<eax>(
        vostok::animation::animation_collection *this@<ecx>,
        int a2@<eax>,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        vostok::animation::mixing::animation_lexeme *const driving_animation,
        bool *is_last_animation)
{
  unsigned int v7; // ecx
  unsigned int v8; // edx
  bool v9; // zf
  bool *v10; // ebx
  int v11; // edi
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  unsigned __int64 v15; // rax
  int v16; // edx
  int v17; // eax
  vostok::resources::unmanaged_resource *v18; // edi
  vostok::resources::unmanaged_resource_vtbl *v19; // edx
  _BYTE *v20; // esi
  bool v21; // al
  vostok::animation::mixing::binary_tree_base_node *m_object; // eax
  vostok::animation::mixing::expression ret_expression; // [esp+10h] [ebp-8h] BYREF

  if ( !*(_DWORD *)(a2 + 280) )
  {
    *is_last_animation = *(_BYTE *)(a2 + 284) == 0;
    v11 = (*(_DWORD *)(a2 + 268) - *(_DWORD *)(a2 + 264)) >> 2;
    if ( *(_BYTE *)(a2 + 285) )
    {
      v12 = 134775813 * *(_DWORD *)(a2 + 272) + 1;
      *(_DWORD *)(a2 + 272) = v12;
      *(_DWORD *)(a2 + 276) = ((unsigned int)v11 * (unsigned __int64)(unsigned int)v12) >> 32;
      v10 = is_last_animation;
      goto LABEL_12;
    }
    v13 = *(_DWORD *)(a2 + 276);
    do
    {
      v14 = 134775813 * *(_DWORD *)(a2 + 272) + 1;
      *(_DWORD *)(a2 + 272) = v14;
      v15 = ((unsigned int)v14 * (unsigned __int64)(unsigned int)v11) >> 32;
      *(_DWORD *)(a2 + 276) = v15;
    }
    while ( v13 == (_DWORD)v15 );
    goto LABEL_11;
  }
  if ( !*(_BYTE *)(a2 + 286) )
  {
LABEL_11:
    v10 = is_last_animation;
    goto LABEL_12;
  }
  v7 = (*(_DWORD *)(a2 + 268) - *(_DWORD *)(a2 + 264)) >> 2;
  v8 = (*(_DWORD *)(a2 + 276) + 1) % v7;
  v9 = *(_BYTE *)(a2 + 284) == 0;
  *(_DWORD *)(a2 + 276) = v8;
  if ( v9 && v8 == v7 - 1 )
  {
    v10 = is_last_animation;
    *is_last_animation = 1;
  }
  else
  {
    v10 = is_last_animation;
    *is_last_animation = 0;
  }
LABEL_12:
  v16 = *(_DWORD *)(a2 + 276);
  v17 = *(_DWORD *)(*(_DWORD *)(a2 + 264) + 4 * v16);
  v18 = 0;
  if ( v17 )
  {
    v18 = *(vostok::resources::unmanaged_resource **)(*(_DWORD *)(a2 + 264) + 4 * v16);
    _InterlockedExchangeAdd((volatile signed __int32 *)(v17 + 208), 1u);
  }
  v19 = v18->__vftable;
  v20 = (_BYTE *)(a2 + 286);
  if ( driving_animation )
    ((void (__thiscall *)(vostok::resources::unmanaged_resource *, vostok::animation::mixing::expression *, vostok::mutable_buffer *, vostok::animation::mixing::animation_lexeme *const, _BYTE *))v19[1].~vostok::resources::resource_base)(
      v18,
      &ret_expression,
      buffer,
      driving_animation,
      v20);
  else
    ((void (__thiscall *)(vostok::resources::unmanaged_resource *, vostok::animation::mixing::expression *, vostok::mutable_buffer *, _BYTE *))v19[1].log_string)(
      v18,
      &ret_expression,
      buffer,
      v20);
  v21 = *v10 && *v20;
  *v10 = v21;
  m_object = ret_expression.m_node.m_object;
  result->m_node.m_object = 0;
  if ( m_object )
  {
    ++m_object->m_reference_count;
    result->m_node.m_object = m_object;
    m_object = ret_expression.m_node.m_object;
  }
  result->m_lexeme = ret_expression.m_lexeme;
  if ( m_object )
  {
    v9 = m_object->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))ret_expression.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        ret_expression.m_node.m_object,
        0);
  }
  if ( !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v18->vostok::resources::unmanaged_intrusive_base, v18);
  return result;
}
