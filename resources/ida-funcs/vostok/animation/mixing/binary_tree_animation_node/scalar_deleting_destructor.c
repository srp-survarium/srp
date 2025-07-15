vostok::animation::mixing::binary_tree_animation_node *__thiscall vostok::animation::mixing::binary_tree_animation_node::`scalar deleting destructor'(
        vostok::animation::mixing::binary_tree_animation_node *this,
        char a2)
{
  vostok::animation::mixing::binary_tree_animation_node *m_object; // eax

  m_object = this->m_next_weight_animation.m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))this->m_next_weight_animation.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        this->m_next_weight_animation.m_object,
        0);
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
