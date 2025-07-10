void __thiscall survarium::booby_trap_core::switch_to_state(
        survarium::booby_trap_core *this,
        survarium::game_camera *new_state)
{
  survarium::booby_trap_set_core *v2; // ecx
  survarium::booby_trap_set_core *v3; // ecx
  survarium::booby_trap_set_core *v4; // ecx

  if ( this->m_trap_state == booby_trap_state_armed )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    survarium::usable_object::remove(&this->survarium::usable_object);
    survarium::collision_sensor::remove(&this->survarium::collision_sensor);
    if ( survarium::booby_trap_set_core::config(v2, (int)this->m_owner)->defuse_by_hit )
      survarium::hittable_object::remove(&this->survarium::hittable_object);
  }
  switch ( (unsigned int)new_state )
  {
    case 0u:
      survarium::weapon_user_dead_state::finalize(new_state);
      goto LABEL_12;
    case 1u:
      survarium::weapon_user_dead_state::finalize(new_state);
      this->m_state_timer = survarium::booby_trap_set_core::config(v3, (int)this->m_owner)->armed_life_time;
      goto LABEL_12;
    case 2u:
      survarium::weapon_user_dead_state::finalize(new_state);
      this->m_state_timer = survarium::booby_trap_set_core::config(
                              (survarium::booby_trap_set_core *)this,
                              (int)this->m_owner)->fired_life_time;
      if ( !this->m_state_timer )
        goto LABEL_8;
      this->m_owner->on_trap_fired(this->m_owner, this);
      goto LABEL_12;
    case 3u:
      survarium::weapon_user_dead_state::finalize(new_state);
      this->m_state_timer = survarium::booby_trap_set_core::config(v4, (int)this->m_owner)->disarmed_life_time;
      if ( this->m_state_timer )
      {
        this->m_owner->on_trap_disarmed(this->m_owner, this);
LABEL_12:
        this->m_trap_state = (survarium::booby_trap_state)new_state;
      }
      else
      {
LABEL_8:
        this->m_owner->remove_trap(this->m_owner, this);
      }
      return;
  }
}
