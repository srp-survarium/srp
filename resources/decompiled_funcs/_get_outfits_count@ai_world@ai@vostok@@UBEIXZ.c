int __thiscall vostok::ai::ai_world::get_outfits_count(vostok::ai::ai_world *this)
{
  return this->m_npc_outfits.m_end - this->m_npc_outfits.m_begin;
}
