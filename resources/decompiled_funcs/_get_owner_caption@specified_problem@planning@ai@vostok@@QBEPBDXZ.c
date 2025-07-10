const survarium::flash_text *__thiscall vostok::ai::planning::specified_problem::get_owner_caption(
        vostok::ai::planning::specified_problem *this)
{
  const vostok::ai::game_object *v1; // eax

  if ( !this->m_owner )
    return &buf;
  v1 = this->m_owner->m_npc->cast_game_object(this->m_owner->m_npc);
  return (const survarium::flash_text *)((int (__thiscall *)(const vostok::ai::game_object *, const vostok::ai::game_object *))v1->get_name)(
                                          v1,
                                          v1);
}
