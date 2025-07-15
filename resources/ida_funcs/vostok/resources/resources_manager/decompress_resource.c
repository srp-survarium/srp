void __thiscall vostok::resources::resources_manager::decompress_resource(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *query,
        unsigned int out_size)
{
  vostok::vfs::vfs_iterator *v3; // ebx
  int v4; // eax
  vostok::resources::resources_manager **v5; // edi
  vostok::threading::mutex *v6; // esi
  vostok::resources::query_result *v7; // ecx
  vostok::vfs::vfs_iterator *v8; // esi
  unsigned __int8 *v9; // eax
  vostok::vfs::base_node<1> *file_size; // eax
  vostok::vfs::vfs_hashset *m_hashset; // eax
  vostok::vfs::base_node<1> *v12; // esi
  vostok::resources::query_result *v13; // ecx
  char *v14; // esi
  vostok::sound::encoded_sound_interface *v15; // eax
  vostok::resources::query_result *v16; // ecx
  int v17; // ecx
  vostok::vfs::base_node<1> *m_link_target; // eax
  int v19; // eax
  volatile __int32 *v20; // eax
  vostok::vfs::base_node<1> *v21; // [esp+0h] [ebp-48h]
  bool *v22; // [esp+4h] [ebp-44h]
  vostok::const_buffer src_file; // [esp+14h] [ebp-34h] BYREF
  vostok::mutable_buffer dest_file; // [esp+1Ch] [ebp-2Ch] BYREF
  vostok::vfs::vfs_iterator v25; // [esp+24h] [ebp-24h] BYREF
  vostok::mutable_buffer v26; // [esp+34h] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v27; // [esp+3Ch] [ebp-Ch] BYREF

  v3 = (vostok::vfs::vfs_iterator *)out_size;
  v4 = *(_DWORD *)(out_size + 632);
  if ( v4 )
  {
    this = *(vostok::resources::resources_manager **)(v4 + 212);
    if ( !*(_DWORD *)&this->m_mounts_path.m_string.m_buffer[4] )
    {
      v5 = (vostok::resources::resources_manager **)(*(_DWORD *)(v4 + 212) + 32);
      this = *v5;
      if ( !*v5 )
      {
        v6 = (vostok::threading::mutex *)(*(_DWORD *)(v4 + 216) + 8368);
        vostok::threading::mutex::lock(v6);
        _InterlockedExchange((volatile __int32 *)v5, 1);
        LeaveCriticalSection((LPCRITICAL_SECTION)v6);
      }
    }
  }
  vostok::resources::query_result::pin_compressed_file(
    (vostok::resources::query_result *)this,
    v3,
    (vostok::mutable_buffer *)&src_file);
  v8 = (vostok::vfs::vfs_iterator *)vostok::resources::query_result::pin_raw_file(
                                      v7,
                                      &v27,
                                      (vostok::resources::query_result *)v3);
  v21 = vostok::mutable_buffer::size(v8);
  v9 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v8);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &dest_file,
    v9,
    (unsigned int)v21);
  if ( v3[10].m_node )
  {
    file_size = (vostok::vfs::base_node<1> *)vostok::vfs::vfs_iterator::get_file_size(v3 + 10);
  }
  else
  {
    m_hashset = v3[13].m_hashset;
    v25.m_node = v3[13].m_node;
    v25.m_hashset = m_hashset;
    file_size = vostok::mutable_buffer::size(&v25);
  }
  v12 = file_size;
  if ( !(*(unsigned __int8 (__thiscall **)(_DWORD, const char *, unsigned int, char *, unsigned int, unsigned int *))(**(_DWORD **)((char *)&query->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20586 + 2) + 4))(
          *(volatile int *)((char *)&query->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20586 + 2),
          src_file.m_data,
          src_file.m_size,
          dest_file.m_data,
          dest_file.m_size,
          &out_size)
    || (vostok::vfs::base_node<1> *)out_size != v12 )
  {
    v3[16].m_hashset = (vostok::vfs::vfs_hashset *)8;
  }
  vostok::resources::query_result::unpin_compressed_file(
    v13,
    (int)v3,
    (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_file);
  vostok::const_buffer::const_buffer((vostok::const_buffer *)&v25.m_link_target, &dest_file);
  v14 = (char *)v3[42].m_hashset
      + (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&v25.m_link_target);
  v15 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v25.m_link_target);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &v26,
    (unsigned __int8 *)((char *)v15 - (char *)v3[42].m_hashset),
    (unsigned int)v14);
  vostok::resources::query_result::unpin_raw_buffer(
    v16,
    (int)v3,
    (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
  m_link_target = v3[39].m_link_target;
  if ( m_link_target )
  {
    v17 = *(_DWORD *)&m_link_target->m_name[161];
    if ( *(_DWORD *)(v17 + 32) )
    {
      v19 = *(_DWORD *)&m_link_target->m_name[161];
      v17 = *(_DWORD *)(v19 + 32);
      v20 = (volatile __int32 *)(v19 + 32);
      if ( v17 )
        _InterlockedExchange(v20, 0);
    }
  }
  v3[38].m_hashset = 0;
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v17,
    (volatile int *)((char *)&query->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_204AD + 3),
    (vostok::resources::query_result *)v3,
    v22);
}
