vostok::animation::mixing::expression *__thiscall vostok::animation::animation_collection::emit_impl(
        vostok::animation::animation_collection *this,
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::expression *buffer,
        vostok::animation::mixing::animation_lexeme *const driving_animation,
        bool *is_last_animation,
        bool *a6)
{
  unsigned int v6; // ecx
  unsigned int v7; // edx
  bool v8; // zf
  bool v9; // al
  int v10; // esi
  vostok::animation::mixing::base_lexeme *v11; // eax
  vostok::animation::mixing::binary_tree_base_node *m_object; // edi
  vostok::animation::mixing::base_lexeme *v13; // eax
  unsigned __int64 v14; // rax
  vostok::particle::particle_system_instance_impl_vtbl *v15; // eax
  _BYTE *v16; // ebx
  bool v17; // cl
  bool v18; // cl
  vostok::animation::mixing::binary_tree_base_node *v19; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+14h] [ebp-Ch] BYREF
  vostok::animation::mixing::expression v22; // [esp+18h] [ebp-8h] BYREF

  if ( result[35].m_lexeme )
  {
    if ( BYTE2(result[36].m_node.m_object) )
    {
      v6 = ((char *)result[33].m_lexeme - (char *)result[33].m_node.m_object) >> 2;
      v7 = ((unsigned int)&result[35].m_node.m_object->__vftable + 1) % v6;
      v8 = LOBYTE(result[36].m_node.m_object) == 0;
      result[35].m_node.m_object = (vostok::animation::mixing::binary_tree_base_node *)v7;
      v9 = v8 && v7 == v6 - 1;
      *a6 = v9;
    }
  }
  else
  {
    *a6 = LOBYTE(result[36].m_node.m_object) == 0;
    v10 = ((char *)result[33].m_lexeme - (char *)result[33].m_node.m_object) >> 2;
    if ( BYTE1(result[36].m_node.m_object) )
    {
      v11 = (vostok::animation::mixing::base_lexeme *)(134775813 * (int)result[34].m_lexeme + 1);
      result[34].m_lexeme = v11;
      result[35].m_node.m_object = (vostok::animation::mixing::binary_tree_base_node *)(((unsigned int)v10
                                                                                       * (unsigned __int64)(unsigned int)v11) >> 32);
    }
    else
    {
      m_object = result[35].m_node.m_object;
      do
      {
        v13 = (vostok::animation::mixing::base_lexeme *)(134775813 * (int)result[34].m_lexeme + 1);
        result[34].m_lexeme = v13;
        v14 = ((unsigned int)v13 * (unsigned __int64)(unsigned int)v10) >> 32;
        result[35].m_node.m_object = (vostok::animation::mixing::binary_tree_base_node *)v14;
      }
      while ( m_object == (vostok::animation::mixing::binary_tree_base_node *)v14 );
    }
  }
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v21,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result[33].m_node.m_object->__vftable
  + (int)result[35].m_node.m_object);
  v15 = v21.m_object->__vftable;
  v16 = (char *)&result[36].m_node.m_object + 2;
  if ( is_last_animation )
  {
    ((void (__stdcall *)(vostok::animation::mixing::expression *, vostok::animation::mixing::animation_lexeme *const, bool *, _BYTE *))v15->is_finished)(
      &v22,
      driving_animation,
      is_last_animation,
      v16);
    v17 = *a6 && *v16;
    *a6 = v17;
    vostok::animation::mixing::expression::expression(buffer, &v22);
    if ( v22.m_node.m_object )
    {
      v8 = v22.m_node.m_object->m_reference_count-- == 1;
      if ( v8 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v22.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v22.m_node.m_object,
          0);
    }
  }
  else
  {
    ((void (__stdcall *)(vostok::animation::mixing::expression *, vostok::animation::mixing::animation_lexeme *const, _BYTE *))v15[1].~vostok::particle::particle_system_instance)(
      &v22,
      driving_animation,
      v16);
    v18 = *a6 && *v16;
    *a6 = v18;
    v19 = v22.m_node.m_object;
    buffer->m_node.m_object = 0;
    if ( v19 )
    {
      buffer->m_node.m_object = v19;
      ++v19->m_reference_count;
      v19 = v22.m_node.m_object;
    }
    buffer->m_lexeme = v22.m_lexeme;
    if ( v19 )
    {
      v8 = v19->m_reference_count-- == 1;
      if ( v8 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v22.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v22.m_node.m_object,
          0);
    }
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
  return buffer;
}
