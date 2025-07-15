char __usercall vostok::command_line::key::is_set_as_string@<al>(
        vostok::command_line::key *this@<ecx>,
        vostok::command_line::key *out_value@<eax>)
{
  char *m_begin; // eax
  unsigned __int8 *v6; // eax
  unsigned int v7; // edi

  if ( this->m_type == type_unset )
  {
    this->m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( this->m_type == type_recursive )
    return 0;
  if ( out_value )
  {
    if ( out_value != this )
    {
      m_begin = out_value->m_string_value.m_begin;
      out_value->m_string_value.m_end = out_value->m_string_value.m_begin;
      *m_begin = 0;
      v6 = (unsigned __int8 *)this->m_string_value.m_begin;
      v7 = this->m_string_value.m_end - this->m_string_value.m_begin;
      memcpy((unsigned __int8 *)out_value->m_string_value.m_end, v6, v7);
      out_value->m_string_value.m_end += v7;
      *out_value->m_string_value.m_end = 0;
    }
  }
  return 1;
}
