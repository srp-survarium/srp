vostok::buffer_string *vostok::buffer_string::assignf(vostok::buffer_string *this, const char *format, ...)
{
  char *m_begin; // eax
  va_list argptr; // [esp+10h] [ebp+Ch] BYREF

  va_start(argptr, format);
  m_begin = this->m_begin;
  this->m_end = this->m_begin;
  *m_begin = 0;
  vostok::buffer_string::appendf_va_list(this, format, argptr);
  return this;
}
