int __thiscall vostok::ai::ai_world::get_groups_count(vostok::ai::ai_world *this)
{
  return this->m_npc_groups.m_end - this->m_npc_groups.m_begin;
}
