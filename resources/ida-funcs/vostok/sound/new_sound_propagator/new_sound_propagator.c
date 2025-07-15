void __thiscall vostok::sound::new_sound_propagator::new_sound_propagator(
        vostok::sound::new_sound_propagator *this,
        const vostok::math::float3 *start_position,
        const vostok::math::float3 *listener_position,
        vostok::sound::playback_mode mode,
        unsigned int playback_id,
        unsigned int playing_offset,
        unsigned int before_playing_offset,
        unsigned int after_playing_offset,
        vostok::sound::sound_instance_proxy_internal *proxy,
        const vostok::sound::sound_propagator_emitter *emitter)
{
  vostok::sound::sound_world *m_owner_world; // [esp+10h] [ebp-70h]
  float v12; // [esp+1Ch] [ebp-64h]
  float v13; // [esp+40h] [ebp-40h]
  float v14; // [esp+44h] [ebp-3Ch]
  SpeedTree::Vec3 v15; // [esp+74h] [ebp-Ch] BYREF

  this->m_voice = 0;
  this->m_submix_voices.m_begin = (IXAudio2SubmixVoice **)this->m_submix_voices.m_buffer;
  this->m_submix_voices.m_end = (IXAudio2SubmixVoice **)this->m_submix_voices.m_buffer;
  this->m_start_position = *start_position;
  this->m_proxy = proxy;
  this->m_emitter = emitter;
  this->m_mode = mode;
  this->m_is_callback_executer = 0;
  this->m_playing_offset = playing_offset;
  this->m_playback_id = playback_id;
  this->m_propagation_time = 0;
  this->m_before_playing_offsets = before_playing_offset;
  this->m_after_playing_offsets = after_playing_offset;
  this->m_propagation_state = propagating;
  this->m_perceived_loudness = *(float *)&FLOAT_0_0;
  this->m_attenuated_loudness = *(float *)&FLOAT_0_0;
  this->m_sound_length = emitter->get_quality_for_resource(emitter)->m_object->m_length_in_msec;
  this->m_sound_length_with_offsets = this->m_after_playing_offsets
                                    + this->m_sound_length
                                    + this->m_before_playing_offsets;
  if ( this->m_proxy->m_type == hud )
  {
    this->m_time_to_listener = 0;
  }
  else
  {
    m_owner_world = proxy->m_user->m_owner_world;
    v13 = listener_position->y - start_position->y;
    v14 = listener_position->z - start_position->z;
    v15.x = listener_position->x - start_position->x;
    v15.y = v13;
    v15.z = v14;
    v12 = vostok::math::float3_pod::squared_length(&v15);
    this->m_time_to_listener = (__int64)(fsqrt(v12)
                                       / ((double (__thiscall *)(vostok::sound::sound_world *))m_owner_world->get_speed_of_sound)(m_owner_world));
  }
  if ( mode )
    this->m_end_propagation_time = -1;
  else
    this->m_end_propagation_time = this->m_sound_length_with_offsets + this->m_time_to_listener - playing_offset;
}
