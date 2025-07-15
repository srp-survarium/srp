BOOL __thiscall vostok::command_line::key::is_set(vostok::command_line::key *this)
{
  if ( this->m_type == type_unset )
  {
    this->m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  return this->m_type != type_recursive;
}
