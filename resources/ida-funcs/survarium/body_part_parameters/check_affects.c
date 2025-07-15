void __thiscall survarium::body_part_parameters::check_affects(
        survarium::body_part_parameters *this,
        unsigned int current_time_in_ms)
{
  survarium::affects_threshold *it_threshold; // [esp+Ch] [ebp-4h]

  for ( it_threshold = this->m_thresholds.m_first; it_threshold; it_threshold = it_threshold->next )
  {
    if ( (float)(this->m_max_health * (float)it_threshold->m_value) >= this->m_health )
      survarium::body_part_parameters::apply_affects(it_threshold->m_bodypart, it_threshold, current_time_in_ms);
  }
}
