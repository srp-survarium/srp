void __thiscall vostok::ai::sensors::interaction_sensor::interaction_sensor(
        vostok::ai::sensors::interaction_sensor *this,
        vostok::ai::npc *npc,
        vostok::ai::ai_world *world,
        vostok::ai::brain_unit *brain)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->m_next = 0;
  this->m_npc = npc;
  this->m_world = world;
  this->m_brain_unit = brain;
  this->__vftable = (vostok::ai::sensors::interaction_sensor_vtbl *)&vostok::ai::sensors::interaction_sensor::`vftable';
  vostok::ai::interaction_sensor_parameters::interaction_sensor_parameters(&this->m_parameters);
}
