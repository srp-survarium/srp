void __userpurge vostok::animation::mixing::n_ary_tree_comparer::change_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_animation_node *to_begin@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *from_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *to_end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *animation; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v7; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // ebx
  unsigned int v9; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v10; // [esp+0h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // [esp+4h] [ebp-10h]

  if ( from_begin->m_weight_synchronization_group_id == -1 )
  {
    vostok::animation::mixing::n_ary_tree_comparer::merge_weight_asynchronous_groups(
      this,
      from_begin,
      to_begin,
      v10,
      v11);
    return;
  }
  animation = vostok::animation::mixing::find_animation(from_begin, from_end, to_begin);
  v8 = animation;
  if ( !animation )
  {
    vostok::animation::mixing::n_ary_tree_comparer::new_weight_driving_animation(v7, this, to_begin);
    goto LABEL_7;
  }
  vostok::animation::mixing::n_ary_tree_comparer::new_weight_driving_animation(this, to_begin, animation);
  if ( v8->m_is_transitting_to_zero )
  {
LABEL_7:
    v9 = 1;
    goto LABEL_8;
  }
  LOBYTE(v9) = 0;
LABEL_8:
  vostok::animation::mixing::n_ary_tree_comparer::merge_weight_synchronization_groups(
    from_begin,
    this,
    from_end,
    to_begin->m_next_weight_animation,
    to_end,
    to_begin,
    v9);
}
