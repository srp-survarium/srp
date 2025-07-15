bool __thiscall vostok::network_core::sequence_number<unsigned short>::operator<(
        vostok::network_core::sequence_number<unsigned short> *this,
        const vostok::network_core::sequence_number<unsigned short> *other)
{
  return this->m_number < (int)other->m_number && (unsigned int)this->m_number + 0x8000 > other->m_number
      || other->m_number < (int)this->m_number && (unsigned int)other->m_number + 0x8000 <= this->m_number;
}


bool __thiscall vostok::network_core::sequence_number<unsigned short>::operator<=(
        vostok::network_core::sequence_number<unsigned short> *this,
        const vostok::network_core::sequence_number<unsigned short> *other)
{
  return this->m_number <= (int)other->m_number && (unsigned int)this->m_number + 0x8000 > other->m_number
      || other->m_number < (int)this->m_number && (unsigned int)other->m_number + 0x8000 <= this->m_number;
}
