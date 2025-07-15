void __thiscall survarium::grenade_core::pull_pin(survarium::grenade_core *this, unsigned int explode_time_ms)
{
  survarium::game_world_core *m_game_world_core; // eax

  this->m_explode_time_ms = explode_time_ms;
  m_game_world_core = this->m_game_world_core;
  this->m_exploded = 0;
  survarium::game_world_core::register_tickable_object((survarium::game_world_core *)this, (int)m_game_world_core);
}
