void __thiscall vostok::ai::brain_unit::tick(vostok::ai::brain_unit *this)
{
  vostok::ai::tick_predicate pred; // [esp+1Fh] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  ((void (__thiscall *)(vostok::ai::sound_player *, vostok::ai::sound_player *))this->m_sound_player.m_object->tick)(
    this->m_sound_player.m_object,
    this->m_sound_player.m_object);
  if ( !this->m_is_activity_suspended )
  {
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
    vostok::intrusive_list<vostok::ai::sensors::active_sensor_base,vostok::ai::sensors::active_sensor_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::ai::tick_predicate>(
      &this->m_active_sensors,
      &pred);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  }
}
