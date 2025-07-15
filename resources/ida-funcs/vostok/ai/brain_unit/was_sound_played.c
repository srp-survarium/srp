bool __thiscall vostok::ai::brain_unit::was_sound_played(
        vostok::ai::brain_unit *this,
        const vostok::ai::sound_item *const target)
{
  return vostok::ai::blackboard::is_sound_played(&this->m_blackboard, target);
}
