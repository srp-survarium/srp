char __thiscall vostok::resources::query_result::process_request_path(
        vostok::resources::query_result *this,
        vostok::resources::query_result *try_sync_way_only,
        vostok::vfs::vfs_iterator *try_sync_way_onlya)
{
  char *m_requery_path; // edi
  char v5; // dl
  vostok::memory::pthreads3_allocator *m_user_allocator; // esi
  vostok::fs_new::native_path_string *v7; // eax
  vostok::vfs::base_node<1> *v8; // eax
  _QWORD *v9; // eax
  char *m_buffer; // eax
  char *v11; // ecx
  bool v12; // zf
  vostok::memory::doug_lea_allocator *v13; // esi
  char *v14; // eax
  char *i; // ecx
  char *v16; // eax
  char *j; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::resources::resources_manager>,boost::_bi::list1<boost::_bi::value<vostok::resources::resources_manager *> > > v18; // [esp-8h] [ebp-4F0h]
  bool v19; // [esp+0h] [ebp-4E8h]
  vostok::vfs::virtual_file_system *file_system; // [esp+10h] [ebp-4D8h]
  vostok::vfs::vfs_locked_iterator out_iterator; // [esp+14h] [ebp-4D4h] BYREF
  vostok::fs_new::synchronous_device_interface device; // [esp+28h] [ebp-4C0h] BYREF
  vostok::vfs::vfs_locked_iterator it; // [esp+34h] [ebp-4B4h] BYREF
  boost::function<void __cdecl(void)> v24; // [esp+48h] [ebp-4A0h] BYREF
  boost::function<void __cdecl(void)> dispatch_callback; // [esp+68h] [ebp-480h] BYREF
  vostok::vfs::vfs_iterator v26; // [esp+88h] [ebp-460h] BYREF
  vostok::fs_new::virtual_path_string in_virtual_path; // [esp+98h] [ebp-450h] BYREF
  vostok::fs_new::virtual_path_string path_to_find; // [esp+1ACh] [ebp-33Ch] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+2C0h] [ebp-228h] BYREF
  vostok::fs_new::path_string_impl v30; // [esp+3D4h] [ebp-114h] BYREF

  if ( (try_sync_way_only->m_flags & 0x100) != 0 )
  {
    vostok::resources::query_result::on_request_iterator_ready(
      (vostok::resources::query_result *)&try_sync_way_only->m_fat_it,
      (int)try_sync_way_only,
      try_sync_way_onlya,
      v19);
    return 1;
  }
  else
  {
    if ( try_sync_way_only->m_fat_it.m_node )
    {
      vostok::threading::interlocked_and(&try_sync_way_only->m_flags, 0xFFFFFFEF);
      vostok::threading::interlocked_exchange_add(
        (int *)((char *)&dword_201B8 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
        0xFFFFFFFF);
    }
    m_requery_path = try_sync_way_only->m_requery_path;
    if ( !m_requery_path )
      m_requery_path = try_sync_way_only->m_request_path;
    v5 = *m_requery_path;
    if ( *m_requery_path == 64 )
    {
      if ( GetCurrentThreadId() == try_sync_way_only->m_user_thread_id )
        m_user_allocator = (vostok::memory::pthreads3_allocator *)try_sync_way_only->m_user_allocator;
      else
        m_user_allocator = &vostok::memory::g_mt_allocator;
      vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        &device,
        *(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8
                                                          + (unsigned int)vostok::resources::g_resources_manager.m_variable),
        m_user_allocator);
      v7 = vostok::fs_new::native_path_string::convert(m_requery_path + 1, &v30);
      v8 = vostok::vfs::create_temp_physical_node(&device, v7, m_user_allocator);
      vostok::vfs::vfs_iterator::vfs_iterator(&v26, v8, 0, 0, type_non_recursive);
      *(_QWORD *)&try_sync_way_only->m_fat_it.m_hashset = *v9;
      *(_QWORD *)&try_sync_way_only->m_fat_it.m_link_target = v9[1];
      vostok::threading::interlocked_or(&try_sync_way_only->m_flags, 0x800u);
      vostok::resources::query_result::on_request_iterator_ready(
        (vostok::resources::query_result *)&try_sync_way_only->m_fat_it,
        (int)try_sync_way_only,
        try_sync_way_onlya,
        v19);
      vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&device);
      return 1;
    }
    else
    {
      file_system = (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                                       + (unsigned int)vostok::resources::g_resources_manager.m_variable);
      if ( try_sync_way_only->m_create_resource_result == result_requery )
      {
        m_buffer = in_virtual_path.m_string.m_buffer;
        in_virtual_path.m_string.m_begin = in_virtual_path.m_string.m_buffer;
        in_virtual_path.m_string.m_max_end = &in_virtual_path.m_separator;
        dispatch_callback.vtable = 0;
        in_virtual_path.m_string.m_end = in_virtual_path.m_string.m_buffer;
        in_virtual_path.m_string.m_buffer[0] = 0;
        v11 = m_requery_path;
        if ( v5 )
        {
          do
          {
            if ( m_buffer >= in_virtual_path.m_string.m_max_end )
              break;
            *m_buffer = *v11;
            m_buffer = in_virtual_path.m_string.m_end + 1;
            v12 = *++v11 == 0;
            ++in_virtual_path.m_string.m_end;
          }
          while ( !v12 );
        }
        *m_buffer = 0;
        in_virtual_path.m_separator = 47;
        vostok::vfs::query_hot_mount_and_wait(
          file_system,
          &in_virtual_path,
          0,
          &vostok::memory::g_resources_helper_allocator,
          &dispatch_callback);
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&dispatch_callback);
      }
      if ( (_BYTE)try_sync_way_onlya )
      {
        if ( GetCurrentThreadId() == try_sync_way_only->m_user_thread_id )
          v13 = (vostok::memory::doug_lea_allocator *)try_sync_way_only->m_user_allocator;
        else
          v13 = &vostok::memory::g_resources_helper_allocator;
        vostok::vfs::vfs_locked_iterator::vfs_locked_iterator(&out_iterator);
        v12 = *m_requery_path == 0;
        v14 = path.m_string.m_buffer;
        path.m_string.m_max_end = &path.m_separator;
        path.m_string.m_begin = path.m_string.m_buffer;
        path.m_string.m_end = path.m_string.m_buffer;
        path.m_string.m_buffer[0] = 0;
        for ( i = m_requery_path; !v12; ++path.m_string.m_end )
        {
          if ( v14 >= path.m_string.m_max_end )
            break;
          *v14 = *i;
          v14 = path.m_string.m_end + 1;
          v12 = *++i == 0;
        }
        *v14 = 0;
        path.m_separator = 47;
        if ( vostok::vfs::virtual_file_system::try_find_sync(file_system, &path, &out_iterator, find_file_only, v13) == result_error
          && (GetCurrentThreadId() == *(int *)((char *)&dword_203CC
                                             + (unsigned int)vostok::resources::g_resources_manager.m_variable)
           || vostok::resources::vfs_sub_fat_resource_is_created(&out_iterator)) )
        {
          vostok::resources::query_result::on_request_iterator_ready(
            (vostok::resources::query_result *)&out_iterator,
            (int)try_sync_way_only,
            try_sync_way_onlya,
            v19);
          vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&out_iterator);
          return 1;
        }
        else
        {
          vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&out_iterator);
          return 0;
        }
      }
      else
      {
        vostok::vfs::vfs_locked_iterator::vfs_locked_iterator(&it);
        v18.l_.a1_.t_ = vostok::resources::g_resources_manager.m_variable;
        v18.f_.f_ = vostok::resources::resources_manager::dispatch_devices;
        v24.vtable = 0;
        boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::resources::resources_manager>,boost::_bi::list1<boost::_bi::value<vostok::resources::resources_manager *>>>>(
          (boost::function0<void> *)vostok::resources::g_resources_manager.m_variable,
          (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::resources::resources_manager>,boost::_bi::list1<boost::_bi::value<vostok::resources::resources_manager *> > > *)&v24,
          v18);
        v12 = *m_requery_path == 0;
        v16 = path_to_find.m_string.m_buffer;
        path_to_find.m_string.m_max_end = &path_to_find.m_separator;
        path_to_find.m_string.m_begin = path_to_find.m_string.m_buffer;
        path_to_find.m_string.m_end = path_to_find.m_string.m_buffer;
        path_to_find.m_string.m_buffer[0] = 0;
        for ( j = m_requery_path; !v12; ++path_to_find.m_string.m_end )
        {
          if ( v16 >= path_to_find.m_string.m_max_end )
            break;
          *v16 = *j;
          v16 = path_to_find.m_string.m_end + 1;
          v12 = *++j == 0;
        }
        *v16 = 0;
        path_to_find.m_separator = 47;
        vostok::vfs::find_async_and_wait(
          file_system,
          &path_to_find,
          &it,
          find_file_only,
          &vostok::memory::g_resources_unmanaged_allocator,
          &v24);
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v24);
        vostok::resources::query_result::on_request_iterator_ready(
          (vostok::resources::query_result *)&it,
          (int)try_sync_way_only,
          0,
          v19);
        vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&it);
        return 1;
      }
    }
  }
}
