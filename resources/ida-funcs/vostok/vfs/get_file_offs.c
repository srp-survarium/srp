unsigned __int64 __usercall vostok::vfs::get_file_offs<1>@<edx:eax>(vostok::vfs::base_node<1> *node@<eax>)
{
  unsigned int v1; // eax
  unsigned __int16 m_flags; // cx
  unsigned int v4; // eax
  vostok::vfs::archive_compressed_file_node<1> *v5; // eax
  const char *v6; // [esp+0h] [ebp-10h]
  bool do_debug_break; // [esp+Fh] [ebp-1h] BYREF

  if ( !`vostok::vfs::get_file_offs<1>'::`9'::debug_macro_helper_ignore_always && (node->m_flags & 1) != 0 )
  {
    v1 = `vostok::vfs::get_file_offs<1>'::`12'::occurances_left;
    if ( `vostok::vfs::get_file_offs<1>'::`12'::occurances_left == -1 )
      v1 = 10;
    `vostok::vfs::get_file_offs<1>'::`12'::occurances_left = v1 - 1;
    if ( !v1 )
      return 0;
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_false,
      (bool *)"!node->is_folder()",
      "c:\\survarium.deploy\\sources\\vostok\\vfs\\sources\\nodes.h",
      "vostok::vfs::get_file_offs",
      (const char *)0x1C6);
    goto LABEL_7;
  }
  m_flags = node->m_flags;
  if ( (m_flags & 0x2000) == 0x2000 )
    return vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node)->offs;
  if ( (m_flags & 4) == 0 || (m_flags & 0x1000) == 0x1000 )
    return 0;
  if ( !`vostok::vfs::get_file_offs<1>'::`33'::debug_macro_helper_ignore_always && (m_flags & 0x40) != 0 )
  {
    v4 = `vostok::vfs::get_file_offs<1>'::`36'::occurances_left;
    if ( `vostok::vfs::get_file_offs<1>'::`36'::occurances_left == -1 )
      v4 = 10;
    `vostok::vfs::get_file_offs<1>'::`36'::occurances_left = v4 - 1;
    if ( !v4 )
      return 0;
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_false,
      0,
      "assertion_failed",
      "!node->is_inlined()",
      "c:\\survarium.deploy\\sources\\vostok\\vfs\\sources\\nodes.h",
      "vostok::vfs::get_file_offs",
      (const char *)0x1D4,
      "you should not call get_file_offs over inline node",
      v6);
LABEL_7:
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
    return 0;
  }
  if ( (m_flags & 0x10) != 0 )
    v5 = vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(node);
  else
    v5 = (vostok::vfs::archive_compressed_file_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(node);
  return v5->pos_in_db;
}
