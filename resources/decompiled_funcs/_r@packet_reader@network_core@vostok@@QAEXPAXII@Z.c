void __userpurge vostok::network_core::packet_reader::r(
        vostok::network_core::packet_reader *this@<esi>,
        unsigned int size@<edi>,
        unsigned __int8 *destination,
        unsigned int destination_size)
{
  unsigned int v4; // [esp+0h] [ebp-4h]

  memcpy(destination, (unsigned __int8 *)this->m_pointer, v4);
  this->m_pointer += size;
}
