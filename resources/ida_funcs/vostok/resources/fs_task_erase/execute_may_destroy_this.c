void __thiscall vostok::resources::fs_task_erase::execute_may_destroy_this(vostok::resources::fs_task_erase *this)
{
  char v2; // bl
  vostok::fs_new::native_path_string *p_m_physical_path; // edi
  vostok::vfs::virtual_file_system *v4; // esi
  boost::function1<void,vostok::vfs::mount_result> *v5; // ecx
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::fs_task_erase,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::resources::fs_task_erase *>,boost::arg<1> > > v8; // [esp-8h] [ebp-40h]
  vostok::vfs::virtual_file_system *vfs; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v2 = 0;
  p_m_physical_path = &this->m_physical_path;
  v4 = (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                          + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  vfs = (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                           + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  if ( vostok::buffer_string::empty(&this->m_physical_path) )
    vostok::vfs::virtual_file_system::convert_virtual_to_physical_path(v4, p_m_physical_path, &this->m_virtual_path, 0);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
  {
    v6 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v6 )
    {
      log_callback.functor.obj_ptr = v6;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v2 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\resources_fs_task_erase.cpp",
      0x37u,
      "void __thiscall vostok::resources::fs_task_erase::execute_may_destroy_this(void)",
      "resources:",
      info,
      "erasing file(%s)",
      p_m_physical_path->m_string.m_begin);
  }
  if ( (v2 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v7 )
          v7(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  v8.l_.a1_.t_ = this;
  v8.f_.f_ = vostok::resources::fs_task_erase::on_hot_unmounted;
  log_callback.vtable = 0;
  boost::function1<void,vostok::vfs::mount_result>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::fs_task_erase,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::resources::fs_task_erase *>,boost::arg<1>>>>(
    v5,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::fs_task_erase,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::resources::fs_task_erase *>,boost::arg<1> > > *)&log_callback,
    v8);
  vostok::vfs::virtual_file_system::query_hot_unmount(
    vfs,
    p_m_physical_path,
    (const boost::function<void __cdecl(vostok::vfs::mount_result)> *)&log_callback,
    lock_operation_lock,
    assert_on_fail_false);
  boost::function1<void,vostok::vfs::base_node<1> *>::~function1<void,vostok::vfs::base_node<1> *>((boost::function<void __cdecl(vostok::vfs::vfs_iterator &)> *)&log_callback);
}
