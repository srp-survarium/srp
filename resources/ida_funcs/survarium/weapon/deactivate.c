void __thiscall survarium::weapon::deactivate(survarium::weapon *this)
{
  ((void (__stdcall *)(const char *, survarium::base_player *))this->m_user->unsubscribe_animation_player)(
    "sound_events",
    this->m_user);
  this->m_user->unsubscribe_animation_player(this->m_user, "shell_extraction", this);
  this->m_user->unsubscribe_animation_player(this->m_user, "left_hand_corrector", this);
  this->m_user->unsubscribe_animation_player(this->m_user, "right_hand_corrector", this);
  survarium::weapon_core::deactivate(this);
}
