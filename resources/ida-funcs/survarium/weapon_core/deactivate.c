void __thiscall survarium::weapon_core::deactivate(survarium::weapon_core *this, BOOL real_remove)
{
  survarium::base_player *v3; // ecx
  vostok::ai::fsm *m_logic; // edi
  vostok::ai::fsm_state *m_current_state; // ecx
  survarium::base_player *v6; // ecx
  vostok::ai::fsm_state *m_first; // eax

  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_user,
    "shell_extraction",
    (int)this);
  this->on_hide(this, real_remove);
  if ( this->m_is_in_sprint_transition )
  {
    survarium::base_player::unsubscribe_animation_player(
      v3,
      (vostok::animation::reserved_channel_ids_enum)this->m_user,
      (const void *)3,
      (int)this);
    this->m_is_in_sprint_transition = 0;
  }
  m_logic = this->m_logic;
  m_current_state = m_logic->m_current_state;
  if ( m_current_state )
  {
    m_current_state->finalize(m_current_state);
    m_logic->m_current_state = 0;
  }
  survarium::player_params_modifiers_container::remove_modifier(
    &this->m_user->m_profile->modifiers,
    movement_speed_modifier,
    &this->m_move_speed_modifier);
  if ( real_remove )
  {
    survarium::base_player::unsubscribe_from_player_death(v6, (int)this->m_user, &this->m_player_death_subscriber);
    this->m_dispersion_calculator.m_character_params = 0;
    this->m_dispersion_calculator.m_character_skill_factor_params = 0;
    this->m_recoil_calculator.m_character_calculator.m_params = 0;
    m_first = this->m_breath_vibration_calculator.m_logic.m_states.m_first;
    this->m_breath_vibration_calculator.m_user = 0;
    while ( m_first )
    {
      m_first[1].next = (vostok::ai::fsm_state *)this->m_breath_vibration_calculator.m_user;
      m_first = m_first->next;
    }
    this->m_user = 0;
  }
  this->m_portable_interactive_object->deactivate(this->m_portable_interactive_object, real_remove);
}
