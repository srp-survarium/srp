void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::accept(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_base_node *node)
{
  node->visit(node, dispatcher, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::accept(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        vostok::animation::mixing::n_ary_tree_visitor *visitor)
{
  visitor->visit(visitor, this);
}
