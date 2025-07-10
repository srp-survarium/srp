void __thiscall vostok::ai::sensors::smell_sensor::set_parameters(
        vostok::ai::sensors::smell_sensor *this,
        const vostok::ai::behaviour *behaviour_parameters)
{
  qmemcpy(&this->m_parameters, &behaviour_parameters->m_smell_parameters, sizeof(this->m_parameters));
}
