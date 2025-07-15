void __thiscall survarium::victory_items_container_core::deserialize(
        survarium::victory_items_container_core *this,
        survarium::usable_object *reader,
        vostok::network_core::buffer_reader *time_offset)
{
  survarium::usable_object *v4; // ecx
  const unsigned __int8 *m_pointer; // esi
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *v6; // ecx
  const unsigned __int8 *v7; // esi
  unsigned int v8; // [esp+0h] [ebp-10h]
  unsigned int v9; // [esp+Ch] [ebp-4h]
  unsigned int __n; // [esp+18h] [ebp+8h]
  unsigned __int8 __n_3; // [esp+1Bh] [ebp+Bh]

  survarium::usable_object::deserialize_usable_object(this, reader, time_offset, v8);
  survarium::usable_object::post_deserialize_resolve(
    v4,
    reader,
    *(survarium::game_world_core **)(*(_DWORD *)reader[5].m_deserialized_users.m_buffer[0].m_store + 336));
  m_pointer = time_offset->m_pointer;
  __n = *(_DWORD *)m_pointer;
  time_offset->m_pointer = m_pointer + 4;
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(
    (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)&reader[4].m_hold_use_button,
    *(void ***)&reader[4].m_hold_use_button,
    (void **)&reader[5].~survarium::usable_object);
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::reserve(
    v6,
    (stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *)&reader[4].m_hold_use_button,
    __n);
  if ( __n )
  {
    v9 = __n;
    do
    {
      v7 = time_offset->m_pointer;
      __n_3 = *v7;
      time_offset->m_pointer = v7 + 1;
      ((void (__thiscall *)(survarium::usable_object *, _DWORD))reader->survarium::collision_geometry_subscriber::__vftable[1].~survarium::usable_object)(
        reader,
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)reader[5].m_deserialized_users.m_buffer[0].m_store + 272) + 4 * __n_3));
      --v9;
    }
    while ( v9 );
  }
}
