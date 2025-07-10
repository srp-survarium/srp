bool __thiscall vostok::engine::engine_world::command_line_no_splash_screen(vostok::engine::engine_world *this)
{
  if ( vostok::command_line::s_show_help.m_type == type_unset )
  {
    vostok::command_line::s_show_help.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  return vostok::command_line::s_show_help.m_type != type_recursive
      || vostok::testing::run_tests_command_line((vostok::command_line::key *)this)
      || vostok::command_line::key::is_set(&s_no_splash_screen_key);
}
