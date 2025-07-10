void __thiscall vostok::ai::find_npc_by_id::operator()(
        vostok::ai::find_npc_by_id *this,
        vostok::ai::brain_unit *const brain)
{
  const vostok::ai::game_object *target; // [esp+Ch] [ebp-4h]

  target = (const vostok::ai::game_object *)((int (__thiscall *)(vostok::ai::npc *, vostok::ai::npc *))brain->m_npc->cast_game_object)(
                                              brain->m_npc,
                                              brain->m_npc);
  if ( target->get_id((vostok::ai::game_object *)target) == this->npc_id )
  {
    this->id_was_found = 1;
    this->found_brain_unit = brain;
  }
}
