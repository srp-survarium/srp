void __usercall vostok::animation::mixing::n_ary_tree_weight_event_iterator::invert_times(
        vostok::animation::mixing::n_ary_tree_weight_event_iterator *this@<ecx>,
        unsigned int time_in_ms@<eax>)
{
  if ( this->m_event_type )
    this->m_time_in_ms = time_in_ms - this->m_time_in_ms;
}
