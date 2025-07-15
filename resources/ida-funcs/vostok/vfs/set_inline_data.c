char __usercall vostok::vfs::set_inline_data<1>@<al>(
        vostok::vfs::base_node<1> *node@<ecx>,
        const vostok::const_buffer *buffer@<esi>)
{
  unsigned int v2; // eax
  char *v4; // eax
  const char **v5; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::vfs::set_inline_data<1>'::`9'::debug_macro_helper_ignore_always || (node->m_flags & 0x40) != 0 )
  {
    if ( (node->m_flags & 0x10) != 0 )
      v4 = (char *)vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node);
    else
      v4 = (char *)vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node);
    v5 = (const char **)(v4 + 24);
    *v5 = buffer->m_data;
    v5[2] = (const char *)buffer->m_size;
    return 1;
  }
  else
  {
    v2 = `vostok::vfs::set_inline_data<1>'::`12'::occurances_left;
    if ( `vostok::vfs::set_inline_data<1>'::`12'::occurances_left == -1 )
      v2 = 10;
    `vostok::vfs::set_inline_data<1>'::`12'::occurances_left = v2 - 1;
    if ( v2 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        (bool *)"node->is_inlined()",
        "c:\\survarium.deploy\\sources\\vostok\\vfs\\sources\\nodes.h",
        "vostok::vfs::set_inline_data",
        (const char *)0x230);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    return 0;
  }
}
