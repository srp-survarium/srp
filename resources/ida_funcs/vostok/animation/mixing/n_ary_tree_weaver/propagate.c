void __userpurge vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_addition_node>(
        vostok::animation::mixing::n_ary_tree_weaver *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_weaver *a2@<eax>,
        vostok::animation::mixing::binary_tree_addition_node *node,
        vostok::animation::mixing::n_ary_tree_weaver *left,
        vostok::animation::mixing::n_ary_tree_weaver *right)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_base_node *v7; // ecx
  vostok::animation::mixing::binary_tree_base_node *m_new_node; // ebx
  vostok::animation::mixing::binary_tree_base_node *v9; // eax
  vostok::animation::mixing::binary_tree_base_node *v10; // ecx
  bool v11; // zf
  vostok::animation::mixing::binary_tree_base_node *v12; // ebp
  vostok::animation::mixing::binary_tree_base_node *v13; // eax
  vostok::animation::mixing::binary_tree_base_node *v14; // ecx

  a2->m_new_node = node;
  m_object = node->m_left.m_object;
  left->m_interpolators_root = a2->m_interpolators_root;
  left->m_weights_root = a2->m_weights_root;
  left->m_current_animations_root = a2->m_current_animations_root;
  m_object->accept(m_object, left);
  a2->m_interpolators_root = left->m_interpolators_root;
  a2->m_interpolators_count += left->m_interpolators_count;
  a2->m_weights_root = left->m_weights_root;
  vostok::animation::mixing::n_ary_tree_weaver::join_animations(a2, left);
  v7 = node->m_right.m_object;
  right->m_interpolators_root = a2->m_interpolators_root;
  right->m_weights_root = a2->m_weights_root;
  right->m_current_animations_root = a2->m_current_animations_root;
  v7->accept(v7, right);
  a2->m_interpolators_root = right->m_interpolators_root;
  a2->m_interpolators_count += right->m_interpolators_count;
  a2->m_weights_root = right->m_weights_root;
  vostok::animation::mixing::n_ary_tree_weaver::join_animations(a2, right);
  m_new_node = left->m_new_node;
  v9 = 0;
  if ( m_new_node )
  {
    ++m_new_node->m_reference_count;
    v9 = m_new_node;
  }
  v10 = node->m_left.m_object;
  node->m_left.m_object = v9;
  if ( v10 )
  {
    v11 = v10->m_reference_count-- == 1;
    if ( v11 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v10->~vostok::animation::mixing::binary_tree_base_node)(
        v10,
        0);
  }
  v12 = right->m_new_node;
  v13 = 0;
  if ( v12 )
  {
    ++v12->m_reference_count;
    v13 = v12;
  }
  v14 = node->m_right.m_object;
  node->m_right.m_object = v13;
  if ( v14 )
  {
    v11 = v14->m_reference_count-- == 1;
    if ( v11 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v14->~vostok::animation::mixing::binary_tree_base_node)(
        v14,
        0);
  }
}
