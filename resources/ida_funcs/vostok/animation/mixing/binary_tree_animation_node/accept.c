void __thiscall vostok::animation::mixing::binary_tree_animation_node::accept(
        vostok::animation::mixing::binary_tree_animation_node *this,
        vostok::animation::mixing::binary_tree_visitor *visitor)
{
  visitor->visit(visitor, this);
}
