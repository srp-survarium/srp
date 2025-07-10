void __userpurge vostok::animation::mixing::n_ary_tree_comparer::merge_weight_asynchronous_groups(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *const from_begin@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *const from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *const to_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *const to_end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // esi
  vostok::animation::mixing::n_ary_tree_node_comparer comparer; // [esp+10h] [ebp-8h] BYREF

  v6 = from_begin;
  comparer.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  comparer.result = equal;
  if ( !from_begin )
  {
LABEL_10:
    while ( from_end )
    {
      vostok::animation::mixing::n_ary_tree_comparer::add_animation(this, from_end, 0);
      from_end = from_end->m_next_weight_animation;
    }
    return;
  }
  while ( from_end )
  {
    comparer.result = equal;
    v6->accept(v6, &comparer, from_end);
    if ( comparer.result == equal )
    {
      vostok::animation::mixing::n_ary_tree_comparer::change_animation(v6, from_end, this, 0);
      v6 = v6->m_next_weight_animation;
      goto LABEL_8;
    }
    if ( comparer.result != less )
    {
      vostok::animation::mixing::n_ary_tree_comparer::add_animation(this, from_end, 0);
LABEL_8:
      from_end = from_end->m_next_weight_animation;
      goto LABEL_9;
    }
    vostok::animation::mixing::n_ary_tree_comparer::remove_animation(this, v6, 0, 0);
    v6 = v6->m_next_weight_animation;
LABEL_9:
    if ( !v6 )
      goto LABEL_10;
  }
  for ( ; v6; v6 = v6->m_next_weight_animation )
    vostok::animation::mixing::n_ary_tree_comparer::remove_animation(this, v6, 0, 0);
}
