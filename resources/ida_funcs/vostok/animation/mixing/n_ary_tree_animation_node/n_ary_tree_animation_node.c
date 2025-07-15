void __userpurge vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
        vostok::animation::mixing::n_ary_tree_animation_node *weight_driving_animation@<edx>,
        const vostok::animation::mixing::animation_interval *animation_intervals_end@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *this,
        const vostok::animation::mixing::animation_interval *animation_intervals_begin,
        unsigned __int8 unique_animation_id,
        unsigned int start_cycle_animation_interval_id,
        const void *animated_object,
        vostok::animation::mixing::playback_enum playback_type,
        const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *time_calculator,
        unsigned int time_synchronization_group_id,
        bool override_existing_animation,
        bool is_positive_event_direction,
        bool can_generate_user_defined_events,
        unsigned int additivity_priority,
        unsigned int bones_mask,
        unsigned int operands_count,
        bool is_transitting_to_zero)
{
  this->m_operands_count = operands_count;
  this->__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)&vostok::animation::mixing::n_ary_tree_animation_node::`vftable';
  this->m_time_calculator.m_Closure.m_pthis = 0;
  this->m_time_calculator.m_Closure.m_pFunction = 0;
  this->m_time_calculator = *time_calculator;
  this->m_weight_driving_animation = weight_driving_animation;
  this->m_time_driving_animation = 0;
  this->m_animation_state = 0;
  this->m_animation_intervals = animation_intervals_begin;
  this->m_weight_interpolator = weight_driving_animation->m_weight_interpolator;
  this->m_next_weight_animation = 0;
  this->m_next_time_animation = 0;
  this->m_animated_object = animated_object;
  this->m_time_synchronization_group_id = time_synchronization_group_id;
  this->m_weight_synchronization_group_id = weight_driving_animation->m_weight_synchronization_group_id;
  this->m_animation_intervals_count = animation_intervals_end - animation_intervals_begin;
  this->m_start_cycle_interval_id = start_cycle_animation_interval_id;
  this->m_playback_type = playback_type;
  this->m_additivity_priority = additivity_priority;
  this->m_bones_mask = bones_mask;
  this->m_unique_animation_id = unique_animation_id;
  this->m_is_transitting_to_zero = is_transitting_to_zero;
  this->m_override_existing_animation = override_existing_animation;
  this->m_is_positive_event_direction = is_positive_event_direction;
  this->m_can_generate_events = can_generate_user_defined_events;
  this->user_data = -33698355;
}
