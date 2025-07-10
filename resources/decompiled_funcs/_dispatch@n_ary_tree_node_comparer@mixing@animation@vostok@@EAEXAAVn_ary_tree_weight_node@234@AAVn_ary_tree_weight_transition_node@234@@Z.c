void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  vostok::animation::comparison_result_enum result; // eax

  right->m_to->accept(right->m_to, this, left);
  result = this->result;
  if ( result == more )
  {
    this->result = less;
  }
  else
  {
    if ( result == less )
      result = more;
    this->result = result;
  }
}
