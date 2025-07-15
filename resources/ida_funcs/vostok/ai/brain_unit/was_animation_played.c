bool __thiscall vostok::ai::brain_unit::was_animation_played(
        vostok::ai::brain_unit *this,
        const vostok::ai::animation_item *const target)
{
  return vostok::ai::blackboard::is_animation_played(&this->m_blackboard, target);
}
