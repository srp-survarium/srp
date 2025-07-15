void __thiscall vostok::ai::sensors::hearing_sensor::set_parameters(
        vostok::ai::sensors::hearing_sensor *this,
        const vostok::ai::behaviour *behaviour_parameters)
{
  qmemcpy(&this->m_parameters, &behaviour_parameters->m_hearing_parameters, sizeof(this->m_parameters));
}
