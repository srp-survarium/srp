void __cdecl vostok::debug::platform::save_minidump(
        const _SYSTEMTIME *date_time,
        _EXCEPTION_POINTERS *exception_information)
{
  vostok::debug::engine *v2; // eax
  char temp[260]; // [esp+4h] [ebp-210h] BYREF
  char minidump_file_name[264]; // [esp+10Ch] [ebp-108h] BYREF

  v2 = vostok::debug::debug_engine();
  v2->generate_debug_file_name(v2, (char (*)[260])temp, date_time, "error_report", ".dmp");
  strcpy_s(minidump_file_name, 0x104u, temp);
  save_minidump(minidump_file_name, exception_information);
  vostok::debug::bugtrap::add_file(minidump_file_name);
}
