vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *__usercall vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::operator=@<eax>(
        vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *this@<esi>,
        const vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *other@<eax>)
{
  vostok::memory::managed_node *m_node; // eax
  const unsigned __int8 *v4; // eax
  unsigned int m_size; // eax

  if ( this->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::memory::managed_node_owner::unpin(this->m_data);
  }
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    &other->m_resource,
    &this->m_resource);
  if ( this->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = this->m_resource.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v4 = (const unsigned __int8 *)&m_node[1];
  }
  else
  {
    v4 = 0;
  }
  this->m_data = v4;
  m_size = 0;
  if ( this->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_size = other->m_size;
  }
  this->m_size = m_size;
  return this;
}
