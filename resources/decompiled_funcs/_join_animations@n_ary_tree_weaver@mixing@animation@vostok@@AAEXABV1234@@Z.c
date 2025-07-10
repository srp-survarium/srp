void __usercall vostok::animation::mixing::n_ary_tree_weaver::join_animations(
        vostok::animation::mixing::n_ary_tree_weaver *this@<esi>,
        const vostok::animation::mixing::n_ary_tree_weaver *other@<edi>)
{
  vostok::animation::mixing::binary_tree_animation_node *m_animations_root; // eax
  vostok::animation::mixing::binary_tree_animation_node *v3; // edx
  vostok::animation::mixing::binary_tree_animation_node *v4; // eax
  vostok::animation::mixing::binary_tree_animation_node *v5; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v6; // eax
  vostok::animation::mixing::binary_tree_animation_node *m_object; // ecx
  bool v8; // zf
  vostok::animation::mixing::binary_tree_animation_node *v9; // eax

  m_animations_root = other->m_animations_root;
  if ( m_animations_root )
  {
    do
    {
      v3 = m_animations_root;
      m_animations_root = m_animations_root->m_next_weight_animation.m_object;
    }
    while ( m_animations_root );
    v4 = this->m_animations_root;
    v5 = 0;
    if ( v4 )
    {
      ++v4->m_reference_count;
      v5 = v4;
    }
    v6 = v5;
    m_object = v3->m_next_weight_animation.m_object;
    v3->m_next_weight_animation.m_object = v6;
    if ( m_object )
    {
      v8 = m_object->m_reference_count-- == 1;
      if ( v8 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
          m_object,
          0);
    }
    v8 = this->m_current_animations_root == 0;
    v9 = other->m_animations_root;
    this->m_animations_root = v9;
    if ( v8 )
      this->m_current_animations_root = v9;
  }
}
