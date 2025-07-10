void __userpurge vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *this@<ecx>,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *a2@<esi>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::memory::managed_node *m_node; // eax
  vostok::resources::managed_resource *v5; // ecx

  a2->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    a2,
    &ptr);
  m_object = ptr.m_object;
  if ( ptr.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = ptr.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v5 = (vostok::resources::managed_resource *)&m_node[1];
    m_object = ptr.m_object;
  }
  else
  {
    v5 = 0;
  }
  a2[1].m_object = v5;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    a2[2].m_object = (vostok::resources::managed_resource *)m_object->m_memory_usage_self.size;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
  }
  else
  {
    a2[2].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
  }
}
