int __cdecl survarium::state_prio(survarium::anomaly_state *a1, survarium::anomaly_state *a2)
{
  unsigned int select_priority; // edx
  unsigned int v3; // esi
  bool v4; // cf
  unsigned int energy_threshold; // edx
  unsigned int v6; // esi
  int result; // eax

  select_priority = a1->select_priority;
  v3 = a2->select_priority;
  v4 = v3 < select_priority;
  if ( v3 != select_priority )
    return v4;
  energy_threshold = a1->energy_threshold;
  v6 = a2->energy_threshold;
  v4 = v6 < energy_threshold;
  if ( v6 != energy_threshold )
    return v4;
  if ( a1->shoot_trigger == a2->shoot_trigger )
    LOBYTE(result) = a1->zone_activity_trigger;
  else
    LOBYTE(result) = a1->shoot_trigger;
  return (unsigned __int8)result;
}
