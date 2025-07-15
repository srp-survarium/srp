void __thiscall survarium::jump_logic::activate(survarium::jump_logic *this)
{
  const survarium::player_input *v1; // eax

  v1 = this->m_user->input(this->m_user);
  this->m_jumping_direction = survarium::get_move_direction(v1);
  this->m_is_jump_from_right_leg = !this->m_owner->m_right_leg_is_supporting;
}
