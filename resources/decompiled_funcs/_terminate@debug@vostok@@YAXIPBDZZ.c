void __noreturn vostok::debug::terminate(unsigned int exit_code, char *format, ...)
{
  char destination[4100]; // [esp+0h] [ebp-1008h] BYREF
  char *args; // [esp+1004h] [ebp-4h]
  va_list va; // [esp+1018h] [ebp+10h] BYREF

  va_start(va, format);
  va_copy(args, va);
  vostok::vsprintf(format, va, destination, 0x1000u);
  terminate_impl((unsigned int)&loc_186A0 + exit_code, destination);
}
