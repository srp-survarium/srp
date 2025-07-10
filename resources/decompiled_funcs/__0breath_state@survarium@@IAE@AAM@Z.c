void __thiscall survarium::breath_state::breath_state(survarium::breath_state *this, float *breath_holding_reserve)
{
  survarium::game_camera *v2; // ecx

  vostok::ai::fsm_state::fsm_state(this);
  survarium::weapon_user_dead_state::finalize(v2);
  this->__vftable = (survarium::breath_state_vtbl *)&stru_977EF0.m_name_registry_entry;
  this->m_breath_holding_reserve = breath_holding_reserve;
}
