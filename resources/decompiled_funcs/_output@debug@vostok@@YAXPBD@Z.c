void __cdecl vostok::debug::output(const char *message)
{
  if ( !vostok::debug::g_disable_output_to_debugger )
    OutputDebugStringA(message);
}
