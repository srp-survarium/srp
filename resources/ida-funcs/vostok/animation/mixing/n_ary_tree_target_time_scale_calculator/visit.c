void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A2E1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A311);
}


void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A2C1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A2D1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  this->m_result = node->m_time_scale;
}


void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  node->m_to->accept(node->m_to, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A2F1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  __debugbreak();
  JUMPOUT(0x56A301);
}
