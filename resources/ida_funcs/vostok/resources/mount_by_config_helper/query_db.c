void __thiscall vostok::resources::mount_by_config_helper::query_db(
        vostok::resources::mount_by_config_helper *this,
        vostok::resources::mount_by_config_helper *thisa)
{
  char *m_end; // esi
  unsigned int v3; // esi
  vostok::memory::base_allocator *m_allocator; // esi
  const char *v5; // ebp
  vostok::resources::fs_task_mount *v6; // edi
  vostok::resources::fs_task *v7; // eax
  vostok::memory::base_allocator *v8; // edi
  vostok::resources::mount_by_config_helper *v9; // ecx
  unsigned __int8 *v10; // [esp-10h] [ebp-250h]
  const char *m_begin; // [esp-4h] [ebp-244h]
  vostok::fs_new::native_path_string path; // [esp+10h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string virtual_path; // [esp+128h] [ebp-118h] BYREF

  path.m_string.m_begin = path.m_string.m_buffer;
  m_begin = thisa->m_mount_id.m_string.m_begin;
  path.m_string.m_end = path.m_string.m_buffer;
  path.m_string.m_max_end = &path.m_separator;
  path.m_string.m_buffer[0] = 0;
  path.m_separator = 92;
  vostok::fs_new::path_string_impl::assignf_with_conversion(
    &path,
    (vostok::fs_new::path_string_impl *)&stru_95AD3C,
    m_begin);
  m_end = thisa->m_mount_id.m_string.m_end;
  virtual_path.m_string.m_max_end = &virtual_path.m_separator;
  v3 = m_end - thisa->m_mount_id.m_string.m_begin;
  v10 = (unsigned __int8 *)thisa->m_mount_id.m_string.m_begin;
  virtual_path.m_string.m_begin = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_end = virtual_path.m_string.m_buffer;
  memcpy((unsigned __int8 *)virtual_path.m_string.m_buffer, v10, v3);
  virtual_path.m_string.m_end += v3;
  *virtual_path.m_string.m_end = 0;
  m_allocator = thisa->m_allocator;
  v5 = thisa->m_mount_id.m_string.m_begin;
  virtual_path.m_separator = 47;
  v6 = (vostok::resources::fs_task_mount *)m_allocator->call_malloc(m_allocator, 992u);
  if ( v6 )
    vostok::resources::fs_task_mount::fs_task_mount(
      v6,
      &virtual_path,
      &path,
      &path,
      v5,
      &thisa->m_callback,
      m_allocator);
  else
    v7 = 0;
  vostok::resources::resources_manager::add_fs_task(vostok::resources::g_resources_manager.m_variable, v7);
  v8 = thisa->m_allocator;
  vostok::resources::mount_by_config_helper::~mount_by_config_helper(v9);
  v8->call_free(v8, thisa);
}
