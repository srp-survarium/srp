void __thiscall vostok::animation::mixing::n_ary_tree_addition_node::accept(
        vostok::animation::mixing::n_ary_tree_addition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_base_node *node)
{
  node->visit(node, dispatcher, this);
}
