vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::animation::mixing::binary_tree_base_node **a2@<esi>)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_base_node *v3; // eax
  vostok::animation::mixing::binary_tree_base_node *v4; // ecx

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    ++m_object->m_reference_count;
  }
  v4 = *a2;
  *a2 = v3;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v4->~vostok::animation::mixing::binary_tree_base_node)(
        v4,
        0);
  }
  return (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)a2;
}
