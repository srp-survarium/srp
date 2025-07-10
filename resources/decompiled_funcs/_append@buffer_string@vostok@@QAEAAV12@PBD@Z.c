vostok::buffer_string *__thiscall vostok::buffer_string::append(vostok::buffer_string *this, char *c_string)
{
  unsigned int v3; // edi

  v3 = strlen(c_string);
  memcpy((unsigned __int8 *)this->m_end, (unsigned __int8 *)c_string, v3);
  this->m_end += v3;
  *this->m_end = 0;
  return this;
}
