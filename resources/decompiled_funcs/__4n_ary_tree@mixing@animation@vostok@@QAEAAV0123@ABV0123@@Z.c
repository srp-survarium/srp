vostok::animation::mixing::n_ary_tree *__usercall vostok::animation::mixing::n_ary_tree::operator=@<eax>(
        vostok::animation::mixing::n_ary_tree *this@<esi>,
        const vostok::animation::mixing::n_ary_tree *other@<edi>,
        vostok::animation::mixing::n_ary_tree *a3@<ecx>)
{
  vostok::animation::mixing::n_ary_tree *result; // eax
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // eax
  vostok::animation::mixing::n_ary_tree_intrusive_base *v5; // ecx

  result = this;
  if ( this != other )
  {
    vostok::animation::mixing::n_ary_tree::destroy(a3, (int)this);
    m_object = 0;
    if ( other->m_reference_counter.m_object )
    {
      m_object = other->m_reference_counter.m_object;
      ++other->m_reference_counter.m_object->m_reference_count;
    }
    v5 = this->m_reference_counter.m_object;
    this->m_reference_counter.m_object = m_object;
    if ( v5 )
      --v5->m_reference_count;
    this->m_weight_root = other->m_weight_root;
    this->m_time_root = other->m_time_root;
    this->m_interpolators = other->m_interpolators;
    this->m_animation_states = other->m_animation_states;
    this->m_animation_events = other->m_animation_events;
    this->m_animated_objects = other->m_animated_objects;
    this->m_animations_count = other->m_animations_count;
    this->m_animated_objects_count = other->m_animated_objects_count;
    this->m_interpolators_count = other->m_interpolators_count;
    this->m_tree_actual_time_in_ms = other->m_tree_actual_time_in_ms;
    this->m_is_logging_enabled = other->m_is_logging_enabled;
    return this;
  }
  return result;
}
