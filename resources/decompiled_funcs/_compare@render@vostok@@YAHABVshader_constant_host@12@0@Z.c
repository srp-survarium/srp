int __usercall vostok::render::compare@<eax>(
        const vostok::render::shader_constant_host *left@<edx>,
        const vostok::render::shader_constant_host *right@<esi>)
{
  vostok::strings::shared::profile *m_object; // eax
  unsigned int v3; // ecx
  vostok::strings::shared::profile *v4; // eax
  vostok::strings::shared::profile *v6; // eax
  unsigned int v7; // ecx
  vostok::strings::shared::profile *v8; // eax

  m_object = left->m_name.m_pointer.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v3 = (unsigned int)&m_object[1];
  }
  else
  {
    v3 = 0;
  }
  v4 = right->m_name.m_pointer.m_object;
  if ( v4
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && v3 < (unsigned int)&v4[1] )
  {
    return -1;
  }
  v6 = left->m_name.m_pointer.m_object;
  if ( v6
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v7 = (unsigned int)&v6[1];
  }
  else
  {
    v7 = 0;
  }
  v8 = right->m_name.m_pointer.m_object;
  if ( v8
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    return (unsigned int)&v8[1] < v7;
  }
  else
  {
    return v7 != 0;
  }
}
