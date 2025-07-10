bool __usercall vostok::animation::mixing::operator<@<al>(
        const vostok::animation::mixing::n_ary_tree_weight_node *left@<edi>,
        const vostok::animation::mixing::n_ary_tree_weight_node *right@<esi>,
        vostok::animation::comparison_result_enum a3@<ecx>)
{
  vostok::animation::interpolator_comparer comparer; // [esp+8h] [ebp-4h] BYREF

  comparer.result = a3;
  left->m_interpolator->accept(left->m_interpolator, &comparer, right->m_interpolator);
  if ( comparer.result )
    return comparer.result == less;
  else
    return right->m_weight > left->m_weight;
}
