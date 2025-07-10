void __usercall vostok::fixed_string<128>::fixed_string<128>(
        vostok::fixed_string<128> *this@<esi>,
        const char *src@<edx>)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}
