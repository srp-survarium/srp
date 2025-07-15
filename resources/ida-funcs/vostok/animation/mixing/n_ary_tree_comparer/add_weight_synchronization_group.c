void __userpurge vostok::animation::mixing::n_ary_tree_comparer::add_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_comparer *a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *begin,
        vostok::animation::mixing::n_ary_tree_animation_node *end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi

  v4 = begin;
  a2->m_equal = 0;
  for ( i = v4->m_weight_synchronization_group_id != -1 ? v4 : 0; v4 != end; v4 = v4->m_next_weight_animation )
    vostok::animation::mixing::n_ary_tree_comparer::add_animation(a2, v4, i);
}
