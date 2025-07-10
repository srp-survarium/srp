void __thiscall vostok::fixed_string<260>::fixed_string<260>(vostok::fixed_string<260> *this, const char *src)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}
