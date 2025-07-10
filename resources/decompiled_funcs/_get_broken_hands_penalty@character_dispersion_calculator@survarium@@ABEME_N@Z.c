double __thiscall survarium::character_dispersion_calculator::get_broken_hands_penalty(
        survarium::character_dispersion_calculator *this,
        unsigned __int8 broken_hands_count,
        bool using_double_handed_weapon)
{
  const vostok::math::float4x4 *injury_penalty_for_double_handed_low; // [esp+4h] [ebp-10h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  switch ( broken_hands_count )
  {
    case 0u:
      return 1.0;
    case 1u:
      if ( using_double_handed_weapon )
        injury_penalty_for_double_handed_low = (const vostok::math::float4x4 *)LODWORD(this->m_params->injury_penalty_for_double_handed);
      else
        injury_penalty_for_double_handed_low = clear_value;
      return *(float *)&injury_penalty_for_double_handed_low;
    case 2u:
      if ( using_double_handed_weapon )
        return this->m_params->injury_penalty_for_double_handed;
      else
        return this->m_params->injury_penalty_for_one_handed;
    default:
      return 1.0;
  }
}
