void __usercall vostok::variant<32>::set<vostok::configs::binary_config_value>(
        vostok::variant<32> *this@<esi>,
        const vostok::configs::binary_config_value *value@<edi>)
{
  vostok::detail::abstract_type_helper *m_helper; // ecx

  m_helper = this->m_helper;
  if ( m_helper )
  {
    m_helper->destroy(m_helper, this->m_storage);
    this->m_helper = 0;
  }
  this->m_type_id = vostok::detail::type_to_int<vostok::configs::binary_config_value>::get();
  if ( this != (vostok::variant<32> *)-8 )
    *(vostok::configs::binary_config_value *)this->m_storage = *value;
  this->m_helper = (vostok::detail::abstract_type_helper *)this;
  *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::`vftable';
}
