vostok::animation::mixing::animation_state *const *__cdecl stlp_std::priv::__median<vostok::animation::mixing::animation_state *,event_iterator_predicate>(
        vostok::animation::mixing::animation_state *const *__a,
        vostok::animation::mixing::animation_state *const *__b,
        vostok::animation::mixing::animation_state *const *__c)
{
  vostok::animation::mixing::animation_state *const *v3; // ebp
  bool is_less; // al
  vostok::animation::mixing::n_ary_tree_event_iterator *p_event_iterator; // esi
  bool v6; // zf
  vostok::animation::mixing::animation_state *const *result; // eax

  v3 = __b;
  is_less = vostok::animation::mixing::n_ary_tree_event_iterator::is_less(
              &(*__a)->event_iterator,
              &(*__b)->event_iterator);
  p_event_iterator = &(*__c)->event_iterator;
  if ( !is_less )
  {
    if ( vostok::animation::mixing::n_ary_tree_event_iterator::is_less(&(*__a)->event_iterator, p_event_iterator) )
      return __a;
LABEL_4:
    v6 = !vostok::animation::mixing::n_ary_tree_event_iterator::is_less(&(*v3)->event_iterator, &(*__c)->event_iterator);
    result = __c;
    if ( !v6 )
      return result;
    return v3;
  }
  if ( !vostok::animation::mixing::n_ary_tree_event_iterator::is_less(&(*__b)->event_iterator, p_event_iterator) )
  {
    v3 = __a;
    goto LABEL_4;
  }
  return v3;
}
