unsigned int __cdecl survarium::hand_to_weapon_ik_processor::get_hand_new_start_transition_time(
        const survarium::hand_to_weapon_ik_processor::hand *h,
        unsigned int current_time_in_ms)
{
  unsigned int current_transition_time; // [esp+4h] [ebp-4h]

  current_transition_time = current_time_in_ms - h->start_transition_time_in_ms;
  if ( current_transition_time >= 0x12C )
    return current_time_in_ms;
  else
    return current_time_in_ms - (300 - current_transition_time);
}
