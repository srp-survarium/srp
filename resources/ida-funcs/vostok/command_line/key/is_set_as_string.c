char __userpurge vostok::command_line::key::is_set_as_string@<al>(
        vostok::command_line::key *this@<ecx>,
        vostok::buffer_string *a2@<edi>,
        vostok::buffer_string *out_value)
{
  if ( !a2[45].m_max_end )
    vostok::command_line::key::initialize(this, (int)a2);
  if ( a2[45].m_max_end == (char *)1 )
    return 0;
  if ( out_value )
    vostok::buffer_string::operator=(a2, out_value);
  return 1;
}
