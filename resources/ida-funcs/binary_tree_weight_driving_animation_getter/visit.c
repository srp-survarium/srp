void __thiscall binary_tree_weight_driving_animation_getter::visit(
        binary_tree_weight_driving_animation_getter *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v3; // ecx
  vostok::particle::particle_system_instance_impl *(__thiscall *v4)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  bool v5; // bl
  unsigned int __val; // [esp+4h] [ebp-8h] BYREF
  binary_tree_weight_driving_animation_getter *v8; // [esp+8h] [ebp-4h]

  m_weight_driving_animation = node->m_weight_driving_animation;
  v8 = this;
  v3 = 0;
  if ( m_weight_driving_animation )
  {
    ++m_weight_driving_animation->m_reference_count;
    v3 = m_weight_driving_animation;
    v4 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  }
  else
  {
    v4 = 0;
  }
  v5 = v4 != 0;
  if ( v3 )
  {
    if ( v3->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v3->~vostok::animation::mixing::binary_tree_base_node)(
        v3,
        0);
  }
  if ( !v5 && node->m_weight_synchronization_group_id != -1 )
  {
    __val = node->m_weight_synchronization_group_id;
    stlp_std::lower_bound<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *>> *,unsigned int,find_weight_driving_animation_predicate>(
      v8->m_animations->m_begin,
      v8->m_animations->m_end,
      &__val)->second.second = node;
  }
}


void __thiscall binary_tree_weight_driving_animation_getter::visit(
        survarium::selected_animations_dumper *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}
