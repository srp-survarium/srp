void __thiscall vostok::animation::mixing::n_ary_tree_addition_node::visit(
        vostok::animation::mixing::n_ary_tree_addition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}
