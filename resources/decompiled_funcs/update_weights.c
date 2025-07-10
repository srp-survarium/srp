void __usercall update_weights(
        vostok::animation::mixing::binary_tree_animation_node *const animations_root@<eax>,
        vostok::animation::mixing::binary_tree_base_node *const weights_root)
{
  vostok::animation::mixing::binary_tree_animation_node *v2; // edi
  vostok::animation::mixing::binary_tree_base_node *m_next_weight; // eax
  vostok::animation::mixing::binary_tree_base_node *v4; // ecx
  vostok::animation::mixing::binary_tree_animation_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v6; // eax
  vostok::animation::mixing::binary_tree_animation_node *v7; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v8; // esi
  bool v9; // zf

  v2 = 0;
  if ( animations_root )
  {
    ++animations_root->m_reference_count;
    v2 = animations_root;
  }
  while ( 1 )
  {
    m_next_weight = v2->m_next_weight;
    v4 = v2;
    if ( m_next_weight )
    {
      while ( v4 != weights_root )
      {
        v4 = m_next_weight;
        m_next_weight = m_next_weight->m_next_weight;
        if ( !m_next_weight )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      if ( v4 != weights_root )
        v4->m_next_weight = weights_root;
    }
    m_object = v2->m_next_weight_animation.m_object;
    v6 = 0;
    if ( m_object )
    {
      v6 = v2->m_next_weight_animation.m_object;
      ++m_object->m_reference_count;
    }
    v7 = v2;
    v8 = v6;
    v2 = v6;
    if ( v7 )
    {
      v9 = v7->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v7->~vostok::animation::mixing::binary_tree_base_node)(
          v7,
          0);
    }
    if ( !v8 )
      break;
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v9 = v8->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, vostok::render::skeleton_model_instance *(__thiscall *)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)))v8->~vostok::animation::mixing::binary_tree_base_node)(
          v8,
          vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr);
      return;
    }
  }
}
