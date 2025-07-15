void __cdecl vostok::command_line::handle_help_key()
{
  if ( vostok::command_line::s_show_help.m_type == type_unset )
  {
    vostok::command_line::s_show_help.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::command_line::s_show_help.m_type != type_recursive )
    vostok::command_line::show_help_and_exit();
}
