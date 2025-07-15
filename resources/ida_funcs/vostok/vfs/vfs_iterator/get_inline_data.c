char __userpurge vostok::vfs::vfs_iterator::get_inline_data@<al>(
        vostok::vfs::vfs_iterator *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::const_buffer *out_buffer)
{
  _BYTE *v3; // eax
  bool do_debug_break; // [esp+Bh] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v3 || debug_macro_helper_ignore_always_6 || this->m_node )
  {
    if ( this->m_link_target )
      return vostok::vfs::get_inline_data<1>(this->m_link_target, out_buffer);
    else
      return vostok::vfs::get_inline_data<1>(this->m_node, out_buffer);
  }
  else
  {
    if ( occurances_left_6 == -1 )
      occurances_left_6 = vostok::ui::ui_dialog::input_priority((survarium::game_world *)debug_macro_helper_ignore_always_6);
    if ( occurances_left_6-- )
    {
      if ( !debug_macro_helper_ignore_always_6 )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          a2,
          &do_debug_break,
          process_error_false,
          &debug_macro_helper_ignore_always_6,
          assert_untyped,
          "assertion_failed",
          "m_node",
          ".\\iterator.cpp",
          "vostok::vfs::vfs_iterator::get_inline_data",
          0xDDu);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
