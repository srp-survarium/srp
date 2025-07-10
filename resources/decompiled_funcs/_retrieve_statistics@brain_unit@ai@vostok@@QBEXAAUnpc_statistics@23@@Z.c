void __thiscall vostok::ai::brain_unit::retrieve_statistics(
        vostok::ai::brain_unit *this,
        vostok::ai::npc_statistics *stats)
{
  vostok::intrusive_list<vostok::ai::selectors::target_selector_base,vostok::ai::selectors::target_selector_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::dump_state_predicate> v3; // [esp+18h] [ebp-38h] BYREF
  vostok::intrusive_list<vostok::ai::sensors::passive_sensor_base,vostok::ai::sensors::passive_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::dump_state_predicate> v4; // [esp+30h] [ebp-20h] BYREF
  vostok::intrusive_list<vostok::ai::sensors::active_sensor_base,vostok::ai::sensors::active_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::dump_state_predicate> pred; // [esp+48h] [ebp-8h] BYREF
  vostok::ai::dump_state_predicate dumper_predicate; // [esp+4Ch] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&dumper_predicate);
  dumper_predicate.stats_to_be_filled = stats;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &dumper_predicate;
  vostok::intrusive_list<vostok::ai::sensors::active_sensor_base,vostok::ai::sensors::active_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::sensors::active_sensor_base,vostok::ai::sensors::active_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::dump_state_predicate>>(
    &this->m_active_sensors,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v4);
  v4.m_predicate_ref = &dumper_predicate;
  vostok::intrusive_list<vostok::ai::sensors::passive_sensor_base,vostok::ai::sensors::passive_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::sensors::passive_sensor_base,vostok::ai::sensors::passive_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::dump_state_predicate>>(
    &this->m_passive_sensors,
    &v4);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v4);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v3);
  v3.m_predicate_ref = &dumper_predicate;
  vostok::intrusive_list<vostok::ai::selectors::target_selector_base,vostok::ai::selectors::target_selector_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::selectors::target_selector_base,vostok::ai::selectors::target_selector_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::dump_state_predicate>>(
    &this->m_target_selectors,
    &v3);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v3);
  vostok::ai::working_memory::dump_state(&this->m_working_memory, stats);
  vostok::ai::blackboard::dump_state(&this->m_blackboard, stats);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&dumper_predicate);
}
