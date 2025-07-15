void __thiscall vostok::ai::ai_world::tick(vostok::ai::ai_world *this)
{
  vostok::ai::tick_brain_unit_predicate pred; // [esp+17h] [ebp-1h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::ai::tick_brain_unit_predicate>(
    &this->m_brain_units,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
}
