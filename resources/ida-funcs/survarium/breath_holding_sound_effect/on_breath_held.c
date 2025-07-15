void __thiscall survarium::breath_holding_sound_effect::on_breath_held(
        survarium::breath_holding_sound_effect *this,
        bool held)
{
  survarium::player *m_user; // eax
  survarium::breath_holding_sound_effect *v3; // ecx

  m_user = this->m_user;
  if ( m_user->is_local )
  {
    this->m_breath_held = held;
    if ( held
      && !this->m_sound_instance.m_object
      && !survarium::base_player::is_in_past((survarium::base_player *)this, (int)m_user, m_user->m_current_time_in_ms) )
    {
      survarium::breath_holding_sound_effect::play_start_sound(v3, v3);
    }
  }
}
