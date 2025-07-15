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
  vostok::animation::mixing::binary_tree_animation_node *m_object; // ecx
  bool v4; // zf
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v6; // ecx
  vostok::render::skeleton_model_instance *(__thiscall *v7)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  bool nodea; // [esp+Ch] [ebp+4h]

  m_object = node->m_next_weight_animation.m_object;
  node->m_next_weight_animation.m_object = 0;
  if ( m_object )
  {
    v4 = m_object->m_reference_count-- == 1;
    if ( v4 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
  m_weight_driving_animation = node->m_weight_driving_animation;
  v6 = 0;
  node->m_n_ary_animation = 0;
  node->m_unique_weights_count = 0;
  node->m_null_weight_found = 0;
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
  if ( m_weight_driving_animation )
  {
    ++m_weight_driving_animation->m_reference_count;
    v6 = m_weight_driving_animation;
    v7 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  }
  else
  {
    v7 = 0;
  }
  nodea = v7 != 0;
  if ( v6 )
  {
    v4 = v6->m_reference_count-- == 1;
    if ( v4 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v6->~vostok::animation::mixing::binary_tree_base_node)(
        v6,
        0);
  }
  if ( nodea )
    node->m_weight_interpolator = 0;
}


void __thiscall vostok::animation::mixing::binary_tree_initializer::visit(
        vostok::animation::mixing::binary_tree_initializer *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
}


void __thiscall vostok::animation::mixing::binary_tree_initializer::visit(
        vostok::animation::mixing::binary_tree_initializer *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
}


void __thiscall vostok::animation::mixing::binary_tree_initializer::visit(
        vostok::animation::mixing::binary_tree_initializer *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
}
