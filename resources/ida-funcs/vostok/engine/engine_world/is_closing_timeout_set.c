BOOL __thiscall vostok::engine::engine_world::is_closing_timeout_set(vostok::engine::engine_world *this)
{
  if ( s_terminate_on_timeout_key.m_type == type_unset )
  {
    s_terminate_on_timeout_key.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  return s_terminate_on_timeout_key.m_type != type_recursive;
}
