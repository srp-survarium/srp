void __thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::copy(
        vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  int *v3; // eax
  int v4; // [esp+1Ch] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v5; // [esp+30h] [ebp-18h] BYREF
  const char *v6; // [esp+34h] [ebp-14h]
  char *m_data; // [esp+38h] [ebp-10h]
  char *v8; // [esp+3Ch] [ebp-Ch]
  char *v9; // [esp+40h] [ebp-8h]
  char v10; // [esp+47h] [ebp-1h]

  v10 = 0;
  m_data = dest_buffer.m_data;
  v9 = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    v8 = v9 + 4;
    *((_DWORD *)v9 + 1) = 0;
  }
  v6 = src_buffer.m_data;
  *(_DWORD *)dest_buffer.m_data = *(_DWORD *)src_buffer.m_data;
  boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
    &v5,
    (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)v6
  + 1);
  v4 = *v3;
  *v3 = *((_DWORD *)dest_buffer.m_data + 1);
  *((_DWORD *)dest_buffer.m_data + 1) = v4;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v5);
}
