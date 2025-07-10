double __thiscall vostok::animation::linear_interpolator::interpolated_value(
        vostok::animation::linear_interpolator *this,
        float current_transition_time)
{
  return current_transition_time / this->m_total_transition_time;
}
