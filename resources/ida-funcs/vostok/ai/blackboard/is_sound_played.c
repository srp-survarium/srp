bool __thiscall vostok::ai::blackboard::is_sound_played(
        vostok::ai::blackboard *this,
        const vostok::ai::animation_item *item)
{
  vostok::ai::find_animation_collection_item_predicate pred; // [esp+1Ch] [ebp-8h] BYREF
  bool v5; // [esp+23h] [ebp-1h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.collection = item;
  v5 = vostok::intrusive_list<vostok::ai::sound_item_wrapper,vostok::ai::sound_item_wrapper *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::find_if<vostok::ai::find_sound_item_predicate>(
         (vostok::intrusive_list<vostok::ai::animation_item_wrapper,vostok::ai::animation_item_wrapper *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_played_sounds,
         &pred) != 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  return v5;
}
