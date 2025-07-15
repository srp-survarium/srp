void __thiscall survarium::weapon::process_finger_correction(
        survarium::weapon *this,
        unsigned int current_time_in_ms,
        vostok::math::float4x4 *const user_matrices)
{
  if ( s_enable_finger_corrector_value )
    survarium::fingers_to_weapon_corrector::process(
      (survarium::fingers_to_weapon_corrector *)this,
      (int)&this->m_fingers_corrector,
      current_time_in_ms,
      user_matrices);
}
