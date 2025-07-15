void __fastcall vostok::animation::mixing::n_ary_tree_event_iterator::n_ary_tree_event_iterator(
        vostok::animation::mixing::animation_state *animation,
        vostok::animation::subscribed_channel **channels_head,
        vostok::animation::mixing::n_ary_tree_event_iterator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node,
        unsigned int start_time_in_ms,
        unsigned __int16 initial_event_types)
{
  float animation_interval_time; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_event_iterator *animation_interval_id; // ecx
  vostok::animation::mixing::n_ary_tree_event_iterator *v8; // ecx

  animation_interval_time = animation->animation_interval_time;
  animation_interval_id = (vostok::animation::mixing::n_ary_tree_animation_event_iterator *)animation->animation_interval_id;
  this->m_animation_event_iterator.m_value.animation_interval_id = (unsigned int)animation_interval_id;
  this->m_animation_event_iterator.m_value.animation_interval_time = animation_interval_time;
  this->m_animation_event_iterator.m_value.event_time_in_ms = start_time_in_ms;
  this->m_animation_event_iterator.m_value.event_type = initial_event_types & 1;
  this->m_animation_event_iterator.m_value.channel_ids = 0;
  this->m_animation_event_iterator.m_value.domain_data = -1;
  this->m_animation_event_iterator.m_animation = animation_node;
  this->m_animation_event_iterator.m_channels_head = channels_head;
  vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(
    animation_interval_id,
    (int)this,
    initial_event_types & 1);
  vostok::animation::mixing::n_ary_tree_weight_event_iterator::n_ary_tree_weight_event_iterator(
    &this->m_weight_event_iterator,
    animation_node,
    start_time_in_ms,
    initial_event_types & 0x80);
  this->m_value.animation_interval_id = -1;
  this->m_value.event_time_in_ms = -1;
  this->m_value.event_type = 0;
  this->m_value.channel_ids = 0;
  this->m_value.animation_interval_time = -4.2170408e37;
  this->m_value.domain_data = -1;
  this->m_animation_node = animation_node;
  vostok::animation::mixing::n_ary_tree_event_iterator::select_state(v8, (int)this);
}
