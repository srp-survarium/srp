void __thiscall vostok::animation::mixing::n_ary_tree_weight_transition_node::accept(
        vostok::animation::mixing::n_ary_tree_weight_transition_node *this,
        vostok::animation::mixing::n_ary_tree_visitor *visitor)
{
  visitor->visit(visitor, this);
}
