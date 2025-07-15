void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_weight_asynchronous_groups(
        vostok::animation::mixing::n_ary_tree_animation_node *const from_begin@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *to_begin@<ecx>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_animation_node *const from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *const to_end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // edi
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v7; // ecx
  vostok::animation::mixing::n_ary_tree_node_comparer comparer; // [esp+10h] [ebp-8h] BYREF

  v5 = from_begin;
  comparer.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  comparer.result = equal;
  v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin;
  if ( !from_begin )
  {
LABEL_10:
    while ( v6 )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(to_begin, this, v6, 0);
      v6 = v6->m_next_weight_animation;
    }
    return;
  }
  while ( v6 )
  {
    comparer.result = equal;
    v5->accept(v5, &comparer, v6);
    if ( comparer.result == equal )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_animation(
        v7,
        this,
        v5,
        (vostok::animation::mixing::n_ary_tree_base_node *const *)v6,
        0,
        0);
      v5 = v5->m_next_weight_animation;
      goto LABEL_8;
    }
    if ( comparer.result != less )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(v7, this, v6, 0);
LABEL_8:
      v6 = v6->m_next_weight_animation;
      goto LABEL_9;
    }
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(this, v5, 0, 0);
    v5 = v5->m_next_weight_animation;
LABEL_9:
    if ( !v5 )
      goto LABEL_10;
  }
  for ( ; v5; v5 = v5->m_next_weight_animation )
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(this, v5, 0, 0);
}
