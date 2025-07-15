LRESULT __stdcall message_processor(HWND window_handle, UINT message_id, WPARAM w_param, HKL l_param)
{
  vostok::editor::engine_vtbl *v5; // eax

  switch ( message_id )
  {
    case 2u:
      PostQuitMessage(0);
      return 0;
    case 6u:
      if ( !(_WORD)w_param || HIWORD(w_param) )
      {
        s_world_5->on_application_deactivate(&s_world_5->vostok::editor::engine);
        v5 = s_world_5->vostok::editor::engine::__vftable;
        BYTE4(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[0]) = 1;
        v5->on_alttab(&s_world_5->vostok::editor::engine, 0);
        while ( ShowCursor(1) < 0 )
          ;
      }
      else
      {
        s_world_5->on_application_activate(&s_world_5->vostok::editor::engine);
        if ( BYTE4(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[0]) )
        {
          s_world_5->on_alttab(&s_world_5->vostok::editor::engine, 1);
          BYTE4(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[0]) = 0;
        }
        while ( ShowCursor(0) >= 0 )
          ;
      }
      return DefWindowProcA(window_handle, message_id, w_param, (LPARAM)l_param);
    case 8u:
      s_world_5->on_alttab(&s_world_5->vostok::editor::engine, 0);
      return DefWindowProcA(window_handle, message_id, w_param, (LPARAM)l_param);
    case 0x10u:
      if ( !s_world_5->m_destruction_started && !s_world_5->m_early_destruction_started )
      {
        s_world_5->terminate(&s_world_5->vostok::engine_user::engine, 0);
        return 1;
      }
      return DefWindowProcA(window_handle, message_id, w_param, (LPARAM)l_param);
    case 0x24u:
      DefWindowProcA(window_handle, 0x24u, w_param, (LPARAM)l_param);
      *((_DWORD *)l_param + 8) = 0x7FFFFFFF;
      *((_DWORD *)l_param + 9) = 0x7FFFFFFF;
      return 0;
  }
  if ( message_id != 81 )
  {
    if ( message_id == 274 )
    {
      if ( w_param != 61696 || HIWORD(l_param) )
        return DefWindowProcA(window_handle, 0x112u, w_param, (LPARAM)l_param);
      return 0;
    }
    return DefWindowProcA(window_handle, message_id, w_param, (LPARAM)l_param);
  }
  ActivateKeyboardLayout(l_param, 0x100u);
  return DefWindowProcA(window_handle, 0x51u, w_param, (LPARAM)l_param);
}
