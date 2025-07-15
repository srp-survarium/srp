int __cdecl vostok::vfs::get_file_offs<1>(const vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax
  _BYTE *v4; // eax
  __int64 v6; // rax
  survarium::game_camera *v7; // ecx
  _BYTE *v8; // eax
  survarium::game_world *v9; // ecx
  _BYTE *v10; // eax
  const vostok::vfs::archive_compressed_file_node<1> *v12; // eax
  bool v14; // [esp+Fh] [ebp-9h] BYREF
  bool do_debug_break; // [esp+17h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( !*v3
    || `vostok::vfs::get_file_offs<1>'::`9'::debug_macro_helper_ignore_always
    || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)((node->m_flags & 1) == 1)), *v4) )
  {
    if ( (node->m_flags & 0x2000) == 0x2000 )
    {
      return vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node)->offs;
    }
    else if ( (node->m_flags & 4) == 4 )
    {
      v7 = (survarium::game_camera *)(node->m_flags & 0x1000);
      if ( v7 == (survarium::game_camera *)4096 )
      {
        LODWORD(v6) = 0;
      }
      else
      {
        survarium::weapon_user_dead_state::finalize(v7);
        if ( !*v8
          || `vostok::vfs::get_file_offs<1>'::`33'::debug_macro_helper_ignore_always
          || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)((node->m_flags & 0x40) != 64)), *v10) )
        {
          if ( (node->m_flags & 0x10) == 0x10 )
            v12 = vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(node);
          else
            v12 = (const vostok::vfs::archive_compressed_file_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(node);
          LODWORD(v6) = v12->pos_in_db;
        }
        else
        {
          if ( `vostok::vfs::get_file_offs<1>'::`36'::occurances_left == -1 )
            `vostok::vfs::get_file_offs<1>'::`36'::occurances_left = vostok::ui::ui_dialog::input_priority(v9);
          if ( `vostok::vfs::get_file_offs<1>'::`36'::occurances_left-- )
          {
            if ( !`vostok::vfs::get_file_offs<1>'::`33'::debug_macro_helper_ignore_always )
            {
              v14 = 0;
              vostok::debug::on_error(
                &v14,
                process_error_false,
                &`vostok::vfs::get_file_offs<1>'::`33'::debug_macro_helper_ignore_always,
                assert_untyped,
                "assertion_failed",
                "!node->is_inlined()",
                "c:\\survarium\\sources\\vostok\\vfs\\sources\\nodes.h",
                "vostok::vfs::get_file_offs",
                0x1D4u,
                "you should not call get_file_offs over inline node");
              if ( vostok::debug::is_debugger_present() || v14 )
                __debugbreak();
            }
          }
          LODWORD(v6) = 0;
        }
      }
    }
    else
    {
      LODWORD(v6) = 0;
    }
  }
  else
  {
    if ( `vostok::vfs::get_file_offs<1>'::`12'::occurances_left == -1 )
      `vostok::vfs::get_file_offs<1>'::`12'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::vfs::get_file_offs<1>'::`12'::occurances_left-- )
    {
      if ( !`vostok::vfs::get_file_offs<1>'::`9'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::vfs::get_file_offs<1>'::`9'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "!node->is_folder()",
          "c:\\survarium\\sources\\vostok\\vfs\\sources\\nodes.h",
          "vostok::vfs::get_file_offs",
          0x1C6u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    LODWORD(v6) = 0;
  }
  return v6;
}
