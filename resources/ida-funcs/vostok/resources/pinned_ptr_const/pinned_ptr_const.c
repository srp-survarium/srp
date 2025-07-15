void __thiscall vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        vostok::resources::pinned_ptr_mutable<unsigned char> *this,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> ptr,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> a3)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *m_object; // ebx
  vostok::resources::managed_resource *v4; // ecx
  vostok::memory::managed_node *m_node; // eax
  vostok::resources::managed_resource *v6; // eax
  vostok::resources::managed_resource *size; // ecx

  m_object = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)ptr.m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &ptr,
    &a3);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    m_object,
    &ptr);
  v4 = ptr.m_object;
  if ( ptr.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = ptr.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v6 = (vostok::resources::managed_resource *)&m_node[1];
  }
  else
  {
    v6 = 0;
  }
  m_object[1].m_object = v6;
  if ( v4
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    size = (vostok::resources::managed_resource *)v4->m_memory_usage_self.size;
  }
  else
  {
    size = 0;
  }
  m_object[2].m_object = size;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ptr);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
}


void __usercall vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
        vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *this@<ecx>,
        const vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *other@<eax>)
{
  vostok::memory::managed_node *m_node; // eax
  const unsigned __int8 *v5; // eax
  vostok::resources::managed_resource *m_object; // edi
  unsigned int size; // edi

  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &this->m_resource,
    &other->m_resource);
  if ( other->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = other->m_resource.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v5 = (const unsigned __int8 *)&m_node[1];
  }
  else
  {
    v5 = 0;
  }
  this->m_data = v5;
  m_object = other->m_resource.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    size = m_object->m_memory_usage_self.size;
  }
  else
  {
    size = 0;
  }
  this->m_size = size;
}
