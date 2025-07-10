void __thiscall vostok::buffer_vector<vostok::variant<32>>::clear(vostok::buffer_vector<vostok::variant<32> > *this)
{
  vostok::variant<32> **p_m_end; // edi

  p_m_end = &this->m_end;
  vostok::buffer_vector<vostok::variant<32>>::destroy(this->m_begin, &this->m_end);
  *p_m_end = this->m_begin;
}
