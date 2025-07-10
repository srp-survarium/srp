void __cdecl __noreturn terminate_impl(unsigned int exit_code, const char *message)
{
  vostok::debug::engine *v2; // [esp+Ch] [ebp-1Ch]

  v2 = vostok::debug::debug_engine();
  v2->on_terminate(v2);
  vostok::debug::platform::terminate(message, exit_code);
}
