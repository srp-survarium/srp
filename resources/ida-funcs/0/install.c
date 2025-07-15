void install()
{
  wchar_t *v0; // eax
  const char *v1; // eax
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  wchar_t *v4; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  char v7[216]; // [esp+8h] [ebp-288h] BYREF
  wchar_t v8[216]; // [esp+E0h] [ebp-1B0h] BYREF

  s_BT_InstallSehFilter();
  strcpy(
    v7,
    "This is Vostok Engine v0.20e crash reporting client. To help the development process, please Submit Bug or save repo"
    "rt and email it manually (button More...).\r\n"
    "Many thanks in advance and sorry for the inconvenience.");
  s_previous_handler = SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)unhandled_exception_handler_on_top_of_bugtrap);
  v0 = convert_to_unicode_if_needed(v8, v7, 216);
  s_BT_SetDialogMessage(BTDM_INTRO2, (const char *)v0);
  v1 = s_debug_engine->bugtrap_application_name(s_debug_engine);
  v2 = convert_to_unicode_if_needed(v8, v1, 216);
  s_BT_SetAppName((const char *)v2);
  v3 = convert_to_unicode_if_needed(v8, s_support_email, 216);
  s_BT_SetSupportEMail((const char *)v3);
  v4 = convert_to_unicode_if_needed(v8, s_support_url, 216);
  s_BT_SetSupportURL((const char *)v4);
  v5 = convert_to_unicode_if_needed(v8, s_support_server, 216);
  s_BT_SetSupportServer((const char *)v5, s_support_server_port);
  v6 = convert_to_unicode_if_needed(v8, s_application_version, 216);
  s_BT_SetAppVersion((const char *)v6);
  s_BT_SetReportFormat(BTRF_XML);
  s_BT_SetFlags(0x117u);
  s_BT_SetDumpType(0xFFFFFFFF);
}
