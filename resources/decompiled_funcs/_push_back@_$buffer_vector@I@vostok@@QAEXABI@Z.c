void __usercall vostok::buffer_vector<unsigned int>::push_back(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<eax>,
        const vostok::variant<32> **value@<edx>)
{
  const vostok::variant<32> **m_end; // ecx

  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}
