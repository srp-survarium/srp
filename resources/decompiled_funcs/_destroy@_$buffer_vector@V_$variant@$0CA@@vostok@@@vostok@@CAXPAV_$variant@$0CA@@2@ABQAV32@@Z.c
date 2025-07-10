void __usercall vostok::buffer_vector<vostok::variant<32>>::destroy(
        vostok::variant<32> *begin@<eax>,
        vostok::variant<32> **end@<edi>)
{
  vostok::variant<32> *i; // esi
  vostok::detail::abstract_type_helper *m_helper; // ecx

  for ( i = begin; i != *end; ++i )
  {
    m_helper = i->m_helper;
    if ( m_helper )
    {
      m_helper->destroy(m_helper, i->m_storage);
      i->m_helper = 0;
    }
  }
}
