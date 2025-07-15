int __thiscall vostok::ai::brain_unit::is_at_cover(vostok::ai::brain_unit *this)
{
  return ((int (__thiscall *)(vostok::ai::npc *, vostok::ai::brain_unit *))this->m_npc->is_at_cover)(this->m_npc, this);
}
