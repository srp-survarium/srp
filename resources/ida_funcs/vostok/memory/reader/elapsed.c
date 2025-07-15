const unsigned __int8 *__thiscall vostok::memory::reader::elapsed(vostok::memory::reader *this)
{
  return &this->m_data[this->m_size - (unsigned int)this->m_pointer];
}
