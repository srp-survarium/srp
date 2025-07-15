char __userpurge vostok::vfs::mounter::allocate_mount_branch@<al>(
        vostok::vfs::mounter *this@<ecx>,
        vostok::vfs::mounter *a2@<eax>,
        vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> *out_helper_nodes)
{
  vostok::fs_new::path_part_iterator *v4; // ecx
  vostok::vfs::mount_helper_node<1> *v5; // esi
  vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> *v6; // ecx
  vostok::vfs::mount_helper_node<1> **m_end; // eax
  const char *v9; // [esp+0h] [ebp-164h]
  vostok::fs_new::virtual_path_string v10; // [esp+10h] [ebp-154h] BYREF
  vostok::fs_new::path_part_iterator v11; // [esp+12Ch] [ebp-38h] BYREF
  vostok::fs_new::path_part_iterator v12; // [esp+144h] [ebp-20h] BYREF
  bool do_debug_break; // [esp+15Fh] [ebp-5h] BYREF

  vostok::fs_new::path_string_impl::begin_part(&a2->m_args.virtual_path, (int)&v12);
  vostok::fs_new::path_part_iterator::path_part_iterator(&v11, 0, include_empty_string_in_iteration_false, 0);
  while ( 1 )
  {
    if ( !vostok::fs_new::path_part_iterator::operator!=(&v12, &v11) )
      return 1;
    v10.m_string.m_begin = v10.m_string.m_buffer;
    v10.m_string.m_end = v10.m_string.m_buffer;
    v10.m_string.m_max_end = &v10.m_separator;
    v10.m_string.m_buffer[0] = 0;
    v10.m_separator = 47;
    vostok::fs_new::path_part_iterator::assign_to_string<vostok::fs_new::virtual_path_string>(&v12, &v10);
    vostok::fs_new::path_part_iterator::operator++(v4, (int)&v12);
    if ( v12.m_include_empty_string_in_iteration == v11.m_include_empty_string_in_iteration
      && v12.m_cur_str == v11.m_cur_str )
    {
      return 1;
    }
    v5 = (vostok::vfs::mount_helper_node<1> *)a2->m_args.allocator->call_malloc(
                                                a2->m_args.allocator,
                                                v10.m_string.m_end - v10.m_string.m_begin + 81,
                                                "mount_helper_node",
                                                "vostok::vfs::mounter::allocate_mount_branch",
                                                ".\\mount_helper_branch.cpp",
                                                524);
    if ( !v5 )
      break;
    v6 = out_helper_nodes;
    if ( out_helper_nodes->m_end >= out_helper_nodes->m_max_end
      && !`vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *>::push_back'::`11'::debug_macro_helper_ignore_always )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
        "vostok::buffer_vector<class vostok::vfs::mount_helper_node<1> *>::push_back",
        (const char *)0x12E,
        "buffer overflow",
        v9);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
      v6 = out_helper_nodes;
    }
    m_end = v6->m_end;
    if ( m_end )
      *m_end = v5;
    ++v6->m_end;
  }
  vostok::vfs::mounter::free_mount_branch(out_helper_nodes, a2);
  return 0;
}
