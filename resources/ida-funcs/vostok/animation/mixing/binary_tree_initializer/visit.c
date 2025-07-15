void __thiscall vostok::animation::mixing::binary_tree_initializer::visit(
        vostok::animation::mixing::binary_tree_initializer *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
}


void __thiscall vostok::animation::mixing::binary_tree_initializer::visit(
        vostok::animation::mixing::binary_tree_initializer *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v4; // ecx
  vostok::particle::particle_system_instance_impl *(__thiscall *v5)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  bool v7; // [esp+17h] [ebp+Bh]

  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    0,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&node->m_next_weight_animation);
  m_weight_driving_animation = node->m_weight_driving_animation;
  v4 = 0;
  node->m_n_ary_animation = 0;
  node->m_unique_weights_count = 0;
  node->m_null_weight_found = 0;
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
  if ( m_weight_driving_animation )
  {
    ++m_weight_driving_animation->m_reference_count;
    v4 = m_weight_driving_animation;
    v5 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  }
  else
  {
    v5 = 0;
  }
  v7 = v5 != 0;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v4->~vostok::animation::mixing::binary_tree_base_node)(
        v4,
        0);
  }
  if ( v7 )
    node->m_weight_interpolator = 0;
}


void __thiscall vostok::animation::mixing::binary_tree_initializer::visit(
        vostok::animation::mixing::binary_tree_initializer *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
}
