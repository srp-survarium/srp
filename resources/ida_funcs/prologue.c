void __cdecl prologue(_EXCEPTION_POINTERS *const exception_information)
{
  vostok::debug::engine *v1; // eax
  vostok::debug::engine *v2; // [esp+4h] [ebp-11Ch]
  _SYSTEMTIME date_time; // [esp+8h] [ebp-118h] BYREF
  char log_file_name[260]; // [esp+18h] [ebp-108h] BYREF

  vostok::debug::platform::format_message();
  GetLocalTime(&date_time);
  vostok::debug::platform::prologue_dump_call_stack(exception_information);
  v2 = vostok::debug::debug_engine();
  v2->generate_debug_file_name(v2, (char (*)[260])log_file_name, &date_time, "error_report", ".log");
  v1 = vostok::debug::debug_engine();
  v1->flush_log_file(v1, log_file_name);
  vostok::debug::bugtrap::add_file(log_file_name);
  vostok::debug::platform::save_minidump(&date_time, exception_information);
  vostok::debug::bugtrap::restart_application_on_crash(0);
}
