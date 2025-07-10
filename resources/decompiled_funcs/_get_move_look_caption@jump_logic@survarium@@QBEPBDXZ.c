const char *__thiscall survarium::jump_logic::get_move_look_caption(survarium::jump_logic *this)
{
  __int32 v3; // [esp+8h] [ebp-14h]
  survarium::weapon_user_animations_selector *m_owner; // [esp+10h] [ebp-Ch]

  m_owner = this->m_owner;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_owner);
  v3 = 3 * this->m_jumping_direction + 2;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_owner->m_animations.m_object);
  return survarium::stand_animations_captions[v3];
}
