void __thiscall vostok::variant<32>::set<unsigned short>(vostok::variant<32> *this, const unsigned __int16 *value)
{
  vostok::detail::abstract_type_helper *v2; // ecx
  vostok::detail::abstract_type_helper *v3; // [esp+0h] [ebp-14h]
  vostok::detail::abstract_type_helper *v5; // [esp+Ch] [ebp-8h]
  _WORD *v6; // [esp+10h] [ebp-4h]

  vostok::variant<32>::~variant<32>(this);
  this->m_type_id = vostok::detail::type_to_int<unsigned short>::get();
  v6 = operator new(2u, this->m_storage);
  if ( v6 )
    *v6 = *value;
  v5 = (vostok::detail::abstract_type_helper *)operator new(4u, this);
  if ( v5 )
  {
    vostok::detail::abstract_type_helper::abstract_type_helper(v2, v5);
    v5->__vftable = (vostok::detail::abstract_type_helper_vtbl *)&vostok::detail::concrete_type_helper<unsigned short>::`vftable';
    v3 = v5;
  }
  else
  {
    v3 = 0;
  }
  this->m_helper = v3;
}
