void __thiscall vostok::memory::reader::r(
        vostok::memory::reader *this,
        unsigned __int8 *destination,
        unsigned int destination_size,
        unsigned int size)
{
  memcpy(destination, (unsigned __int8 *)this->m_pointer, size);
  this->m_pointer += size;
}
