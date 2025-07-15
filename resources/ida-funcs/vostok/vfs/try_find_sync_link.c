vostok::vfs::result_enum __usercall vostok::vfs::try_find_sync_link@<eax>(vostok::vfs::find_environment *env@<edi>)
{
  unsigned int v1; // kr00_4
  vostok::fs_new::virtual_path_string out_path; // [esp+0h] [ebp-9Ch] BYREF

  out_path.m_string.m_begin = out_path.m_string.m_buffer;
  out_path.m_string.m_end = out_path.m_string.m_buffer;
  out_path.m_string.m_max_end = &out_path.m_separator;
  out_path.m_string.m_buffer[0] = 0;
  out_path.m_separator = 47;
  vostok::vfs::find_link_target_path<1>(&out_path);
  v1 = strlen(env->partial_path);
  vostok::buffer_string::append(
    (vostok::buffer_string *)&env->path_to_find[v1],
    (int)&out_path,
    (char *)&env->path_to_find[v1]);
  return vostok::vfs::try_find_sync(
           out_path.m_string.m_begin,
           env->out_iterator,
           env->find_flags.m_flags,
           env->file_system,
           env->allocator);
}
