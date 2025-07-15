void __usercall vostok::shared_string::shared_string(vostok::shared_string *this@<esi>, const char *value@<eax>)
{
  vostok::strings::shared::profile *v2; // eax

  v2 = vostok::strings::shared::manager::string(s_manager.m_variable, s_manager.m_variable, value);
  this->m_pointer.m_object = 0;
  if ( v2 )
  {
    this->m_pointer.m_object = v2;
    _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
}
