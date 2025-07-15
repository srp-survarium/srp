void __usercall vostok::variant<32>::operator=(
        vostok::variant<32> *this@<eax>,
        const vostok::variant<32> *other@<edi>,
        vostok::variant<32> *a3@<ecx>)
{
  if ( this != other )
  {
    vostok::variant<32>::destroy_previous_variable_if_needed(a3, (int)this);
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
