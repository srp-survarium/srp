void __usercall mount_tests_resources(
        double a1@<st0>,
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *out_mount,
        const char *resources_path)
{
  char *m_buffer; // eax
  char *m_begin; // ecx
  char *v5; // eax
  char *v6; // ecx
  vostok::resources::resources_manager *v7; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v9; // ecx
  vostok::command_line::key::type_enum v10; // eax
  vostok::resources::resources_manager *v11; // ecx
  _BYTE v12[40]; // [esp-28h] [ebp-398h] BYREF
  bool completed; // [esp+13h] [ebp-35Dh] BYREF
  vostok::command_line::key_initializator v14[4]; // [esp+14h] [ebp-35Ch]
  vostok::command_line::key_initializator v15[4]; // [esp+18h] [ebp-358h]
  vostok::command_line::key_initializator v16[4]; // [esp+1Ch] [ebp-354h]
  vostok::command_line::key_initializator predicate[4]; // [esp+20h] [ebp-350h]
  void (__usercall *v18)(vostok::resources::intrusive_fs_task_unmount_base *@<esi>, bool *, vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *, vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>); // [esp+24h] [ebp-34Ch]
  bool *p_completed; // [esp+28h] [ebp-348h]
  vostok::fs_new::virtual_path_string virtual_path; // [esp+30h] [ebp-340h] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+144h] [ebp-22Ch] BYREF
  vostok::fs_new::native_path_string test_resources_path; // [esp+258h] [ebp-118h] BYREF

  test_resources_path.m_string.m_begin = test_resources_path.m_string.m_buffer;
  test_resources_path.m_string.m_end = test_resources_path.m_string.m_buffer;
  test_resources_path.m_string.m_max_end = &test_resources_path.m_separator;
  test_resources_path.m_string.m_buffer[0] = 0;
  test_resources_path.m_separator = 92;
  vostok::fs_new::path_string_impl::assignf_with_conversion(
    &test_resources_path,
    (vostok::fs_new::path_string_impl *)&stru_954D10,
    resources_path,
    "tests");
  m_buffer = physical_path.m_string.m_buffer;
  physical_path.m_string.m_begin = physical_path.m_string.m_buffer;
  m_begin = test_resources_path.m_string.m_begin;
  completed = 0;
  physical_path.m_string.m_end = physical_path.m_string.m_buffer;
  physical_path.m_string.m_max_end = &physical_path.m_separator;
  physical_path.m_string.m_buffer[0] = 0;
  if ( test_resources_path.m_string.m_begin )
  {
    if ( *test_resources_path.m_string.m_begin )
    {
      do
      {
        if ( m_buffer >= physical_path.m_string.m_max_end )
          break;
        *m_buffer = *m_begin;
        m_buffer = physical_path.m_string.m_end + 1;
        ++m_begin;
        ++physical_path.m_string.m_end;
      }
      while ( *m_begin );
    }
    *m_buffer = 0;
  }
  v5 = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_max_end = &virtual_path.m_separator;
  physical_path.m_separator = 92;
  virtual_path.m_string.m_begin = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_end = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_buffer[0] = 0;
  v6 = stru_954D10.m_string.m_buffer;
  do
  {
    if ( v5 >= virtual_path.m_string.m_max_end )
      break;
    *v5 = *v6;
    v5 = virtual_path.m_string.m_end + 1;
    ++v6;
    ++virtual_path.m_string.m_end;
  }
  while ( *v6 );
  *v5 = 0;
  p_completed = &completed;
  v18 = on_tests_resources_mount_completed;
  virtual_path.m_separator = 47;
  *(_DWORD *)v12 = &completed;
  *(_DWORD *)&v12[8] = 0;
  *(_DWORD *)&v12[4] = out_mount;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         (boost::detail::function::function_buffer *)&v12[16],
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)on_tests_resources_mount_completed,
         *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > *)v12) )
  {
    *(_DWORD *)&v12[8] = &stru_954D10.m_string.m_buffer[49];
  }
  else
  {
    *(_DWORD *)&v12[8] = 0;
  }
  vostok::resources::query_mount_physical(
    &vostok::memory::g_mt_allocator,
    &virtual_path,
    &physical_path,
    "tests",
    watcher_enabled_true,
    *(boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *)&v12[8]);
  while ( !completed )
  {
    m_type = vostok::threading::g_debug_single_thread.m_type;
    if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
    {
      predicate[0] = 0;
      *(_DWORD *)&v12[36] = *(_DWORD *)predicate;
      vostok::threading::g_debug_single_thread.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      m_type = vostok::threading::g_debug_single_thread.m_type;
    }
    if ( m_type != type_recursive )
    {
      if ( m_type == type_unset )
      {
        v16[0] = 0;
        *(_DWORD *)&v12[36] = *(_DWORD *)v16;
        vostok::threading::g_debug_single_thread.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        m_type = vostok::threading::g_debug_single_thread.m_type;
      }
      if ( m_type != type_recursive )
      {
        vostok::resources::resources_manager::resources_thread_tick(
          v7,
          vostok::resources::g_resources_manager.m_variable,
          a1);
        vostok::resources::resources_manager::cooker_thread_tick(v9, vostok::resources::g_resources_manager.m_variable);
      }
    }
    if ( vostok::resources::g_resources_manager.m_initialized )
    {
      v10 = vostok::threading::g_debug_single_thread.m_type;
      if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
      {
        v15[0] = 0;
        *(_DWORD *)&v12[36] = *(_DWORD *)v15;
        vostok::threading::g_debug_single_thread.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        v10 = vostok::threading::g_debug_single_thread.m_type;
      }
      if ( v10 != type_recursive )
      {
        if ( v10 == type_unset )
        {
          v14[0] = 0;
          *(_DWORD *)&v12[36] = *(_DWORD *)v14;
          vostok::threading::g_debug_single_thread.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
          v10 = vostok::threading::g_debug_single_thread.m_type;
        }
        if ( v10 != type_recursive )
        {
          vostok::resources::resources_manager::resources_thread_tick(
            v7,
            vostok::resources::g_resources_manager.m_variable,
            a1);
          vostok::resources::resources_manager::cooker_thread_tick(
            v11,
            vostok::resources::g_resources_manager.m_variable);
        }
      }
      vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
    }
  }
}
