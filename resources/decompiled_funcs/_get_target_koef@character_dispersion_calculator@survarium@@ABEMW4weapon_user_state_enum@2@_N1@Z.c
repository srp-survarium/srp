double __thiscall survarium::character_dispersion_calculator::get_target_koef(
        survarium::character_dispersion_calculator *this,
        survarium::weapon_user_state_enum character_state,
        bool is_moving,
        bool is_aiming)
{
  double result; // st7
  float crouch_aim_multiplier; // [esp+0h] [ebp-1Ch]
  float crouch_walk_aim_multiplier; // [esp+4h] [ebp-18h]
  float idle_aim_multiplier; // [esp+8h] [ebp-14h]
  float walk_aim_multiplier; // [esp+Ch] [ebp-10h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  switch ( character_state )
  {
    case type_stand:
      if ( is_moving )
      {
        if ( is_aiming )
          walk_aim_multiplier = this->m_params->walk_aim_multiplier;
        else
          walk_aim_multiplier = this->m_params->walk_multiplier;
        result = walk_aim_multiplier;
      }
      else
      {
        if ( is_aiming )
          idle_aim_multiplier = this->m_params->idle_aim_multiplier;
        else
          idle_aim_multiplier = this->m_params->idle_multiplier;
        result = idle_aim_multiplier;
      }
      break;
    case type_crouch:
      if ( is_moving )
      {
        if ( is_aiming )
          crouch_walk_aim_multiplier = this->m_params->crouch_walk_aim_multiplier;
        else
          crouch_walk_aim_multiplier = this->m_params->crouch_walk_multiplier;
        result = crouch_walk_aim_multiplier;
      }
      else
      {
        if ( is_aiming )
          crouch_aim_multiplier = this->m_params->crouch_aim_multiplier;
        else
          crouch_aim_multiplier = this->m_params->crouch_multiplier;
        result = crouch_aim_multiplier;
      }
      break;
    case type_sprint:
      result = this->m_params->run_multiplier;
      break;
    case type_jump:
      result = this->m_params->jump_multiplier;
      break;
    case type_preview:
      result = 1.0;
      break;
  }
  return result;
}
