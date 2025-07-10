char *__cdecl vostok::debug::platform::fill_format_message(int error_code)
{
  char *result; // [esp+0h] [ebp-4h] BYREF

  FormatMessageA(0x1100u, 0, error_code, 0, (LPSTR)&result, 0, 0);
  return result;
}
