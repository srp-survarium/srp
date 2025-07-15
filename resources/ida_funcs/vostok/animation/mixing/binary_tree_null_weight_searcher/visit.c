void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::animation::mixing::binary_tree_null_weight_searcher *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  ;
}


void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::animation::mixing::binary_tree_null_weight_searcher *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  __debugbreak();
  JUMPOUT(0x568D11);
}


void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::animation::mixing::binary_tree_null_weight_searcher *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}


void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::animation::mixing::binary_tree_null_weight_searcher *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  ;
}


void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::animation::mixing::binary_tree_null_weight_searcher *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  this->m_result = this->m_result || node->m_weight == 0.0;
}
