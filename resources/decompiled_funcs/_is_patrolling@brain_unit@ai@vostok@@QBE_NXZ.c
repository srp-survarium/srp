int __thiscall vostok::ai::brain_unit::is_patrolling(vostok::ai::brain_unit *this)
{
  return ((int (__thiscall *)(vostok::ai::npc *, vostok::ai::brain_unit *))this->m_npc->is_patrolling)(
           this->m_npc,
           this);
}
