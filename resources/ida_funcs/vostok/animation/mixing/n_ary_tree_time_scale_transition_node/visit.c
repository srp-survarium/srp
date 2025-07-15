void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}
