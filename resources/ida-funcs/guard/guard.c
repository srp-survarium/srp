guard *__thiscall guard::guard(guard *this, guard *a2)
{
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  survarium::application *v4; // ecx
  wchar_t *v5; // eax
  wchar_t output[64]; // [esp+8h] [ebp-80h] BYREF

  *(_DWORD *)&s_application.m_static_memory[4] = &survarium::game_module_proxy::`vftable';
  _InterlockedExchange(&s_application.m_initialized, 1);
  strcpy_s(s_support_email, 0x40u, "game_crash_reports@survarium.com");
  if ( s_BT_SetSupportEMail )
  {
    v2 = convert_to_unicode_if_needed(output, s_support_email, 64);
    s_BT_SetSupportEMail((const char *)v2);
  }
  strcpy_s(s_support_url, 0x40u, "http://support.survarium.com");
  if ( s_BT_SetSupportURL )
  {
    v3 = convert_to_unicode_if_needed(output, s_support_url, 64);
    s_BT_SetSupportURL((const char *)v3);
  }
  strcpy_s(s_support_server, 0x40u, "http://crasheat.survarium.com/process.php");
  s_support_server_port = 80;
  if ( s_BT_SetSupportServer )
  {
    v5 = convert_to_unicode_if_needed(output, s_support_server, 64);
    s_BT_SetSupportServer((const char *)v5, s_support_server_port);
  }
  survarium::application::initialize(v4, (int)s_application.m_variable);
  return a2;
}
