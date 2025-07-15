void __usercall vostok::command_line::key::initialize(vostok::command_line::key *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 548) = 1;
  vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
}


void __userpurge vostok::command_line::key::initialize(char *value@<eax>, vostok::command_line::key *this)
{
  char *m_begin; // eax
  int v4; // eax

  if ( value && *value )
  {
    m_begin = this->m_string_value.m_begin;
    if ( this->m_string_value.m_begin != value )
    {
      this->m_string_value.m_end = m_begin;
      *m_begin = 0;
      vostok::buffer_string::operator+=(&this->m_string_value, value);
    }
    strchr(value, 0x3Au);
    if ( v4 )
      this->m_type = type_string;
    else
      this->m_type = 4 - vostok::strings::convert_string_to_number(value, &this->m_number_value);
  }
  else
  {
    this->m_type = type_void;
  }
}
