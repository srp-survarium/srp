void __thiscall survarium::jump_logic::jump_logic(
        survarium::jump_logic *this,
        survarium::weapon_user_animations_selector *owner)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_owner = owner;
  this->m_user = 0;
  this->m_logic = 0;
  this->m_animated_object = 0;
  this->m_jumping_direction = move_direction_on_site;
  this->m_is_jump_from_right_leg = 1;
  survarium::jump_logic::initialize_logic(this);
}
