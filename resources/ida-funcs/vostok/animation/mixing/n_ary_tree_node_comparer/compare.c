vostok::animation::comparison_result_enum __userpurge vostok::animation::mixing::n_ary_tree_node_comparer::compare@<eax>(
        vostok::animation::mixing::n_ary_tree_node_comparer *this@<ecx>,
        int a2@<esi>,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_base_node *right)
{
  *(_DWORD *)(a2 + 8) = 0;
  this->dispatch(this, (vostok::animation::mixing::n_ary_tree_time_scale_node *)a2, left);
  return *(_DWORD *)(a2 + 8);
}
