BOOL __cdecl survarium::hand_to_weapon_ik_processor::hand_need_interpolation(
        const survarium::hand_to_weapon_ik_processor::hand *h,
        unsigned int current_time_in_ms)
{
  return current_time_in_ms - h->start_transition_time_in_ms < 0x12C;
}
