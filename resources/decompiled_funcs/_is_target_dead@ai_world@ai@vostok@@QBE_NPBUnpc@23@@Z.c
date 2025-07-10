bool __thiscall vostok::ai::ai_world::is_target_dead(vostok::ai::ai_world *this, const vostok::ai::npc *target)
{
  survarium::game_camera *v2; // ecx
  vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::find_npc_by_id> pred; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int v6; // [esp+18h] [ebp-18h]
  bool v7; // [esp+1Eh] [ebp-12h]
  char v8; // [esp+1Fh] [ebp-11h]
  const vostok::ai::game_object *target_obj; // [esp+20h] [ebp-10h]
  vostok::ai::find_npc_by_id searching_predicate; // [esp+24h] [ebp-Ch] BYREF

  target_obj = target->cast_game_object(target);
  v8 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  v6 = target_obj->get_id((vostok::ai::game_object *)target_obj);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&searching_predicate);
  searching_predicate.npc_id = v6;
  searching_predicate.id_was_found = 0;
  searching_predicate.found_brain_unit = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &searching_predicate;
  vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::find_npc_by_id>>(
    &this->m_brain_units,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  v7 = !searching_predicate.id_was_found;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&searching_predicate);
  return v7;
}
