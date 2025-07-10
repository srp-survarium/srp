void __userpurge vostok::animation::mixing::n_ary_tree_animation_event_iterator::n_ary_tree_animation_event_iterator(
        vostok::animation::mixing::animation_state *animation_state@<ecx>,
        unsigned __int16 event_types@<ax>,
        vostok::animation::mixing::n_ary_tree_animation_event_iterator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node,
        unsigned int start_time_in_ms,
        vostok::animation::subscribed_channel **channel_ids,
        vostok::animation::subscribed_channel **channels_head)
{
  float animation_interval_time; // xmm0_4

  animation_interval_time = animation_state->animation_interval_time;
  this->m_value.animation_interval_id = animation_state->animation_interval_id;
  this->m_value.event_time_in_ms = start_time_in_ms;
  this->m_value.animation_interval_time = animation_interval_time;
  this->m_value.event_type = event_types;
  this->m_value.channel_ids = 0;
  this->m_value.domain_data = -1;
  this->m_animation = animation_node;
  this->m_channels_head = channel_ids;
  vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(
    (vostok::animation::mixing::n_ary_tree_animation_event_iterator *)animation_node,
    (int)this,
    event_types);
}
