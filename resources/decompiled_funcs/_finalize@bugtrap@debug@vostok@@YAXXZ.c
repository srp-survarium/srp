void __cdecl vostok::debug::bugtrap::finalize()
{
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+0h] [ebp-4h]

  if ( s_bugtrap_usage )
  {
    if ( s_initialized_2 )
    {
      s_BT_CallCppFilter = 0;
      s_BT_SetUserMessage = 0;
      s_BT_InstallSehFilter = 0;
      s_BT_SetDialogMessage = 0;
      s_BT_SetAppName = 0;
      s_BT_SetReportFormat = 0;
      s_BT_SetFlags = 0;
      s_BT_SetDumpType = 0;
      s_BT_SetSupportEMail = 0;
      FreeLibrary(s_bugtrap_handle);
      s_initialized_2 = 0;
    }
    else
    {
      log_callback = vostok::debug::get_log_callback();
      if ( log_callback )
        log_callback("debug::bugtrap", 1, 0, "you cannot finalize bugtrap library usage until you initialize it");
    }
  }
}
