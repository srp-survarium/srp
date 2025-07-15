void __userpurge vostok::animation::mixing::n_ary_tree_comparer::change_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_subtraction_node *to_begin@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *from_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *to_end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // ebx
  unsigned int v9; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v10; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // [esp+0h] [ebp-10h]
  vostok::animation::mixing::n_ary_tree_animation_node *v12; // [esp+4h] [ebp-Ch]

  if ( from_begin->m_weight_synchronization_group_id == -1 )
  {
    vostok::animation::mixing::n_ary_tree_comparer::merge_weight_asynchronous_groups(
      (vostok::animation::mixing::n_ary_tree_comparer *)from_begin,
      this,
      from_begin,
      to_begin,
      v11,
      v12);
  }
  else
  {
    animation = vostok::animation::mixing::find_animation(
                  this->m_animated_object_resolver,
                  from_begin,
                  from_end,
                  (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin);
    v8 = animation;
    if ( animation )
      vostok::animation::mixing::n_ary_tree_comparer::new_weight_driving_animation(
        this,
        (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin,
        animation);
    else
      vostok::animation::mixing::n_ary_tree_comparer::new_weight_driving_animation(
        (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin,
        (BOOL)this);
    if ( !v8 || v8->m_is_transitting_to_zero )
      v9 = 1;
    else
      LOBYTE(v9) = 0;
    vostok::animation::mixing::n_ary_tree_comparer::merge_weight_synchronization_groups(
      v10,
      this,
      from_begin,
      from_end,
      (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin[5].__vftable,
      to_end,
      (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin,
      v9);
  }
}
