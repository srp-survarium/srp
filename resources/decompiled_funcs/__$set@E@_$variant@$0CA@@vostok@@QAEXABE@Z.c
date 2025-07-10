void __thiscall vostok::variant<32>::set<unsigned char>(vostok::variant<32> *this, const unsigned __int8 *value)
{
  vostok::detail::abstract_type_helper *v2; // [esp+0h] [ebp-14h]

  vostok::variant<32>::~variant<32>(this);
  this->m_type_id = vostok::detail::type_to_int<unsigned char>::get();
  if ( this != (vostok::variant<32> *)-8 )
    this->m_storage[0] = *value;
  if ( this )
  {
    *(_DWORD *)this->m_helper_storage = &vostok::detail::abstract_type_helper::`vftable';
    *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<unsigned char>::`vftable';
    v2 = (vostok::detail::abstract_type_helper *)this;
  }
  else
  {
    v2 = 0;
  }
  this->m_helper = v2;
}
