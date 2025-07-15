int __thiscall vostok::ai::ai_world::get_characters_count(vostok::ai::ai_world *this)
{
  return this->m_npc_characters.m_end - this->m_npc_characters.m_begin;
}
