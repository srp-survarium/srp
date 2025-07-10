void __userpurge vostok::command_line::key_initializator::operator()(
        vostok::command_line::key *const command_line_key@<edi>,
        const char *key_name@<esi>,
        const char *key_value)
{
  if ( !strcmp(command_line_key->m_full_name, key_name) || !strcmp(command_line_key->m_short_name, key_name) )
    vostok::command_line::key::initialize(command_line_key, key_value);
}
