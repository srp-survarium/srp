vostok::animation::mixing::n_ary_tree_event_iterator *__usercall vostok::animation::mixing::n_ary_tree_event_iterator::operator++@<eax>(
        vostok::animation::mixing::n_ary_tree_event_iterator *this@<ecx>,
        int a2@<edi>)
{
  if ( (*(_BYTE *)(a2 + 52) & 1) != 0 )
    vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(
      &this->m_animation_event_iterator,
      a2,
      0,
      (unsigned __int8 *)0xFF);
  if ( (*(_BYTE *)(a2 + 52) & 2) != 0 )
    vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator++(
      (vostok::animation::mixing::n_ary_tree_weight_event_iterator *)this,
      a2 + 20);
  vostok::animation::mixing::n_ary_tree_event_iterator::select_state(this, (_DWORD *)a2);
  return (vostok::animation::mixing::n_ary_tree_event_iterator *)a2;
}
