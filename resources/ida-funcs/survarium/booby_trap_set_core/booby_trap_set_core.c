void __thiscall survarium::booby_trap_set_core::booby_trap_set_core(survarium::booby_trap_set_core *this)
{
  survarium::inventory_item::inventory_item(this, use_silent);
  this->__vftable = (survarium::booby_trap_set_core_vtbl *)&survarium::booby_trap_set_core::`vftable';
  this->m_traps.m_begin = 0;
  this->m_traps.m_end = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_traps);
  this->m_damage_parameters.m_begin = 0;
  this->m_damage_parameters.m_end = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_damage_parameters);
  survarium::booby_trap_set_core::config_params::config_params(&this->m_config);
  this->m_traps_buffer = 0;
}
