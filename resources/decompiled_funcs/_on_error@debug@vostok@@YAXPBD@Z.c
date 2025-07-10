void __cdecl vostok::debug::on_error(const char *message)
{
  survarium::game_camera *v1; // ecx
  void *v2; // esp
  wchar_t *v3; // eax
  _DWORD v4[4]; // [esp+0h] [ebp-1Ch] BYREF
  const char *v5; // [esp+10h] [ebp-Ch]
  wchar_t *unicode_message; // [esp+14h] [ebp-8h]
  unsigned int count; // [esp+18h] [ebp-4h]

  if ( !vostok::debug::bugtrap::initialized() )
    vostok::debug::bugtrap::initialize(v1);
  if ( s_bugtrap_usage == native_bugtrap )
  {
    v5 = message;
    v4[3] = message + 1;
    v5 += strlen(v5) + 1;
    v4[1] = v5 - (message + 1);
    count = v5 - message;
    v2 = alloca(2 * (v5 - message));
    v4[0] = v4;
    unicode_message = (wchar_t *)v4;
    v3 = convert_to_unicode_if_needed(message, (wchar_t *const)v4, v5 - message);
    s_BT_SetUserMessage((const char *)v3);
  }
  set_show_dialog_for_unhandled_exceptions(0);
}
