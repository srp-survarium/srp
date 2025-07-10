void install()
{
  wchar_t *v0; // eax
  vostok::debug::engine *v1; // eax
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  char message[216]; // [esp+Ch] [ebp-290h] BYREF
  wchar_t unicode_message[214]; // [esp+E4h] [ebp-1B8h] BYREF
  const char *bugtrap_application_name; // [esp+298h] [ebp-4h]

  s_BT_InstallSehFilter();
  vostok::debug::bugtrap::setup_unhandled_exception_handler();
  strcpy(
    message,
    "This is Vostok Engine v0.1 crash reporting client. To help the development process, please Submit Bug or save report"
    " and email it manually (button More...).\r\n"
    "Many thanks in advance and sorry for the inconvenience.");
  v0 = convert_to_unicode_if_needed_214_(message, (wchar_t (*)[214])unicode_message);
  s_BT_SetDialogMessage(BTDM_INTRO2, (const char *)v0);
  v1 = vostok::debug::debug_engine();
  bugtrap_application_name = v1->bugtrap_application_name(v1);
  v2 = convert_to_unicode_if_needed_214_(bugtrap_application_name, (wchar_t (*)[214])unicode_message);
  s_BT_SetAppName((const char *)v2);
  v3 = convert_to_unicode_if_needed_214_(s_support_email, (wchar_t (*)[214])unicode_message);
  s_BT_SetSupportEMail((const char *)v3);
  s_BT_SetReportFormat(BTRF_TEXT);
  s_BT_SetFlags(5u);
  s_BT_SetDumpType(0xFFFFFFFF);
}
