vostok::animation::comparison_result_enum __usercall vostok::animation::mixing::n_ary_tree_node_comparer::compare@<eax>(
        vostok::animation::mixing::n_ary_tree_node_comparer *this@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *left@<ecx>,
        vostok::animation::mixing::n_ary_tree_base_node *right@<edx>)
{
  this->result = equal;
  left->accept(left, this, right);
  return this->result;
}
