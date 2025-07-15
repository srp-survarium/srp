void __usercall vostok::sound::sound_voice::sound_voice(
        vostok::sound::sound_voice *this@<esi>,
        vostok::sound::new_sound_propagator *propagator@<eax>,
        const vostok::sound::sound_propagator_emitter *emitter@<ecx>)
{
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v3; // edi
  vostok::sound::voice_factory *m_voice_factory; // eax
  unsigned int *p_m_mono_pool_iterator; // edi
  vostok::sound::voice_bridge **m_mono_voices; // ebx
  vostok::sound::voice_bridge *v7; // ecx
  vostok::sound::new_sound_propagator *m_propagator; // eax
  unsigned int mono_voices_count; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  this->m_next_for_delete = 0;
  this->m_next_for_active = 0;
  this->m_is_playing = 0;
  this->m_world_user = propagator->m_proxy->m_user;
  this->m_emitter = emitter;
  this->m_propagator = propagator;
  this->m_stream_cursor_pcm = 0;
  this->m_current_sound_quality.m_object = 0;
  this->m_start_deffered = 0;
  v3 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)emitter->dbg_get_encoded_sound(emitter, 0);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v3,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_current_sound_quality);
  this->m_current_sound_quality.m_object->attach(this->m_current_sound_quality.m_object);
  m_voice_factory = this->m_world_user->m_owner_world->m_voice_factory;
  if ( this->m_current_sound_quality.m_object->m_channels_num == 1 )
  {
    mono_voices_count = m_voice_factory->m_pool_params.mono_voices_count;
    p_m_mono_pool_iterator = &m_voice_factory->m_mono_pool_iterator;
    m_mono_voices = m_voice_factory->m_mono_voices;
  }
  else
  {
    mono_voices_count = m_voice_factory->m_pool_params.stereo_voices_count;
    p_m_mono_pool_iterator = &m_voice_factory->m_stereo_pool_iterator;
    m_mono_voices = m_voice_factory->m_stereo_voices;
  }
  for ( i = 0; ; ++i )
  {
    v7 = m_mono_voices[*p_m_mono_pool_iterator];
    *p_m_mono_pool_iterator = (*p_m_mono_pool_iterator + 1) % mono_voices_count;
    if ( !v7->m_handler_ )
      break;
  }
  v7->m_handler_ = this;
  m_propagator = this->m_propagator;
  this->m_voice = v7;
  v7->m_output_voice = m_propagator->m_proxy->m_scene->m_submix_voice;
}
