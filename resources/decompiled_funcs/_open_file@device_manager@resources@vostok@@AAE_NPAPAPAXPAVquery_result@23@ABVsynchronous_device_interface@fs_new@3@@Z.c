char __userpurge vostok::resources::device_manager::open_file@<al>(
        vostok::fs_new::synchronous_device_interface *device@<eax>,
        vostok::resources::query_result *a2@<ecx>,
        vostok::resources::device_manager *this,
        void ***out_file,
        vostok::resources::query_result *query)
{
  vostok::resources::query_result *v5; // ebp
  volatile int m_flags; // eax
  char v8; // bl
  int v10; // eax
  int v11; // ecx
  vostok::animation::mixing::animation_interval *v12; // eax
  vostok::fs_new::device_file_system_no_watcher_proxy *v13; // eax
  const char *v14; // ebp
  const char *v15; // edi
  void (__cdecl *v16)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v17)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::fs_new::file_mode::mode_enum v18; // [esp-14h] [ebp-17Ch]
  vostok::fs_new::file_access::access_enum v19; // [esp-10h] [ebp-178h]
  bool opened_file; // [esp+17h] [ebp-151h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-150h] BYREF
  int v22; // [esp+3Ch] [ebp-12Ch]
  vostok::vfs::vfs_iterator it; // [esp+40h] [ebp-128h] BYREF
  vostok::fs_new::native_path_string path; // [esp+50h] [ebp-118h] BYREF

  v5 = query;
  m_flags = query->m_flags;
  v8 = 0;
  v22 = 0;
  if ( (m_flags & 8) != 0
    || (vostok::vfs::vfs_iterator::vfs_iterator(&it, &query->m_fat_it), it.m_node)
    && !vostok::vfs::vfs_iterator::is_folder(&it) )
  {
    vostok::resources::query_result::absolute_physical_path(a2, (const vostok::vfs::vfs_iterator *)query, (int)&path);
    if ( (query->m_flags & 2) != 0 )
    {
      v10 = 1;
      v11 = 1;
    }
    else
    {
      vostok::fs_new::create_folder_r(device, &path, 0);
      v10 = 0;
      v11 = 0;
    }
    v19 = v11;
    v18 = v10;
    v12 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(device);
    v13 = (vostok::fs_new::device_file_system_no_watcher_proxy *)vostok::animation::mixing::animation_interval::animation(v12);
    opened_file = vostok::fs_new::device_file_system_no_watcher_proxy::open(
                    v13,
                    out_file,
                    &path,
                    v18,
                    v19,
                    assert_on_fail_false,
                    notify_watcher_true,
                    use_buffering_true);
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:device_manager:", info) )
    {
      v14 = "read";
      if ( (query->m_flags & 2) == 0 )
        v14 = "write";
      v15 = "successfull";
      if ( !opened_file )
        v15 = "failed";
      v16 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v16 )
      {
        log_callback.functor.obj_ptr = v16;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v8 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_device_manager_thread.cpp",
        0x8Au,
        "bool __thiscall vostok::resources::device_manager::open_file(void ***,class vostok::resources::query_result *,co"
        "nst class vostok::fs_new::synchronous_device_interface &)",
        "resources:device_manager:",
        info,
        "%s opened %s for %s",
        v15,
        path.m_string.m_begin,
        v14);
      v5 = query;
    }
    if ( (v8 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v17 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v17 )
            v17(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
    if ( vostok::fs_new::path_string_impl::operator!=(&this->m_last_file_name, &path) )
    {
      this->m_sector_data_last_file_pos = -1;
      vostok::fs_new::virtual_path_string::operator=(
        (vostok::fs_new::virtual_path_string *)&this->m_last_file_name,
        (vostok::fs_new::virtual_path_string *)&path);
    }
    if ( opened_file )
    {
      return 1;
    }
    else
    {
      v5->m_error_type = error_type_cannot_open_file;
      return 0;
    }
  }
  else
  {
    query->m_error_type = error_type_file_not_found;
    return 0;
  }
}
