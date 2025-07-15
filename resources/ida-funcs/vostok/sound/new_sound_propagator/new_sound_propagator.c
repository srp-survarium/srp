void __userpurge vostok::sound::new_sound_propagator::new_sound_propagator(
        vostok::sound::new_sound_propagator *this@<esi>,
        vostok::sound::sound_instance_proxy_internal *proxy@<eax>,
        const vostok::sound::sound_propagator_emitter *emitter@<ecx>,
        unsigned int playback_id)
{
  unsigned int m_length_in_msec; // eax
  bool v5; // zf

  this->m_proxy = proxy;
  this->m_voice = 0;
  this->m_emitter = emitter;
  this->m_playback_mode = once;
  this->m_master_propagator = 0;
  this->m_playback_id = playback_id;
  this->m_start_offset_ms = 0;
  this->m_propagation_time_ms = 0;
  this->m_propagation_state = propagating_idle;
  this->m_is_callback_executer = 0;
  this->m_amplitude_freezed = 0;
  this->m_dist_to_listener = 0.0;
  this->m_perceived_loudness_db = 0.0;
  this->m_attenuated_loudness_db = 0.0;
  this->m_voice_displaced_timer = 0;
  this->m_out_amplitude_value = 0.0;
  m_length_in_msec = emitter->dbg_get_encoded_sound(emitter, 0)->m_object->m_length_in_msec;
  v5 = this->m_playback_mode == once;
  this->m_start_offset_ms = 0;
  this->m_sound_length_ms = m_length_in_msec;
  if ( v5 )
    this->m_end_propagation_time_ms = m_length_in_msec;
  else
    this->m_end_propagation_time_ms = -1;
}
