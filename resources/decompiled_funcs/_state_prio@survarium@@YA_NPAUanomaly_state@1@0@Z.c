bool __cdecl survarium::state_prio(survarium::anomaly_state *s1, survarium::anomaly_state *s2)
{
  if ( s1->enabled != s2->enabled )
    return !s1->enabled < !s2->enabled;
  if ( s1->energy_threshold == s2->energy_threshold )
    return s1->energy_threshold < s2->energy_threshold;
  else
    return s2->select_priority < s1->select_priority;
}
