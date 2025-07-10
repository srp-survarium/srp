BOOL __cdecl vostok::command_line::show_help()
{
  if ( vostok::command_line::s_show_help.m_type == type_unset )
  {
    vostok::command_line::s_show_help.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  return vostok::command_line::s_show_help.m_type != type_recursive;
}
