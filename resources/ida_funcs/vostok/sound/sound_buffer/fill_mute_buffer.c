void __thiscall vostok::sound::sound_buffer::fill_mute_buffer(
        vostok::sound::sound_buffer *this,
        const vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *encoded_sound)
{
  vostok::memory::zero(this->m_buff, 0xAC44u);
  vostok::memory::zero(&this->m_xaudio_buffer, 0x24u);
  this->m_xaudio_buffer.AudioBytes = 44100;
  this->m_xaudio_buffer.pAudioData = this->m_buff;
  this->m_xaudio_buffer.pContext = this;
  this->m_xaudio_buffer.PlayLength = 0xAC44
                                   / (encoded_sound->m_object->m_bytes_per_sample
                                    * this->m_encoded_sound.m_object->m_channels_num);
}
