void __thiscall vostok::resources::device_manager::on_query_processed(
        vostok::resources::device_manager *this,
        vostok::resources::query_result *query,
        bool result)
{
  vostok::resources::query_result *v4; // ecx
  vostok::vfs::base_node<1> *v5; // esi
  vostok::resources::save_generated_data *m_save_generated_data; // esi
  char *m_physical_path; // eax
  char *m_buffer; // ecx
  vostok::vfs::virtual_file_system *v9; // ebx
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  void (__cdecl *v12)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  char v13; // bl
  vostok::resources::query_result *v14; // ecx
  vostok::vfs::vfs_iterator v15; // [esp-10h] [ebp-2C8h] BYREF
  vostok::const_buffer *v16; // [esp+0h] [ebp-2B8h]
  int v17; // [esp+Ch] [ebp-2ACh]
  char *other; // [esp+10h] [ebp-2A8h] BYREF
  vostok::vfs::vfs_iterator v19; // [esp+14h] [ebp-2A4h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-290h] BYREF
  boost::function<void __cdecl(void)> *v21; // [esp+50h] [ebp-268h]
  vostok::vfs::vfs_locked_iterator iterator; // [esp+54h] [ebp-264h] BYREF
  boost::function<void __cdecl(void)> dispatch_callback; // [esp+68h] [ebp-250h] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+88h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string virtual_path; // [esp+1A0h] [ebp-118h] BYREF

  v17 = 0;
  v19.m_type = (vostok::vfs::vfs_iterator::type_enum)&this->m_pre_allocated_mutex;
  vostok::threading::mutex::lock(&this->m_pre_allocated_mutex);
  if ( (query->m_flags & 2) != 0 )
  {
    vostok::resources::query_result::pin_raw_buffer(v4, v16);
    v5 = vostok::mutable_buffer::size(&v19);
    vostok::resources::query_result::unpin_raw_buffer(
      (vostok::resources::query_result *)&v19,
      (const vostok::const_buffer *)&v19);
    this->m_pre_allocated_size -= (int)v5;
  }
  if ( (query->m_flags & 8) != 0 )
  {
    m_save_generated_data = query->m_save_generated_data;
    m_physical_path = m_save_generated_data->m_physical_path;
    m_buffer = physical_path.m_string.m_buffer;
    physical_path.m_string.m_begin = physical_path.m_string.m_buffer;
    v9 = (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                            + (unsigned int)vostok::resources::g_resources_manager.m_variable);
    physical_path.m_string.m_end = physical_path.m_string.m_buffer;
    physical_path.m_string.m_max_end = &physical_path.m_separator;
    physical_path.m_string.m_buffer[0] = 0;
    if ( m_physical_path )
    {
      for ( ; *m_physical_path; ++physical_path.m_string.m_end )
      {
        if ( m_buffer >= physical_path.m_string.m_max_end )
          break;
        *m_buffer = *m_physical_path;
        m_buffer = physical_path.m_string.m_end + 1;
        ++m_physical_path;
      }
      *m_buffer = 0;
    }
    physical_path.m_separator = 92;
    other = m_save_generated_data->m_virtual_path;
    vostok::fs_new::virtual_path_string::virtual_path_string(&virtual_path, (const char **)&other);
    vostok::vfs::vfs_locked_iterator::vfs_locked_iterator(&iterator);
    v19.m_node = (vostok::vfs::base_node<1> *)vostok::resources::g_resources_manager.m_variable;
    LOBYTE(v21) = 0;
    v19.m_hashset = (vostok::vfs::vfs_hashset *)vostok::resources::resources_manager::dispatch_callbacks;
    *(_QWORD *)&v15.m_node = *(_QWORD *)&v19.m_hashset;
    v15.m_type = (vostok::vfs::vfs_iterator::type_enum)v21;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v21,
      (int)&dispatch_callback,
      (unsigned int)m_save_generated_data,
      *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,bool>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::_bi::value<bool> > > *)&v15.m_node,
      (int)v16);
    vostok::vfs::query_hot_mount_and_wait(
      v9,
      &physical_path,
      &virtual_path,
      &iterator,
      &vostok::memory::g_resources_helper_allocator,
      &dispatch_callback);
    if ( dispatch_callback.vtable )
    {
      if ( ((int)dispatch_callback.vtable & 1) == 0 )
      {
        v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)dispatch_callback.vtable & 0xFFFFFFFE);
        if ( v10 )
          v10(&dispatch_callback.functor, &dispatch_callback.functor, 2);
      }
    }
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
    {
      v13 = v17;
    }
    else
    {
      v12 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v12 )
      {
        log_callback.functor.obj_ptr = v12;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v13 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_device_manager.cpp",
        0xA9u,
        "void __thiscall vostok::resources::device_manager::on_query_processed(class vostok::resources::query_result *,bool)",
        "resources:",
        info,
        "written generated resource to file: '%s'",
        physical_path.m_string.m_begin);
    }
    if ( (v13 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v11,
        (int *)&log_callback);
    vostok::vfs::vfs_iterator::vfs_iterator(&v15, &iterator);
    vostok::resources::query_result::late_set_fat_it(v14, v15);
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&iterator);
  }
  vostok::resources::query_result::on_file_operation_end(v4, (vostok::resources::query_result *)v16);
  LeaveCriticalSection((LPCRITICAL_SECTION)v19.m_type);
}
