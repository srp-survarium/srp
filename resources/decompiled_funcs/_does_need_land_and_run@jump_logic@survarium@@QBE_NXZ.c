bool __thiscall survarium::jump_logic::does_need_land_and_run(survarium::jump_logic *this)
{
  const survarium::player_input *v1; // eax
  bool result; // al
  bool v3; // [esp+0h] [ebp-2Ch]
  bool v4; // [esp+4h] [ebp-28h]
  bool v5; // [esp+8h] [ebp-24h]
  bool v6; // [esp+Ch] [ebp-20h]
  bool v7; // [esp+10h] [ebp-1Ch]
  bool v8; // [esp+14h] [ebp-18h]
  bool v9; // [esp+18h] [ebp-14h]
  bool v10; // [esp+1Ch] [ebp-10h]
  survarium::move_direction_enum landing_direction; // [esp+28h] [ebp-4h]

  v1 = this->m_user->input(this->m_user);
  landing_direction = survarium::get_move_direction(v1);
  switch ( this->m_jumping_direction )
  {
    case move_direction_on_site:
      result = 0;
      break;
    case move_direction_fwd:
      v10 = landing_direction == move_direction_fwd
         || landing_direction == move_direction_fwd_left
         || landing_direction == move_direction_fwd_right;
      result = v10;
      break;
    case move_direction_fwd_right:
      v9 = landing_direction == move_direction_fwd_right
        || landing_direction == move_direction_fwd
        || landing_direction == move_direction_right;
      result = v9;
      break;
    case move_direction_right:
      v8 = landing_direction == move_direction_right
        || landing_direction == move_direction_fwd_right
        || landing_direction == move_direction_back_right;
      result = v8;
      break;
    case move_direction_back_right:
      v7 = landing_direction == move_direction_back_right
        || landing_direction == move_direction_right
        || landing_direction == move_direction_back;
      result = v7;
      break;
    case move_direction_back:
      v6 = landing_direction == move_direction_back
        || landing_direction == move_direction_back_right
        || landing_direction == move_direction_back_left;
      result = v6;
      break;
    case move_direction_back_left:
      v5 = landing_direction == move_direction_back_left
        || landing_direction == move_direction_back
        || landing_direction == move_direction_left;
      result = v5;
      break;
    case move_direction_left:
      v4 = landing_direction == move_direction_left
        || landing_direction == move_direction_back_left
        || landing_direction == move_direction_fwd_left;
      result = v4;
      break;
    case move_direction_fwd_left:
      v3 = landing_direction == move_direction_fwd_left
        || landing_direction == move_direction_left
        || landing_direction == move_direction_fwd;
      result = v3;
      break;
  }
  return result;
}
