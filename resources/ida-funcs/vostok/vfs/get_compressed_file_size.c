int __usercall vostok::vfs::get_compressed_file_size<1>@<eax>(vostok::vfs::base_node<1> *node@<eax>)
{
  unsigned int v1; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::vfs::get_compressed_file_size<1>'::`9'::debug_macro_helper_ignore_always || (node->m_flags & 0x10) != 0 )
  {
    if ( (node->m_flags & 0x55) == 4 )
      return *((_DWORD *)node - 6);
    else
      return vostok::vfs::get_raw_file_size_impl<1>(node);
  }
  else
  {
    v1 = `vostok::vfs::get_compressed_file_size<1>'::`12'::occurances_left;
    if ( `vostok::vfs::get_compressed_file_size<1>'::`12'::occurances_left == -1 )
      v1 = 10;
    `vostok::vfs::get_compressed_file_size<1>'::`12'::occurances_left = v1 - 1;
    if ( v1 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        (bool *)"node->is_compressed()",
        "c:\\survarium.deploy\\sources\\vostok\\vfs\\sources\\nodes.h",
        "vostok::vfs::get_compressed_file_size",
        (const char *)0x1DF);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    return 0;
  }
}
