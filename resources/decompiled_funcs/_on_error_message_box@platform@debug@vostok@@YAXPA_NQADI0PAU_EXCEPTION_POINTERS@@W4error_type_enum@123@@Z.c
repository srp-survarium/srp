void __cdecl vostok::debug::platform::on_error_message_box(
        bool *do_debug_break,
        char *const message,
        unsigned int message_size,
        bool *ignore_always,
        _EXCEPTION_POINTERS *exception_information,
        survarium::game_camera *error_type)
{
  survarium::game_camera *v6; // ecx
  _BYTE *v7; // eax
  HWND TopWindow; // eax
  unsigned int v9; // [esp+0h] [ebp-1Ch]

  survarium::weapon_user_dead_state::finalize(v6);
  if ( *v7 )
    survarium::weapon_user_dead_state::finalize(error_type);
  if ( do_debug_break )
    *do_debug_break = 0;
  v9 = strlen(message);
  sprintf_s(&message[v9], message_size - v9, "%s%sPress OK to abort execution%s", "\r\n", "\r\n", "\r\n");
  TopWindow = GetTopWindow(0);
  MessageBoxA(TopWindow, message, "Fatal Error", 0x1010u);
  vostok::debug::on_error(message);
}
