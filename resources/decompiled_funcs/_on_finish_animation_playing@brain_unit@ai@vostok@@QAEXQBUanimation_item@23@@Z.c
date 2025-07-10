void __thiscall vostok::ai::brain_unit::on_finish_animation_playing(
        vostok::ai::brain_unit *this,
        const vostok::ai::animation_item *const animation)
{
  vostok::ai::blackboard::add_played_animation(&this->m_blackboard, animation);
}
