void __thiscall vostok::ai::brain_unit::set_sensors_parameters(vostok::ai::brain_unit *this)
{
  vostok::intrusive_list<vostok::ai::sensors::passive_sensor_base,vostok::ai::sensors::passive_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::sensor_parameters_predicate> v2; // [esp+20h] [ebp-28h] BYREF
  vostok::intrusive_list<vostok::ai::sensors::active_sensor_base,vostok::ai::sensors::active_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::sensor_parameters_predicate> pred; // [esp+40h] [ebp-8h] BYREF
  vostok::ai::sensor_parameters_predicate sensor_parameters_setter; // [esp+44h] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&sensor_parameters_setter);
  sensor_parameters_setter.m_behaviour = &this->m_behaviour;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &sensor_parameters_setter;
  vostok::intrusive_list<vostok::ai::sensors::active_sensor_base,vostok::ai::sensors::active_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::sensors::active_sensor_base,vostok::ai::sensors::active_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::sensor_parameters_predicate>>(
    &this->m_active_sensors,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v2);
  v2.m_predicate_ref = &sensor_parameters_setter;
  vostok::intrusive_list<vostok::ai::sensors::passive_sensor_base,vostok::ai::sensors::passive_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::sensors::passive_sensor_base,vostok::ai::sensors::passive_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::sensor_parameters_predicate>>(
    &this->m_passive_sensors,
    &v2);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v2);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&sensor_parameters_setter);
}
