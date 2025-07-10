void __usercall vostok::variant<32>::set<vostok::animation::animation_collection_cook_user_data>(
        vostok::variant<32> *this@<esi>,
        const vostok::animation::animation_collection_cook_user_data *value@<eax>)
{
  vostok::detail::abstract_type_helper *m_helper; // ecx

  m_helper = this->m_helper;
  if ( m_helper )
  {
    m_helper->destroy(m_helper, this->m_storage);
    this->m_helper = 0;
  }
  this->m_type_id = vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::get();
  if ( this != (vostok::variant<32> *)-8 )
  {
    *(_DWORD *)this->m_storage = value->val;
    *(_DWORD *)&this->m_storage[4] = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_storage[4],
      &value->cfg_ptr);
  }
  this->m_helper = (vostok::detail::abstract_type_helper *)this;
  *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::`vftable';
}
