void __thiscall survarium::damage_model::tick(
        survarium::damage_model *this,
        unsigned int time_delta_ms,
        unsigned int current_time_in_ms)
{
  vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::regenerate_body_parts_predicate> pred; // [esp+14h] [ebp-Ch] BYREF
  survarium::regenerate_body_parts_predicate regeneration_predicate; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_last_tick_time_in_ms )
  {
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&regeneration_predicate);
    regeneration_predicate.time_delta_ms = time_delta_ms;
    regeneration_predicate.current_time_in_ms = current_time_in_ms;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
    pred.m_predicate_ref = &regeneration_predicate;
    vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::regenerate_body_parts_predicate>>(
      &this->m_body_parts,
      &pred);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
    this->m_last_tick_time_in_ms = current_time_in_ms;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&regeneration_predicate);
  }
  else
  {
    this->m_last_tick_time_in_ms = current_time_in_ms;
  }
}
