char __thiscall survarium::body_part_parameters::can_affect_death(survarium::body_part_parameters *this)
{
  unsigned int i; // [esp+Ch] [ebp-10h]
  survarium::affects_threshold *it_threshold; // [esp+18h] [ebp-4h]

  for ( it_threshold = this->m_thresholds.m_first; it_threshold; it_threshold = it_threshold->next )
  {
    for ( i = 0; i < it_threshold->m_affects_count; ++i )
    {
      if ( !*((_DWORD *)&it_threshold[1].next + i) )
        return 1;
    }
  }
  return 0;
}
