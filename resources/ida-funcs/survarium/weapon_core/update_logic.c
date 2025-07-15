void __thiscall survarium::weapon_core::update_logic(survarium::weapon_core *this)
{
  vostok::ai::fsm_state *m_current_state; // ecx
  survarium::base_player *m_user; // eax
  unsigned int actions_mask; // eax
  survarium::weapon_core *v5; // ecx
  vostok::ai::fsm *v6; // ecx
  survarium::weapon_core *v7; // ecx
  survarium::weapon_user_animations_selector *v8; // ecx
  survarium::weapon_core *v9; // ecx

  survarium::weapon_user_animations_selector::tick(
    (survarium::weapon_user_animations_selector *)this,
    (int)&this->m_portable_interactive_object->m_user_animations_selector);
  m_user = this->m_user;
  if ( m_user )
  {
    m_current_state = this->m_logic->m_current_state;
    if ( m_current_state[12].transitions.m_size == 3 )
    {
      actions_mask = m_user->m_input.actions_mask;
      m_current_state = (vostok::ai::fsm_state *)(actions_mask >> 5);
      if ( (actions_mask & 0x20) == 0 || (actions_mask & 0x40) != 0 )
      {
        if ( (actions_mask & 0x800) != 0 )
        {
          this->set_next_fire_queue_type(this);
        }
        else if ( (actions_mask & 0x1000) != 0 )
        {
          this->set_next_ammo_type(this);
        }
        else
        {
          survarium::weapon_core::reset_fire_queue((survarium::weapon_core *)m_current_state, (int)this);
        }
      }
    }
  }
  survarium::weapon_core::check_for_sprint_transition(
    (survarium::weapon_core *)m_current_state,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)this);
  survarium::weapon_core::check_for_no_ammo_message(v5, this);
  vostok::ai::fsm::tick(v6, (int)this->m_logic);
  if ( survarium::weapon_core::is_going_to_sprint(v7, (int)this)
    && this->can_sprint((survarium::interactive_object *)this)
    || survarium::weapon_core::is_going_to_jump((survarium::weapon_core *)v8, (int)this)
    && this->can_jump((survarium::interactive_object *)this)
    || survarium::weapon_user_animations_selector::is_going_to_aim(
         v8,
         (int)&this->m_portable_interactive_object->m_user_animations_selector)
    && this->can_aim((survarium::interactive_object *)this)
    || this->m_aimed && !this->can_aim((survarium::interactive_object *)this) )
  {
    survarium::weapon_user_animations_selector::tick(
      v8,
      (int)&this->m_portable_interactive_object->m_user_animations_selector);
    survarium::weapon_core::check_for_sprint_transition(
      v9,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)this);
  }
}
