bool __cdecl survarium::hand_to_weapon_ik_processor::hand_need_correction(
        const survarium::hand_to_weapon_ik_processor::hand *h,
        unsigned int current_time_in_ms)
{
  return h->is_active || survarium::hand_to_weapon_ik_processor::hand_need_interpolation(h, current_time_in_ms);
}
