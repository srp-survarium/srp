vostok::animation::mixing::n_ary_tree_animation_node *__usercall vostok::animation::mixing::find_animation@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_node *const begin@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *const end@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation_to_find)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v3; // esi
  vostok::animation::mixing::animation_comparer_equal_predicate equal_predicate; // [esp+8h] [ebp-4h] BYREF

  v3 = begin;
  equal_predicate.m_predicate.m_use_synchronized_animations = 0;
  equal_predicate.m_predicate.m_use_overriding_animations = 0;
  if ( begin == end )
    return 0;
  while ( vostok::animation::mixing::animation_comparer_predicate::operator()(
            &equal_predicate.m_predicate,
            v3,
            animation_to_find) )
  {
    v3 = v3->m_next_weight_animation;
    if ( v3 == end )
      return 0;
  }
  return v3;
}
