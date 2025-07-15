void __thiscall vostok::animation::mixing::n_ary_tree_comparer::merge_weight_synchronization_groups(
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_comparer *from_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *to_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *to_end,
        vostok::animation::mixing::n_ary_tree_animation_node *new_weight_driving_animation,
        vostok::animation::mixing::n_ary_tree_animation_node *is_new_driving_animation,
        unsigned int a8)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // eax
  int v9; // esi
  void *v10; // esp
  vostok::animation::mixing::n_ary_tree_animation_node **v11; // ecx
  const boost::function<unsigned char __cdecl(void const *)> *m_animated_object_resolver; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v14; // esi
  int v15; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v16[3]; // [esp+0h] [ebp-2Ch] BYREF
  vostok::animation::mixing::animation_comparer_predicate v17; // [esp+Ch] [ebp-20h] BYREF
  vostok::animation::mixing::animation_comparer_predicate v18; // [esp+14h] [ebp-18h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node **v19; // [esp+20h] [ebp-Ch]
  char v20; // [esp+27h] [ebp-5h]
  vostok::animation::mixing::n_ary_tree_animation_node **v21; // [esp+3Ch] [ebp+10h]

  v8 = from_end;
  v9 = 0;
  while ( v8 != to_begin )
  {
    v8 = v8->m_next_weight_animation;
    ++v9;
  }
  v18.m_animated_object_resolver = from_begin->m_animated_object_resolver;
  v18.m_use_synchronized_animations = 0;
  v18.m_use_overriding_animations = 1;
  v20 = 0;
  v10 = alloca(4 * v9);
  v19 = v16;
  if ( from_end != to_begin )
  {
    do
    {
      if ( vostok::animation::mixing::animation_comparer_predicate::operator()(&v18, from_end, is_new_driving_animation) )
      {
        v11 = v19++;
        *v11 = from_end;
      }
      else
      {
        v20 = 1;
      }
      from_end = from_end->m_next_weight_animation;
    }
    while ( from_end != to_begin );
    if ( v20 )
      --v9;
  }
  m_animated_object_resolver = from_begin->m_animated_object_resolver;
  LOWORD(v19) = 256;
  v21 = &v16[v9];
  stlp_std::sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::animation_comparer_less_predicate>(
    v16,
    v21,
    (vostok::animation::mixing::animation_comparer_less_predicate)__PAIR64__(
                                                                    (unsigned int)v19,
                                                                    (unsigned int)m_animated_object_resolver));
  v17.m_animated_object_resolver = from_begin->m_animated_object_resolver;
  v17.m_use_synchronized_animations = 0;
  v17.m_use_overriding_animations = 1;
  v14 = v16;
  if ( v16 != v21 )
  {
    while ( 1 )
    {
      if ( to_end == new_weight_driving_animation )
      {
LABEL_22:
        while ( v14 != v21 )
          vostok::animation::mixing::n_ary_tree_comparer::remove_animation(
            from_begin,
            *v14++,
            is_new_driving_animation,
            a8);
        goto LABEL_25;
      }
      v15 = vostok::animation::mixing::animation_comparer_predicate::operator()(&v17, *v14, to_end);
      if ( !v15 )
        break;
      if ( v15 != 1 )
      {
        vostok::animation::mixing::n_ary_tree_comparer::add_animation(from_begin, to_end, is_new_driving_animation);
LABEL_18:
        to_end = to_end->m_next_weight_animation;
        goto LABEL_19;
      }
      vostok::animation::mixing::n_ary_tree_comparer::remove_animation(from_begin, *v14++, is_new_driving_animation, a8);
LABEL_19:
      if ( v14 == v21 )
        goto LABEL_22;
    }
    vostok::animation::mixing::n_ary_tree_comparer::change_animation(from_begin, to_end, *v14++, a8);
    goto LABEL_18;
  }
LABEL_25:
  while ( to_end != new_weight_driving_animation )
  {
    vostok::animation::mixing::n_ary_tree_comparer::add_animation(from_begin, to_end, is_new_driving_animation);
    to_end = to_end->m_next_weight_animation;
  }
}
