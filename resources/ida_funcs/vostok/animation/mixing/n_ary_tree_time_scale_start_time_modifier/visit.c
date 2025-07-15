void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  __debugbreak();
  JUMPOUT(0x56CB01);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  __debugbreak();
  JUMPOUT(0x56CB31);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  __debugbreak();
  JUMPOUT(0x56CAE1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  __debugbreak();
  JUMPOUT(0x56CAF1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  float m_animation_interval_time; // xmm0_4

  m_animation_interval_time = this->m_animation_interval_time;
  node->m_time_scale_start_time_in_ms = this->m_new_start_time_in_ms;
  node->m_animation_time_before_scale_starts = m_animation_interval_time;
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  ;
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  __debugbreak();
  JUMPOUT(0x56CB11);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  __debugbreak();
  JUMPOUT(0x56CB21);
}
