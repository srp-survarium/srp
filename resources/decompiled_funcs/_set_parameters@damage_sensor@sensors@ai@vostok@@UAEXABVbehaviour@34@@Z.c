void __thiscall vostok::ai::sensors::damage_sensor::set_parameters(
        vostok::ai::sensors::damage_sensor *this,
        const vostok::ai::behaviour *behaviour_parameters)
{
  this->m_parameters.enabled = behaviour_parameters->m_damage_parameters.enabled;
}
