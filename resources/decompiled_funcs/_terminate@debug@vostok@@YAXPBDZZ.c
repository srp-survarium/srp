void __noreturn vostok::debug::terminate(char *format, ...)
{
  vostok::debug::engine *v1; // eax
  int v2; // [esp+0h] [ebp-1010h]
  char destination[4096]; // [esp+8h] [ebp-1008h] BYREF
  int v4; // [esp+1008h] [ebp-8h]
  char *args; // [esp+100Ch] [ebp-4h]
  va_list va; // [esp+101Ch] [ebp+Ch] BYREF

  va_start(va, format);
  va_copy(args, va);
  vostok::vsprintf(format, va, destination, 0x1000u);
  if ( vostok::debug::debug_engine() )
  {
    v1 = vostok::debug::debug_engine();
    v2 = v1->get_exit_code(v1);
  }
  else
  {
    v2 = 1;
  }
  v4 = v2;
  terminate_impl((unsigned int)&loc_186A0 + v2, destination);
}
