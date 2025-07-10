void __usercall vostok::core::initialize_resources(
        vostok::resources::resources_manager *hdd@<ecx>,
        vostok::fs_new::asynchronous_device_interface *dvd@<eax>)
{
  const char *v2; // edi
  vostok::core_test_suite *v3; // esi
  char *m_begin; // eax
  vostok::fs_new::path_string_impl *p_m_resources_path; // esi
  vostok::resources::unmanaged_allocation_cook *v6; // ecx
  vostok::resources::resources_manager *v7; // eax
  vostok::resources::enable_fs_watcher_bool v8; // [esp+0h] [ebp-14h]
  vostok::resources *v9; // [esp+0h] [ebp-14h]

  vostok::resources::resources_manager::resources_manager(
    hdd,
    (vostok::fs_new::asynchronous_device_interface *)hdd,
    dvd,
    v8);
  _InterlockedExchange(&vostok::resources::g_resources_manager.m_initialized, 1);
  vostok::threading::yield(0xAu);
  v2 = s_engine_0->get_resources_path(s_engine_0);
  v3 = vostok::testing::suite_base<vostok::core_test_suite>::singleton();
  m_begin = v3->m_resources_path.m_string.m_begin;
  p_m_resources_path = &v3->m_resources_path;
  if ( m_begin != v2 )
  {
    p_m_resources_path->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&p_m_resources_path->m_string, v2);
  }
  vostok::fs_new::path_string_impl::convert(
    p_m_resources_path,
    p_m_resources_path->m_string.m_begin,
    p_m_resources_path->m_string.m_end);
  if ( s_mount_mounts_path.m_type == type_unset )
  {
    s_mount_mounts_path.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_mount_mounts_path.m_type != type_recursive )
  {
    v7 = (vostok::resources::resources_manager *)s_engine_0->get_mounts_path(s_engine_0);
    vostok::resources::resources_manager::mount_mounts_path(
      v7,
      (int)vostok::resources::g_resources_manager.m_variable,
      v9);
  }
  if ( (_S3_14 & 1) == 0 )
  {
    _S3_14 |= 1u;
    vostok::resources::unmanaged_allocation_cook::unmanaged_allocation_cook(v6);
    atexit(vostok::core::initialize_resources_::_4_::_dynamic_atexit_destructor_for__s_unmanaged_allocation_cook__);
  }
  vostok::resources::resources_manager::register_cook(&s_unmanaged_allocation_cook);
}
