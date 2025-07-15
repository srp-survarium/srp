void __usercall vostok::animation::mixing::binary_tree_expression_simplifier::~binary_tree_expression_simplifier(
        vostok::animation::mixing::binary_tree_expression_simplifier *this@<ecx>,
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *a2@<esi>)
{
  vostok::animation::mixing::binary_tree_animation_node *m_object; // eax

  m_object = a2[3].m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))a2[3].m_object->~vostok::animation::mixing::binary_tree_base_node)(
        a2[3].m_object,
        0);
  }
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>(a2 + 2);
}
