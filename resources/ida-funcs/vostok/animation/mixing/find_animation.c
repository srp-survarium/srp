vostok::animation::mixing::n_ary_tree_animation_node *__usercall vostok::animation::mixing::find_animation@<eax>(
        const boost::function<unsigned char __cdecl(void const *)> *animated_object_resolver@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *const begin@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *const end,
        vostok::animation::mixing::n_ary_tree_animation_node *animation_to_find)
{
  vostok::animation::mixing::animation_comparer_predicate v6; // [esp+8h] [ebp-8h] BYREF

  v6.m_animated_object_resolver = animated_object_resolver;
  v6.m_use_synchronized_animations = 0;
  v6.m_use_overriding_animations = 0;
  while ( 1 )
  {
    if ( begin == end )
      return 0;
    if ( !vostok::animation::mixing::animation_comparer_predicate::operator()(&v6, begin, animation_to_find) )
      break;
    begin = begin->m_next_weight_animation;
  }
  return begin;
}
