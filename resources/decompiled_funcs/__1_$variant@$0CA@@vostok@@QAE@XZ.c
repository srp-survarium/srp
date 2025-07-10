void __thiscall vostok::variant<32>::~variant<32>(vostok::variant<32> *this)
{
  vostok::detail::abstract_type_helper *m_helper; // ecx

  m_helper = this->m_helper;
  if ( m_helper )
  {
    m_helper->destroy(m_helper, this->m_storage);
    this->m_helper = 0;
  }
}
