void __thiscall vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
        vostok::resources::pinned_ptr_base<unsigned char const > *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::memory::managed_node *m_node; // eax
  const unsigned __int8 *v5; // ecx

  this->m_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->m_resource,
    &ptr);
  m_object = ptr.m_object;
  if ( ptr.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = ptr.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v5 = (const unsigned __int8 *)&m_node[1];
    m_object = ptr.m_object;
  }
  else
  {
    v5 = 0;
  }
  this->m_data = v5;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    this->m_size = m_object->m_memory_usage_self.size;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
  }
  else
  {
    this->m_size = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
  }
}
