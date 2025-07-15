char *__cdecl vostok::core::get_command_line()
{
  char *CommandLineA; // eax

  if ( !s_initialized_7 )
  {
    CommandLineA = GetCommandLineA();
    vostok::strings::copy<512>((char (*)[512])s_command_line, CommandLineA);
    s_initialized_7 = 1;
  }
  return s_command_line;
}
