void __userpurge vostok::buffer_vector<vostok::variant<32> const *>::buffer_vector<vostok::variant<32> const *>(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<eax>,
        const vostok::variant<32> **buffer@<ecx>,
        const vostok::variant<32> **value@<esi>,
        unsigned int max_count,
        unsigned int count)
{
  const vostok::variant<32> **v5; // edx

  v5 = &buffer[max_count];
  this->m_begin = buffer;
  for ( this->m_end = v5; buffer != this->m_end; ++buffer )
  {
    if ( buffer )
      *buffer = *value;
  }
}
