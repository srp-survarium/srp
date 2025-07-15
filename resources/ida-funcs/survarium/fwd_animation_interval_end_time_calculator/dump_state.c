char __thiscall survarium::fwd_animation_interval_end_time_calculator::dump_state(
        survarium::fwd_animation_interval_end_time_calculator *this,
        const vostok::animation::animation_states_dumper::animation_state_info *info)
{
  if ( info->animated_object == this->m_animated_object
    && stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
         (char *)this->m_animations,
         (int *)&info->intervals[info->interval_id],
         (char *)&this->m_animated_object) != (char *)&this->m_animated_object )
  {
    this->m_current_time_scale = info->time_scale;
    this->m_remaining_interval_time_to_end = info->intervals[info->interval_id].m_length - info->interval_time;
  }
  return 1;
}
