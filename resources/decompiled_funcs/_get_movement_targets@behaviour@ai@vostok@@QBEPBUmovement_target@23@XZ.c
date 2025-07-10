const vostok::ai::movement_target *__thiscall vostok::ai::behaviour::get_movement_targets(vostok::ai::behaviour *this)
{
  return (const vostok::ai::movement_target *)((char *)&this[1]
                                             + 280 * this->m_animations_count
                                             + 280 * this->m_sounds_count);
}
