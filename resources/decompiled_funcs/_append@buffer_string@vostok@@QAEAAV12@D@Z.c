vostok::buffer_string *__thiscall vostok::buffer_string::append(vostok::buffer_string *this, char c)
{
  vostok::buffer_string *result; // eax

  result = this;
  *this->m_end++ = c;
  *this->m_end = 0;
  return result;
}
