int __thiscall vostok::ai::ai_world::get_classes_count(vostok::ai::ai_world *this)
{
  return this->m_npc_classes.m_end - this->m_npc_classes.m_begin;
}
