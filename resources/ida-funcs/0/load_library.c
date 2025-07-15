void load_library()
{
  const char *v1; // eax
  HMODULE LibraryA; // eax

  if ( s_bugtrap_handle )
    return;
  v1 = "BugTrap.dll";
  if ( s_bugtrap_usage != native_bugtrap )
    v1 = "BugTrapN.dll";
  LibraryA = LoadLibraryA(v1);
  s_bugtrap_handle = LibraryA;
  if ( !LibraryA )
  {
    if ( (s_log_disable_counter == 0 ? (unsigned int)s_log_callback : 0) != 0 )
      ((void (__cdecl *)(const char *, int, _DWORD, const char *))(s_log_disable_counter == 0
                                                                 ? (unsigned int)s_log_callback
                                                                 : 0))(
        "debug:bugtrap",
        1,
        0,
        "cannot load bugtrap library");
    s_bugtrap_usage = no_bugtrap;
    return;
  }
  if ( s_bugtrap_usage )
  {
    s_BT_CallCppFilter = (void (__cdecl *)())GetProcAddress(LibraryA, "BT_CallCppFilter");
    if ( !s_BT_CallCppFilter )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    s_BT_CallCppFilter = 0;
  }
  load_function_void___stdcall_char_const____(&s_BT_SetUserMessage, (HINSTANCE__ *const)&module);
  if ( s_bugtrap_usage )
  {
    s_BT_InstallSehFilter = (int (__stdcall *(__stdcall *)())(_EXCEPTION_POINTERS *))GetProcAddress(
                                                                                       s_bugtrap_handle,
                                                                                       "BT_InstallSehFilter");
    if ( !s_BT_InstallSehFilter )
      s_bugtrap_usage = no_bugtrap;
    if ( s_bugtrap_usage )
    {
      s_BT_SetDialogMessage = (void (__stdcall *)(BUGTRAP_DIALOGMESSAGE_tag, const char *))GetProcAddress(
                                                                                             s_bugtrap_handle,
                                                                                             "BT_SetDialogMessage");
      if ( !s_BT_SetDialogMessage )
        s_bugtrap_usage = no_bugtrap;
      goto LABEL_20;
    }
  }
  else
  {
    s_BT_InstallSehFilter = 0;
  }
  s_BT_SetDialogMessage = 0;
LABEL_20:
  load_function_void___stdcall_char_const____(&s_BT_SetAppName, (HINSTANCE__ *const)&stru_807FCC);
  if ( s_bugtrap_usage )
  {
    s_BT_SetReportFormat = (void (__stdcall *)(BUGTRAP_REPORTFORMAT_tag))GetProcAddress(
                                                                           s_bugtrap_handle,
                                                                           "BT_SetReportFormat");
    if ( !s_BT_SetReportFormat )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    s_BT_SetReportFormat = 0;
  }
  load_function_void___stdcall_char_const____(
    (void (__stdcall **)(const char *))&s_BT_SetFlags,
    (HINSTANCE__ *const)&stru_807FF0);
  load_function_void___stdcall_char_const____(
    (void (__stdcall **)(const char *))&s_BT_SetDumpType,
    (HINSTANCE__ *const)&stru_807FFC);
  load_function_void___stdcall_char_const____(&s_BT_SetSupportEMail, (HINSTANCE__ *const)&stru_80800C);
  load_function_void___stdcall_char_const____(&s_BT_SetSupportURL, (HINSTANCE__ *const)&stru_808020);
  if ( s_bugtrap_usage )
  {
    s_BT_SetSupportServer = (void (__stdcall *)(const char *, __int16))GetProcAddress(
                                                                         s_bugtrap_handle,
                                                                         "BT_SetSupportServer");
    if ( !s_BT_SetSupportServer )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    s_BT_SetSupportServer = 0;
  }
  load_function_void___stdcall_char_const____(&s_BT_SetAppVersion, (HINSTANCE__ *const)&stru_808048);
  if ( s_bugtrap_usage )
  {
    s_BT_SetActivityType = (void (__stdcall *)(BUGTRAP_ACTIVITY_tag))GetProcAddress(
                                                                       s_bugtrap_handle,
                                                                       "BT_SetActivityType");
    if ( !s_BT_SetActivityType )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    s_BT_SetActivityType = 0;
  }
  load_function_void___stdcall_char_const____(&s_BT_AddLogFile, (HINSTANCE__ *const)&stru_808070);
  load_function_void___stdcall_char_const____(&s_BT_SetReportFilePath, (HINSTANCE__ *const)&stru_808080);
}
