char __usercall is_unique_animation_lexeme@<al>(
        vostok::animation::mixing::binary_tree_animation_node *node@<ecx>,
        vostok::animation::mixing::binary_tree_animation_node *const animations_root@<eax>)
{
  if ( node->m_next_weight_animation.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    return 0;
  }
  if ( animations_root )
  {
    while ( animations_root != node )
    {
      animations_root = animations_root->m_next_weight_animation.m_object;
      if ( !animations_root )
        return 1;
    }
    return 0;
  }
  return 1;
}
