char __thiscall vostok::resources::query_result::process_request_path(
        vostok::resources::query_result *this,
        vostok::resources::query_result *try_sync_way_only,
        bool a3)
{
  char *requested_path; // eax
  vostok::fixed_string<260> *v5; // ecx
  bool v6; // zf
  vostok::fs_new::synchronous_device_interface *v7; // ecx
  vostok::memory::pthreads3_allocator *m_user_allocator; // ebx
  const vostok::fs_new::native_path_string *v9; // eax
  vostok::vfs::base_node<1> *v10; // eax
  vostok::fs_new::synchronous_device_interface *v11; // ecx
  char v12; // bl
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  vostok::fixed_string<260> *v14; // ecx
  vostok::vfs::vfs_locked_iterator *v15; // ecx
  vostok::fixed_string<260> *v17; // ecx
  vostok::particle::particle_action *v18; // ecx
  vostok::vfs::vfs_locked_iterator *v19; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::resources::resources_manager>,boost::_bi::list1<boost::_bi::value<vostok::resources::resources_manager *> > > v20; // [esp-8h] [ebp-4E0h]
  int v21; // [esp+0h] [ebp-4D8h]
  vostok::fs_new::native_path_string result; // [esp+10h] [ebp-4C8h] BYREF
  vostok::fs_new::virtual_path_string v23; // [esp+124h] [ebp-3B4h] BYREF
  vostok::buffer_string v24[22]; // [esp+238h] [ebp-2A0h] BYREF
  char v25; // [esp+348h] [ebp-190h]
  vostok::buffer_string v26[22]; // [esp+34Ch] [ebp-18Ch] BYREF
  char v27; // [esp+45Ch] [ebp-7Ch]
  vostok::memory::base_allocator v28; // [esp+460h] [ebp-78h] BYREF
  boost::function<void __cdecl(void)> v29; // [esp+480h] [ebp-58h] BYREF
  vostok::fs_new::synchronous_device_interface v30; // [esp+4A0h] [ebp-38h] BYREF
  vostok::vfs::vfs_locked_iterator v31; // [esp+4ACh] [ebp-2Ch] BYREF
  vostok::vfs::vfs_locked_iterator v32; // [esp+4C0h] [ebp-18h] BYREF
  char *v33; // [esp+4D4h] [ebp-4h]
  vostok::memory::doug_lea_allocator *v34; // [esp+4E0h] [ebp+8h]

  if ( (try_sync_way_only->m_flags & 0x100) != 0 )
  {
    vostok::resources::query_result::on_request_iterator_ready(&try_sync_way_only->m_fat_it, try_sync_way_only, a3);
    return 1;
  }
  vostok::resources::query_result::unlock_fat_it(this, (int)try_sync_way_only);
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(try_sync_way_only);
  v6 = *requested_path == 64;
  v33 = requested_path;
  if ( v6 )
  {
    if ( GetCurrentThreadId() == try_sync_way_only->m_user_thread_id )
      m_user_allocator = (vostok::memory::pthreads3_allocator *)try_sync_way_only->m_user_allocator;
    else
      m_user_allocator = &vostok::memory::g_mt_allocator;
    vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
      v7,
      (int)&v30,
      (vostok::fs_new::asynchronous_device_query_vtbl *)s_resources_manager_buffer.m_hdd,
      m_user_allocator);
    v9 = vostok::fs_new::native_path_string::convert(&result, v33 + 1);
    v10 = vostok::vfs::create_temp_physical_node(v9, &v30, (vostok::vfs::query_mount_arguments *)m_user_allocator);
    v32.m_node = 0;
    v32.m_link_target = v10;
    v32.m_type = type_uninitialized;
    v32.mount_operation_id = 2;
    if ( v10 )
    {
      if ( (v10->m_flags & 0x800) == 0x800 )
      {
        v32.m_link_target = 0;
        v32.m_type = type_uninitialized;
      }
    }
    try_sync_way_only->m_fat_it = *(vostok::vfs::vfs_iterator *)&v32.m_node;
    _InterlockedOr(&try_sync_way_only->m_flags, 0x800u);
    vostok::resources::query_result::on_request_iterator_ready(&try_sync_way_only->m_fat_it, try_sync_way_only, a3);
    vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v11, (int *)&v30);
    return 1;
  }
  v12 = 0;
  if ( try_sync_way_only->m_create_resource_result == result_cannot_lock )
  {
    v29.vtable = 0;
    vostok::fixed_string<260>::fixed_string<260>(v5, &v23.m_string, requested_path);
    v23.m_separator = 47;
    vostok::vfs::query_hot_mount_and_wait(
      (vostok::fs_new::native_path_string *)&s_resources_manager_buffer.m_vfs,
      &v23,
      &vostok::memory::g_resources_helper_allocator,
      &v29);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v13,
      (int *)&v29);
  }
  if ( !a3 )
  {
    v20.l_.a1_.t_ = &s_resources_manager_buffer;
    v20.f_.f_ = vostok::resources::resources_manager::dispatch_devices;
    memset(&v31, 0, sizeof(v31));
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&s_resources_manager_buffer,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::resources::resources_manager>,boost::_bi::list1<boost::_bi::value<vostok::resources::resources_manager *> > > *)&v28,
      v20,
      v21);
    vostok::fixed_string<260>::fixed_string<260>(v17, v24, v33);
    v25 = 47;
    while ( vostok::vfs::find_async(
              &v31,
              v18,
              v24[0].m_begin,
              &s_resources_manager_buffer.m_vfs,
              &vostok::memory::g_resources_unmanaged_allocator,
              &v28) == 4 )
      ;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v18,
      (int *)&v28);
    vostok::resources::query_result::on_request_iterator_ready(&v31, try_sync_way_only, 0);
    vostok::vfs::vfs_locked_iterator::clear(v19, (int)&v31);
    return 1;
  }
  if ( GetCurrentThreadId() == try_sync_way_only->m_user_thread_id )
    v34 = (vostok::memory::doug_lea_allocator *)try_sync_way_only->m_user_allocator;
  else
    v34 = &vostok::memory::g_resources_helper_allocator;
  memset(&v32, 0, sizeof(v32));
  vostok::fixed_string<260>::fixed_string<260>(v14, v26, v33);
  v27 = 47;
  if ( vostok::vfs::try_find_sync(v26[0].m_begin, &v32, 2u, &s_resources_manager_buffer.m_vfs, v34) == result_success
    && (GetCurrentThreadId() == s_resources_manager_buffer.m_resources_thread_id
     || !v32.m_node
     || vostok::resources::get_node_sub_fat(
          v32.m_node,
          (vostok::vfs::base_node<1> *)s_resources_manager_buffer.m_resources_thread_id)) )
  {
    vostok::resources::query_result::on_request_iterator_ready(&v32, try_sync_way_only, a3);
    v12 = 1;
  }
  vostok::vfs::vfs_locked_iterator::clear(v15, (int)&v32);
  return v12;
}
