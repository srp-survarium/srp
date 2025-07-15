void __thiscall binary_tree_weight_driving_animation_getter::visit(
        binary_tree_weight_driving_animation_getter *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v4; // ecx
  vostok::render::skeleton_model_instance *(__thiscall *v5)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  bool v6; // bl
  vostok::buffer_vector<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > > *m_animations; // ecx
  int *v9; // [esp+0h] [ebp-Ch]
  unsigned int __val; // [esp+8h] [ebp-4h] BYREF

  m_weight_driving_animation = node->m_weight_driving_animation;
  v4 = 0;
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
  v6 = v5 != 0;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v4->~vostok::animation::mixing::binary_tree_base_node)(
        v4,
        0);
  }
  if ( !v6 && node->m_weight_synchronization_group_id != -1 )
  {
    m_animations = this->m_animations;
    __val = node->m_weight_synchronization_group_id;
    stlp_std::priv::__lower_bound<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *>> *,unsigned int,find_weight_driving_animation_predicate,find_weight_driving_animation_predicate,int>(
      m_animations->m_begin,
      m_animations->m_end,
      &__val,
      0,
      0,
      v9)->second.second = node;
  }
}


void __thiscall binary_tree_weight_driving_animation_getter::visit(
        binary_tree_weight_driving_animation_getter *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}
