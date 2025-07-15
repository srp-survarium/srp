char __usercall vostok::vfs::vfs_iterator::get_inline_data@<al>(
        vostok::vfs::vfs_iterator *this@<eax>,
        vostok::const_buffer *out_buffer@<esi>)
{
  unsigned int v2; // eax
  vostok::vfs::base_node<1> *m_link_target; // ecx
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( debug_macro_helper_ignore_always_6 || this->m_node )
  {
    m_link_target = this->m_link_target;
    if ( !m_link_target )
      m_link_target = this->m_node;
    return vostok::vfs::get_inline_data<1>(m_link_target, out_buffer);
  }
  else
  {
    v2 = occurances_left_5;
    if ( occurances_left_5 == -1 )
      v2 = 10;
    occurances_left_5 = v2 - 1;
    if ( v2 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        (bool *)"m_node",
        ".\\iterator.cpp",
        "vostok::vfs::vfs_iterator::get_inline_data",
        (const char *)0xDD);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    return 0;
  }
}
