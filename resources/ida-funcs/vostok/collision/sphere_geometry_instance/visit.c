void __thiscall vostok::collision::sphere_geometry_instance::visit(
        vostok::animation::mixing::n_ary_tree_addition_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::collision::sphere_geometry_instance::visit(
        vostok::animation::mixing::n_ary_tree_animation_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::collision::sphere_geometry_instance::visit(
        vostok::animation::mixing::n_ary_tree_multiplication_node *this,
        vostok::animation::mixing::n_ary_tree_double_dispatcher *dispatcher,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}
