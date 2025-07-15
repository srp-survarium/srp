void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::journaling::gamepad *this,
        vostok::input::gamepad_vibrators vibrator,
        vostok::render::surface_stats *__formal,
        const char *function)
{
  __debugbreak();
  JUMPOUT(0x293BD);
}


void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::animation::mixing::binary_tree_null_weight_searcher *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  bool v2; // al

  v2 = this->m_result || node->m_weight == 0.0;
  this->m_result = v2;
}
