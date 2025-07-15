void __thiscall vostok::vfs::vfs_intrusive_mount_base::destroy(
        vostok::vfs::vfs_intrusive_mount_base *this,
        vostok::vfs::vfs_mount *object)
{
  vostok::vfs::vfs_mount *v2; // edi
  vostok::vfs::mount_root_node_base<1> *m_mount_root; // ebx
  vostok::memory::base_allocator *m_allocator; // eax
  bool v5; // zf
  const vostok::threading::simple_lock *pointer; // esi
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v7; // ecx
  vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *v8; // ecx
  vostok::vfs::query_mount_arguments *v9; // ecx
  vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *v10; // ecx
  vostok::vfs::virtual_file_system *v11; // esi
  vostok::threading::simple_lock *v12; // ecx
  vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  vostok::fs_new::asynchronous_device_interface *v15; // ecx
  vostok::fixed_string<260> *v16; // ecx
  vostok::vfs::base_node<1> *v17; // edi
  vostok::fixed_string<260> *v18; // ecx
  vostok::fixed_string<260> *v19; // ecx
  vostok::fixed_string<260> *v20; // ecx
  vostok::vfs::query_mount_arguments *v21; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v22; // ecx
  int *v23; // esi
  vostok::fixed_string<260> *v24; // ecx
  vostok::vfs::query_mount_arguments *v25; // eax
  vostok::vfs::vfs_mount *v26; // esi
  vostok::fs_new::asynchronous_device_interface *v27; // ecx
  _BYTE v28[40]; // [esp-2Ch] [ebp-151Ch] BYREF
  vostok::vfs::lock_operation_enum v29; // [esp-4h] [ebp-14F4h]
  bool *v30; // [esp+0h] [ebp-14F0h]
  vostok::vfs::virtual_file_system *file_system; // [esp+Ch] [ebp-14E4h]
  vostok::threading::simple_lock::mutex_raii v32; // [esp+10h] [ebp-14E0h] BYREF
  vostok::memory::base_allocator *allocator; // [esp+18h] [ebp-14D8h]
  vostok::vfs::base_node<1> *out_locked_branch; // [esp+1Ch] [ebp-14D4h] BYREF
  vostok::vfs::unmounter v35; // [esp+24h] [ebp-14CCh] BYREF
  HANDLE descriptor[51]; // [esp+34h] [ebp-14BCh] BYREF
  vostok::fs_new::native_path_string archive_physical_path; // [esp+100h] [ebp-13F0h] BYREF
  vostok::fixed_string<260> v38; // [esp+214h] [ebp-12DCh] BYREF
  char v39; // [esp+324h] [ebp-11CCh]
  vostok::fs_new::virtual_path_string virtual_path; // [esp+328h] [ebp-11C8h] BYREF
  vostok::fs_new::virtual_path_string v41; // [esp+43Ch] [ebp-10B4h] BYREF
  vostok::fixed_string<260> v42; // [esp+550h] [ebp-FA0h] BYREF
  char v43; // [esp+660h] [ebp-E90h]
  vostok::vfs::query_mount_arguments m_args; // [esp+664h] [ebp-E8Ch] BYREF
  _BYTE v45[1104]; // [esp+B3Ch] [ebp-9B4h] BYREF
  char v46; // [esp+F8Ch] [ebp-564h] BYREF
  _BYTE v47[1104]; // [esp+1014h] [ebp-4DCh] BYREF
  char v48; // [esp+1464h] [ebp-8Ch] BYREF

  v2 = object;
  m_mount_root = object->m_mount_root;
  m_allocator = object->m_allocator;
  out_locked_branch = (vostok::vfs::base_node<1> *)m_allocator;
  if ( m_mount_root )
  {
    v5 = object->children.m_first.m_object == 0;
    pointer = (const vostok::threading::simple_lock *)m_mount_root->file_system.pointer;
    v32.lock = (const vostok::threading::simple_lock *)m_mount_root->file_system.pointer;
    if ( !v5 )
    {
      do
      {
        vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy>::pop_back(
          (vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy> *)this,
          (int)&v2->children,
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v35,
          v30);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
          v7,
          (int *)&v35,
          0);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v35);
      }
      while ( v2->children.m_first.m_object );
      pointer = v32.lock;
    }
    *(_DWORD *)&v32.locked = (char *)pointer + 12;
    vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, (int)&pointer[1].m_thread_id);
    v32.locked = 1;
    if ( vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy>::contains_object(
           v8,
           (int)pointer,
           v2) )
    {
      if ( *(unsigned int *)((char *)&pointer->m_lock + (_DWORD)&loc_2015E + 2) == -1
        || *(unsigned int *)((char *)&pointer->m_lock + (_DWORD)&loc_2015E + 2) == GetCurrentThreadId() )
      {
        vostok::vfs::query_mount_arguments::query_mount_arguments(v9, (int)&m_args);
        v11 = file_system;
        out_locked_branch = 0;
        if ( vostok::vfs::vfs_hashset::find_and_lock_branch(
               uri,
               &file_system->hashset,
               &out_locked_branch,
               lock_type_read,
               v29) )
        {
          if ( v2->m_reference_count )
          {
            vostok::vfs::unlock_branch(m_args.root_write_lock, lock_type_write);
            v14 = *(boost::function1<void,vostok::sound::create_sound_propagator_params const &> **)&v28[36];
          }
          else
          {
            vostok::vfs::erase_from_mount_history(object, file_system, v12);
            v5 = file_system->mount_history.m_policy.m_lock-- == 1;
            if ( v5 )
              v15 = (vostok::fs_new::asynchronous_device_interface *)_InterlockedExchange(
                                                                       &v11->mount_history.m_policy.m_thread_id,
                                                                       0);
            *(_DWORD *)&v28[36] = m_mount_root->device.pointer;
            v32.locked = 0;
            vostok::fs_new::asynchronous_device_interface::asynchronous_device_interface(
              v15,
              descriptor,
              *(vostok::fs_new::device_file_system_interface **)&v28[36],
              (vostok::fs_new::watcher_enabled_bool)v29);
            if ( m_mount_root->mount_type == mount_type_archive )
            {
              v17 = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::mount_root_node_base,1>(m_mount_root);
              vostok::fixed_string<260>::fixed_string<260>(v18, &archive_physical_path.m_string, &v17->m_name[313]);
              archive_physical_path.m_separator = 92;
              vostok::fixed_string<260>::fixed_string<260>(v19, &virtual_path.m_string, &v17->m_name[573]);
              *(_DWORD *)&v28[36] = m_mount_root->virtual_path.pointer;
              virtual_path.m_separator = 92;
              vostok::fixed_string<260>::fixed_string<260>(v20, &v42, *(char **)&v28[36]);
              v43 = 47;
              *(_DWORD *)&v28[8] = 0;
              v21 = vostok::vfs::query_mount_arguments::mount_archive(
                      0,
                      (int)v45,
                      (vostok::vfs::query_mount_arguments *)m_mount_root->allocator.pointer,
                      &v42,
                      &virtual_path,
                      &archive_physical_path,
                      (const vostok::fs_new::native_path_string *)&v17->m_name[833],
                      (const char *)descriptor,
                      0,
                      0,
                      *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)&v28[8]);
              vostok::vfs::query_mount_arguments::operator=(&m_args, v21);
              v23 = (int *)&v46;
            }
            else
            {
              vostok::fixed_string<260>::fixed_string<260>(
                v16,
                &v41.m_string,
                (char *)m_mount_root->physical_path.pointer);
              *(_DWORD *)&v28[36] = m_mount_root->virtual_path.pointer;
              v41.m_separator = 92;
              vostok::fixed_string<260>::fixed_string<260>(v24, &v38, *(char **)&v28[36]);
              v39 = 47;
              *(_DWORD *)&v28[8] = 0;
              *(_DWORD *)&v28[4] = m_mount_root->watcher_enabled;
              *(_DWORD *)v28 = 0;
              v25 = vostok::vfs::query_mount_arguments::mount_physical_path(
                      0,
                      (int)v47,
                      (vostok::vfs::query_mount_arguments *)m_mount_root->allocator.pointer,
                      &v38,
                      &v41,
                      (const vostok::fs_new::native_path_string *)m_mount_root->descriptor.pointer,
                      (const char *)descriptor,
                      0,
                      (vostok::fs_new::synchronous_device_interface *)1,
                      *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)v28);
              vostok::vfs::query_mount_arguments::operator=(&m_args, v25);
              v23 = (int *)&v48;
            }
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              v22,
              v23);
            v26 = object;
            m_args.root_write_lock = out_locked_branch;
            m_args.mount_ptr = object;
            vostok::vfs::unmounter::unmounter(&m_args, file_system, &v35);
            if ( !_InterlockedExchangeAdd(&v26->m_destroy_count, 0xFFFFFFFF) )
            {
              vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::vfs_mount>(
                (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> **)&object,
                allocator,
                (const char *const)0xAD);
              v27 = *(vostok::fs_new::asynchronous_device_interface **)&v28[36];
            }
            vostok::fs_new::asynchronous_device_interface::~asynchronous_device_interface(v27, (int)descriptor);
          }
        }
        else
        {
          *(_DWORD *)&v28[36] = 0;
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::set(
            (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v28[36],
            v2);
          vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
            v13,
            (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)((char *)v11 + (_DWORD)&loc_20144 + 4),
            *(bool **)&v28[36]);
        }
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v14,
          (int *)&m_args.callback);
      }
      else
      {
        *(_DWORD *)&v28[36] = 0;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::set(
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v28[36],
          v2);
        vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
          v10,
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)((char *)pointer + (_DWORD)&loc_20144 + 4),
          *(bool **)&v28[36]);
      }
    }
    else if ( !_InterlockedExchangeAdd(&v2->m_destroy_count, 0xFFFFFFFF) )
    {
      vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::vfs_mount>(
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> **)&object,
        allocator,
        (const char *const)0x61);
    }
    vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v32);
  }
  else
  {
    _InterlockedExchangeAdd(&object->m_destroy_count, 0xFFFFFFFF);
    vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::vfs_mount>(
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> **)&object,
      m_allocator,
      (const char *const)0x51);
  }
}
