void __userpurge vostok::animation::mixing::n_ary_tree_weaver::join_animations(
        vostok::animation::mixing::n_ary_tree_weaver *this@<ecx>,
        int a2@<edi>,
        const vostok::animation::mixing::n_ary_tree_weaver *other)
{
  vostok::animation::mixing::binary_tree_animation_node *m_animations_root; // eax
  vostok::animation::mixing::binary_tree_animation_node *v4; // ecx
  bool v5; // zf
  vostok::animation::mixing::binary_tree_animation_node *v6; // eax

  m_animations_root = other->m_animations_root;
  if ( m_animations_root )
  {
    do
    {
      v4 = m_animations_root;
      m_animations_root = m_animations_root->m_next_weight_animation.m_object;
    }
    while ( m_animations_root );
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      *(vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)(a2 + 12),
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&v4->m_next_weight_animation);
    v5 = *(_DWORD *)(a2 + 24) == 0;
    v6 = other->m_animations_root;
    *(_DWORD *)(a2 + 12) = v6;
    if ( v5 )
      *(_DWORD *)(a2 + 24) = v6;
  }
}
