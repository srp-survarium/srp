void __thiscall survarium::portable_interactive_object::process_hands_ik(
        survarium::portable_interactive_object *this,
        const vostok::math::float4x4 *current_time_in_ms,
        vostok::math::float4x4 *const user_matrices,
        vostok::math::float4x4 *const item_matrices)
{
  bool is_first_view; // al
  vostok::animation::hand_to_weapon_ik_solver *v6; // ecx

  is_first_view = survarium::player::is_first_view((survarium::player *)this, (int)this->m_user);
  vostok::animation::hand_to_weapon_ik_solver::process(
    v6,
    (int)&this->m_hand_ik_solver,
    current_time_in_ms,
    item_matrices,
    is_first_view,
    user_matrices);
}
