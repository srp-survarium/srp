unsigned int __cdecl vostok::vfs::get_file_hash<1>(vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  _BYTE *v8; // eax
  _BYTE *v9; // eax
  bool v13; // [esp+Eh] [ebp-2h] BYREF
  bool do_debug_break; // [esp+Fh] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize(v2);
  v4 = (survarium::game_camera *)(unsigned __int8)*v3;
  if ( !*v3
    || `vostok::vfs::get_file_hash<1>'::`9'::debug_macro_helper_ignore_always
    || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)((node->m_flags & 1) == 1)),
        v4 = (survarium::game_camera *)(unsigned __int8)*v5,
        *v5) )
  {
    survarium::weapon_user_dead_state::finalize(v4);
    if ( !*v8
      || `vostok::vfs::get_file_hash<1>'::`26'::debug_macro_helper_ignore_always
      || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)node), *v9) )
    {
      if ( (node->m_flags & 0x40) == 0x40 )
      {
        if ( (node->m_flags & 0x10) == 0x10 )
          return vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node)->hash;
        else
          return vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node)->hash;
      }
      else if ( (node->m_flags & 0x10) == 0x10 )
      {
        return vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(node)->hash;
      }
      else
      {
        return vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(node)->hash;
      }
    }
    else
    {
      if ( `vostok::vfs::get_file_hash<1>'::`29'::occurances_left == -1 )
        `vostok::vfs::get_file_hash<1>'::`29'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v9);
      if ( `vostok::vfs::get_file_hash<1>'::`29'::occurances_left-- )
      {
        if ( !`vostok::vfs::get_file_hash<1>'::`26'::debug_macro_helper_ignore_always )
        {
          v13 = 0;
          vostok::debug::on_error(
            &v13,
            process_error_false,
            &`vostok::vfs::get_file_hash<1>'::`26'::debug_macro_helper_ignore_always,
            assert_untyped,
            "assertion_failed",
            "node->is_archive()",
            "c:\\survarium\\sources\\vostok\\vfs\\sources\\nodes.h",
            "vostok::vfs::get_file_hash",
            0x17Fu);
          if ( vostok::debug::is_debugger_present() || v13 )
            __debugbreak();
        }
      }
      return 0;
    }
  }
  else
  {
    if ( `vostok::vfs::get_file_hash<1>'::`12'::occurances_left == -1 )
      `vostok::vfs::get_file_hash<1>'::`12'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)v4);
    if ( `vostok::vfs::get_file_hash<1>'::`12'::occurances_left-- )
    {
      if ( !`vostok::vfs::get_file_hash<1>'::`9'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::vfs::get_file_hash<1>'::`9'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "!node->is_folder()",
          "c:\\survarium\\sources\\vostok\\vfs\\sources\\nodes.h",
          "vostok::vfs::get_file_hash",
          0x17Eu);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
