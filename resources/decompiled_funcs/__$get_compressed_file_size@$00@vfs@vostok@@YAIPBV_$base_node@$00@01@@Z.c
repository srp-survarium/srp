unsigned int __cdecl vostok::vfs::get_compressed_file_size<1>(const vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax
  survarium::game_world *v4; // ecx
  _BYTE *v5; // eax
  bool do_debug_break; // [esp+27h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( !*v3
    || `vostok::vfs::get_compressed_file_size<1>'::`9'::debug_macro_helper_ignore_always
    || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(node->m_flags & 0x10)), *v5) )
  {
    if ( (node->m_flags & 4 | node->m_flags & 0x51) == 4 )
      return *((_DWORD *)node - 6);
    else
      return vostok::vfs::get_raw_file_size_impl<1>(node);
  }
  else
  {
    if ( `vostok::vfs::get_compressed_file_size<1>'::`12'::occurances_left == -1 )
      `vostok::vfs::get_compressed_file_size<1>'::`12'::occurances_left = vostok::ui::ui_dialog::input_priority(v4);
    if ( `vostok::vfs::get_compressed_file_size<1>'::`12'::occurances_left-- )
    {
      if ( !`vostok::vfs::get_compressed_file_size<1>'::`9'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::vfs::get_compressed_file_size<1>'::`9'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "node->is_compressed()",
          "c:\\survarium\\sources\\vostok\\vfs\\sources\\nodes.h",
          "vostok::vfs::get_compressed_file_size",
          0x1DFu);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
