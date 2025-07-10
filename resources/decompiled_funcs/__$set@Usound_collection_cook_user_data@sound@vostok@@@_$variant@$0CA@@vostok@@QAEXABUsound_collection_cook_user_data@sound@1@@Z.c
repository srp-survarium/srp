void __thiscall vostok::variant<32>::set<vostok::sound::sound_collection_cook_user_data>(
        vostok::variant<32> *this,
        const vostok::sound::sound_collection_cook_user_data *value)
{
  vostok::detail::abstract_type_helper *v2; // [esp+0h] [ebp-24h]

  vostok::variant<32>::~variant<32>(this);
  this->m_type_id = vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::get();
  if ( this != (vostok::variant<32> *)-8 )
  {
    *(_DWORD *)this->m_storage = value->val;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&this->m_storage[4],
      &value->cfg_ptr);
  }
  if ( this )
  {
    *(_DWORD *)this->m_helper_storage = &vostok::detail::abstract_type_helper::`vftable';
    *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::`vftable';
    v2 = (vostok::detail::abstract_type_helper *)this;
  }
  else
  {
    v2 = 0;
  }
  this->m_helper = v2;
}
