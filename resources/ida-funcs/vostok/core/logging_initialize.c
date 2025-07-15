void vostok::core::logging_initialize()
{
  char *v0; // eax
  vostok::memory::pthreads3_allocator *v1; // ecx
  vostok::logging::memory_base_allocator_wrapper *v2; // eax
  vostok::logging::memory_base_allocator_wrapper *v3; // ecx
  vostok::logging::base_allocator *v4; // edi
  int v5; // eax
  vostok::logging::filter_tree *v6; // ecx
  vostok::logging::filter_tree *v7; // eax
  char *v8; // eax
  vostok::memory::pthreads3_allocator *v9; // ecx
  void *v10; // eax
  vostok::console_commands::console_command *v11; // ecx
  vostok::logging::filter_tree *v12; // edi
  vostok::console_commands::logging_filters_console_command *v13; // eax
  char *v14; // eax
  vostok::memory::pthreads3_allocator *v15; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v16; // eax
  char *v17; // eax
  vostok::memory::pthreads3_allocator *v18; // ecx
  vostok::logging::fs_new_device_impl *v19; // eax
  vostok::fs_new::device_file_system_interface *m_device_file_system; // edx
  vostok::logging::memory_base_allocator_wrapper *v21; // ecx
  vostok::logging::log_file *v22; // eax
  const char *v23; // [esp+0h] [ebp-128h]
  const char *v24; // [esp+0h] [ebp-128h]
  const char *v25; // [esp+0h] [ebp-128h]
  const char *v26; // [esp+0h] [ebp-128h]
  unsigned int v27; // [esp+4h] [ebp-124h]
  unsigned int v28; // [esp+4h] [ebp-124h]
  unsigned int v29; // [esp+4h] [ebp-124h]
  unsigned int v30; // [esp+4h] [ebp-124h]
  vostok::fs_new::native_path_string v31; // [esp+10h] [ebp-118h] BYREF

  v0 = type_info::raw_name(&vostok::logging::memory_base_allocator_wrapper `RTTI Type Descriptor');
  v2 = (vostok::logging::memory_base_allocator_wrapper *)vostok::memory::pthreads3_allocator::malloc_impl(
                                                           v1,
                                                           (unsigned int)&vostok::memory::g_mt_allocator,
                                                           (const char *const)8,
                                                           v0,
                                                           v23,
                                                           v27);
  if ( v2 )
  {
    v2->__vftable = (vostok::logging::memory_base_allocator_wrapper_vtbl *)&vostok::logging::memory_base_allocator_wrapper::`vftable';
    v2->m_allocator = &vostok::memory::g_mt_allocator;
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  s_logging_allocator_wrapper = v3;
  v4 = v3;
  v5 = ((int (__stdcall *)(int))v3->allocate)(56);
  if ( v5 )
    vostok::logging::filter_tree::filter_tree(v6, v5, v4);
  else
    v7 = 0;
  vostok::core::g_log_filter_tree = v7;
  v8 = type_info::raw_name(&vostok::console_commands::logging_filters_console_command `RTTI Type Descriptor');
  v10 = vostok::memory::pthreads3_allocator::malloc_impl(
          v9,
          (unsigned int)&vostok::memory::g_mt_allocator,
          (const char *const)0x48,
          v8,
          v24,
          v28);
  if ( v10 )
  {
    v12 = vostok::core::g_log_filter_tree;
    vostok::console_commands::console_command::console_command(
      v11,
      (int)v10,
      "logging_rule",
      1,
      command_type_user_specific,
      execution_filter_early);
    v13->__vftable = (vostok::console_commands::logging_filters_console_command_vtbl *)&vostok::console_commands::logging_filters_console_command::`vftable';
    v13->m_filter_tree = v12;
    v13->m_need_args = 1;
    s_logging_console_command = v13;
  }
  else
  {
    s_logging_console_command = 0;
  }
  vostok::core::push_logging_filters((vostok::command_line::key *)v11);
  if ( vostok::core::g_log_file_usage )
  {
    v14 = type_info::raw_name(&vostok::fs_new::device_file_system_no_watcher_proxy `RTTI Type Descriptor');
    v16 = (vostok::fs_new::device_file_system_no_watcher_proxy *)vostok::memory::pthreads3_allocator::malloc_impl(
                                                                   v15,
                                                                   (unsigned int)&vostok::memory::g_mt_allocator,
                                                                   (const char *const)4,
                                                                   v14,
                                                                   v25,
                                                                   v29);
    if ( v16 )
    {
      v16->m_device_file_system = &s_hdd;
      s_logging_fs_device = v16;
    }
    else
    {
      s_logging_fs_device = 0;
    }
    v17 = type_info::raw_name(&vostok::logging::fs_new_device_impl `RTTI Type Descriptor');
    v19 = (vostok::logging::fs_new_device_impl *)vostok::memory::pthreads3_allocator::malloc_impl(
                                                   v18,
                                                   (unsigned int)&vostok::memory::g_mt_allocator,
                                                   (const char *const)0x14,
                                                   v17,
                                                   v26,
                                                   v30);
    if ( v19 )
    {
      m_device_file_system = s_logging_fs_device->m_device_file_system;
      v21 = s_logging_allocator_wrapper;
      v19->__vftable = (vostok::logging::fs_new_device_impl_vtbl *)&vostok::logging::fs_new_device_impl::`vftable';
      v19->m_device.m_synchronize_query = 0;
      v19->m_device.m_device.m_device_file_system = m_device_file_system;
      v19->m_device.m_out_of_memory = 0;
      v19->m_allocator = v21;
      s_logging_fs_device_impl = v19;
    }
    else
    {
      s_logging_fs_device_impl = 0;
    }
    vostok::fs_new::native_path_string::native_path_string(&v31);
    vostok::core::generate_log_file_name(&v31);
    vostok::logging::new_log_file((vostok::logging::base_allocator *)v31.m_string.m_begin);
    vostok::core::g_log_file = v22;
  }
}
