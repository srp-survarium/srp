int __thiscall vostok::ai::brain_unit::is_at_node(
        vostok::ai::brain_unit *this,
        const vostok::ai::game_object *const node)
{
  return ((int (__thiscall *)(vostok::ai::npc *, const vostok::ai::game_object *const))this->m_npc->is_at_node)(
           this->m_npc,
           node);
}
