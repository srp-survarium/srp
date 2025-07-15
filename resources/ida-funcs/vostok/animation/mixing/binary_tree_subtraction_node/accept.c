void __thiscall vostok::animation::mixing::binary_tree_subtraction_node::accept(
        vostok::animation::mixing::n_ary_tree_subtraction_node *this,
        vostok::animation::mixing::n_ary_tree_visitor *visitor)
{
  visitor->visit(visitor, this);
}
