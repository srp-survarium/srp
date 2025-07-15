void __usercall update_weights(
        vostok::animation::mixing::binary_tree_weight_node *animations_root@<eax>,
        vostok::animation::mixing::binary_tree_base_node *const weights_root@<edi>)
{
  vostok::animation::mixing::binary_tree_weight_node *v2; // ecx
  vostok::animation::mixing::binary_tree_base_node *m_next_weight; // eax
  vostok::animation::mixing::binary_tree_base_node *v4; // edx
  vostok::animation::mixing::binary_tree_weight_node *v6; // [esp+0h] [ebp-4h] BYREF

  v2 = 0;
  v6 = 0;
  if ( animations_root )
  {
    ++animations_root->m_reference_count;
    v2 = animations_root;
    v6 = animations_root;
  }
  while ( 1 )
  {
    m_next_weight = v2->m_next_weight;
    v4 = v2;
    while ( m_next_weight )
    {
      if ( v4 == weights_root )
        goto LABEL_9;
      v4 = m_next_weight;
      m_next_weight = m_next_weight->m_next_weight;
    }
    if ( v4 != weights_root )
      v4->m_next_weight = weights_root;
LABEL_9:
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v2[1].m_simplified_weight,
      &v6);
    v2 = v6;
    if ( !v6 )
      break;
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( v6->m_reference_count-- == 1 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v2->~vostok::animation::mixing::binary_tree_base_node)(
          v2,
          0);
      return;
    }
  }
}
