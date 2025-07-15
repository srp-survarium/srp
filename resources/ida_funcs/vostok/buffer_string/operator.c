const vostok::fixed_string<32> *__usercall vostok::buffer_string::operator=@<eax>(
        vostok::fixed_string<32> *this@<ecx>,
        vostok::fixed_string<32> *a2@<esi>)
{
  char *m_begin; // eax
  unsigned int v3; // edi

  if ( a2 != this )
  {
    m_begin = a2->m_begin;
    a2->m_end = a2->m_begin;
    *m_begin = 0;
    v3 = this->m_end - this->m_begin;
    memcpy((unsigned __int8 *)a2->m_end, (unsigned __int8 *)this->m_begin, v3);
    a2->m_end += v3;
    *a2->m_end = 0;
  }
  return a2;
}


const vostok::buffer_string *__thiscall vostok::buffer_string::operator=(vostok::buffer_string *this, const char *s)
{
  char *m_begin; // eax

  m_begin = this->m_begin;
  this->m_end = this->m_begin;
  *m_begin = 0;
  return vostok::buffer_string::operator+=(this, s);
}


char *__thiscall vostok::buffer_string::operator[](vostok::buffer_string *this, unsigned int i)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  return &this->m_begin[i];
}


const vostok::buffer_string *__thiscall vostok::buffer_string::operator+=(vostok::buffer_string *this, const char *s)
{
  const vostok::buffer_string *result; // eax
  const char *v3; // ecx
  char i; // dl
  char *m_end; // esi

  result = this;
  v3 = s;
  if ( s )
  {
    for ( i = *s; i; i = *++v3 )
    {
      m_end = result->m_end;
      if ( m_end >= result->m_max_end )
        break;
      *m_end = i;
      ++result->m_end;
    }
    *result->m_end = 0;
  }
  return result;
}
