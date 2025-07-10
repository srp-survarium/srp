void __thiscall vostok::ai::sensors::smell_sensor::smell_sensor(
        vostok::ai::sensors::smell_sensor *this,
        vostok::ai::npc *npc,
        vostok::ai::ai_world *world,
        vostok::ai::brain_unit *brain)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->m_next = 0;
  this->m_npc = npc;
  this->m_world = world;
  this->m_brain_unit = brain;
  this->m_enabled = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)world) != 0
                  ? -51
                  : -3;
  this->__vftable = (vostok::ai::sensors::smell_sensor_vtbl *)&vostok::ai::sensors::smell_sensor::`vftable';
  vostok::ai::smell_sensor_parameters::smell_sensor_parameters(&this->m_parameters);
}
