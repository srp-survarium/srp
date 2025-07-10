void __usercall vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>(
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *this@<esi>,
        const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *other@<edi>)
{
  vostok::memory::managed_node *m_node; // eax
  const unsigned __int8 *v3; // eax
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v4; // [esp+0h] [ebp-8h]

  this->m_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->m_resource,
    v4);
  if ( other->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = other->m_resource.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v3 = (const unsigned __int8 *)&m_node[1];
  }
  else
  {
    v3 = 0;
  }
  this->m_data = v3;
  if ( other->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    this->m_size = other->m_resource.m_object->m_memory_usage_self.size;
  }
  else
  {
    this->m_size = 0;
  }
}
