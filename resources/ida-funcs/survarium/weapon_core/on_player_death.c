void __thiscall survarium::weapon_core::on_player_death(survarium::weapon_core *this)
{
  vostok::ai::fsm *m_logic; // ebp
  survarium::base_player *m_current_state; // ecx
  survarium::weapon_core_base_state *m_object; // edi
  survarium::base_player *m_user; // [esp-Ch] [ebp-14h]

  if ( this->m_user )
  {
    m_logic = this->m_logic;
    m_current_state = (survarium::base_player *)m_logic->m_current_state;
    m_object = this->m_idle_state.m_object;
    if ( m_current_state != (survarium::base_player *)m_object )
    {
      if ( m_current_state )
        ((void (__thiscall *)(survarium::base_player *))m_current_state->unlink_child_resource)(m_current_state);
      m_logic->m_current_state = m_object;
      if ( m_object )
        m_object->initialize(m_object);
    }
    this->m_need_to_auto_reload = 0;
    if ( this->m_aimed )
      this->instant_aim_end(this);
    if ( this->m_is_in_sprint_transition )
    {
      m_user = this->m_user;
      this->m_is_in_sprint_transition = 0;
      survarium::base_player::unsubscribe_animation_player(
        m_current_state,
        (vostok::animation::reserved_channel_ids_enum)m_user,
        (const void *)3,
        (int)this);
    }
    if ( this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size == 3 )
      survarium::base_player::end_jump(m_current_state, (int)this->m_user);
  }
}
