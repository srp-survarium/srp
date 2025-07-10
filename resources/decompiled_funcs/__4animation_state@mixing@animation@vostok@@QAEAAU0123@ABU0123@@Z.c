vostok::animation::mixing::animation_state *__userpurge vostok::animation::mixing::animation_state::operator=@<eax>(
        const vostok::animation::mixing::animation_state *__that@<eax>,
        vostok::animation::mixing::animation_state *this)
{
  const vostok::animation::mixing::animation_state *v2; // esi

  v2 = __that;
  vostok::animation::mixing::bone_matrices_computer_data::operator=(
    &this->bone_matrices_computer,
    &__that->bone_matrices_computer);
  this->animation_interval_id = v2->animation_interval_id;
  this->previous_animation_interval_id = v2->previous_animation_interval_id;
  this->animation_interval_time = v2->animation_interval_time;
  v2 = (const vostok::animation::mixing::animation_state *)((char *)v2 + 120);
  this->weight = *(float *)&v2[-1].event_iterator.m_value.event_time_in_ms;
  this->animation_time = *(float *)&v2[-1].event_iterator.m_value.event_type;
  this->animation_time_threshold = *(float *)&v2[-1].event_iterator.m_animation_node;
  this->are_there_any_weight_transitions = v2[-1].event_iterator.m_state;
  this->is_freezed = BYTE1(v2[-1].event_iterator.m_state);
  qmemcpy(&this->event_iterator, v2, sizeof(this->event_iterator));
  return this;
}
