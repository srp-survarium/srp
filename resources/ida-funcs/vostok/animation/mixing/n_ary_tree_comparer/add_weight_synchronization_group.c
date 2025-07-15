void __userpurge vostok::animation::mixing::n_ary_tree_comparer::add_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_comparer *a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *begin,
        vostok::animation::mixing::n_ary_tree_animation_node *end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // esi

  a2->m_equal = 0;
  v6 = begin->m_weight_synchronization_group_id != -1 ? begin : 0;
  while ( begin != end )
  {
    vostok::animation::mixing::n_ary_tree_comparer::add_animation(a2, begin, v6);
    begin = begin->m_next_weight_animation;
  }
}
