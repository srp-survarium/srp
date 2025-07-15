void __userpurge vostok::animation::hand_to_weapon_ik_solver::activate_hand(
        const vostok::animation::hand_to_weapon_ik_solver::hands_enum hand@<eax>,
        bool active@<dl>,
        vostok::animation::hand_to_weapon_ik_solver *this,
        vostok::animation::hand_to_weapon_ik_solver::ik_locator_id_enum __formal,
        unsigned int locator_id,
        const unsigned int current_time_in_ms)
{
  vostok::animation::hand_to_weapon_ik_solver::hand *v6; // eax
  vostok::animation::hand_to_weapon_ik_solver::ik_locator_id_enum *p_locator_id; // ecx

  v6 = &this->m_hands[hand];
  if ( v6->is_active != active || v6->locator_id != __formal )
  {
    p_locator_id = &v6->locator_id;
    v6->previous_locator_id = v6->locator_id;
    if ( active )
      *p_locator_id = __formal;
    else
      *p_locator_id = ik_locator_id_count;
    v6->is_active = active;
    v6->start_transition_time_in_ms = locator_id;
  }
}
