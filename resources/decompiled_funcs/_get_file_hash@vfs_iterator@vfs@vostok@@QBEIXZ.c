unsigned int __usercall vostok::vfs::vfs_iterator::get_file_hash@<eax>(
        vostok::vfs::vfs_iterator *this@<ecx>,
        unsigned int a2@<ebx>)
{
  _BYTE *v2; // eax
  bool do_debug_break; // [esp+Bh] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2 || debug_macro_helper_ignore_always_5 || this->m_node )
  {
    if ( this->m_link_target )
      return vostok::vfs::get_file_hash<1>(this->m_link_target);
    else
      return vostok::vfs::get_file_hash<1>(this->m_node);
  }
  else
  {
    if ( occurances_left_5 == -1 )
      occurances_left_5 = vostok::ui::ui_dialog::input_priority((survarium::game_world *)debug_macro_helper_ignore_always_5);
    if ( occurances_left_5-- )
    {
      if ( !debug_macro_helper_ignore_always_5 )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          a2,
          &do_debug_break,
          process_error_false,
          &debug_macro_helper_ignore_always_5,
          assert_untyped,
          "assertion_failed",
          "m_node",
          ".\\iterator.cpp",
          "vostok::vfs::vfs_iterator::get_file_hash",
          0xD7u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
