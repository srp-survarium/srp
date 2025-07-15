void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A061);
}


void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A071);
}


void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A041);
}


void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A051);
}


void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  this->m_result = node->m_interpolator;
}


void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  node->m_to->accept(node->m_to, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  this->m_result = node->m_interpolator;
}


void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  node->m_to->accept(node->m_to, this);
}
