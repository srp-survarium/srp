void __thiscall vostok::ai::sensors::vision_sensor::tick(vostok::ai::sensors::vision_sensor *this)
{
  if ( this->m_parameters.enabled
    && vostok::ai::ai_world::get_current_time_in_ms(this->m_world) - this->m_last_tick >= 0x3E8 )
  {
    vostok::ai::sensors::vision_sensor::update_visible_objects(this);
    vostok::ai::sensors::vision_sensor::update_perceptors(this);
  }
}
