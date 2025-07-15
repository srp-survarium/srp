void __thiscall vostok::ai::sensors::vision_sensor::set_parameters(
        vostok::ai::sensors::vision_sensor *this,
        const vostok::ai::behaviour *behaviour_parameters)
{
  qmemcpy(&this->m_parameters, &behaviour_parameters->m_vision_parameters, sizeof(this->m_parameters));
}
