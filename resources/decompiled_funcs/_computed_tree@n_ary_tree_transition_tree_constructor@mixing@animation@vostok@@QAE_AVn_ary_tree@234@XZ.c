vostok::animation::mixing::n_ary_tree *__usercall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::computed_tree@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree *a2@<eax>)
{
  vostok::animation::mixing::n_ary_tree::n_ary_tree(
    a2,
    this->m_weight_root,
    this->m_time_root,
    this->m_cloner.m_interpolators,
    this->m_animation_states,
    this->m_animation_events,
    this->m_animated_objects,
    this->m_reference_counter,
    this->m_animations_count,
    this->m_animated_objects_count,
    this->m_cloner.m_interpolators_count,
    this->m_current_time_in_ms);
  return a2;
}
