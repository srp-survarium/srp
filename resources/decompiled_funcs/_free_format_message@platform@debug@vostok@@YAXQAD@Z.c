void __cdecl vostok::debug::platform::free_format_message(char *const buffer)
{
  LocalFree(buffer);
}
