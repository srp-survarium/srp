void __userpurge vostok::animation::mixing::n_ary_tree_comparer::merge_weight_synchronization_groups(
        vostok::animation::mixing::n_ary_tree_animation_node *from_begin@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *to_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *to_end,
        vostok::animation::mixing::n_ary_tree_animation_node *new_weight_driving_animation,
        unsigned int is_new_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // edi
  int j; // ebx
  void *v9; // esp
  vostok::animation::mixing::n_ary_tree_animation_node **v10; // esi
  vostok::animation::mixing::n_ary_tree_animation_node **v11; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v12; // edi
  int v13; // eax
  int k; // ecx
  int v16; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v17[4]; // [esp+0h] [ebp-20h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node **i; // [esp+10h] [ebp-10h]
  vostok::animation::mixing::animation_comparer_predicate comparer; // [esp+14h] [ebp-Ch] BYREF
  vostok::animation::mixing::animation_comparer_equal_predicate equal_predicate; // [esp+18h] [ebp-8h] BYREF
  bool new_driving_animation_in_old_target_found; // [esp+1Fh] [ebp-1h]
  vostok::animation::mixing::n_ary_tree_animation_node *from_enda; // [esp+2Ch] [ebp+Ch]

  v7 = from_begin;
  for ( j = 0; from_begin != from_end; ++j )
    from_begin = from_begin->m_next_weight_animation;
  equal_predicate.m_predicate.m_use_synchronized_animations = 0;
  equal_predicate.m_predicate.m_use_overriding_animations = 1;
  new_driving_animation_in_old_target_found = 0;
  v9 = alloca(4 * j);
  v10 = v17;
  i = v17;
  if ( v7 != from_end )
  {
    do
    {
      if ( vostok::animation::mixing::animation_comparer_predicate::operator()(
             &equal_predicate.m_predicate,
             v7,
             new_weight_driving_animation) )
      {
        v11 = i;
        *i = v7;
        i = v11 + 1;
      }
      else
      {
        new_driving_animation_in_old_target_found = 1;
      }
      v7 = v7->m_next_weight_animation;
    }
    while ( v7 != from_end );
    if ( new_driving_animation_in_old_target_found )
      --j;
  }
  v12 = &v17[j];
  LOWORD(i) = 256;
  from_enda = (vostok::animation::mixing::n_ary_tree_animation_node *)v12;
  if ( v17 != v12 )
  {
    v13 = (4 * j) >> 2;
    for ( k = 0; v13 != 1; ++k )
      v13 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::n_ary_tree_animation_node *,int,vostok::animation::mixing::animation_comparer_less_predicate>(
      (vostok::animation::mixing::animation_comparer_less_predicate)v12,
      v17,
      &v17[j],
      0,
      2 * k,
      i);
    stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::animation_comparer_less_predicate>(
      v17,
      v12,
      (int)i,
      (vostok::animation::mixing::animation_comparer_less_predicate)v17,
      (vostok::animation::mixing::animation_comparer_less_predicate)i);
  }
  comparer.m_use_synchronized_animations = 0;
  comparer.m_use_overriding_animations = 1;
  if ( v17 != v12 )
  {
    while ( 1 )
    {
      if ( to_begin == to_end )
      {
        if ( v10 != v12 )
        {
          do
            vostok::animation::mixing::n_ary_tree_comparer::remove_animation(
              this,
              *v10++,
              new_weight_driving_animation,
              is_new_driving_animation);
          while ( v10 != (vostok::animation::mixing::n_ary_tree_animation_node **)from_enda );
        }
        goto LABEL_26;
      }
      v16 = vostok::animation::mixing::animation_comparer_predicate::operator()(&comparer, *v10, to_begin);
      if ( !v16 )
        break;
      if ( v16 != 1 )
      {
        vostok::animation::mixing::n_ary_tree_comparer::add_animation(this, to_begin, new_weight_driving_animation);
        v12 = (vostok::animation::mixing::n_ary_tree_animation_node **)from_enda;
LABEL_21:
        to_begin = to_begin->m_next_weight_animation;
        goto LABEL_22;
      }
      vostok::animation::mixing::n_ary_tree_comparer::remove_animation(
        this,
        *v10,
        new_weight_driving_animation,
        is_new_driving_animation);
      v12 = (vostok::animation::mixing::n_ary_tree_animation_node **)from_enda;
      ++v10;
LABEL_22:
      if ( v10 == v12 )
        goto LABEL_26;
    }
    vostok::animation::mixing::n_ary_tree_comparer::change_animation(*v10++, to_begin, this, is_new_driving_animation);
    goto LABEL_21;
  }
LABEL_26:
  while ( to_begin != to_end )
  {
    vostok::animation::mixing::n_ary_tree_comparer::add_animation(this, to_begin, new_weight_driving_animation);
    to_begin = to_begin->m_next_weight_animation;
  }
}
