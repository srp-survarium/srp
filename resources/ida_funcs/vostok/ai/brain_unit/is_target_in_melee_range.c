int __thiscall vostok::ai::brain_unit::is_target_in_melee_range(
        vostok::ai::brain_unit *this,
        const vostok::ai::npc *const target)
{
  return ((int (__thiscall *)(vostok::ai::npc *, const vostok::ai::npc *const))this->m_npc->is_target_in_melee_range)(
           this->m_npc,
           target);
}
