double __thiscall vostok::sound::sound_spl::get_loudness(vostok::sound::sound_spl *this, float distance)
{
  float normalized_level; // [esp+50h] [ebp-8h]
  float max_spl; // [esp+54h] [ebp-4h]

  max_spl = this->m_curve_line.curve_value_max - this->m_curve_line.curve_value_min;
  normalized_level = vostok::math::curve_line_points<float,0>::evaluate(
                       &this->m_curve_line,
                       distance,
                       0.0,
                       range_time_type,
                       0.0,
                       0.0)
                   - this->m_curve_line.curve_value_min;
  if ( normalized_level >= 0.0 )
    return normalized_level / max_spl;
  else
    return 0.0;
}
