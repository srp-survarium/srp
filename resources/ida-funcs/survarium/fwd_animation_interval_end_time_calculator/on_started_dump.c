void __thiscall survarium::fwd_animation_interval_end_time_calculator::on_started_dump(
        survarium::fwd_animation_interval_end_time_calculator *this,
        unsigned int current_time_in_ms)
{
  this->m_current_time_in_ms = current_time_in_ms;
  this->m_remaining_interval_time_to_end = 0.0;
}
