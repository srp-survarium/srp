void __usercall vostok::core::initialize_resources(
        vostok::resources::resources_manager *a1@<ecx>,
        volatile int *a2@<edi>,
        vostok::fs_new::asynchronous_device_interface *hdd,
        vostok::fs_new::asynchronous_device_interface *dvd)
{
  vostok::core_test_suite *v4; // eax
  vostok::command_line::key *v5; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v6; // ecx
  const char *v7; // eax
  vostok::buffer_vector<vostok::resources::cook_base *> *v8; // [esp-4h] [ebp-Ch]
  char *v9; // [esp+4h] [ebp-4h] BYREF

  vostok::resources::g_resources_manager_initialized = 1;
  vostok::resources::resources_manager::resources_manager(
    a1,
    &s_resources_manager_buffer,
    (vostok::vfs::virtual_file_system *)hdd,
    (volatile int)dvd);
  vostok::threading::yield(0xAu);
  v9 = (char *)s_engine_0->get_resources_path(s_engine_0);
  v4 = vostok::testing::suite_base<vostok::core_test_suite>::singleton(a2);
  vostok::fs_new::path_string_impl::assign_with_conversion<char const *>(&v4->m_resources_path, &v9);
  if ( vostok::command_line::key::is_set(v5, (int)&s_mount_mounts_path) )
  {
    v7 = s_engine_0->get_mounts_path(s_engine_0);
    vostok::resources::mount_mounts_path(v7);
  }
  if ( (_S5_16 & 1) == 0 )
  {
    _S5_16 |= 1u;
    vostok::resources::cook_base::cook_base(
      &s_unmanaged_allocation_cook,
      unmanaged_allocation_class,
      0xFFFFFFFC,
      reuse_false,
      0,
      0xFFFFFFFC);
    s_unmanaged_allocation_cook.__vftable = (vostok::resources::unmanaged_allocation_cook_vtbl *)&vostok::resources::unmanaged_allocation_cook::`vftable';
    atexit((int (__cdecl *)())vostok::core::initialize_resources_::_4_::_dynamic_atexit_destructor_for__s_unmanaged_allocation_cook__);
    v6 = v8;
  }
  vostok::resources::resources_manager::register_cook(&s_unmanaged_allocation_cook, v6);
}
