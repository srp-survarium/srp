void __thiscall survarium::grenade_core::reset_pin(survarium::grenade_core *this)
{
  survarium::grenade_set_core::current_time_in_ms((survarium::grenade_set_core *)this, (int)this->m_owner);
  survarium::game_world_core::unregister_tickable_object(this->m_game_world_core, this);
  this->m_explode_time_ms = -1;
}
