void __thiscall vostok::sound::sound_buffer::fill_buffer(
        vostok::sound::sound_buffer *this,
        const vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *encoded_sound,
        unsigned int pcm_offset,
        unsigned int *next_pcm_offset)
{
  unsigned int v4; // [esp+0h] [ebp-58h]
  vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *p_m_encoded_sound; // [esp+3Ch] [ebp-1Ch]
  vostok::sound::encoded_sound_interface *m_object; // [esp+44h] [ebp-14h]
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+48h] [ebp-10h] BYREF
  unsigned int audio_bytes; // [esp+4Ch] [ebp-Ch]
  unsigned __int64 total_pcm; // [esp+50h] [ebp-8h]

  p_m_encoded_sound = &this->m_encoded_sound;
  v8.m_object = 0;
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v8,
    encoded_sound);
  m_object = v8.m_object;
  v8.m_object = p_m_encoded_sound->m_object;
  p_m_encoded_sound->m_object = m_object;
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
  this->m_cached_offset = pcm_offset;
  total_pcm = this->m_encoded_sound.m_object->m_length_in_pcm;
  audio_bytes = this->m_encoded_sound.m_object->decompress(
                  this->m_encoded_sound.m_object,
                  this->m_buff,
                  pcm_offset,
                  next_pcm_offset,
                  44100u);
  this->m_last_value_in_buffer = *(&this->m_last_value_in_buffer + *next_pcm_offset - pcm_offset);
  this->m_xaudio_buffer.PlayLength = audio_bytes
                                   / (this->m_encoded_sound.m_object->m_bytes_per_sample
                                    * this->m_encoded_sound.m_object->m_channels_num);
  this->m_xaudio_buffer.PlayBegin = 0;
  this->m_cached_offset_after_decompress = *next_pcm_offset;
  if ( total_pcm == *next_pcm_offset )
    v4 = 64;
  else
    v4 = 0;
  this->m_xaudio_buffer.Flags = v4;
  this->m_xaudio_buffer.AudioBytes = audio_bytes;
  this->m_xaudio_buffer.pAudioData = this->m_buff;
  this->m_xaudio_buffer.LoopBegin = 0;
  this->m_xaudio_buffer.LoopLength = 0;
  this->m_xaudio_buffer.LoopCount = 0;
  this->m_xaudio_buffer.pContext = this;
}
