void __userpurge vostok::command_line::key_initializator::operator()(
        vostok::command_line::key *const command_line_key@<esi>,
        char *key_name,
        char *key_value)
{
  if ( !vostok::strings::compare(command_line_key->m_full_name, key_name)
    || !vostok::strings::compare(command_line_key->m_short_name, key_name) )
  {
    vostok::command_line::key::initialize(key_value, command_line_key);
  }
}
