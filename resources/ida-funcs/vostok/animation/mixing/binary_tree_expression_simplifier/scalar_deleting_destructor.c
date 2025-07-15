vostok::animation::mixing::binary_tree_expression_simplifier *__thiscall vostok::animation::mixing::binary_tree_expression_simplifier::`scalar deleting destructor'(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        char a2)
{
  vostok::animation::mixing::binary_tree_expression_simplifier::~binary_tree_expression_simplifier(
    this,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
