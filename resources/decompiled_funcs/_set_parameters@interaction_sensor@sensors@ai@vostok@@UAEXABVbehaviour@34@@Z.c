void __thiscall vostok::ai::sensors::interaction_sensor::set_parameters(
        vostok::ai::sensors::interaction_sensor *this,
        const vostok::ai::behaviour *behaviour_parameters)
{
  this->m_parameters.enabled = behaviour_parameters->m_interaction_parameters.enabled;
}
