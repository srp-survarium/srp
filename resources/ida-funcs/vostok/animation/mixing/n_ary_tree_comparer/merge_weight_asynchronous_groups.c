void __userpurge vostok::animation::mixing::n_ary_tree_comparer::merge_weight_asynchronous_groups(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_comparer *a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *const from_begin,
        vostok::animation::mixing::n_ary_tree_subtraction_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *const to_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *const to_end)
{
  vostok::animation::comparison_result_enum v9; // eax
  vostok::animation::mixing::n_ary_tree_subtraction_node *v10; // esi
  vostok::animation::mixing::n_ary_tree_base_node *v11; // [esp+0h] [ebp-20h]
  _DWORD v12[3]; // [esp+10h] [ebp-10h] BYREF
  char v13; // [esp+1Ch] [ebp-4h]
  vostok::animation::mixing::n_ary_tree_subtraction_node *left; // [esp+28h] [ebp+8h]

  v12[2] = 0;
  v12[1] = a2->m_animated_object_resolver;
  v12[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v13 = 0;
LABEL_9:
  left = from_end;
  while ( 1 )
  {
    if ( !from_begin )
      goto LABEL_13;
    if ( !left )
      break;
    v9 = vostok::animation::mixing::n_ary_tree_node_comparer::compare(
           (vostok::animation::mixing::n_ary_tree_node_comparer *)from_begin,
           (int)v12,
           left,
           v11);
    if ( v9 == equal )
    {
      v10 = left;
      vostok::animation::mixing::n_ary_tree_comparer::change_animation(
        a2,
        (vostok::animation::mixing::n_ary_tree_animation_node *)left,
        from_begin,
        0);
      from_begin = from_begin->m_next_weight_animation;
      goto LABEL_8;
    }
    if ( v9 != less )
    {
      v10 = left;
      vostok::animation::mixing::n_ary_tree_comparer::add_animation(
        a2,
        (vostok::animation::mixing::n_ary_tree_animation_node *)left,
        0);
LABEL_8:
      from_end = (vostok::animation::mixing::n_ary_tree_subtraction_node *)v10[5].__vftable;
      goto LABEL_9;
    }
    vostok::animation::mixing::n_ary_tree_comparer::remove_animation(a2, from_begin, 0, 0);
    from_begin = from_begin->m_next_weight_animation;
  }
  do
  {
    vostok::animation::mixing::n_ary_tree_comparer::remove_animation(a2, from_begin, 0, 0);
    from_begin = from_begin->m_next_weight_animation;
  }
  while ( from_begin );
LABEL_13:
  while ( left )
  {
    vostok::animation::mixing::n_ary_tree_comparer::add_animation(
      a2,
      (vostok::animation::mixing::n_ary_tree_animation_node *)left,
      0);
    left = (vostok::animation::mixing::n_ary_tree_subtraction_node *)left[5].__vftable;
  }
}
