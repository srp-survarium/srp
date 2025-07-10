char __cdecl vostok::vfs::set_inline_data<1>(vostok::vfs::base_node<1> *node, const vostok::const_buffer *buffer)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  survarium::game_world *v5; // ecx
  _BYTE *v6; // eax
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  vostok::vfs::archive_inline_file_node<1> *inline_file; // [esp+20h] [ebp-Ch]
  vostok::vfs::archive_inline_compressed_file_node<1> *inline_compressed_file; // [esp+24h] [ebp-8h]
  bool do_debug_break; // [esp+2Bh] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  if ( !*v4
    || `vostok::vfs::set_inline_data<1>'::`9'::debug_macro_helper_ignore_always
    || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(node->m_flags & 0x40)), *v6) )
  {
    if ( (node->m_flags & 0x10) == 0x10 )
    {
      inline_compressed_file = vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node);
      survarium::weapon_user_dead_state::finalize(v9);
      inline_compressed_file->m_inlined_data.pointer = buffer->m_data;
      inline_compressed_file->m_inlined_size = buffer->m_size;
    }
    else
    {
      inline_file = vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node);
      survarium::weapon_user_dead_state::finalize(v10);
      inline_file->m_inlined_data.pointer = buffer->m_data;
      inline_file->m_inlined_size = buffer->m_size;
    }
    return 1;
  }
  else
  {
    if ( `vostok::vfs::set_inline_data<1>'::`12'::occurances_left == -1 )
      `vostok::vfs::set_inline_data<1>'::`12'::occurances_left = vostok::ui::ui_dialog::input_priority(v5);
    if ( `vostok::vfs::set_inline_data<1>'::`12'::occurances_left-- )
    {
      if ( !`vostok::vfs::set_inline_data<1>'::`9'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::vfs::set_inline_data<1>'::`9'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "node->is_inlined()",
          "c:\\survarium\\sources\\vostok\\vfs\\sources\\nodes.h",
          "vostok::vfs::set_inline_data",
          0x230u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
