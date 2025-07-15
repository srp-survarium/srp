void __thiscall survarium::player_logic_jump_state::finalize(survarium::player_logic_jump_state *this)
{
  survarium::player_logic_jump_state *v1; // esi
  survarium::jump_type_enum m_jump_type; // eax
  boost::function<void __cdecl(void)> *p_m_sprint_finalize_callback; // eax
  vostok::ai::fsm_state *m_current_state; // ecx

  v1 = this;
  m_jump_type = this->m_logic.m_jump_type;
  if ( m_jump_type == jump_type_sprint_fwd
    || m_jump_type == jump_type_sprint_fwd_left
    || m_jump_type == jump_type_sprint_fwd_right )
  {
    p_m_sprint_finalize_callback = &this->m_sprint_finalize_callback;
    this = (survarium::player_logic_jump_state *)-(this->m_sprint_finalize_callback.vtable != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & (unsigned int)this) != 0 )
      boost::function0<void>::operator()((boost::function0<bool> *)this, p_m_sprint_finalize_callback);
  }
  survarium::base_player::end_jump((survarium::base_player *)this, (int)v1->m_logic.m_user);
  m_current_state = v1->m_logic.m_logic.m_current_state;
  if ( m_current_state )
  {
    m_current_state->finalize(m_current_state);
    v1->m_logic.m_logic.m_current_state = 0;
  }
  v1->m_is_sprinting = 0;
}
