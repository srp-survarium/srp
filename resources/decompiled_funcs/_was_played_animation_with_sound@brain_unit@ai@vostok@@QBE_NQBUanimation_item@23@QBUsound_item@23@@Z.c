bool __thiscall vostok::ai::brain_unit::was_played_animation_with_sound(
        vostok::ai::brain_unit *this,
        const vostok::ai::animation_item *const animation,
        const vostok::ai::sound_item *const sound)
{
  return vostok::ai::blackboard::is_animation_played(&this->m_blackboard, animation)
      || vostok::ai::blackboard::is_sound_played(&this->m_blackboard, sound);
}
