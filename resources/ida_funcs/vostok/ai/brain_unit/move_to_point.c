void __thiscall vostok::ai::brain_unit::move_to_point(
        vostok::ai::brain_unit *this,
        const vostok::ai::movement_target *const target)
{
  this->m_npc->move_to_position(this->m_npc, target);
}
