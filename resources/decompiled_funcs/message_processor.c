int __stdcall message_processor(HWND__ *window_handle, UINT message_id, WPARAM w_param, HKL l_param)
{
  int result; // eax

  switch ( message_id )
  {
    case 2u:
      PostQuitMessage(0);
      return 0;
    case 6u:
      if ( !(_WORD)w_param || HIWORD(w_param) )
      {
        s_world_4->on_application_deactivate(&s_world_4->vostok::editor::engine);
        s_deactivated = 1;
        while ( ShowCursor(1) < 0 )
          ;
      }
      else
      {
        s_world_4->on_application_activate(&s_world_4->vostok::editor::engine);
        if ( s_deactivated )
        {
          s_world_4->on_fullscreen_alttab(&s_world_4->vostok::editor::engine, 1);
          s_deactivated = 0;
        }
        while ( ShowCursor(0) >= 0 )
          ;
      }
      goto LABEL_11;
    case 0x10u:
      if ( s_world_4->m_destruction_started || s_world_4->m_early_destruction_started )
        goto LABEL_11;
      s_world_4->exit(s_world_4, s_world_4->m_destruction_started);
      result = 1;
      break;
    case 0x51u:
      ActivateKeyboardLayout(l_param, 0x100u);
      return DefWindowProcA(window_handle, message_id, w_param, (LPARAM)l_param);
    default:
LABEL_11:
      result = DefWindowProcA(window_handle, message_id, w_param, (LPARAM)l_param);
      break;
  }
  return result;
}
