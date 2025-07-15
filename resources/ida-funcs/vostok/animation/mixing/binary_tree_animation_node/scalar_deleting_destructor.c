vostok::animation::mixing::binary_tree_animation_node *__thiscall vostok::animation::mixing::binary_tree_animation_node::`scalar deleting destructor'(
        vostok::animation::mixing::binary_tree_animation_node *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>(&this->m_next_weight_animation);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
