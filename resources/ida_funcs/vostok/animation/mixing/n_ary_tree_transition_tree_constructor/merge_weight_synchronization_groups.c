void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_weight_synchronization_groups(
        vostok::animation::mixing::n_ary_tree_animation_node *from_begin@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_animation_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *to_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *to_end,
        vostok::animation::mixing::n_ary_tree_animation_node *new_weight_driving_animation,
        vostok::animation::mixing::n_ary_tree_base_node **is_new_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v7; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // edi
  int j; // ebx
  void *v10; // esp
  vostok::animation::mixing::n_ary_tree_animation_node **v11; // esi
  vostok::animation::mixing::n_ary_tree_animation_node **v12; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v13; // ebx
  int v14; // eax
  int k; // ecx
  int v17; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v18[4]; // [esp+0h] [ebp-20h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node **i; // [esp+10h] [ebp-10h]
  vostok::animation::mixing::animation_comparer_predicate comparer; // [esp+14h] [ebp-Ch] BYREF
  vostok::animation::mixing::animation_comparer_equal_predicate equal_predicate; // [esp+18h] [ebp-8h] BYREF
  bool new_driving_animation_in_old_target_found; // [esp+1Fh] [ebp-1h]

  v7 = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)from_end;
  v8 = from_begin;
  for ( j = 0; from_begin != from_end; ++j )
    from_begin = from_begin->m_next_weight_animation;
  equal_predicate.m_predicate.m_use_synchronized_animations = 0;
  equal_predicate.m_predicate.m_use_overriding_animations = 1;
  new_driving_animation_in_old_target_found = 0;
  v10 = alloca(4 * j);
  v11 = v18;
  i = v18;
  if ( v8 != from_end )
  {
    do
    {
      if ( vostok::animation::mixing::animation_comparer_predicate::operator()(
             &equal_predicate.m_predicate,
             v8,
             new_weight_driving_animation) )
      {
        v12 = i;
        *i = v8;
        i = v12 + 1;
      }
      else
      {
        new_driving_animation_in_old_target_found = 1;
      }
      v8 = v8->m_next_weight_animation;
    }
    while ( v8 != from_end );
    if ( new_driving_animation_in_old_target_found )
      --j;
  }
  v13 = &v18[j];
  LOWORD(from_end) = 256;
  if ( v18 != v13 )
  {
    v14 = v13 - v18;
    for ( k = 0; v14 != 1; ++k )
      v14 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::n_ary_tree_animation_node *,int,vostok::animation::mixing::animation_comparer_less_predicate>(
      (vostok::animation::mixing::animation_comparer_less_predicate)v8,
      v18,
      v13,
      0,
      2 * k,
      (vostok::animation::mixing::n_ary_tree_animation_node **)from_end);
    stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::animation_comparer_less_predicate>(
      v18,
      v13,
      (int)from_end,
      (vostok::animation::mixing::animation_comparer_less_predicate)v18,
      (vostok::animation::mixing::animation_comparer_less_predicate)256);
  }
  comparer.m_use_synchronized_animations = 0;
  comparer.m_use_overriding_animations = 1;
  if ( v18 != v13 )
  {
    while ( 1 )
    {
      if ( to_begin == to_end )
      {
        for ( ; v11 != v13; ++v11 )
          vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(
            this,
            *v11,
            new_weight_driving_animation,
            (int)is_new_driving_animation);
        goto LABEL_26;
      }
      v17 = vostok::animation::mixing::animation_comparer_predicate::operator()(&comparer, *v11, to_begin);
      if ( !v17 )
        break;
      if ( v17 != 1 )
      {
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
          this,
          this,
          to_begin,
          new_weight_driving_animation);
LABEL_21:
        to_begin = to_begin->m_next_weight_animation;
        goto LABEL_22;
      }
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(
        this,
        *v11++,
        new_weight_driving_animation,
        (int)is_new_driving_animation);
LABEL_22:
      if ( v11 == v13 )
        goto LABEL_26;
    }
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_animation(
      (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)new_weight_driving_animation,
      this,
      *v11++,
      (vostok::animation::mixing::n_ary_tree_base_node *const *)to_begin,
      new_weight_driving_animation,
      is_new_driving_animation);
    goto LABEL_21;
  }
LABEL_26:
  while ( to_begin != to_end )
  {
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
      v7,
      this,
      to_begin,
      new_weight_driving_animation);
    to_begin = to_begin->m_next_weight_animation;
  }
}
