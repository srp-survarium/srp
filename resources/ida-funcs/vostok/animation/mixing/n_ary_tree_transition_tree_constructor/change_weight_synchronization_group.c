void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_animation_node *from_end@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *to_begin@<esi>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_animation_node *from_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *to_end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // eax
  int v9; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v10; // [esp+0h] [ebp-10h]
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // [esp+4h] [ebp-Ch]

  if ( from_begin->m_weight_synchronization_group_id == -1 )
  {
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_weight_asynchronous_groups(
      from_begin,
      to_begin,
      this,
      v10,
      v11);
    return;
  }
  animation = vostok::animation::mixing::find_animation(
                from_begin,
                from_end,
                (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin);
  v7 = animation;
  if ( !animation )
  {
    v8 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_driving_animation(
           this,
           this,
           (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin);
    goto LABEL_7;
  }
  v8 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_driving_animation(
         this,
         animation,
         (vostok::animation::mixing::n_ary_tree_base_node **)to_begin);
  if ( v7->m_is_transitting_to_zero )
  {
LABEL_7:
    v9 = 1;
    goto LABEL_8;
  }
  LOBYTE(v9) = 0;
LABEL_8:
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_weight_synchronization_groups(
    from_begin,
    this,
    from_end,
    (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin->m_cloner.m_constructor,
    to_end,
    v8,
    (vostok::animation::mixing::n_ary_tree_base_node **)v9);
}
