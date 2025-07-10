void load_library_0()
{
  HMODULE LibraryA; // eax
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+4h] [ebp-4h]

  if ( !s_bugtrap_handle )
  {
    if ( s_bugtrap_usage == native_bugtrap )
      LibraryA = LoadLibraryA(s_bugtrap_native_id);
    else
      LibraryA = LoadLibraryA(s_bugtrap_dotnet_id);
    s_bugtrap_handle = LibraryA;
    if ( LibraryA )
    {
      load_function_void___cdecl_void__(&s_BT_CallCppFilter, s_bugtrap_handle, "BT_CallCppFilter");
      load_function_void___stdcall_char_const____(&s_BT_SetUserMessage, s_bugtrap_handle, "BT_SetUserMessage");
      load_function_long____stdcall___stdcall_void____EXCEPTION_POINTERS____(
        &s_BT_InstallSehFilter,
        s_bugtrap_handle,
        "BT_InstallSehFilter");
      load_function_void___stdcall_enum_BUGTRAP_DIALOGMESSAGE_tag_char_const____(
        &s_BT_SetDialogMessage,
        s_bugtrap_handle,
        "BT_SetDialogMessage");
      load_function_void___stdcall_char_const____(&s_BT_SetAppName, s_bugtrap_handle, "BT_SetAppName");
      load_function_void___stdcall_enum_BUGTRAP_REPORTFORMAT_tag__(
        &s_BT_SetReportFormat,
        s_bugtrap_handle,
        "BT_SetReportFormat");
      load_function_void___stdcall_unsigned_long__(&s_BT_SetFlags, s_bugtrap_handle, "BT_SetFlags");
      load_function_void___stdcall_unsigned_long__(&s_BT_SetDumpType, s_bugtrap_handle, "BT_SetDumpType");
      load_function_void___stdcall_char_const____(&s_BT_SetSupportEMail, s_bugtrap_handle, "BT_SetSupportEMail");
      load_function_void___stdcall_enum_BUGTRAP_ACTIVITY_tag__(
        &s_BT_SetActivityType,
        s_bugtrap_handle,
        "BT_SetActivityType");
      load_function_void___stdcall_char_const____(&s_BT_AddLogFile, s_bugtrap_handle, "BT_AddLogFile");
      load_function_void___stdcall_char_const____(&s_BT_SetReportFilePath, s_bugtrap_handle, "BT_SetReportFilePath");
    }
    else
    {
      log_callback = vostok::debug::get_log_callback();
      if ( log_callback )
        log_callback("debug:bugtrap", 1, 0, "cannot load bugtrap library");
      s_bugtrap_usage = no_bugtrap;
    }
  }
}
