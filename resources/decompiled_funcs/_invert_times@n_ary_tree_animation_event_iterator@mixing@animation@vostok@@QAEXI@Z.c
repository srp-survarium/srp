void __usercall vostok::animation::mixing::n_ary_tree_animation_event_iterator::invert_times(
        vostok::animation::mixing::n_ary_tree_animation_event_iterator *this@<ecx>,
        unsigned int time_in_ms@<eax>)
{
  if ( this->m_value.event_type )
    this->m_value.event_time_in_ms = time_in_ms - this->m_value.event_time_in_ms;
}
