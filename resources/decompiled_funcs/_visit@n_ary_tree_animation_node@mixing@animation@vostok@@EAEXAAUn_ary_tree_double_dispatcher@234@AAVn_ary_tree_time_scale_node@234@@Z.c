void __thiscall vostok::animation::mixing::n_ary_tree_animation_node::visit(
        vostok::animation::mixing::n_ary_tree_animation_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}
