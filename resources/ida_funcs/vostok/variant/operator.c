void __thiscall vostok::variant<32>::operator=(vostok::variant<32> *this, const vostok::variant<32> *other)
{
  vostok::detail::abstract_type_helper *m_helper; // ecx

  if ( this != other )
  {
    m_helper = this->m_helper;
    if ( m_helper )
    {
      m_helper->destroy(m_helper, this->m_storage);
      this->m_helper = 0;
    }
    this->m_type_id = other->m_type_id;
    if ( other->m_helper )
    {
      ((void (__thiscall *)(vostok::detail::abstract_type_helper *, char *, int, char *, int))other->m_helper->copy)(
        other->m_helper,
        this->m_storage,
        32,
        other->m_storage,
        32);
      this->m_helper = (vostok::detail::abstract_type_helper *)((int (__thiscall *)(vostok::detail::abstract_type_helper *, vostok::variant<32> *, int))other->m_helper->copy_helper)(
                                                                 other->m_helper,
                                                                 this,
                                                                 4);
    }
  }
}
