// bad sp value at call has been detected, the output may be wrong!
void __cdecl process_0(
        bool *do_debug_break,
        vostok::process_error_enum process_error,
        bool *ignore_always,
        const char *assert_type,
        const char *reason,
        char *expression,
        const char *description,
        const char *file,
        const char *function)
{
  DWORD CurrentThreadId; // edi
  void *v10; // esp
  char v11[8192]; // [esp-2000h] [ebp-200Ch] BYREF

  if ( s_process_lock_thread_id == GetCurrentThreadId() )
  {
    ++s_process_lock_count;
  }
  else
  {
    CurrentThreadId = GetCurrentThreadId();
    while ( InterlockedCompareExchange(&s_process_lock_thread_id, CurrentThreadId, 0) )
    {
      if ( !SwitchToThread() )
        Sleep(0);
    }
    s_process_lock_count = 1;
  }
  v10 = alloca(0x2000);
  v11[0] = 0;
  _LN17_0(v11, 0x2000u, (char *)uri);
  _LN17_0(v11, 0x2000u, "Error occurred : %s", assert_type);
  _LN17_0(v11, 0x2000u, "Expression    : %s", reason);
  if ( expression )
    _LN17_0(v11, 0x2000u, "Description   : %s", expression);
  _LN17_0(v11, 0x2000u, "File          : %s", description);
  _LN17_0(v11, 0x2000u, "Line          : %d", function);
  _LN17_0(v11, 0x2000u, "Function      : %s", file);
  if ( s_debug_engine->is_testing(s_debug_engine) )
  {
    s_debug_engine->on_testing_exception(s_debug_engine, (vostok::assert_enum)ignore_always, v11, 0, 1);
  }
  else if ( process_error )
  {
    if ( process_error == process_error_to_message_box )
      strcpy_s(v11, 0x2000u, expression);
    on_error(v11, (char *)0x2000, process_error, do_debug_break);
  }
  if ( !--s_process_lock_count )
    InterlockedExchange(&s_process_lock_thread_id, 0);
}
