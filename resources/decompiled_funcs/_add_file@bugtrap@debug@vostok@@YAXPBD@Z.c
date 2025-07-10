void __cdecl vostok::debug::bugtrap::add_file(const char *full_path_file_name)
{
  wchar_t *v1; // eax
  wchar_t unicode_path[260]; // [esp+0h] [ebp-208h] BYREF

  if ( s_bugtrap_usage )
  {
    v1 = convert_to_unicode_if_needed_260_(full_path_file_name, (wchar_t (*)[260])unicode_path);
    s_BT_AddLogFile((const char *)v1);
  }
}
