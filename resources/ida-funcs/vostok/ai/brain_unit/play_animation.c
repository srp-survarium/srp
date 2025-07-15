void __thiscall vostok::ai::brain_unit::play_animation(
        vostok::ai::brain_unit *this,
        const vostok::ai::animation_item *const animation_to_be_played)
{
  this->m_npc->play_animation(this->m_npc, animation_to_be_played);
}
