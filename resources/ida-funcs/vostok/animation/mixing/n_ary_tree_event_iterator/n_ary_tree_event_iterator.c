void __userpurge vostok::animation::mixing::n_ary_tree_event_iterator::n_ary_tree_event_iterator(
        vostok::animation::mixing::n_ary_tree_event_iterator *this@<esi>,
        vostok::animation::mixing::animation_state *animation@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<edi>,
        unsigned int start_time_in_ms,
        unsigned __int16 initial_event_types,
        unsigned __int8 *disabled_channel_ids_at_start_time)
{
  float animation_interval_time; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_event_iterator *animation_interval_id; // ecx
  vostok::animation::mixing::n_ary_tree_event_iterator *v8; // ecx
  unsigned int m_weight_transition_end_time_in_ms; // eax
  unsigned __int16 m_event_type; // ax
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator v11; // [esp+4h] [ebp-10h] BYREF

  animation_interval_time = animation->animation_interval_time;
  animation_interval_id = (vostok::animation::mixing::n_ary_tree_animation_event_iterator *)animation->animation_interval_id;
  this->m_animation_event_iterator.m_value.animation_interval_id = (unsigned int)animation_interval_id;
  this->m_animation_event_iterator.m_value.animation_interval_time = animation_interval_time;
  this->m_animation_event_iterator.m_value.event_time_in_ms = start_time_in_ms;
  this->m_animation_event_iterator.m_value.event_type = initial_event_types & 1;
  this->m_animation_event_iterator.m_value.channel_ids = 0;
  this->m_animation_event_iterator.m_value.domain_data = -1;
  this->m_animation_event_iterator.m_animation = animation_node;
  vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(
    animation_interval_id,
    (int)this,
    initial_event_types & 1,
    disabled_channel_ids_at_start_time);
  v11.m_weight_transition_end_time_in_ms = -1;
  this->m_weight_event_iterator.m_animation = animation_node;
  v11.__vftable = (vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::`vftable';
  v11.m_event_type = 0;
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(&v11, animation_node);
  m_weight_transition_end_time_in_ms = v11.m_weight_transition_end_time_in_ms;
  this->m_weight_event_iterator.m_time_in_ms = v11.m_weight_transition_end_time_in_ms;
  if ( m_weight_transition_end_time_in_ms == -1 )
  {
    this->m_weight_event_iterator.m_animation = 0;
    m_event_type = 0;
  }
  else if ( (initial_event_types & 0x80u) != 0 )
  {
    this->m_weight_event_iterator.m_time_in_ms = start_time_in_ms;
    m_event_type = 128;
  }
  else
  {
    m_event_type = v11.m_event_type;
  }
  this->m_weight_event_iterator.m_event_type = m_event_type;
  this->m_value.animation_interval_id = -1;
  this->m_value.event_time_in_ms = -1;
  this->m_value.animation_interval_time = -4.2170408e37;
  this->m_value.event_type = 0;
  this->m_value.channel_ids = 0;
  this->m_value.domain_data = -1;
  this->m_animation_node = animation_node;
  vostok::animation::mixing::n_ary_tree_event_iterator::select_state(v8, this);
}
