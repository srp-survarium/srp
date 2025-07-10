void __thiscall vostok::animation::mixing::binary_tree_addition_node::accept(
        vostok::animation::mixing::binary_tree_addition_node *this,
        vostok::animation::mixing::binary_tree_visitor *visitor)
{
  visitor->visit(visitor, this);
}
