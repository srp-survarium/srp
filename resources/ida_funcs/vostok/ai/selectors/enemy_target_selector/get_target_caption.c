const char *__thiscall vostok::ai::selectors::enemy_target_selector::get_target_caption(
        vostok::ai::selectors::enemy_target_selector *this,
        unsigned int target_index)
{
  survarium::game_camera *v2; // ecx
  const vostok::ai::npc *first; // [esp+0h] [ebp-10h]
  const vostok::ai::game_object *object; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  first = this->m_selected_enemies.m_begin[target_index].first;
  object = (const vostok::ai::game_object *)((int (__thiscall *)(const vostok::ai::npc *, const vostok::ai::npc *))first->cast_game_object)(
                                              first,
                                              first);
  survarium::weapon_user_dead_state::finalize(v2);
  return (const char *)object->get_name((vostok::ai::game_object *)object);
}
