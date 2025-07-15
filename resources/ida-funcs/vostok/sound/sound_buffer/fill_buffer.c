void __userpurge vostok::sound::sound_buffer::fill_buffer(
        vostok::sound::sound_buffer *this@<esi>,
        const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *encoded_sound@<eax>,
        unsigned int start_pcm_offset,
        unsigned int *next_pcm_offset)
{
  vostok::sound::encoded_sound_interface *m_object; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ebx
  unsigned int v7; // eax
  unsigned __int64 m_length_in_pcm; // [esp+8h] [ebp-8h]

  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    encoded_sound,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_encoded_sound);
  m_object = this->m_encoded_sound.m_object;
  this->m_cached_offset = start_pcm_offset;
  m_length_in_pcm = m_object->m_length_in_pcm;
  v5 = m_object->decompress(m_object, this->m_buff, start_pcm_offset, next_pcm_offset, 88200u);
  v6 = this->m_encoded_sound.m_object->m_bytes_per_sample * this->m_encoded_sound.m_object->m_channels_num;
  this->m_xaudio_buffer.PlayBegin = 0;
  this->m_xaudio_buffer.PlayLength = v5 / v6;
  this->m_cached_offset_after_decompress = *next_pcm_offset;
  if ( m_length_in_pcm == *next_pcm_offset )
    v7 = 64;
  else
    v7 = 0;
  this->m_xaudio_buffer.Flags = v7;
  this->m_xaudio_buffer.AudioBytes = v5;
  this->m_xaudio_buffer.pAudioData = this->m_buff;
  this->m_xaudio_buffer.LoopBegin = 0;
  this->m_xaudio_buffer.LoopLength = 0;
  this->m_xaudio_buffer.LoopCount = 0;
  this->m_xaudio_buffer.pContext = this;
}
