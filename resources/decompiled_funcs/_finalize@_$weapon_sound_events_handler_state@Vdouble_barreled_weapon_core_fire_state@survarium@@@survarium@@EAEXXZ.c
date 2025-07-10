void __thiscall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state> *this)
{
  survarium::weapon_core::remove_animation_callback(this->m_weapon, "sound_events", &this->m_sound_effect);
  if ( this->m_sound_effect.m_stop_sounds_on_state_finalize )
  {
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
      this->m_sound_effect.m_first_view_sounds.sounds_instances.m_begin,
      &this->m_sound_effect.m_first_view_sounds.sounds_instances.m_end);
    this->m_sound_effect.m_first_view_sounds.sounds_instances.m_end = this->m_sound_effect.m_first_view_sounds.sounds_instances.m_begin;
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::destroy(
      this->m_sound_effect.m_third_view_sounds.sounds_instances.m_begin,
      &this->m_sound_effect.m_third_view_sounds.sounds_instances.m_end);
    this->m_sound_effect.m_third_view_sounds.sounds_instances.m_end = this->m_sound_effect.m_third_view_sounds.sounds_instances.m_begin;
  }
  survarium::weapon_core_fire_state_base::finalize(this);
}
