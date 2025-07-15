void __thiscall survarium::base_player::remove(survarium::base_player *this, BOOL real_remove)
{
  bool v3; // zf
  survarium::interactive_object *m_current_active_object; // ecx
  survarium::base_game_effect_presenter *m_effect_presenter; // ecx

  v3 = !this->m_is_alive;
  this->m_has_been_inserted = 0;
  if ( v3 )
    survarium::base_player::deactivate_physics(this, (int)this);
  else
    survarium::base_player::remove_alive(this, (int)this, real_remove);
  if ( real_remove )
  {
    m_current_active_object = this->m_current_active_object;
    if ( m_current_active_object )
    {
      m_current_active_object->deactivate(m_current_active_object, real_remove);
      this->m_current_active_object = 0;
    }
    m_effect_presenter = this->m_effect_presenter;
    if ( m_effect_presenter )
      m_effect_presenter->clear(m_effect_presenter);
  }
  this->m_target_active_object = 0;
}
