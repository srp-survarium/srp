void __usercall vostok::animation::mixing::n_ary_tree_event_iterator::operator++(
        vostok::animation::mixing::n_ary_tree_event_iterator *this@<ecx>,
        int a2@<eax>)
{
  if ( (*(_BYTE *)(a2 + 56) & 1) != 0 )
    vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(&this->m_animation_event_iterator, a2, 0);
  if ( (*(_BYTE *)(a2 + 56) & 2) != 0 )
    vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator++(
      (vostok::animation::mixing::n_ary_tree_weight_event_iterator *)this,
      a2 + 24);
  vostok::animation::mixing::n_ary_tree_event_iterator::select_state(this, a2);
}
