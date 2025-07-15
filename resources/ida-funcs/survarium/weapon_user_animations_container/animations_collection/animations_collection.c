void __thiscall survarium::weapon_user_animations_container::animations_collection::animations_collection(
        survarium::weapon_user_animations_container::animations_collection *this)
{
  memset(this, 0, 0x6Cu);
  memset(this->m_aimed_stand_animations, 0, sizeof(this->m_aimed_stand_animations));
  memset(this->m_crouch_animations, 0, sizeof(this->m_crouch_animations));
  memset(this->m_aimed_crouch_animations, 0, sizeof(this->m_aimed_crouch_animations));
  memset(this->m_sprint_animations, 0, sizeof(this->m_sprint_animations));
  memset(this->m_jump_animations, 0, sizeof(this->m_jump_animations));
  memset(this->m_stand_hit_animations, 0, sizeof(this->m_stand_hit_animations));
}
